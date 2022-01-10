/**
 * \file
 *
 * \brief Battery service
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

 /**
 * \mainpage
 * \section preface Preface
 * This is the reference manual for the Battery Service
 */
/****************************************************************************************
*							        Includes	                                     	*
****************************************************************************************/
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "battery.h"

/** Initial value of the battery level characteristic value */
uint8_t battery_init_value = 10;

bool volatile bat_notification_flag = false;

//extern ble_connected_dev_info_t ble_dev_info[BLE_MAX_DEVICE_CONNECTED];

/**@brief Initialize the service with its included service, characteristics, and descriptors
 */
void bat_init_service(bat_gatt_service_handler_t *battery_serv, uint8_t *battery_value)
{
	battery_serv->serv_tble.type = PRIMARY_SERVICE;
	battery_serv->serv_tble.handle = 0;

	battery_serv->serv_tble.uuid.type = BLE_UUID_16B;
	battery_serv->serv_tble.uuid.uuid.uuid_16b[1]  = (uint8_t) BAT_SERVICE_UUID;
	battery_serv->serv_tble.uuid.uuid.uuid_16b[0] = (uint8_t) (BAT_SERVICE_UUID >> 8);

	battery_serv->serv_tble.char_count = 1;

	battery_serv->serv_tble.char_list = &battery_serv->serv_chars;
	
	//Battery service characteristic
	battery_serv->serv_chars.char_val.char_handle = 0;          /* handle stored here */
	battery_serv->serv_chars.char_val.uuid.type = BLE_UUID_16B;
	battery_serv->serv_chars.char_val.uuid.uuid.uuid_16b[1] = (uint8_t) BAT_CHAR_BAT_LEVEL_UUID;          /* UUID : Manufacturer Name String */
	battery_serv->serv_chars.char_val.uuid.uuid.uuid_16b[0] = (uint8_t) (BAT_CHAR_BAT_LEVEL_UUID >> 8);          /* UUID : Manufacturer Name String */
	battery_serv->serv_chars.char_val.properties = (BLE_CHAR_READ | BLE_CHAR_NOTIFY); /* Properties */
	battery_serv->serv_chars.char_val.init_value = &battery_init_value;             /* value */
	battery_serv->serv_chars.char_val.len = sizeof(uint8_t);
	battery_serv->serv_chars.char_val.max_len = sizeof(uint8_t);
#if BLE_PAIR_ENABLE
	battery_serv->serv_chars.char_val.permissions = (BLE_ATTR_READABLE_REQ_AUTHN_NO_AUTHR |
												 BLE_ATTR_WRITABLE_REQ_AUTHN_NO_AUTHR);   /* permissions */
#else
	battery_serv->serv_chars.char_val.permissions = (BLE_ATTR_READABLE_NO_AUTHN_NO_AUTHR |
												 BLE_ATTR_WRITABLE_NO_AUTHN_NO_AUTHR);   /* permissions */
#endif



	battery_serv->serv_chars.user_desc.ud_included = 1;           /* user defined name */
	battery_serv->serv_chars.user_desc.len = 0;	
	battery_serv->serv_chars.user_desc.permissions = BLE_ATTR_NO_PERMISSIONS;             /*user description permissions*/
	battery_serv->serv_chars.client_config_desc.perm = BLE_ATTR_NO_PERMISSIONS;         /*client config permissions*/
	battery_serv->serv_chars.server_config_desc.perm = BLE_ATTR_NO_PERMISSIONS;         /*server config permissions*/
	battery_serv->serv_chars.user_desc.handle = 0;             /*user desc handles*/

	/*client config handles*/
	battery_serv->serv_chars.client_config_desc.ccd_included = 1;
	battery_serv->serv_chars.client_config_desc.handle = 0;        
	/*server config handles*/
	battery_serv->serv_chars.server_config_desc.ccd_included = 0;
	battery_serv->serv_chars.server_config_desc.handle = 0;         

	battery_serv->serv_chars.presentation_format.format = BLE_PRES_FORMAT_UINT8;
	battery_serv->serv_chars.presentation_format.exponent = BAT_CHAR_PRESENTATION_FORMAT_EXPONENT;
	battery_serv->serv_chars.presentation_format.unit = (uint8_t) BAT_CHAR_PRESENTATION_FORMAT_UNIT;
	battery_serv->serv_chars.presentation_format.unit |= (uint8_t) (BAT_CHAR_PRESENTATION_FORMAT_UNIT >> 8);
	battery_serv->serv_chars.presentation_format.name_space = BAT_CHAR_PRESENTATION_FORMAT_NAMESPACE;
	battery_serv->serv_chars.presentation_format.description = (uint8_t) BAT_CHAR_PRESENTATION_FORMAT_DESCRIPTOR;
	battery_serv->serv_chars.presentation_format.description |= (uint8_t) (BAT_CHAR_PRESENTATION_FORMAT_DESCRIPTOR >> 8);
	
}

/**@brief defining a initialized service 
 */
ble_status_t bat_primary_service_define(bat_gatt_service_handler_t *battery_service)
{
	return(ble_gatt_service_create(&battery_service->serv_tble));
}

/**@brief Function used to update characteristic value
 */
ble_status_t bat_update_char_value (ble_handle_t conn_handle, bat_gatt_service_handler_t *battery_serv , uint8_t char_data,bool volatile *flag)
{
	ble_status_t status = BLE_SUCCESS;
#if 0
	/* Updating the att data base */
	if ((status = ble_characteristic_value_update(battery_serv->serv_chars.char_val.value_handle, &char_data, sizeof(uint8_t))) != BLE_SUCCESS){
		DBG_LOG("updating the characteristic failed%d",status);
		return status;
	} else {
		DBG_LOG("updating the characteristic value is successful");
	}
#endif    
	if(*flag){
		/* sending notification to the peer about change in the battery level */ 
		if((status = ble_characteristic_value_send(conn_handle, battery_serv->serv_chars.char_val.value_handle, &char_data, sizeof(uint8_t))) != BLE_SUCCESS) {
			DBG_LOG("sending notification failed%d",status);
			printf("%s[status = %d]::connHndl = 0x%02X  attHndl = 0x%02X length = %d", __FUNCTION__, status, conn_handle, battery_serv->serv_chars.char_val.value_handle, sizeof(uint8_t));
			return status;
		}
		else {
			DBG_LOG("sending notification successful");
			printf("%s[status = %d]::connHndl = 0x%02X  attHndl = 0x%02X length = %d", __FUNCTION__, status, conn_handle, battery_serv->serv_chars.char_val.value_handle, sizeof(uint8_t));
			//*flag = false;
			return status;
		}
	}
	return status;
}
/**@brief function to check the client characteristic configuration value. 
 */
ble_status_t bat_char_changed_event(bat_gatt_service_handler_t *battery_service, ble_characteristic_value_received_event_t *characteristic_changed_param)
{
	ble_status_t status = BLE_FAILURE;
	if((battery_service->serv_chars.client_config_desc.handle == characteristic_changed_param->char_value_handle) && (characteristic_changed_param->char_value_data[0] == 0x01))
	{
		status = BLE_SUCCESS;
	}
	else if((battery_service->serv_chars.client_config_desc.handle == characteristic_changed_param->char_value_handle) && (characteristic_changed_param->char_value_data[0] == 0x00))
	{
		status = BLE_PRF_NTF_DISABLED;
	}
	return status;
}

