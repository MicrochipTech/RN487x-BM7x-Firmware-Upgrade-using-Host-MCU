/**
 * \file
 *
 * \brief OTAU GATT Server Service
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
 *    Atmel micro controller product.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel
 * Support</a>
 */

/************************************************************************/
/*							Includes									*/
/************************************************************************/
#include "plib.h"
#include "platform_files.h"
#include "bm_application_mode.h"
#include "event_mem.h"
#include "ble_api.h"
#include "ble_manager.h"
#include "otau_service.h"

/************************************************************************/
/*							Globals										*/
/************************************************************************/
/** Initial OTAU characteristics default value */
static const uint16_t otau_char_default_val = OTAU_CHARACTERISTICS_DEFAULT_VALUE;



/************************************************************************/
/*							Implementation								*/
/************************************************************************/

/**@brief its an utility function to reverse the memory content of given length
 *
 * @param[in] buf pointer to memory location
 * @param[in] len length of the memory needs to be reversed
 *
 * @return at_ble_status_t AT_BLE_SUCCESS or AT_BLE_FAILURE
 */
void reverse_byte_buffer(uint8_t *buf, uint16_t len)
{
	uint16_t mid_pos = len/2;
	uint16_t idx;
	uint16_t tail = len-1;
	uint8_t data;
	
	for(idx = 0; idx < mid_pos; idx++)
	{
		data = buf[idx];
		buf[idx] = buf[tail];
		buf[tail--] = data;	 
	}
}

/**@brief OTAU GATT service and characteristic initialization to default values
 *
 * @param[in] OTAU service instance pointer
 *
 * @return at_ble_status_t AT_BLE_SUCCESS or AT_BLE_FAILURE
 */
ble_status_t otau_service_get_default(otau_gatt_service_handler_t *otau_service)
{
	if (otau_service == NULL)
	{
		return BLE_FAILURE;
	}
	
	/* OTAU is handled in single connection, It good to keep the track of connection handle for OTAU */
	otau_service->conn_hanle = DEFAULT_CONNECTION_HANDLE;
	
	/* ------------------------ OTAU Service Related definition ------------------------------------- */
	/** Set default OTAU service handle. Its automatically set by stack, so its desired to set 0 */
	otau_service->otaService.handle = 0;
	/** OTAU service UUID type */
	otau_service->otaService.uuid.type = BLE_UUID_128B;	
    
    otau_service->otaService.perm = BLE_ATTR_NO_PERMISSIONS;
    
    otau_service->otaService.char_count = OTAU_MAX_CHARACTERISTICS;  
    
    otau_service->otaService.char_list = otau_service->chars;
    
	/* set OTAU service UUID */
	memcpy(otau_service->otaService.uuid.uuid.uuid_128b, OTAU_SERVICE_UUID, BLE_UUID_128B_LEN);
	//reverse_byte_buffer(otau_service->otaService.uuid.uuid.uuid_128b, BLE_UUID_128B_LEN);
	
	/* ------------------------ OTAU Endpoint-1 Characteristics Related definition ------------------------------------- */
    /**< The stack will store the char handle. so value handle is set to 0 */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.char_handle = 0;
    /** OTAU Characteristics UUID type */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.uuid.type = BLE_UUID_128B;	
    /* set characteristics UUID of OTAU */
    memcpy(otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.uuid.uuid.uuid_128b, OTAU_CHARACTERISTICS_ENDPOINT1_UUID, BLE_UUID_128B_LEN);

    //reverse_byte_buffer(otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.uuid.uuid.uuid_128b, BLE_UUID_128B_LEN);

    /* set the properties of OTAU characteristics */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.properties = BLE_CHAR_INDICATE;

    /**< initial value of this characteristic  */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.init_value = (uint8_t *)&otau_char_default_val;
     /**< initial value length */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.len = sizeof(otau_char_default_val);
    /**< maximum possible length of the char. value */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.max_len = OTAU_CHARACTERISTICS_ENDPOINT1_MAX_SIZE;	
     /**< Value permissions */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].char_val.permissions= BLE_ATTR_WRITABLE_NO_AUTHN_NO_AUTHR;

    /**< no user description is desired then set to NULL */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].user_desc.ud_included = 0;

    /* no presentation format, so it is necessary set to NULL */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].presentation_format.pf_included = 0;	
    /* Set the Maximum security be default to Client configuration permission */
	otau_service->chars[OTAU_INDICATION_CHAR_IDX].client_config_desc.ccd_value = 0;
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].client_config_desc.perm = BLE_PM_WRITABLE;
    /** client config handle is set by stack, so it is desired to set client config handle to 0 */
    otau_service->chars[OTAU_INDICATION_CHAR_IDX].client_config_desc.handle = 0;

    otau_service->chars[OTAU_INDICATION_CHAR_IDX].client_config_desc.ccd_included = 1;

    otau_service->chars[OTAU_INDICATION_CHAR_IDX].server_config_desc.ccd_included = 0;

    otau_service->chars[OTAU_INDICATION_CHAR_IDX].ext_properties.ep_included = 0;

    otau_service->chars[OTAU_INDICATION_CHAR_IDX].additional_desc_count = 0;

    /* ------------------------ OTAU Endpoint-2 Characteristics Related definition ------------------------------------- */
    /**< The stack will store the char handle. so value handle is set to 0 */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.char_handle = 0;
    /** OTAU Characteristics UUID type */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.uuid.type = BLE_UUID_128B;
    /* set characteristics UUID of OTAU */
    memcpy(otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.uuid.uuid.uuid_128b, OTAU_CHARACTERISTICS_ENDPOINT2_UUID, BLE_UUID_128B_LEN);
    //reverse_byte_buffer(otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.uuid.uuid.uuid_128b, BLE_UUID_128B_LEN);

    /* set the properties of OTAU characteristics */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.properties = BLE_CHAR_WRITE;

    /**< initial value of this characteristic  */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.init_value = (uint8_t *)&otau_char_default_val;
    /**< initial value length */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.len = sizeof(otau_char_default_val);
    /**< maximum possible length of the char. value */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.max_len = OTAU_CHARACTERISTICS_ENDPOINT2_MAX_SIZE;
    /**< Value permissions */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].char_val.permissions = BLE_ATTR_WRITABLE_NO_AUTHN_NO_AUTHR;

    /**< no user description is desired then set to NULL */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].user_desc.ud_included = 0;

    /* no presentation format, so it is necessary set to NULL */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].presentation_format.pf_included = 0;	

    /* Set the CCCD included to 0 */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].client_config_desc.ccd_included = 0;

    /* Set the SCCD included to 0 */
    otau_service->chars[OTAU_WRITE_CHAR_IDX].server_config_desc.ccd_included = 0;

    otau_service->chars[OTAU_WRITE_CHAR_IDX].ext_properties.ep_included = 0;

    otau_service->chars[OTAU_WRITE_CHAR_IDX].additional_desc_count = 0;

    /* ------------------------ OTAU Endpoint-3 Characteristics Related definition ------------------------------------- */
    /**< The stack will store the char handle. so value handle is set to 0 */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.char_handle = 0;
    /** OTAU Characteristics UUID type */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.uuid.type = BLE_UUID_128B;
    /* set characteristics UUID of OTAU */
    memcpy(otau_service->chars[OTAU_READ_CHAR_IDX].char_val.uuid.uuid.uuid_128b, OTAU_CHARACTERISTICS_ENDPOINT3_UUID, BLE_UUID_128B_LEN);
    //reverse_byte_buffer(otau_service->chars[OTAU_READ_CHAR_IDX].char_val.uuid.uuid.uuid_128b, BLE_UUID_128B_LEN);

    /* set the properties of OTAU characteristics */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.properties = BLE_CHAR_READ;

    /**< initial value of this characteristic  */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.init_value = (uint8_t *)&otau_char_default_val;
    /**< initial value length */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.len = sizeof(otau_char_default_val);
    /**< maximum possible length of the char. value */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.max_len = OTAU_CHARACTERISTICS_ENDPOINT3_MAX_SIZE;
    /**< Value permissions */
    otau_service->chars[OTAU_READ_CHAR_IDX].char_val.permissions = BLE_ATTR_READABLE_NO_AUTHN_NO_AUTHR;

    /**< no user description is desired then set to NULL */
    otau_service->chars[OTAU_READ_CHAR_IDX].user_desc.ud_included = 0;

    /* no presentation format, so it is necessary set to NULL */
    otau_service->chars[OTAU_READ_CHAR_IDX].presentation_format.pf_included = 0;	

    /* Set the CCCD included to 0 */
    otau_service->chars[OTAU_READ_CHAR_IDX].client_config_desc.ccd_included = 0;

    /* Set the SCCD included to 0 */
    otau_service->chars[OTAU_READ_CHAR_IDX].server_config_desc.ccd_included = 0;

    otau_service->chars[OTAU_READ_CHAR_IDX].ext_properties.ep_included = 0;

    otau_service->chars[OTAU_READ_CHAR_IDX].additional_desc_count = 0;
	
	return BLE_SUCCESS;
}

/**@brief Register a OTAU service instance into database.
 *
 * @param[in] otau_service_instance OTAU service instance
 * @param[in] service_type  primary service or secondary service
 *
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_FAILURE Generic error.
 */
ble_status_t otau_gatt_service_define(otau_gatt_service_handler_t *otau_service_instance, 
											ble_service_type_t service_type)
{
	ble_status_t status = BLE_FAILURE;

    otau_service_instance->otaService.type = service_type;
    
	status = ble_gatt_service_create(&otau_service_instance->otaService);
     
	return status;
}

/**@brief otau_characteritics_changed_handler for characteristic CCCD write
 *
 * @param[in] otau_service_instance of type otau_gatt_service_handler_t
 * @param[in] params of type at_ble_characteristic_changed_t
 *
 * @return number representing the changed characteristic in case of failure CCCD_WRITE_UNUSED
 *			CCCD_WRITE_FAILED will be returned
 */
uint16_t otau_characteritics_changed_handler(otau_gatt_service_handler_t *otau_service_instance,
		ble_characteristic_value_received_event_t *params)
{
	uint16_t cccd_value;
    ble_status_t status;
	DBG_LOG_DEV("%s", __FUNCTION__);
	if(params->char_value_handle == otau_service_instance->chars[OTAU_WRITE_CHAR_IDX].char_val.value_handle)
	{        
		if(ble_write_response_send(params->conn_handle, params->char_value_handle, BLE_SUCCESS) != BLE_SUCCESS)
        {
			DBG_LOG("%s::Failed to Send Write Response", __FUNCTION__);
        }
        else
        {
            DBG_LOG_DEV("%s::Successfully sent Write Response", __FUNCTION__);
		}
	}
	
	if (((params->conn_handle == otau_service_instance->conn_hanle) || 
		(otau_service_instance->conn_hanle == DEFAULT_CONNECTION_HANDLE)) &&
		(params->char_value_handle == otau_service_instance->chars[OTAU_INDICATION_CHAR_IDX].client_config_desc.handle))
	{
		if (otau_service_instance->conn_hanle == DEFAULT_CONNECTION_HANDLE)
		{
			/* Update the connection handle, based on the OTAU indication enable */
			DBG_LOG_DEV("Updating the connection Handle value");
			otau_service_instance->conn_hanle = params->conn_handle;
		}
		
		/*if (params->status == BLE_SUCCESS)*/
		{
			/*if ((params->char_len == CCCD_VALUE_LENGTH) && (params->char_offset == CCCD_VALUE_OFFSET))*/
			{
				
				cccd_value = ((params->char_value_data[CCCD_VALUE_OFFSET+1] << 8) | params->char_value_data[CCCD_VALUE_OFFSET]);
				DBG_LOG_DEV("CCCD Write Value 0x%04X", cccd_value);
				if ((cccd_value == CCCD_NOTIFICATION_ENABLED) ||
				    (cccd_value == CCCD_INDICATION_ENABLED) ||
					(cccd_value == CCCD_NOTIFICATION_INDICATION_ENABLED) ||
					(cccd_value == CCCD_NOTIFICATION_INDICATION_DISABLED))					
				{
#if 1				
					uint16_t wr_cccd = 0xFFFF;//(params->char_value_data[CCCD_VALUE_OFFSET] | (params->char_value_data[CCCD_VALUE_OFFSET+1] << 8));
                    status = ble_characteristic_value_update(params->char_value_handle, (uint8_t*)&wr_cccd, sizeof(wr_cccd));
					if(status == BLE_SUCCESS)
					{
						DBG_LOG_DEV("CCCD Write Success 0x%04X", status);
						return cccd_value;
					}
					else
					{
						DBG_LOG_DEV("CCCD Write failed1 0x%04X", status);
					}
#else					
					return cccd_value;
#endif
				}
			}
		}
		
		DBG_LOG_DEV("CCCD Write failed2");
		return CCCD_WRITE_FAILED;
	}	
	return CCCD_WRITE_UNUSED;
}

