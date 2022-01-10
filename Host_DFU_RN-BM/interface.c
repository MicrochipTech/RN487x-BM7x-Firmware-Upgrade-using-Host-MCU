/*
********************************************************************************

Software License Agreement

Copyright © 2018 Microchip Technology Inc. and its licensors.  All
rights reserved.

Microchip licenses to you the right to: (1) install Software on a single
computer and use the Software with Microchip microcontrollers and
digital signal controllers ("Microchip Product"); and (2) at your
own discretion and risk, use, modify, copy and distribute the device
driver files of the Software that are provided to you in Source Code;
provided that such Device Drivers are only used with Microchip Products
and that no open source or free software is incorporated into the Device
Drivers without Microchip's prior written consent in each instance.

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE
LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY,
CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY
DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR
LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

********************************************************************************
*/
#include "platform_files.h"
#include "config.h"
#include "bm_mode.h"
#include "bm_application_mode.h"
#include "bm_program_mode.h"
#include "bm_utils.h"
#include "fifo.h"
#include "event_mem.h"
#include "memory.h"
#include "ble_api.h"
#include "dfu_api.h"
#include "interface.h"


static fifo_t rx_fifo;
static uint8_t rx_fifo_buffer[1024];
static bool is_fifo_full = false;
//static uint8_t uart_frame_rx_state = FRAME_RX_WAITING_STATE;
//static bm_cmd_frame_t bm_cmd_frame = {0,};
static uint8_t resp_event_id = INVALID_EVENT_ID;
static void *platform_timer_handle = NULL;
static sw_timer_t sw_timers[INTERFACE_SW_TIMERS] = {0};
static bool hw_timer_status = 0;
static void* interface_uart_timer_handle = NULL;
static void* interface_event_timer_handle = NULL;
//static event_mem_t *event_mem = NULL;
static bool interface_uart_timer_timeout = false;
static bool interface_event_timer_timeout = false;

ble_platform_api_list_t *platform;
uart_write_sync_cb_t ble_uart_send_sync = interface_cmd_send_no_wait;
uart_read_async_cb_t ble_uart_receive_async;

extern event_t appEvent;


static void interface_timer_callback(void *arg1)
{
    uint8_t index;
    platform->start_timer(platform_timer_handle, 1);
    hw_timer_status = 0;
    for (index = 0; index < INTERFACE_SW_TIMERS; index++)
    {
	    if (sw_timers[index].timer_usage == 1 && sw_timers[index].timer_counter > 0)
	    {
		    sw_timers[index].timer_counter--;
		    if (sw_timers[index].timer_counter == 0 && sw_timers[index].timer_cb != NULL)
		    {
			    sw_timers[index].timer_cb();
		    }
		    if (sw_timers[index].timer_counter > 0)
		    {
			    hw_timer_status = 1;
		    }
	    }
    }
    if (0 == hw_timer_status)
    {
	    platform->stop_timer(platform_timer_handle);
    }
	
	arg1 = arg1;
}

static void interface_uart_timer_cb(void)
{
	interface_uart_timer_timeout = true;
}

static void interface_event_timer_cb(void)
{
	interface_event_timer_timeout = true;
}

static void* interface_create_timer(timer_cb_t timer_cb)
{
	uint32_t index;
	for (index = 0; index < INTERFACE_SW_TIMERS; index++)
	{
		if (sw_timers[index].timer_usage == 0)
		{
			sw_timers[index].timer_usage = 1;
			sw_timers[index].timer_counter = 0;
			sw_timers[index].timer_cb = timer_cb;
			return &sw_timers[index];
		}
	}
	return NULL;
}

#if 0	//Removed, just to avoid compiler error
static void interface_delete_timer(void *timer_handle)
{
	uint32_t index;
	sw_timer_t *temp_sw_timer = (sw_timer_t *)timer_handle;
	temp_sw_timer->timer_usage = 0;
	temp_sw_timer->timer_counter = 0;
	temp_sw_timer->timer_cb = NULL;
	hw_timer_status = 0;
	for (index = 0; index < INTERFACE_SW_TIMERS; index++)
	{
		if (sw_timers[index].timer_usage == 1 && sw_timers[index].timer_counter > 0)
		{
			hw_timer_status = 1;
			break;
		}
	}
	if (0 == hw_timer_status)
	{
		platform->stop_timer(platform_timer_handle);
	}
}
#endif //#if 0

static void interface_start_timer(void *timer_handle, uint32_t ms)
{
	sw_timer_t *temp_sw_timer = (sw_timer_t *)timer_handle;
	temp_sw_timer->timer_counter = ms;
	if (0 == hw_timer_status)
	{
		platform->start_timer(platform_timer_handle, 1);
		hw_timer_status = 1;
	}
}

static void interface_stop_timer(void *timer_handle)
{
	uint32_t index;
	sw_timer_t *temp_sw_timer = (sw_timer_t *)timer_handle;
	temp_sw_timer->timer_counter = 0;
	hw_timer_status = 0;
	for (index = 0; index < INTERFACE_SW_TIMERS; index++)
	{
		if (sw_timers[index].timer_usage == 1 && sw_timers[index].timer_counter > 0)
		{
			hw_timer_status = 1;
			break;
		}
	}
	if (0 == hw_timer_status)
	{
		platform->stop_timer(platform_timer_handle);
	}
}


/*
 * @brief Initialize the interface layer
 *
 * @param pointer to platform_init which contains platform API list and event memory
 *
 * @return status of interface initialization
*/
ble_status_t  interface_init(platform_init_t *platform_init)
{
	init_fifo();
	
	if((NULL == platform_init->event_mem.event_mem_pool) || (0 == platform_init->event_mem.event_mem_pool_size))
	{
		return BLE_FAILURE;
	}
	if((NULL == platform_init->event_mem.event_payload_mem) || (0 == platform_init->event_mem.event_payload_mem_size))
	{
		return BLE_FAILURE;
	}
	
	mem_init((uint8_t *)platform_init->event_mem.event_payload_mem, platform_init->event_mem.event_payload_mem_size);
	/* Initialize an event queue */
	if(false == event_fifo_init(platform_init->event_mem.event_mem_pool, platform_init->event_mem.event_mem_pool_size))
	{
		return BLE_FAILURE;
	}
	
	if(NULL == platform_init ||
		NULL == platform_init->platform_api_list.create_timer ||
		NULL == platform_init->platform_api_list.delete_timer ||
		NULL == platform_init->platform_api_list.start_timer ||
		NULL == platform_init->platform_api_list.stop_timer ||
		NULL == platform_init->platform_api_list.sleep_timer_ms ||
		NULL == platform_init->platform_api_list.gpio_set ||
		NULL == platform_init->platform_api_list.mode_set ||
		NULL == platform_init->platform_api_list.uart_rx_cb ||
		NULL == platform_init->platform_api_list.uart_tx_cb)
		{
			return BLE_GAP_INVALID_PARAM;
		}
		
		platform = &platform_init->platform_api_list;
		
		/* Create platform timer */
		platform_timer_handle = platform_init->platform_api_list.create_timer(interface_timer_callback);
        if (NULL == platform_timer_handle)
        {
	        return BLE_FAILURE;
        }
		
		/* Creating timers used in interface layer */
		interface_uart_timer_handle = interface_create_timer(interface_uart_timer_cb);
        if (NULL == interface_uart_timer_handle)
        {
	        return BLE_FAILURE;
        }
		
		interface_event_timer_handle = interface_create_timer(interface_event_timer_cb);
        if (NULL == interface_event_timer_handle)
        {
	        return BLE_FAILURE;
        }
		
		/* Start reading UART data */
		platform_init->platform_api_list.uart_rx_cb(&store_uart_data);
		
		return BLE_SUCCESS;
}

/*
 * @brief Initialize the UART receive FIFO
 *
 * @param
 *
 * @return 
*/
void init_fifo(void)
{
	fifo_init(&rx_fifo, rx_fifo_buffer, sizeof(rx_fifo_buffer));
}

/*
 * @brief Send BM7x command through UART
 *
 * @param[in] cmd BM7x command
 * @param[in] cmd_len BM7x command length
 *
 * @return ble_status_t
*/
ble_status_t interface_cmd_send_no_wait(uint8_t *cmd, uint32_t cmd_len)
{
	platform->uart_tx_cb(cmd, cmd_len);
	return BLE_SUCCESS;
}

/*
 * @brief Send BM7x command through UART
 *
 * @param[in] cmd BM7x command
 * @param[in] cmd_len BM7x command length
 * @param[in] event_id response event from BM7x for the command is being send
 *
 * @return ble_status_t
*/
ble_status_t interface_cmd_send_wait(uint8_t *cmd, uint32_t cmd_len, uint8_t event_id)
{
	resp_event_id = event_id;
	platform->uart_tx_cb(cmd, cmd_len);
	interface_start_timer(interface_uart_timer_handle, INTERFACE_CMD_COMPLETE_TIMEOUT);
	while(!interface_uart_timer_timeout && !interface_event_process());
	
	if(interface_uart_timer_timeout)
	{
		interface_uart_timer_timeout = false;
		return BLE_TIMEOUT;
	}
	else
	{
		interface_stop_timer(interface_uart_timer_handle);
		return BLE_SUCCESS;
	}
}

ble_status_t interface_cmd_wait(uint8_t event_id)
{
	resp_event_id = event_id;
	interface_start_timer(interface_uart_timer_handle, INTERFACE_CMD_COMPLETE_TIMEOUT);
	while(!interface_uart_timer_timeout && !interface_event_process());
	
	if(interface_uart_timer_timeout)
	{
		interface_uart_timer_timeout = false;
		return BLE_TIMEOUT;
	}
	else
	{
		interface_stop_timer(interface_uart_timer_handle);
		return BLE_SUCCESS;
	}
}

//! [callback_funcs]
void store_uart_data(uint16_t rx_data)
{
	uint8_t data = (uint8_t) rx_data;
	
	if (!fifo_put(&rx_fifo, data))
	{
		//DBG_LOG("trying to put data in full fifo, wr_idx = %d, rd_idx = %d\r\n", (int)rx_fifo.wr_idx, (int)rx_fifo.rd_idx);
	}
	// We will stop receiving from the HW,
	// when fifo_full return zero we can start receiving from HW again
	if (fifo_full(&rx_fifo))
	{
		// stop receiver
		is_fifo_full = true;
	}
	else
	{
		// read the next byte
		platform->uart_rx_cb(&store_uart_data);
        
	}
}

/*
 * @brief Reads fifo where data/commands from BMxx stored. It also parse commands and check CRC
 *
 * @param 
 *
 * @return
*/
uint8_t interface_process_fifo_data(void)
{
	uint8_t byte;
	bool result;
	
	while (!fifo_empty(&rx_fifo))
	{
		//Initialize the mode variable to avoid warning
		BM_MODE mode = BM_MODE_PROGRAM;
		
		fifo_get(&rx_fifo, &byte);
		
		if(true == is_fifo_full)
		{
			is_fifo_full = false;
			platform->uart_rx_cb(&store_uart_data);
		}
		
        BM_MODE_Get(mode);
        if (mode == BM_MODE_APPLICATION)
            result = ble_response_check(byte);
        else if (mode == BM_MODE_PROGRAM)
            result = dfu_response_check(byte);

		if (result)
		{
			return INTERFACE_EVENT_READY;
		}
	}
	
	return INTERFACE_EVENT_WAITING;
}

bool is_waiting_for_this_response(uint8_t event_id)
{
	if((event_id == resp_event_id) && (INVALID_EVENT_ID != resp_event_id))
	{
		return true;
	}
	
	return false;
}

bool is_waiting_for_response(void)
{
	if(INVALID_EVENT_ID != resp_event_id)
	{
		return true;
	}
	
	return false;
}

/*
 * @brief Process events from BM7x
 *
 * @param
 *
 * @return true, if desired event is received otherwise false
*/
bool interface_event_process(void)
{
	bool is_event_ready = interface_process_fifo_data();
	bool is_event_received = false;
	
	if(is_waiting_for_response())
	{
		/* Waiting for response from BM7x */
		do 
		{
			if(INTERFACE_EVENT_READY == is_event_ready)
			{
				if(is_waiting_for_this_response(appEvent.event_id))
				{
					/* Received the specific event? then return status to application */
					is_event_received = true;
				}
				else
				{
					/* If this is not the expected event then post event in event Q and look for specific event */
					/* !!! POST an EVENT !!! */
					is_event_received = false;
					appEvent.event_msg.data_len--; //Subtract the length of event_id
					/* Since this is not a specific event we are looking for, 
						not checking the status of event post */
					event_fifo_write(&appEvent);
					is_event_ready = interface_process_fifo_data();
				}
			}
			else
			{
				is_event_ready = interface_process_fifo_data();
			}
		} while ((false == is_event_received) && (!interface_uart_timer_timeout)); /* Is expected event received? or timeout happened*/
	}

	return is_event_received;
}

/*
 * @brief Process BM7x command, if any, and post it in Event Q
 *
 * @param
 *OTAU_INDICATION_CHAR_IDX
 * @return Event Q status
*/
event_status_t interface_event_get(void)
{
	event_status_t status = BLE_EVENT_Q_EMPTY;
	bool is_event_ready = interface_process_fifo_data();
	
	if(INTERFACE_EVENT_READY == is_event_ready)
	{
		/* Post response in event Q and process event */
		/* !!! POST an EVENT !!! */
		appEvent.event_msg.data_len--; //Subtract the length of event_id
		status = event_fifo_write(&appEvent);
	}
	
	return status;
}

/*
 * @brief Provides pointer to received command frame
 *
 * @param
 *
 * @return pointer to event_t
*/
event_t* get_received_cmd_frame(void)
{
	return &appEvent;
}
