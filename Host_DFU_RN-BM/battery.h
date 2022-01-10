
/**
 * \file
 *
 * \brief Battery Service declarations
 *
 * Copyright (c) 2014-2016 Atmel Corporation. All rights reserved.
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

// <<< Use Configuration Wizard in Context Menu >>>
// <h> Battery Service Configuration
// =======================

#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "plib.h"
#include "platform_files.h"
#include "bm_application_mode.h"
#include "event_mem.h"
#include "ble_api.h"
#include "platform_pic.h"
#include "ble_manager.h"

/** battery service uuid */
#define BAT_SERVICE_UUID 						(0x180F)

/** battery level characteristic uuid */
#define BAT_CHAR_BAT_LEVEL_UUID 				(0x2A19)

/** characteristic presentation format value */
#define BAT_CHAR_PRESENTATION_FORMAT_VALUE 0x04

/** @brief Characteristic presentation format exponent */
#define BAT_CHAR_PRESENTATION_FORMAT_EXPONENT 0x00

/** @brief Characteristic presentation format unit */
#define BAT_CHAR_PRESENTATION_FORMAT_UNIT BAT_SERVICE_UUID

/** @brief Characteristic presentation format namespace */
#define BAT_CHAR_PRESENTATION_FORMAT_NAMESPACE 0x01

/**  @brief Characteristic presentation format descriptor */
#define BAT_CHAR_PRESENTATION_FORMAT_DESCRIPTOR 0x1000

typedef struct bat_gatt_service_handler
{
	/** OTAU service connection Handle */
	ble_handle_t conn_hanle;
	/// service uuid
	ble_service_t	serv_tble;
	/// service characteristic
	ble_char_t	serv_chars;
}bat_gatt_service_handler_t;

/**@brief Update the battery characteristic value after defining the services using bat_primary_service_define
 *
 * @param[in] conn_handle connection handle
 * @param[in] battery_serv battery service instance
 * @param[in] char_data New battery level
 * @param[in] flag flag to track the notification sent 
 *
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
ble_status_t bat_update_char_value (ble_handle_t conn_handle, bat_gatt_service_handler_t *battery_serv , uint8_t char_data,bool volatile *flag);

/**@brief Battery service and characteristic initialization(Called only once by user).
 *
 * @param[in] battery_serv battery service instance
 *
 * @return none
 */
void bat_init_service(bat_gatt_service_handler_t *battery_serv, uint8_t *battery_value);

/**@brief Register a battery service instance inside stack. 
 *
 * @param[in] battery_service battery service instance
 *
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
ble_status_t bat_primary_service_define(bat_gatt_service_handler_t *battery_service);

/**@brief function to check the client characteristic configuration value. 
 *
 * @param[in] conn_handle connection handle
 * @param[in] battery_service battery service instance
 * @param[in] char_handle characteristic changed @ref at_ble_characteristic_changed_t
 * @param[in] flag flag to track the notification sent 
 *
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
	ble_status_t bat_char_changed_event(bat_gatt_service_handler_t *battery_service, ble_characteristic_value_received_event_t *characteristic_changed_param);


#endif /* __BATTERY_H__ */
// </h>

// <<< end of configuration section >>>
