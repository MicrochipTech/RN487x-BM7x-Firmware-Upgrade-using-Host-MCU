#include "platform_files.h"
#include "bm_mode.h"
#include "event_mem.h"
#include "bm_program_mode.h"
#include "bm_application_mode.h"
#include "dfu_api.h"
#include "ble_api.h"
#include "dfu_manager.h"
#include "ble_manager.h"
#include "platform_pic.h"
#include "config.h"

extern event_t event_mem[];
extern uint32_t event_payload[];

platform_init_t pf_cfg = {
	/* Register Platform callback API's */
	.platform_api_list.create_timer = platform_create_timer,
	.platform_api_list.delete_timer = platform_delete_timer,
	.platform_api_list.start_timer = platform_start_timer,
	.platform_api_list.stop_timer = platform_stop_timer,
	.platform_api_list.sleep_timer_ms = platform_sleep,
	.platform_api_list.gpio_set = platform_gpio_set,
	.platform_api_list.mode_set = platform_mode_set,
	.platform_api_list.uart_tx_cb = platform_send_sync,
	.platform_api_list.uart_rx_cb = platform_recv_async,
	.event_mem.event_mem_pool = event_mem,
	.event_mem.event_mem_pool_size = MAX_EVENT_SIZE,
	.event_mem.event_payload_mem = event_payload,
	.event_mem.event_payload_mem_size = MAX_EVENT_PAYLOAD_SIZE,
};

/*
static void dfu_mgr_init(void)
{
	// BLE event callback registration 
	//ble_mgr_events_register_callback(BLE_GAP_EVENT_TYPE, &ble_mgr_gap_event_handle);
	//ble_mgr_events_register_callback(BLE_GATT_SERVER_EVENT_TYPE, &ble_mgr_gatt_server_event_handle);
	//ble_mgr_events_register_callback(BLE_GATT_CLIENT_EVENT_TYPE, &ble_mgr_gatt_client_event_handle);
	//ble_mgr_events_register_callback(BLE_COMMON_EVENT_TYPE, &ble_mgr_common_event_handle);
	//ble_mgr_events_register_callback(BLE_PAIRING_EVENT_TYPE, &ble_mgr_pairing_event_handle);
	//ble_mgr_events_register_callback(BLE_GATT_TP_EVENT_TYPE, &ble_mgr_transparent_event_handle);
}
*/

dfu_status_t dfu_mgr_init(void)
{
	dfu_status_t status = DFU_SUCCESS;
	
    platform_init();
	//dfu_mgr_init();
    //Initialize mode pin
    BM_MODE_Init();
	
	/* Initialize platform */
	status = dfu_init(&pf_cfg);
    
	if(DFU_SUCCESS == status)
	{
		DBG_LOG("DFU init succeeded");
	}
	else
	{
		DBG_LOG("DFU init failed");
	}
	
	return status;
}

dfu_status_t dfu_mgr_deinit(void)
{
	dfu_status_t status = DFU_SUCCESS;
	
	/* Initialize platform */
	status = dfu_deinit();
    
	if(DFU_SUCCESS == status)
	{
		DBG_LOG("DFU deinit succeeded");
	}
	else
	{
		DBG_LOG("DFU deinit failed");
	}
	
	return status;
}

dfu_status_t dfu_mgr_update_start(uint32_t address, uint8_t* data, uint8_t length, uint32_t continue_length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    status = dfu_program_memory_erase(0x00000000, 0);
    
    if(DFU_SUCCESS == status)
	{
		DBG_LOG("DFU erase program memory succeeded");
        status = dfu_program_memory_write_continue(address, data, length, DFU_WRITE_CONTINUE_START, continue_length);
        if(DFU_SUCCESS == status)
        {
            DBG_LOG("DFU write start program memory succeeded");
        }
        else
        {
            DBG_LOG("DFU write start program memory failed");
        }
	}
	else
	{
		DBG_LOG("DFU erase program memory failed");
	}
	
	return status;
}

dfu_status_t dfu_mgr_update_continue(uint8_t* data, uint8_t length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    status = dfu_program_memory_write_continue(0x00000000, data, length, DFU_WRITE_CONTINUE_PROCEED, 0x00000000);
    if(DFU_SUCCESS == status)
    {
        DBG_LOG("DFU write continue program memory succeeded");
    }
    else
    {
        DBG_LOG("DFU write continue program memory failed");
    }

	return status;
}

dfu_status_t dfu_mgr_update_stop(uint8_t* data, uint8_t length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    status = dfu_program_memory_write_continue(0x00000000, data, length, DFU_WRITE_CONTINUE_STOP, 0x00000000);
    if(DFU_SUCCESS == status)
    {
        DBG_LOG("DFU write stop program memory succeeded");
    }
    else
    {
        DBG_LOG("DFU write stop program memory failed");
    }
	
	return status;
}

dfu_status_t dfu_mgr_update_verify(uint32_t address, uint8_t* data, uint8_t length)
{
    dfu_status_t status = DFU_SUCCESS;
    uint8_t buff[DFU_MAX_DATA_LENGTH];
    
    status = dfu_program_memory_read(address, buff, length);
    if(DFU_SUCCESS == status && (memcmp(buff, data, length) == 0))
    {
        DBG_LOG("DFU read and verify program memory succeeded");
    }
    else
    {
        DBG_LOG("DFU read and verify program memory failed");
    }
}