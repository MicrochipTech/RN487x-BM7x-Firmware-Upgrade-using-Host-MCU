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

/** \file ble_api.h
 * Defines BLE APIs.
 * Support for central, peripheral role functions and events.
 */

#ifndef _BLE_API_H_
#define _BLE_API_H_

/** DEFINES  ******************************************************/
#define BLE_CCCD_UUID			0x2902
#define BLE_CCCD_NOTIFICATION_ENABLED	0x0001
#define BLE_CCCD_INDICATION_ENABLED		0x0002

#define BLE_ADDR_LEN			6

#define BM77_BLUETOOTH_DEVICE	0
#define BM78_BLUETOOTH_DEVICE	1
#define BM70_BLUETOOTH_DEVICE	2

#define BMXX_DEVICE (BM70_BLUETOOTH_DEVICE)

//Advertisement parameter 
#define ADV_PARAM_INTERVAL_INDEX_HIGH		0
#define ADV_PARAM_INTERVAL_INDEX_LOW		1
#define ADV_PARAM_TYPE_INDEX				2
#define ADV_PARAM_DIRECT_ADDR_TYPE_INDEX	3
#define ADV_PARAM_DIRECT_ADDR_INDEX			4

//Advertisement interval
#define ADV_INTERVAL_1_S					1600	//(1600 * 625 us)
#define ADV_INTERVAL_100_MS					160

// GAP Advertising interval max. and min.
#define AT_BLE_ADV_INTERVAL_MIN        0x0020 /**< Minimum Advertising interval in 625 us units, i.e. 20 ms. */
#define AT_BLE_ADV_INTERVAL_MAX        0x4000 /**< Maximum Advertising interval in 625 us units, i.e. 10.24 s. */

//Scan parameters
#define MIN_SCAN_INTERVAL		0x0004
#define MAX_SCAN_INTERVAL		0x4000
#define MIN_SCAN_WINDOW			0x0004
#define MAX_SCAN_WINDOW			0x4000

//Connection parameters
#define MIN_CONN_INTERVAL		0x0006
#define MAX_CONN_INTERVAL		0x0C80
#define MIN_SLAVE_LATENCY		0x0000
#define MAX_SLAVE_LATENCY		0x01F4
#define MIN_SV_TIMEOUT			0x000A
#define MAX_SV_TIMEOUT			0x0C80

#define BLE_PAIR_CONFIRM_YES true
#define BLE_PAIR_CONFIRM_NO false

#define BLE_UUID_128B_LEN	(1 << BLE_UUID_128B)
#define BLE_UUID_16B_LEN	(1 << BLE_UUID_16B)

#define MAX_CHAR_WRITE_VALUE	20

/**@brief BLE Attribute UUID lengths */
/**< 16-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_2		2
/**< 32-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_4		4
/**< 128-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_16		16

/**< Characteristic properties */
#define BLE_CHAR_BROADCST				(0x01 << 0)
#define BLE_CHAR_READ					(0x01 << 1)
#define BLE_CHAR_WRITE_WITHOUT_RESPONSE (0x01 << 2)
#define BLE_CHAR_WRITE					(0x01 << 3)
#define BLE_CHAR_NOTIFY					(0x01 << 4)
#define BLE_CHAR_INDICATE				(0x01 << 5)
#define BLE_CHAR_SIGNED_WRITE			(0x01 << 6)
#define BLE_CHAR_EXT_PROPERTIES			(0x01 << 7)

/**< Characteristic extended properties */
#define BLE_CHAR_EXT_PROP_RELIABLE_WRITE	(0x0001 << 0)
#define BLE_CHAR_EXT_PROP_WRITABLE_AUX		(0x0001 << 1)

/* The following values inherited from BLEDK3. This needs to be updated whenever BLEDK3 update these values */

/**< Attribute Permissions. All attributes are readable as default. */
#define BLE_PM_WRITABLE					0x02	/**< Access Permission: Writeable.*/
#define BLE_PM_SECURITY_READ_ENABLE		0x04	/**< Encryption/Authentication Permission on READ property attribute. If enabled, it requires pairing to device to access the attribute. Note that Encryption or Authentication permission is based on IO capability of device. */
#define BLE_PM_SECURITY_WRITE_ENABLE	0x08	/**< Encryption/Authentication Permission on WRITE property attribute. If enabled, it requires pairing to device to access the attribute. Note that Encryption or Authentication permission is based on IO capability of device. */
#define BLE_PM_MANUAL_WRITE_RESP		0x40	/**< Authorization Permission: Manual sending write response configuration. Application can send write response manually. */
#define BLE_PM_MANUAL_READ_RESP			0x80	/**< Authorization Permission: Manual sending read response configuration. Application can send read response with data manually. */

#define BLE_ATTR_NO_PERMISSIONS               0x00
/** @brief Read enable. */
#define BLE_ATTR_READABLE_NO_AUTHN_NO_AUTHR   0x01
/** @brief  Read operation require MITM protected encrypted link & no authorization. */
#define BLE_ATTR_READABLE_REQ_AUTHN_NO_AUTHR  0x03
/** @brief  Read operation require Authorization & no encryption. */
#define BLE_ATTR_READABLE_NO_AUTHN_REQ_AUTHR  0x09
/** @brief  Read operation require MITM protected encrypted link & authorization. */
#define BLE_ATTR_READABLE_REQ_AUTHN_REQ_AUTHR 0x0B
/** @brief Read operation require encrypted link , MITM protection not necessary & No authorization. */
#define BLE_ATTR_READABLE_REQ_ENC_NO_AUTHN_NO_AUTHR  0x02
/** @brief Read operation require encrypted link, MITM protection not necessary & authorization. */
#define BLE_ATTR_READABLE_REQ_ENC_NO_AUTHN_REQ_AUTHR  0x0A

/** @brief Write enable. */
#define BLE_ATTR_WRITABLE_NO_AUTHN_NO_AUTHR   0x10
/** @brief  Write operation require MITM protected encrypted link & no authorization. */
#define BLE_ATTR_WRITABLE_REQ_AUTHN_NO_AUTHR  0x30
/** @brief  Write operation require Authorization & no encryption. */
#define BLE_ATTR_WRITABLE_NO_AUTHN_REQ_AUTHR  0x90
/** @brief  Write operation require MITM protected encrypted link & authorization. */
#define BLE_ATTR_WRITABLE_REQ_AUTHN_REQ_AUTHR 0xB0
/** @brief Write operation require encrypted link , MITM protection not necessary & No authorization. */
#define BLE_ATTR_WRITABLE_REQ_ENC_NO_AUTHN_NO_AUTHR 0x20
/** @brief Write operation require encrypted link, MITM protection not necessary & authorization. */
#define BLE_ATTR_WRITABLE_REQ_ENC_NO_AUTHN_REQ_AUTHR 0xA0
/** @brief  Encryption key Size must be 16 bytes. */
#define BLE_ENC_KEY_SIZE_PERM 0X40

#define BLE_ATT_ATTRIBUTE_VALUE_LEN			23		/**< The Maximum Length of Attribute Value. Refer to ATT default MTU size. */
#define BLE_ATT_DEFAULT_MTU_LENGTH			23		/**< ATT default MTU size. */

#define BLE_MAX_SERVICE_BUF_LEN    			(0x01FF - 8)

/**@defgroup BLE_GATT_WRITE_RESP_TYPES BLE_GATT_WRITE_RESP_TYPES
 * @brief GATT write response type definitions
 * @{ */
#define BLE_GATT_TYPE_WRITE_RESP		0x01	/**< Write Response.*/
#define BLE_GATT_TYPE_PREP_WRITE_RESP		0x02	/**< Prepare Write Response.*/
#define BLE_GATT_TYPE_EXEC_WRITE_RESP		0x03	/**< Execute Write Response.*/
/** @} */


typedef bool ble_pair_confirm_t;
typedef BM_APPLICATION_EVENT_OPCODE bm_app_event_opcode_t;
/****************************************************************************************
*										Enumerations									*
****************************************************************************************/
typedef enum 
{
	///Generic errors
	///Success
	BLE_SUCCESS  = 0x00,

	///ATT Error Codes
	///Handle is invalid
	BLE_ATT_INVALID_HANDLE  = 0x01,
	///Read permission disabled
	BLE_ATT_READ_NOT_PERMITTED  = 0x02,
	///Write permission disabled
	BLE_ATT_WRITE_NOT_PERMITTED  = 0x03,
	///Incorrect PDU
	BLE_ATT_INVALID_PDU  = 0x04,
	///Authentication privilege not enough
	BLE_ATT_INSUFF_AUTHEN  = 0x05,
	///Request not supported or not understood
	BLE_ATT_REQUEST_NOT_SUPPORTED  = 0x06,
	///Incorrect offset value
	BLE_ATT_INVALID_OFFSET  = 0x07,
	///Authorization privilege not enough
	BLE_ATT_INSUFF_AUTHOR  = 0x08,
	///Capacity queue for reliable write reached
	BLE_ATT_PREPARE_QUEUE_FULL  = 0x09,
	///Attribute requested not existing
	BLE_ATT_ATTRIBUTE_NOT_FOUND  = 0x0A,
	///Attribute requested not long
	BLE_ATT_ATTRIBUTE_NOT_LONG  = 0x0B,
	///Encryption size not sufficient
	BLE_ATT_INSUFF_ENC_KEY_SIZE  = 0x0C,
	///Invalid length of the attribute value
	BLE_ATT_INVALID_ATTRIBUTE_VAL_LEN  = 0x0D,
	///Operation not fit to condition
	BLE_ATT_UNLIKELY_ERR = 0x0E,
	///Attribute requires encryption before operation
	BLE_ATT_INSUFF_ENC  = 0x0F,
	///Attribute grouping not supported
	BLE_ATT_UNSUPP_GRP_TYPE  = 0x10,
	///Resources not sufficient to complete the request
	BLE_ATT_INSUFF_RESOURCE  = 0x11,

	///L2C Specific Error
	///Message cannot be sent because connection lost. (disconnected)
	BLE_L2C_CONNECTION_LOST  = 0x30,
	///Invalid PDU length exceed MTU
	BLE_L2C_INVALID_MTU_EXCEED  = 0x31,
	///Invalid PDU length exceed MPS
	BLE_L2C_ERR_INVALID_MPS_EXCEED        = 0x32,
	///Invalid Channel ID
	BLE_L2C_INVALID_CID  = 0x33,
	///Invalid PDU
	BLE_L2C_INVALID_PDU  = 0x34,
	/// Connection refused - no resources available
	BLE_L2C_ERR_NO_RES_AVAIL              = 0x35,
	/// Connection refused - insufficient authentication
	BLE_L2C_ERR_INSUFF_AUTHEN             = 0x36,
	/// Connection refused - insufficient authorization
	BLE_L2C_ERR_INSUFF_AUTHOR             = 0x37,
	/// Connection refused - insufficient encryption key size
	BLE_L2C_ERR_INSUFF_ENC_KEY_SIZE       = 0x38,
	/// Connection Refused - insufficient encryption
	BLE_L2C_ERR_INSUFF_ENC                = 0x39,
	/// Connection refused - LE_PSM not supported
	BLE_L2C_ERR_LEPSM_NOT_SUPP            = 0x3A,
	/// No more credit
	BLE_L2C_ERR_INSUFF_CREDIT              = 0x3B,
	/// Command not understood by peer device
	BLE_L2C_ERR_NOT_UNDERSTOOD            = 0x3C,

	///GAP Error Codes
	///Invalid parameters set
	BLE_GAP_INVALID_PARAM  = 0x40,
	///Problem with protocol exchange, get unexpected response
	BLE_GAP_PROTOCOL_PROBLEM  = 0x41,
	///Request not supported by software configuration
	BLE_GAP_NOT_SUPPORTED  = 0x42,
	///Request not allowed in current state.
	BLE_GAP_COMMAND_DISALLOWED  = 0x43,
	///Requested operation canceled.
	BLE_GAP_CANCELED  = 0x44,
	///Requested operation timeout.
	BLE_GAP_TIMEOUT  = 0x45,
	///Link connection lost during operation.
	BLE_GAP_DISCONNECTED  = 0x46,
	///Search algorithm finished, but no result found
	BLE_GAP_NOT_FOUND  = 0x47,
	///Request rejected by peer device
	BLE_GAP_REJECTED  = 0x48,
	///Problem with privacy configuration
	BLE_GAP_PRIVACY_CFG_PB  = 0x49,
	///Duplicate or invalid advertising data
	BLE_GAP_ADV_DATA_INVALID  = 0x4A,
	///Insufficient resources
	BLE_GAP_INSUFF_RESOURCES  = 0x4B,
	///Unexpected Error
	BLE_GAP_UNEXPECTED  = 0x4C,

	///GATT Error Codes
	///Problem with ATTC protocol response
	BLE_GATT_INVALID_ATT_LEN  = 0x50 ,
	///Error in service search
	BLE_GATT_INVALID_TYPE_IN_SVC_SEARCH  = 0x51,
	///Invalid write data
	BLE_GATT_WRITE  = 0x52,
	///Signed write error
	BLE_GATT_SIGNED_WRITE  = 0x53,
	///No attribute client defined
	BLE_GATT_ATT_CLIENT_MISSING  = 0x54,
	///No attribute server defined
	BLE_GATT_ATT_SERVER_MISSING  = 0x55,
	///Permission set in service/attribute are invalid
	BLE_GATT_INVALID_PERM  = 0x56,

	///SMP Errors detected on local device
	///The user input of passkey failed, for example, the user cancelled the operation.
	BLE_SMP_LOC_PASSKEY_ENTRY_FAILED  = 0x61,
	///The OOB Data is not available.
	BLE_SMP_LOC_OOB_NOT_AVAILABLE  = 0x62,
	///The pairing procedure cannot be performed as authentication requirements cannot be met due to IO capabilities of one or both devices.
	BLE_SMP_LOC_AUTH_REQ  = 0x63,
	///The confirm value does not match the calculated confirm value.
	BLE_SMP_LOC_CONF_VAL_FAILED  = 0x64,
	///Pairing is not supported by the device.
	BLE_SMP_LOC_PAIRING_NOT_SUPP  = 0x65,
	///The resultant encryption key size is insufficient for the security requirements of this device.
	BLE_SMP_LOC_ENC_KEY_SIZE  = 0x66,
	///The SMP command received is not supported on this device.
	BLE_SMP_LOC_CMD_NOT_SUPPORTED  = 0x67,
	///Pairing failed due to an unspecified reason.
	BLE_SMP_LOC_UNSPECIFIED_REASON  = 0x68,
	///Pairing or Authentication procedure is disallowed because too little time has elapsed since last pairing request or security request.
	BLE_SMP_LOC_REPEATED_ATTEMPTS  = 0x69,
	///The command length is invalid or a parameter is outside of the specified range.
	BLE_SMP_LOC_INVALID_PARAM   = 0x6A ,
	///The request sent by the HL cannot be handled for some reasons (unauthorized source task, role, ...)
	BLE_SMP_LOC_REQ_DISALLOWED  = 0x6B,
	///An error has been received from the controller upon an encryption request.
	BLE_SMP_LOC_LL_ERROR = 0x6C,
	///The provided resolvable address has not been resolved.
	BLE_SMP_LOC_ADDR_RESOLV_FAIL  = 0x6D,
	///The Signature Verification Failed.
	BLE_SMP_LOC_SIGN_VERIF_FAIL  = 0x6E,
	///The command cannot be executed because a SMP timeout has been raised during the connection.
	BLE_SMP_LOC_TIMEOUT = 0x6F,

	///SMP Errors detected by remote device
	///The user input of passkey failed, for example, the user cancelled the operation.
	BLE_SMP_REM_PASSKEY_ENTRY_FAILED  = 0x71,
	///The OOB Data is not available.
	BLE_SMP_REM_OOB_NOT_AVAILABLE  = 0x72,
	///The pairing procedure cannot be performed as authentication requirements cannot be met due to IO capabilities of one or both
	BLE_SMP_REM_AUTH_REQ  = 0x73,
	///The confirm value does not match the calculated confirm value.
	BLE_SMP_REM_CONF_VAL_FAILED = 0x74,
	///Pairing is not supported by the device.
	BLE_SMP_REM_PAIRING_NOT_SUPP  = 0x75,
	///The resultant encryption key size is insufficient for the security requirements of this device.
	BLE_SMP_REM_ENC_KEY_SIZE  = 0x76,
	///The SMP command received is not supported on this device.
	BLE_SMP_REM_CMD_NOT_SUPPORTED  = 0x77 ,
	///Pairing failed due to an unspecified reason.
	BLE_SMP_REM_UNSPECIFIED_REASON  = 0x78,
	///Pairing or Authentication procedure is disallowed because too little time has elapsed since last pairing request or security request.
	BLE_SMP_REM_REPEATED_ATTEMPTS  = 0x79,
	///The command length is invalid or a parameter is outside of the specified range.
	BLE_SMP_REM_INVALID_PARAM  = 0x7A,
	///The encryption procedure failed because the slave device didn't find the LTK needed to start an encryption session.
	BLE_SMP_REM_ENC_KEY_MISSING  = 0x7B,
	///The encryption procedure failed because the slave device doesn't support the encryption feature.
	BLE_SMP_REM_ENC_NOT_SUPPORTED = 0x7C,
	///A timeout has occurred during the start encryption session.
	BLE_SMP_REM_ENC_TIMEOUT  = 0x7D,

	/// Profile error codes
	///Application Error
	BLE_ATT_APP_ERROR  = 0x80,
	///Application Error
	BLE_PRF_APP_ERROR  = 0x80,
	///Invalid parameter in request
	BLE_PRF_INVALID_PARAM  = 0x81,
	///Nonexistent handle for sending a read/write characteristic request
	BLE_PRF_INEXISTENT_HDL  = 0x82,
	///Discovery stopped due to missing attribute according to specification
	BLE_PRF_STOP_DISC_CHAR_MISSING  = 0x83,
	///Too many SVC instances found -> protocol violation
	BLE_PRF_MULTIPLE_SVC  = 0x84,
	///Discovery stopped due to found attribute with incorrect properties
	BLE_PRF_STOP_DISC_WRONG_CHAR_PROP  = 0x85,
	///Too many Char. instances found-> protocol violation
	BLE_PRF_MULTIPLE_CHAR  = 0x86,
	///Attribute write not allowed
	BLE_PRF_NOT_WRITABLE  = 0x87,
	///Attribute read not allowed
	BLE_PRF_NOT_READABLE  = 0x88,
	///Request not allowed
	BLE_PRF_REQ_DISALLOWED  = 0x89,
	///Notification Not Enabled
	BLE_PRF_NTF_DISABLED  = 0x8A,
	///Indication Not Enabled
	BLE_PRF_IND_DISABLED  = 0x8B,
	///Feature not supported by profile
	BLE_PRF_FEATURE_NOT_SUPPORTED  = 0x8C,
	///Read value has an unexpected length
	BLE_PRF_UNEXPECTED_LEN  = 0x8D,
	///Disconnection occurs
	BLE_PRF_DISCONNECTED  = 0x8E,
	///Procedure Timeout
	BLE_PRF_PROC_TIMEOUT  = 0x8F,

	///LL Error codes conveyed to upper layer
	///Unknown HCI Command
	BLE_LL_UNKNOWN_HCI_COMMAND  = 0x91,

	///Unknown Connection Identifier
	BLE_LL_UNKNOWN_CONNECTION_ID  = 0x92,
	///Hardware Failure
	BLE_LL_HARDWARE_FAILURE  = 0x93,
	///BT Page Timeout
	BLE_LL_PAGE_TIMEOUT  = 0x94,
	///Authentication failure
	BLE_LL_AUTH_FAILURE  = 0x95,
	///Pin code missing
	BLE_LL_PIN_MISSING  = 0x96,
	///Memory capacity exceed
	BLE_LL_MEMORY_CAPA_EXCEED  = 0x97,
	///Connection Timeout
	BLE_LL_CON_TIMEOUT  = 0x98,
	///Connection limit Exceed
	BLE_LL_CON_LIMIT_EXCEED  = 0x99,
	///Synchronous Connection limit exceed
	BLE_LL_SYNC_CON_LIMIT_DEV_EXCEED  = 0x9A,
	///ACL Connection exits
	BLE_LL_ACL_CON_EXISTS  = 0x9B,
	///Command Disallowed
	BLE_LL_COMMAND_DISALLOWED  = 0x9C,
	///Connection rejected due to limited resources
	BLE_LL_CONN_REJ_LIMITED_RESOURCES  = 0x9D,
	///Connection rejected due to security reason
	BLE_LL_CONN_REJ_SECURITY_REASONS  = 0x9E,
	///Connection rejected due to unacceptable BD Addr
	BLE_LL_CONN_REJ_UNACCEPTABLE_BDADDR  = 0x9F,
	///Connection rejected due to Accept connection timeout
	BLE_LL_CONN_ACCEPT_TIMEOUT_EXCEED  = 0xA0,
	///Not Supported
	BLE_LL_UNSUPPORTED  = 0xA1,
	///invalid parameters
	BLE_LL_INVALID_HCI_PARAM  = 0xA2,
	///Remote user terminate connection
	BLE_LL_REMOTE_USER_TERM_CON  = 0xA3,
	///Remote device terminate connection due to low resources
	BLE_LL_REMOTE_DEV_TERM_LOW_RESOURCES  = 0xA4,
	///Remote device terminate connection due to power off
	BLE_LL_REMOTE_DEV_POWER_OFF  = 0xA5,
	///Connection terminated by local host
	BLE_LL_CON_TERM_BY_LOCAL_HOST  = 0xA6,
	///Repeated attempts
	BLE_LL_REPEATED_ATTEMPTS  = 0xA7,
	///Pairing not Allowed
	BLE_LL_PAIRING_NOT_ALLOWED  = 0xA8,
	///Unknown PDU Error
	BLE_LL_UNKNOWN_LMP_PDU  = 0xA9,
	///Unsupported remote feature
	BLE_LL_UNSUPPORTED_REMOTE_FEATURE  = 0xAA,
	///Sco Offset rejected
	BLE_LL_SCO_OFFSET_REJECTED  = 0xAB,
	///SCO Interval Rejected
	BLE_LL_SCO_INTERVAL_REJECTED  = 0xAC,
	///SCO air mode Rejected
	BLE_LL_SCO_AIR_MODE_REJECTED  = 0xAD,
	///Invalid LMP parameters
	BLE_LL_INVALID_LMP_PARAM  = 0xAE,
	///Unspecified error
	BLE_LL_UNSPECIFIED_ERROR  = 0xAF,
	///Unsupported LMP Parameter value
	BLE_LL_UNSUPPORTED_LMP_PARAM_VALUE  = 0xB0,
	///Role Change Not allowed
	BLE_LL_ROLE_CHANGE_NOT_ALLOWED  = 0xB1,
	///LMP Response timeout
	BLE_LL_LMP_RSP_TIMEOUT  = 0xB2,
	///LMP Collision
	BLE_LL_LMP_COLLISION  = 0xB3,
	///LMP Pdu not allowed
	BLE_LL_LMP_PDU_NOT_ALLOWED  = 0xB4,
	///Encryption mode not accepted
	BLE_LL_ENC_MODE_NOT_ACCEPT  = 0xB5,
	///Link Key Cannot be changed
	BLE_LL_LINK_KEY_CANT_CHANGE  = 0xB6,
	///Quality of Service not supported
	BLE_LL_QOS_NOT_SUPPORTED  = 0xB7,
	///Error, instant passed
	BLE_LL_INSTANT_PASSED  = 0xB8 ,
	///Pairing with unit key not supported
	BLE_LL_PAIRING_WITH_UNIT_KEY_NOT_SUP  = 0xB9,
	///Transaction collision
	BLE_LL_DIFF_TRANSACTION_COLLISION  = 0xBA,
	///Unacceptable parameters
	BLE_LL_QOS_UNACCEPTABLE_PARAM  = 0xBC,
	///Quality of Service rejected
	BLE_LL_QOS_REJECTED  = 0xBD,
	///Channel class not supported
	BLE_LL_CHANNEL_CLASS_NOT_SUP  = 0xBE,
	///Insufficient security
	BLE_LL_INSUFFICIENT_SECURITY  = 0xBF,
	///Parameters out of mandatory range
	BLE_LL_PARAM_OUT_OF_MAND_RANGE  = 0xC0,
	///Role switch pending
	BLE_LL_ROLE_SWITCH_PEND  = 0xC2,
	///Reserved slot violation
	BLE_LL_RESERVED_SLOT_VIOLATION  = 0xC4,
	///Role Switch fail
	BLE_LL_ROLE_SWITCH_FAIL  = 0xC5,
	///Error, EIR too large
	BLE_LL_EIR_TOO_LARGE  = 0xC6,
	///Simple pairing not supported by host
	BLE_LL_SP_NOT_SUPPORTED_HOST  = 0xC7,
	///Host pairing is busy
	BLE_LL_HOST_BUSY_PAIRING  = 0xC8,
	///Controller is busy
	BLE_LL_CONTROLLER_BUSY  = 0xCA,
	///Unacceptable connection initialization
	BLE_LL_UNACCEPTABLE_CONN_INT  = 0xCB,
	///Direct Advertising Timeout
	BLE_LL_DIRECT_ADV_TO  = 0xCC,
	///Connection Terminated due to a MIC failure
	BLE_LL_TERMINATED_MIC_FAILURE  = 0xCD,
	///Connection failed to be established
	BLE_LL_CONN_FAILED_TO_BE_EST = 0xCE,
	///Invalid input argument to function
	BLE_INVALID_PARAM = 0xCF,
	///Timeout has been occurred while waiting for a specific event
	BLE_TIMEOUT = 0xD0,
	///Invalid bus initialization
	BLE_BUS_TIMEOUT = 0xD1,
	///This operation can't be handled now, wait for its event first
	BLE_BUSY = 0xD2,
	///Data base memory hasn't been assigned, it is a must to call @ref BLE_init with proper parameter @ref BLE_init_config_t
	BLE_DB_MEMORY_NOT_SETTED = 0xD3,

	/// Operation disallowed in this state
	BLE_INVALID_STATE = 0xE0,
	/// Error On bus or undefined state
	BLE_BUS_FAILURE = 0XE1,
	///Generic Failure
	BLE_FAILURE  = 0xE2,
	///Client characteristic configuration improperly configured
	BLE_PRF_CCCD_IMPR_CONFIGURED  = 0xFD,
	///Procedure already in progress
	BLE_PRF_PROC_IN_PROGRESS  = 0xFE,
	///Out of Range
	BLE_PRF_OUT_OF_RANGE  = 0xFF,
}ble_status_t;

/// GAP Advertising types
typedef enum
{
	BLE_ADV_TYPE_UNDIRECTED    = 0x00,   /**< Connectable undirected. */
	BLE_ADV_TYPE_DIRECTED,               /**< Connectable high duty cycle directed advertising. */
	BLE_ADV_TYPE_SCANNABLE_UNDIRECTED,   /**< Scannable undirected. */
	BLE_ADV_TYPE_NONCONN_UNDIRECTED,     /**< Non connectable undirected. */
	BLE_ADV_TYPE_DIRECTED_LDC,           /**< Connectable low duty cycle directed advertising. */
	BLE_ADV_TYPE_SCAN_RESPONSE           /** only used in @ref BLE_SCAN_INFO event to signify a scan response*/
} ble_adv_type_t;

/**@brief Advertising Mode
*/
typedef enum
{
	/// Mode in non-discoverable
	BLE_ADV_NON_DISCOVERABLE,
	/// Mode in general discoverable, AD type general flag in Flags set to 1.
	BLE_ADV_GEN_DISCOVERABLE,
	/// Mode in limited discoverable, AD type limited flag in Flags set to 1 (This mode is automatically stopped after 180 sec of activity)
	BLE_ADV_LIM_DISCOVERABLE,
	/// Broadcaster mode which is a non discoverable and non connectable mode.
	BLE_ADV_BROADCASTER_MODE
} ble_adv_mode_t;

/**@brief BLE can accept to kinds of addresses, either public or random addresses
*/
typedef enum
{
	/** a public static address */
	BLE_ADDRESS_PUBLIC,
	/** a random static address */
	BLE_ADDRESS_RANDOM_STATIC,
	/** resolvable private random address */
	BLE_ADDRESS_RANDOM_PRIVATE_RESOLVABLE,
	/** non-resolvable private random address */
	BLE_ADDRESS_RANDOM_PRIVATE_NON_RESOLVABLE ,

} ble_addr_type_t;

typedef enum
{
	GAP_EVENT_HANDLERS,
	GATT_SERVER_EVENT_HANDLERS,
	GATT_CLIENT_EVENT_HANDLERS,
	COMMON_EVENT_HANDLERS,
	TRANSPARENT_EVENT_HANDLERS
}ble_event_types_t;

enum
{
	PASSKEY_ENTRY_REQ			= 0x60,
	PAIRING_COMPLETE,
	PASSKEY_CONFIRM_REQ,
	ADV_REPORT					= 0x70,
	CONNECTION_COMPLETE,
	DISCONNECTION_COMPLETE,
	CONN_PARAM_UPDATE_NOTIFY,
	COMMAND_COMPLETE			= 0x80,
	STATUS_REPORT,
	CONFIG_MODE_STATUS,
	DISCOVER_ALL_PRIMARY_SERVICE_RESP = 0x90,
	DISCOVER_SPECIFIC_PRIMARY_SERVICE_CHAR_RESP,
	DISCOVER_ALL_CHAR_DESCRIPTOR_RESP,
	CHAR_VALUE_RECEIVED,
	CLIENT_WRITE_CHAR_VALUE		= 0x98,
	RECEIVED_TRANSPARENT_DATA	= 0x9A,
};

typedef struct
{
	uint32_t cmd_index;
	BM_APPLICATION_CMD_OPCODE cmd_id;
	BM_APPLICATION_EVENT_OPCODE event_id;
	uint8_t status;
}cmd_event_pair_t;

typedef enum
{
	SCANNING_MODE = 0x01,
	CONNECTING_MODE,
	STANDBY_MODE,
	BROADCAST_MODE = 0x05,
	TRANSPARENT_SERVICE_ENABLED_MODE = 0x08,
	IDLE_MODE,
	SHUTDOWN_MODE,
	CONFIGURE_MODE,
	BLE_CONNECTED_MODE,
}bledk3_status_t;

typedef enum
{
	FRAME_RX_WAITING_STATE,
	FRAME_RX_LEN_HIGH_STATE,
	FRAME_RX_LEN_LOW_STATE,
	FRAME_RX_CMD_ID_STATE,
	FRAME_RX_PAYLOAD_STATE,
	FRAME_RX_CRC_STATE,
}bm7x_event_rx_state_t;

typedef enum
{
	BM7X_PIN_RESET,
	BM7X_PIN_MODE,
	BM7X_PIN_TX_IND,
	BM7X_PIN_RX_IND,
} gpio_pin_t;

typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
} gpio_status_t;


/**@brief Scan types used at @ref ble_scan_param_set
*/
typedef enum
{
	/* No SCAN_REQ packets shall be sent */
	BLE_SCAN_PASSIVE,
	/* SCAN_REQ packets may be sent */
	BLE_SCAN_ACTIVE
}ble_scan_type_t;

/**@brief Scan enable used at @ref ble_scan_start
*/
typedef enum
{
	BLE_SCAN_DISABLED,
	BLE_SCAN_ENABLED,
}ble_scan_enable_t;

/**@brief Scan filter duplicate used at @ref ble_scan_start
*/
typedef enum
{
	BLE_SCAN_DUPLICATE_FILTER_DISABLED,
	BLE_SCAN_DUPLICATE_FILTER_ENABLED,
}ble_scan_duplicate_filter_t;

/**@brief Connection filter used at @ref ble_create_connection
*/
typedef enum
{
	BLE_CONN_WHITELIST_FILTER_DISABLED,
	BLE_CONN_WHITELIST_FILTER_ENABLED,
}ble_connection_filter_t;

typedef enum
{
	ADV_IND,
	ADV_DIRECT_IND,
	ADV_SCAN_IND,
	ADV_NONCONN_IND,
	SCAN_RESP,
}ble_adv_event_type_t;

typedef enum
{
	CONFIG_MODE_DISABLED,
	CONFIG_MODE_ENABLED,
}ble_config_mode_status_t;

typedef enum
{
	BLE_UUID_16B = 1,
	BLE_UUID_128B = 4,
	BLE_UUID_INVALID
} ble_uuid_type_t;

/**@brief GATT UUIDs defined by SIG
*/
typedef enum
{
/**< Primary Service Declaration.*/
UUID_PRIMARY_SERVICE = 0x2800,
/**< Secondary Service Declaration.*/
UUID_SECONDARY_SERVICE,
/**< Include Declaration.*/
UUID_INCLUDE,
/**< Characteristic Declaration.*/
UUID_CHARACTERISTIC
}ble_public_uuids_t;

/**@brief GATT Descriptor UUID defined by SIG
*/
typedef enum
{
	CHAR_EXTENDED_PROPERTIES = 0x2900,
	CHAR_USER_DESCRIPTION,
	CLIENT_CHAR_CONFIGURATION,
	SERVER_CHAR_CONFIGURATION,
	CHAR_PRESENTATION_FORMAT,
	CHAR_AGGREGATE_FORMAT,
	VALID_RANGE,
	EXTERNAL_REPORT_REFERENCE,
	REPORT_REFERENCE,
	NUMBER_OF_DIGITALS,
	VALUE_TRIGGER_SETTING,
	ENVIRONMENTAL_SENSING_CONFIGURATION,
	ENVIRONMENTAL_SENSING_MEASUREMENT,
	ENVIRONMENTAL_SENSING_TRIGGER_SETTING,
	TIME_TRIGGER_SETTING
}gatt_descriptors_uuid_t;

typedef enum
{
	BLE_PRES_FORMAT_BOOLEAN = 0X01,
	BLE_PRES_FORMAT_2BIT = 0X02,
	BLE_PRES_FORMAT_NIBBLE = 0X03,
	BLE_PRES_FORMAT_UINT8 = 0X04,
	BLE_PRES_FORMAT_UINT12 = 0X05,
	BLE_PRES_FORMAT_UINT16 = 0X06,
	BLE_PRES_FORMAT_UINT24 = 0X07,
	BLE_PRES_FORMAT_UINT32 = 0X08,
	BLE_PRES_FORMAT_UINT48 = 0X09,
	BLE_PRES_FORMAT_UINT64 = 0X0A,
	BLE_PRES_FORMAT_UINT128 = 0X0B,
	BLE_PRES_FORMAT_SINT8 = 0X0C,
	BLE_PRES_FORMAT_SINT12 = 0X0D,
	BLE_PRES_FORMAT_SINT16 = 0X0E,
	BLE_PRES_FORMAT_SINT24 = 0X0F,
	BLE_PRES_FORMAT_SINT32 = 0X10,
	BLE_PRES_FORMAT_SINT48 = 0X11,
	BLE_PRES_FORMAT_SINT64 = 0X12,
	BLE_PRES_FORMAT_SINT128 = 0X13,
	BLE_PRES_FORMAT_FLOAT32 = 0X14,
	BLE_PRES_FORMAT_FLOAT64 = 0X15,
	BLE_PRES_FORMAT_SFLOAT = 0X16,
	BLE_PRES_FORMAT_FLOAT = 0X17,
	BLE_PRES_FORMAT_DUINT16 = 0X18,
	BLE_PRES_FORMAT_UTF8S = 0X19,
	BLE_PRES_FORMAT_UTF16S = 0X1A,
	BLE_PRES_FORMAT_STRUCT = 0X1B,
}ble_char_pres_format_t;

typedef enum
{
	BLE_EXT_PROP_RELIABLE_WRITE = 0x0001,
	BLE_EXT_PROP_WRITABLE_AUX,
}ble_char_ext_prop_t;

typedef enum
{
	SECONDARY_SERVICE,
	PRIMARY_SERVICE
}ble_service_type_t;

/****************************************************************************************
*                                   Structures                                          *
****************************************************************************************/
typedef struct
{
	uint16_t frame_length;
	uint8_t  event_id;
	uint8_t  palyload[800];
	uint8_t  crc;
}bm_cmd_frame_t;

typedef void (*uart_recv_async_cb_t)(uint16_t);
typedef void (*uart_write_sync_cb_t)(uint8_t *, uint32_t);
typedef void (*uart_read_async_cb_t) (void (*)(uint16_t));
typedef void *(*create_timer_cb_t)(void (*)(void *));
typedef void (*delete_timer_cb_t)(void *);
typedef void (*start_timer_cb_t)(void *, uint32_t);
typedef void (*stop_timer_cb_t)(void *);
typedef void (*sleep_timer_cb_t)(uint32_t);
typedef void (*gpio_set_cb_t)(gpio_pin_t, gpio_status_t);
typedef void (*mode_set_cb_t)(uint8_t);

/**@brief Blue-tooth Low Energy address Type. */
typedef struct PACKED
{
	uint8_t type;          /**< BLE address type. */
	uint8_t addr[BLE_ADDR_LEN];    /**< 48-bit address, LSB format. */
} ble_addr_t, ble_rand_addr_changed_t;

typedef struct PACKED
{
	uint8_t conn_handle;
	uint8_t server_transparent_cntrl;
	uint8_t client_transparent_mode;
}ble_enable_transparent_uart_t;

typedef struct PACKED
{
	/* Minimum time between two connection events. Range is from 0x0006 to 0x0C80.
		This should be less than or equal to max_conn_interval */
	uint16_t min_conn_interval;
	/* Maximum time between two connection events. Range is from 0x0006 to 0x0C80. 
		This should be greater than or equal to min_conn_interval */
	uint16_t max_conn_interval;
	/* Slave latency for the connection in number of connection events. Range is from 0x0000 to 0x01F3 */
	uint16_t conn_latency;
	/* LE link supervision timeout. Range is from 0x000A to 0x0C80 */
	uint16_t link_sv_to;
}ble_set_conn_param_t;

typedef struct PACKED
{
	/* Time between two connection events. Range is from 0x0006 to 0x0C80 */
	uint16_t conn_interval;
	/* Slave latency for the connection in number of connection events. Range is from 0x0000 to 0x01F3 */
	uint16_t conn_latency;
	/* LE link supervision timeout. Range is from 0x000A to 0x0C80 */
	uint16_t link_sv_to;
}ble_conn_param_t;

typedef struct PACKED
{
	uint8_t status;
	uint8_t conn_handle;
	uint8_t role;
	ble_addr_t peer_addr;
	ble_conn_param_t conn_param;
}ble_conn_complete_event_t;

typedef struct PACKED
{
	uint8_t adv_event_type;
	ble_addr_t addr;
	int8_t rssi;
	uint8_t data_len;
	uint8_t data[31];
}ble_adv_report_event_t;

typedef struct PACKED
{
	uint8_t conn_handle;
	uint8_t reason;
}ble_disconnect_complete_t;

typedef struct PACKED
{
	uint8_t conn_handle;
	ble_conn_param_t conn_param;
}ble_conn_param_update_event_t;

typedef struct PACKED
{
	uint8_t cmd_id;
	ble_status_t status;
	uint8_t data_len;
	uint8_t *data;
}ble_cmd_complete_t;

typedef struct
{
	bledk3_status_t status;
}ble_status_report_event_t;

typedef struct
{
	uint16_t num_of_packets;
}ble_end_test_result_t;

typedef struct
{
	ble_config_mode_status_t status;
}ble_config_mode_status_event_t;

typedef union
{
	uint8_t uuid_16b[BLE_UUID_16B_LEN];
	uint8_t uuid_128b[BLE_UUID_128B_LEN];
} ble_uuid_val_t;

typedef struct
{
	uint8_t type;
	ble_uuid_val_t uuid;
} ble_uuid_t;

typedef struct PACKED
{
	uint8_t conn_handle;
	uint16_t char_value_handle;
	uint8_t char_value[MAX_CHAR_WRITE_VALUE];
}ble_write_char_value_event_t;

typedef struct PACKED
{
    uint16_t group_handle_start;
    uint16_t group_handle_end;
    ble_uuid_val_t service_uuid;
}ble_service_attribute_data;

typedef struct
{
    uint8_t conn_handle;
    uint8_t attribute_length;
    ble_service_attribute_data attribute_data[];
}ble_primary_service_discover_all_event_t;

typedef struct PACKED
{
    uint16_t char_attribute_handle;
    uint8_t char_property;
    uint16_t char_value_handle;
    ble_uuid_val_t char_uuid;
}ble_characteristic_attribute_data;

typedef struct
{
    uint8_t conn_handle;
    uint8_t char_attribute_length;
    ble_characteristic_attribute_data attribute_data[];
}ble_primary_service_characteristics_discover_event_t;

typedef struct
{
    uint16_t desc_handle;
    uint8_t uuid_8b[BLE_UUID_16B_LEN];
}ble_descriptor_attribute_data_16b;

typedef struct
{
    uint16_t desc_handle;
    uint8_t uuid_16b[BLE_UUID_128B_LEN];
}ble_descriptor_attribute_data_128b;

typedef struct
{
    uint16_t desc_handle;
    ble_uuid_val_t desc_uuid;
}ble_descriptor_attribute_data;

typedef struct
{
    uint8_t conn_handle;
    uint8_t desc_format;
    ble_descriptor_attribute_data attribute_data[];
}ble_primary_service_descriptors_discover_event_t;

typedef struct  __attribute__ ((packed))
{
    uint8_t conn_handle;
    uint16_t char_value_handle;
    uint8_t char_value_data[];
}ble_characteristic_value_received_event_t, ble_characteristic_value_write_event_t;

typedef struct  __attribute__ ((packed))
{
    uint8_t conn_handle;
    uint16_t char_value_handle;
	uint16_t char_value_offset;
    uint8_t char_value_data[];
}ble_characteristic_preapare_write_received_event_t, ble_characteristic_preapare_write_event_t;


typedef struct  __attribute__ ((packed))
{
    uint8_t conn_handle;
    uint8_t data[];
}ble_transparent_uart_data_received_event_t, ble_transparent_uart_data_write_event_t;

//typedef struct  
//{
	///* Advertising report event */
	//ble_event_callback_t	adv_report_event;
	///* Connection complete event */
	//ble_event_callback_t	conn_complete_event;
	///* Disconnect event */
	//ble_event_callback_t	disconnect_event;
	///* Connection parameter update event */
	//ble_event_callback_t	conn_param_update_event;
//}ble_gap_event_cb_t;
//
//typedef struct
//{
	///* Command complete event */
	//ble_event_callback_t	cmd_complete_event;
	///* Status report  event */
	//ble_event_callback_t	status_report_event;
	///* Status report  event */
	//ble_event_callback_t	config_mode_status_event;
//}ble_common_event_cb_t;
//
//typedef struct
//{
	///* Discover all primary services response event */
	//ble_event_callback_t	discover_all_primary_services_resp_event;
	///* Discover primary service characteristic response event */
	//ble_event_callback_t	discover_primary_service_char_resp_event;
	///* Discover all characteristic descriptor response event */
	//ble_event_callback_t	discover_all_char_descriptor_resp_event;
	///* Characteristic value received event */
	//ble_event_callback_t	char_value_received;
//}ble_gatt_client_event_cb_t;
//
//typedef struct
//{
	///* Client write characteristic value event */
	//ble_event_callback_t	client_write_char_value_event;
//}ble_gatt_server_event_cb_t;
//
//typedef struct
//{
	///* Transparent data received event */
	//ble_event_callback_t	transparent_data_received_event;
//}ble_transparent_data_event_cb_t;

typedef struct
{
    /* Pointer to function that creates new one-shot timer. 
		@return timer handle */
    create_timer_cb_t create_timer;
    /* Pointer to function that deletes the one-shot timer which was created earlier.
		@param timer handle */
    delete_timer_cb_t delete_timer;
    /* Pointer to function that starts the one-shot timer which was created earlier.
       @param timer handle
       @param time in milliseconds */
    start_timer_cb_t start_timer;
    /* Pointer to function that stops the one-shot timer which was started earlier.
       @param timer handle */
    stop_timer_cb_t stop_timer;
    /* Pointer to function that enables sleep mode for specified amount of time.
		@param duration in millisecond */
    sleep_timer_cb_t sleep_timer_ms;
    /* Pointer to function that set the specified GPIO in specified state.
		@param gpio_pin, the valid pins are RST, MODE, TX_IND and RX_IND
		@param gpio_status */
    gpio_set_cb_t gpio_set;
    /* Pointer to function that set the specified mode.
		@param mode, operation mode */
    mode_set_cb_t mode_set;
    /* Pointer to function that sends uart data synchronously to BM7x.
       The function should block until transmission done */
    uart_write_sync_cb_t uart_tx_cb;
    /* Pointer to function that receives asynchronously from BM7xto.
       The function should return immediately */
    uart_read_async_cb_t uart_rx_cb;
} ble_platform_api_list_t;

typedef struct
{
	event_t *event_mem_pool;
	uint32_t event_mem_pool_size;
	uint32_t *event_payload_mem;
	uint32_t event_payload_mem_size;
}event_mem_t;

typedef struct 
{
	event_mem_t event_mem;
	ble_platform_api_list_t platform_api_list;
}platform_init_t;


typedef uint16_t ble_handle_t;
typedef uint8_t ble_attr_permissions_t;
typedef uint8_t ble_char_properties_t;

typedef struct PACKED
{
	ble_handle_t char_attr_handle;
	uint8_t property;
	ble_handle_t char_value_attr_handle;
	ble_uuid_val_t	uuid;
}attribute_data_t;

typedef struct  PACKED
{
	uint8_t conn_handle;
	uint8_t length;
	uint8_t attrib_data[];
}primary_service_char_discovery_resp_t;

typedef struct PACKED
{
	ble_handle_t desc_attr_handle;
	ble_uuid_t	uuid;
}desc_attrib_data_t;

typedef struct  
{
	uint8_t conn_handle;
	uint8_t format;
	uint8_t desc_attrib_data[];
}char_desc_discovery_resp_t;

/**
 * @brief The service attribute definition.
 * This will be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Attribute end handle */
	ble_handle_t end_handle;
	/**< Service UUID */
	ble_uuid_val_t uuid;
}attrib_service_t;

/**
 * @brief The characteristic attribute definition.
 * This will be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Characteristic properties */
	ble_char_properties_t properties;
	/**< Attribute value handle */
	ble_handle_t value_handle;
	/**< Service UUID */
	ble_uuid_val_t uuid;
}attrib_char_t;

/**
 * @brief The characteristic value attribute definition.
 * This will be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_16];
	/**< Characteristic value length */
	uint8_t value_length;
	/**< Characteristic value */
	uint8_t value[BLE_ATT_ATTRIBUTE_VALUE_LEN];
}attrib_char_value_t;

/**
 * @brief The Client Characteristic Configuration Descriptor attribute definition.
 * This may be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Client/Server Characteristic Configuration Descriptor */
	uint8_t ccd_value[2];
}attrib_ccd_desc_t;

/**
 * @brief The User descriptor attribute definition.
 * This may be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< User descriptor length */
	uint8_t ud_length;
	/**< User descriptor */
	uint8_t user_desc[BLE_ATT_ATTRIBUTE_VALUE_LEN];
}attrib_user_desc_t;

/**
 * @brief The Extended property descriptor attribute definition.
 * This may be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Extended property descriptor */
	uint8_t extend_property[2];
}attrib_ext_prop_desc_t;

/**
 * @brief The Presentation format descriptor attribute definition.
 * This may be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Format */
	uint8_t format;
	/**< Exponent */
	uint8_t exponent;
	/**< Unit */
	uint16_t unit;
	/**< Description */
	uint16_t description;
	/**< Namespace */
	uint8_t name_space;
}attrib_pres_format_desc_t;

/**
 * @brief The Presentation format descriptor attribute definition.
 * This may be used as part of GATT-Service Create request
 */
typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Attribute start handle */
	ble_handle_t start_handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**< Number of attribute handles */
	uint8_t num_of_handles;
	/**< Attribute handles list */
	uint16_t *handles_list;
}attrib_aggr_format_desc_t;

typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Here the stack will store the handle for future use */
	ble_handle_t handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 2 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_2];
	/**<  descriptor value length */
	uint16_t desc_val_length;
	///**<  maximum possible length of the descriptor value */
	//uint16_t desc_val_max_length;
	/*< descriptor value*/
	uint8_t desc_value[BLE_ATT_ATTRIBUTE_VALUE_LEN];
}ble_generic_att_public_desc_t;

typedef struct PACKED
{
	/**< Length of the whole attribute. Including Header and Value */
	uint8_t	length;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Here the stack will store the handle for future use */
	ble_handle_t handle;
	/**< Length of the attribute type */
	uint8_t	type_length;
	/**< The 16 bytes attribute type (UUID) */
	uint8_t	type[BLE_ATTRIB_UUID_LENGTH_16];
	/**<  descriptor value length */
	uint16_t desc_val_length;
	///**<  maximum possible length of the descriptor value */
	//uint16_t desc_val_max_length;
	/*< descriptor value*/
	uint8_t desc_value[BLE_ATT_ATTRIBUTE_VALUE_LEN];
}ble_generic_att_private_desc_t;

typedef struct
{
	/**< Here the stack will store the handle for future use */
	ble_handle_t handle;
	/**< characteristic configuration value */
	uint16_t ccd_value;
	/**<  descriptor permissions */
	ble_attr_permissions_t perm;
	/**< set this flag, if CCD used. Reset otherwise. */
	bool ccd_included;
}ble_client_char_config_desc_t;

typedef ble_client_char_config_desc_t ble_server_char_config_desc_t;

typedef struct PACKED
{
	/**< user descriptor handle */
	ble_handle_t handle;
	/**< the user friendly description length, this value will be stored in the relevant descriptor, if no user description is desired set to 0*/
	uint16_t len;
	/**< a user friendly description, this value will be stored in the relevant descriptor, if no user description is desired set to NULL */
	uint8_t *user_description;
	/**< user descriptor permissions */
	ble_attr_permissions_t permissions;
	/**< set this flag, if user descriptor used. Reset otherwise. */
	bool ud_included;
}ble_user_desc_t;

/** @brief Characteristic presentation format
*/
typedef struct PACKED
{
	/**< presentation format handle */
	ble_handle_t handle;
	/**< value format */
	ble_char_pres_format_t format;
	/**< value exponent */
	int8_t exponent;
	/**<  as defined in GATT spec Part G, Section 3.3.3.5.4 */
	uint16_t unit;
	/**<  as defined in GATT spec Part G, Section 3.3.3.5.6 */
	uint16_t description;
	/**<  as defined in GATT spec Part G, Section 3.3.3.5.5 */
	uint8_t name_space;
	/**< presentation format permissions */
	ble_attr_permissions_t permissions;
	/**< set this flag, if presentation format used. Reset otherwise. */
	bool pf_included;
}ble_char_presentation_format_t;

/** @brief Characteristic extended properties
*/
typedef struct PACKED
{
	/**< presentation format handle */
	ble_handle_t handle;
	/**< value format */
	ble_char_ext_prop_t ext_property;
	/**< presentation format permissions */
	ble_attr_permissions_t permissions;
	/**< set this flag, if extended properties used. Reset otherwise. */
	bool ep_included;
}ble_char_ext_properties_t;

typedef struct PACKED
{
	/**< Descriptor handle */
	ble_handle_t handle;
	/**< The attribute permission */
	ble_attr_permissions_t	permission;
	/**< Descriptor UUID */
	ble_uuid_t desc_uuid;
	/**<  Descriptor value length */
	uint16_t desc_val_length;
	/*< Descriptor value*/
	uint8_t desc_value[BLE_ATT_ATTRIBUTE_VALUE_LEN];
}ble_generic_desc_t;

typedef struct PACKED
{
	/**< Characteristic handle */
	ble_handle_t char_handle;
	/**< Characteristic properties, values for Client Characteristic Configuration Descriptor and Server Characteristic Configuration Descriptor will be decided from this value*/
	ble_char_properties_t properties;
	/**< Value permissions */
	ble_attr_permissions_t permissions;
	/**< Characteristic value handle */
	ble_handle_t value_handle;
	/**< Characteristic UUID */
	ble_uuid_t uuid;
	/**<  initial value length */
	uint8_t len;
	/**< maximum possible length of the char. value */
	uint16_t max_len;
	/**< initial value of this characteristic  */
	uint8_t *init_value;
}ble_char_val_t;

typedef struct PACKED
{
	/**< characteristics value related info */
	ble_char_val_t char_val;
	/**< client config descriptor related info */
	ble_client_char_config_desc_t  client_config_desc;
	/**< server config descriptor related info */
	ble_server_char_config_desc_t  server_config_desc;
	/**< user descriptor related info */
	ble_user_desc_t user_desc;
	/**< Characteristic presentation format, if no presentation format is necessary then reset pf_included flag */
	ble_char_presentation_format_t presentation_format;
	/**< Characteristic extended properties, if no extended properties is necessary then reset ep_included flag */
	ble_char_ext_properties_t ext_properties;
	/**< Number of generic descriptors included in list */
	uint16_t additional_desc_count;
	/**< generic descriptor list */
	ble_generic_desc_t    *additional_desc_list;
}ble_char_t;

typedef struct PACKED
{
	/**< Service type (PRIMARY or SECONDARY )*/
	ble_service_type_t type;
	/**< Service permissions*/
	ble_attr_permissions_t perm;
	/**< Here the stack will store the handle for future use */
	ble_handle_t handle;
	/**< UUID of the  Service*/
	ble_uuid_t uuid;
	/**< Characteristics count*/
	uint16_t char_count;
	/**< Characteristics list*/
	ble_char_t *char_list;
}ble_service_t;

/****************************************************************************************
*											APIs	                                    *
****************************************************************************************/
/*
 * @brief Resets BM7x module
 *
 * @param pointer to platform_init which contains platform API list and event memory
 * @param mode operation mode
 *
 * @return status of BLE initialization
*/
ble_status_t ble_init(platform_init_t *platform_init);

/*
 * @brief Set an advertisement data on BM7x
 *
 * @param[in] adv_data advertisement data
 * @param[in] adv_data_len advertisement data length
 *
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_adv_data_set(uint8_t const *adv_data, uint8_t adv_data_len);

/*
 * @brief Set scan response data on BM7x
 *
 * @param[in] scan_data scan response data
 * @param[in] scan_data_len scan response data length
 *
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_scan_resp_data_set(uint8_t const *scan_data, uint8_t scan_data_len);

/*
 * @brief Set an advertisement parameters on BM7x
 *
 * @param[in] type advertisement type @ref BM_ADV_TYPE
 * @param[in] peer_addr peer device address and its type. Only applicable in direct advertising mode
 * @param[in] interval advertisment interval. each unit is .625 ms
 *
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_adv_param_set(BM_ADV_TYPE type, ble_addr_t *peer_addr, uint16_t interval);

/* @brief Set an advertisement parameters on BM7x
 *
 * @param
 *
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_adv_start(void);

ble_status_t ble_adv_stop(void);

/*
 * @brief Set device name for BM7x
 *
 * @param[in] device_name name of the device
 * @param[in] length length of device name
 *
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_set_device_name(const uint8_t *device_name, uint8_t length);

/*
 * @brief Gives RSSI value for peer connection. This API is only valid after connection established with peer device
 *
 * @param[in] conn_handle connection handle
 * @param[out] rssi rssi value of peer connection
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_rssi_read(uint8_t conn_handle, uint8_t *rssi);

/*
 * @brief Set scan parameters
 *
 * @param[in] scan_interval time interval between subsequent scans. The scan interval should be in the range of 0x0004 to 0x4000
 * @param[in] scan_window is a scan duration and it should not be greater than scan_interval
 * @param[in] scan_type controls the type of scan @ref ble_scan_type_t
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_scan_param_set(uint16_t scan_interval, uint16_t scan_window, ble_scan_type_t scan_type);

/*
 * @brief Start scan
 *
 * @param[in] scan_enable enables/disables scan operation
 * @param[in] scan_dup_filter enables/disables scan duplicate filter
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_scan_start(ble_scan_enable_t scan_enable, ble_scan_duplicate_filter_t scan_dup_filter);

/*
 * @brief Set connection parameters
 *
 * @param[in] conn_params provides connection parameter for upcoming connections. @ref ble_set_conn_param_t
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_set_connection_params(ble_set_conn_param_t *conn_params);

/*
 * @brief Create connection
 *
 * @param[in] conn_filter determines the peer device info source. If @ref BLE_CONN_WHITELIST_FILTER_DISABLED is set 
 *				then whitelist is not used select the peer device. If @ref BLE_CONN_WHITELIST_FILTER_ENABLED is set
 *				then whitelist is used to select peer device.
 * @param[in] ble_addr provides peer device address and its type to connect
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_create_connection(ble_connection_filter_t conn_filter, ble_addr_t *address);

/*
 * @brief Cancel ongoing connection
 *
 * @param None
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_cancel_connection(void);

/*
 * @brief Update connection parameters
 *
 * @param[in] conn_handle identifies the connection 
 * @param[in] conn_param @ref ble_conn_param_t
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_update_connection_parameter(uint8_t conn_handle, ble_conn_param_t *conn_param);

/*
 * @brief Disconnect from remote device
 *
 * @param[in] conn_handle connection handle. 
 * 
 * @note Since current version supports single connection, the connection handle is not honored.
 *				In future versions when multi connection is supported, this will be honored.
 *
 * @return 
*/
void ble_disconnect_device(uint8_t conn_handle);

ble_status_t ble_pair_mode_set(BM_PAIR_MODE mode);

ble_status_t ble_pair_mode_get(void);

ble_status_t ble_pair_request(ble_handle_t conn_handle);

ble_status_t ble_pair_passkey_enter(ble_handle_t conn_handle, uint8_t* passkey, uint8_t length);

ble_status_t ble_pair_passkey_reply(ble_handle_t conn_handle);

ble_status_t ble_pair_passkey_erase_digits(ble_handle_t conn_handle, uint8_t length);

ble_status_t ble_pair_passkey_clear(ble_handle_t conn_handle);

ble_status_t ble_pair_passkey_confirm(ble_handle_t conn_handle, ble_pair_confirm_t confirm);

ble_status_t ble_pair_device_erase_all(void);

ble_status_t ble_pair_device_delete(uint8_t index);

/*
 * @brief Read remote device name
 *
 * @param[in] conn_handle connection handle
 * @param[out] name remote device name
 * @param[out] name_length length of remote device name
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
 */
 //ble_status_t ble_remote_device_name_read(uint8_t conn_handle, uint8_t *name, uint8_t *name_length);
 
/*
 * @brief Enable transparent UART service
 *
 * @param[in] enable_transparent_uart transparent UART parameters @ref ble_enable_transparent_uart_t
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_enable_transparent_uart(ble_enable_transparent_uart_t * enable_transparent_uart);

/*
 * @brief Transparent UART data
 *
 * @param[in] data transparent UART data
 * @param[in] datalen length of transparent UART data
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_send_transparent_data(ble_handle_t conn_handle, uint8_t *data, uint8_t datalen);

/*
 * @brief Register ble event callbacks
 *
 * @param[in] event_type type of event @ref ble_event_types_t
 * @param[in] event_handler callback function
 * 
 * @return 
*/
void register_ble_event_cb_handlers(ble_event_types_t event_type, const void *event_handler);

///*
 //* @brief Reads FIFO where data/commands from BM7x stored. It also parse commands and check CRC
 //*
 //* @param
 //*
 //* @return
//*/
//void ble_event_handler(void);

/*
 * @brief Process BMxx commands and invoke appropriate callbacks
 *
 * @param[in] bm_cmd command/data from BM7x device @ref bm_cmd_frame_t
 *
 * @return
*/
void ble_event_cb_handler(bm_cmd_frame_t *bm_cmd);

/*
 * @brief Reads fifo where data/commands from BMxx stored. It also parse commands and check CRC
 *
 * @param 
 *
 * @return
*/
uint8_t interface_process_fifo_data(void);

/*
 * @brief Create GATT-Service
 *
 * @param[in] GATT-Service parameters
 * 
 * @return Upon successful completion of the function shall return @ref BLE_SUCCESS, otherwise it shall return @ref ble_status_t
*/
ble_status_t ble_gatt_service_create(ble_service_t *ble_service);

/*! \fn ble_status_t ble_primary_service_discover_all(ble_handle_t conn_handle)
 *  \brief Discovers all the primary services on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_primary_service_discover_all(ble_handle_t conn_handle);

/*! \fn ble_status_t ble_primary_service_characteristics_discover(ble_handle_t conn_handle, ble_uuid_t *service_uuid)
 *  \brief Discovers all the characteristics of the service specified on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \param service_uuid Handle to the service UUID for which characteristics need to discovered.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_primary_service_characteristics_discover(ble_handle_t conn_handle, ble_uuid_t *service_uuid);

/*! \fn ble_status_t ble_characteristic_read_by_uuid(ble_handle_t conn_handle, ble_uuid_t *characteristic_uuid, void *data, uint16_t *data_len)
 *  \brief Perform read operation of the characteristic specified by UUID on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_uuid Handle to the characteristic UUID for which read operation is to be performed.
 *  \param data Handle to the data buffer to copy to the read data.
 *  \param data_len Handle to the data length variable to copy the length of the read data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_read_by_uuid(ble_handle_t conn_handle, ble_uuid_t *characteristic_uuid, void *data, uint16_t *data_len);

/*! \fn ble_status_t ble_characteristic_read(ble_handle_t conn_handle, ble_handle_t characteristic_handle, void *data, uint16_t *data_len)
 *  \brief Perform read operation of the characteristic specified by handle on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle to the characteristic for which read operation is to be performed.
 *  \param data Handle to the data buffer to copy the read data.
 *  \param data_len Handle to the data length variable to copy the length of the read data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_read(ble_handle_t conn_handle, ble_handle_t characteristic_handle, void *data, uint16_t *data_len);

/*! \fn ble_status_t ble_characteristic_write_with_response(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length)
 *  \brief Perform write with response operation of the characteristic specified by handle on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle to the characteristic for which write operation is to be performed.
 *  \param data Handle to the data buffer with write data.
 *  \param length Length of the data to be written.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_write_with_response(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_write_without_respose(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length)
 *  \brief Perform write without response operation of the characteristic specified by handle on the GATT server by GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle to the characteristic for which write operation is to be performed.
 *  \param data Handle to the data buffer with write data.
 *  \param length Length of the data to be written.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_write_without_respose(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_reliable_write_request_prepare(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint16_t offset, uint8_t* data, uint16_t length)
 *  \brief Send Prepare Write Request from the GATT client to the GATT server.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle of the characteristic value.
 *  \param offset Offset of the first octet to be written.
 *  \param data Handle to the part of characteristic value data.
 *  \param length Length of the part of characteric value data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_reliable_write_request_prepare(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint16_t offset, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_reliable_write_request_execute(ble_handle_t conn_handle)
 *  \brief Send Execute Write Request from the GATT client to the GATT server.
 *  \param conn_handle Connection handle.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_reliable_write_request_execute(ble_handle_t conn_handle);

/*! \fn ble_status_t ble_characteristic_reliable_write_request_execute(ble_handle_t conn_handle)
 *  \brief Send Cancel Write Request from the GATT client to the GATT server.
 *  \param conn_handle Connection handle.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_reliable_write_request_cancel(ble_handle_t conn_handle);
ble_status_t ble_characteristic_attribute_read_request(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint16_t offset);

/*! \fn ble_status_t ble_characteristic_value_send(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length)
 *  \brief Perform characteristic value send to GATT client by GATT server.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle to the characteristic for which send operation is to be performed.
 *  \param data Handle to the data buffer with data.
 *  \param length Length of the data to be sent.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_value_send(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_value_update(ble_handle_t characteristic_handle, uint8_t* data, uint16_t length)
 *  \brief Perform local update of characteristic value send by GATT server.
 *  \param characteristic_handle Handle to the characteristic for which send operation is to be performed.
 *  \param data Handle to the data buffer with data to be updated.
 *  \param length Length of the data updated.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_value_update(ble_handle_t characteristic_handle, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_value_read(ble_handle_t characteristic_handle, void *data, uint16_t *data_len)
 *  \brief Perform local read of characteristic value send by GATT server.
 *  \param characteristic_handle Handle to the characteristic for which send operation is to be performed.
 *  \param data Handle to the data buffer to copy the read data.
 *  \param data_len Handle to the data length variable to copy the length of the read data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_value_read(ble_handle_t characteristic_handle, void *data, uint16_t *data_len);

/*! \fn ble_status_t ble_primary_service_read_all(void)
 *  \brief Read all local services by the GATT server.
 *  \param None.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_primary_service_read_all(void);

/*! \fn ble_status_t ble_primary_service_characteristics_read(ble_uuid_t* service_uuid)
 *  \brief Read all chracterictics of the local service by the GATT server.
 *  \param service_uuid Handle to the service UUID for which characteristics are read.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_primary_service_characteristics_read(ble_uuid_t* service_uuid);

/*! \fn ble_status_t ble_write_response_send(ble_handle_t conn_handle, ble_handle_t attr_handle, uint8_t err_code)
 *  \brief Send response from the GATT server to the write operation requested by the GATT client.
 *  \param conn_handle Connection handle.
 *  \param attr_handle Attribute handle to send the write response.
 *  \param err_code Code of the response to be sent for the write request.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_write_response_send(ble_handle_t conn_handle, ble_handle_t attr_handle, uint8_t err_code);

/*! \fn ble_status_t ble_read_response_send(ble_handle_t conn_handle, uint8_t rsp_type, uint8_t* data, uint16_t length)
 *  \brief Send response from the GATT server to the read operation requested by the GATT client.
 *  \param conn_handle Connection handle.
 *  \param rsp_type Type of the read response.
 *  \param data Handle to the data to be sent for the read request.
 *  \param length Length of the data to be sent for the read request.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_read_response_send(ble_handle_t conn_handle, uint8_t rsp_type, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_reliable_write_response_prepare(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint16_t offset, uint8_t* data, uint16_t length)
 *  \brief Send response from the GATT server to the Prepare Write Request by the GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Handle of the characteristic value.
 *  \param offset Offset of the first octet to be written.
 *  \param data Handle to the part of characteristic value data.
 *  \param length Length of the part of characteric value data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_reliable_write_response_prepare(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint16_t offset, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_characteristic_reliable_write_response_execute(ble_handle_t conn_handle)
 *  \brief Send response from the GATT server to the Prepare Write Execute by the GATT client.
 *  \param conn_handle Connection handle.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_reliable_write_response_execute(ble_handle_t conn_handle);

/*! \fn ble_status_t ble_characteristic_attribute_read_response(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length)
 *  \brief Send response from the GATT server to the Read Blob Request by the GATT client.
 *  \param conn_handle Connection handle.
 *  \param data Handle to the part of characteristic value data.
 *  \param length Length of the part of characteric value data.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_characteristic_attribute_read_response(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t* data, uint16_t length);

/*! \fn ble_status_t ble_error_response_send(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t req_opcode, uint8_t err_code)
 *  \brief Send error response from the GATT server to the GATT client.
 *  \param conn_handle Connection handle.
 *  \param characteristic_handle Charactertic handle to which the error response is to be sent.
 *  \param req_opcode Opcode of the request for which the error response is to be sent.
 *  \param err_code Error code response to be sent.
 *  \pre The BLE Central must have an active connection with the BLE Peripheral.
 *  \return ble_status_t Status returned for the command issued.
 */
ble_status_t ble_error_response_send(ble_handle_t conn_handle, ble_handle_t characteristic_handle, uint8_t req_opcode, uint8_t err_code);

//Shutdown BLE. This API configures the GPIOs that can wakeup the device and puts the device into power saving mode.
//In the power saving mode, the cpu clock is switched to 32 KHz and only hardware Logic handling wakeup is powered on. On wakeup the device starts out of reset.
ble_status_t ble_shutdown(void);

bool ble_response_check(uint8_t byte);

#endif //_BLE_API_H_
