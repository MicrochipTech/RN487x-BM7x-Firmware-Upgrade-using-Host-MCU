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
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#define INVALID_EVENT_ID	0xFF

#define INTERFACE_SW_TIMERS	5

#define INTERFACE_CMD_COMPLETE_TIMEOUT		5000


enum
{
	INTERFACE_EVENT_WAITING,
	INTERFACE_EVENT_READY,
};

typedef struct
{
	uint32_t timer_usage;
	uint32_t timer_counter;
	void (*timer_cb)(void);
}sw_timer_t;

typedef void (*timer_cb_t)(void);
/*
 * @brief Initialize the interface layer
 *
 * @param pointer to platform_init which contains platform API list and event memory
 *
 * @return status of interface initialization
*/
ble_status_t interface_init(platform_init_t *platform_init);

/*
 * @brief Initialize the UART receive FIFO
 *
 * @param
 *
 * @return 
*/
void init_fifo(void);

/*
 * @brief Register a callback for BMxx UART TX
 *
 * @param[in] uart_tx_cb UART TX callback
 *
 * @return 
*/
void ble_api_register_uart_interface(uart_write_sync_cb_t uart_tx_cb, uart_read_async_cb_t uart_rx_cb);

/*
 * @brief Stores UART data in FIFO
 *
 * @param[in] rx_data UART received data
 *
 * @return
*/
void store_uart_data(uint16_t rx_data);

/*
 * @brief Send BM7x command through UART
 *
 * @param[in] cmd BM7x command
 * @param[in] cmd_len BM7x command length
 *
 * @return ble_status_t
*/
ble_status_t interface_cmd_send_no_wait(uint8_t *cmd, uint32_t cmd_len);

/*
 * @brief Send BM7x command through UART
 *
 * @param[in] cmd BM7x command
 * @param[in] cmd_len BM7x command length
 * @param[in] event_id response event from BM7x for the command is being send
 *
 * @return ble_status_t
*/
ble_status_t interface_cmd_send_wait(uint8_t *cmd, uint32_t cmd_len, uint8_t event_id);

bool is_waiting_for_this_response(uint8_t cmd_id);
bool is_waiting_for_response(void);

/*
 * @brief Process events from BM7x
 *
 * @param
 *
 * @return true, if desired event is received otherwise false
*/
bool interface_event_process(void);

/*
 * @brief Process BM7x command, if any, and post it in Event Q
 *
 * @param
 *
 * @return Event Q status
*/
event_status_t interface_event_get(void);

/*
 * @brief Provides pointer to received command frame
 *
 * @param
 *
 * @return pointer to event_t
*/
event_t* get_received_cmd_frame(void);

ble_status_t interface_cmd_wait(uint8_t event_id);

#endif //_INTERFACE_H_