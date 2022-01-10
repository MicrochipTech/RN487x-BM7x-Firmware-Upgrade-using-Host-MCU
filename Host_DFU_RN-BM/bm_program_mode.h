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
#ifndef _BM_PROGRAM_MODE_H_
#define _BM_PROGRAM_MODE_H_
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#define BM_PGM_PKT_LEN_MAX  320  

/*! \struct BM_PROGRAM_CMD
 * PROGRAM command structure. Consists of the address of the PROGRAM parameter and its length.
 */
typedef struct _bm_program_cmd
{
    uint16_t handle;
    uint32_t address;
    uint8_t* data;
    uint8_t length;
    bool    write_continue;
    uint32_t write_continue_length; 
} BM_PROGRAM_CMD;


/*! \struct BM_PROGRAM_CMDPKT
 * PROGRAM command packet. Consists of the length of and handle to command data.
 */
typedef struct _bm_program_cmdpkt
{
    /*! Length of the command data. */
    uint8_t length;
    /*! Handle to the command data. */
    uint8_t* cmdPkt;
} BM_PROGRAM_CMDPKT;

typedef enum {
	COMMAND_PKT_TYPE = 0x01,
    DATA_ACL_PKT_TYPE = 0x02,
    EVENT_PKT_TYPE = 0x04,
}HCI_PKT_TYPE;



typedef struct __attribute__ ((packed)) _hci_command_pkt
{
    uint8_t type;
    uint16_t opcode;
    uint8_t length;
}HCI_COMMAND_PKT;

typedef struct __attribute__ ((packed)) _hci_event_pkt
{
    uint8_t type;
    uint8_t event;
    uint8_t length;
}HCI_EVENT_PKT;

typedef struct __attribute__ ((packed)) _hci_data_pkt
{
    uint8_t type;
    uint16_t conn_handle;
    uint16_t length;
}HCI_DATA_PKT;

typedef struct __attribute__ ((packed)) _bm_program_connect_pkt
{
    HCI_COMMAND_PKT hci_command_pkt;
    uint8_t addr[6];
    uint16_t type;
    uint8_t mode;
    uint8_t rsvd;
    uint16_t offset;
    uint8_t role;
}BM_PROGRAM_CONNECT_PKT;

typedef struct __attribute__ ((packed)) _bm_program_disconnect_pkt
{
    HCI_COMMAND_PKT hci_command_pkt;
    uint16_t conn_handle;
    uint8_t reason;
}BM_PROGRAM_DISCONNECT_PKT;


typedef struct __attribute__ ((packed)) _bm_program_data_pkt
{
    HCI_DATA_PKT acl_data_pkt;
    uint16_t pgm_cmd_id;
    uint16_t pgm_data_len;
    uint8_t pgm_mem_type;
    uint8_t pgm_mem_subtype;
    uint32_t address;
    uint32_t size;
}BM_PROGRAM_DATA_PKT;

typedef struct __attribute__ ((packed)) _bm_program_data_alt_pkt
{
    HCI_DATA_PKT acl_data_pkt;
    uint16_t pgm_cmd_id;
    uint16_t pgm_data_len;
}BM_PROGRAM_DATA_ALT_PKT;

typedef struct __attribute__ ((packed)) _bm_program_crc_pkt
{
    HCI_DATA_PKT acl_data_pkt;
    uint16_t pgm_cmd_id;
    uint16_t pgm_data_len;
    uint8_t pgm_mem_type;
    uint8_t pgm_mem_subtype;
	uint32_t crc_algo;
    uint32_t address;
    uint32_t size;
}BM_PROGRAM_CRC_PKT;

typedef enum _bm_program_cmd_state
{
	BM_PGM_HCI_EVENT = 0x00,
    BM_PGM_HCI_EVENT_TYPE,
    BM_PGM_HCI_EVENT_LEN,
    BM_PGM_HCI_EVENT_DATA,
            
    BM_PGM_HCI_ACL_HANDLEH,
    BM_PGM_HCI_ACL_HANDLEL,
    BM_PGM_HCI_ACL_LENH,
    BM_PGM_HCI_ACL_LENL,
    BM_PGM_HCI_ACL_DATA,
} BM_PROGRAM_CMD_STATE;

typedef enum _bm_pgm_hci_index
{
    BM_PGM_HCI_EVENT_INDEX = 0x00,
    BM_PGM_HCI_EVENT_TYPE_INDEX,
    BM_PGM_HCI_EVENT_LEN_INDEX,
    BM_PGM_HCI_EVENT_DATA_INDEX,
} BM_PGM_HCI_INDEX;

typedef enum _bm_pgm_hci_acl_index
{
    BM_PGM_HCI_ACL_HANDLEL_INDEX = 0x01,
    BM_PGM_HCI_ACL_HANDLEH_INDEX,
    BM_PGM_HCI_ACL_LENL_INDEX,
    BM_PGM_HCI_ACL_LENH_INDEX,
    BM_PGM_HCI_ACL_DATA_INDEX,     
} BM_PGM_HCI_ACL_INDEX;

#define BM_PGM_HCI_ACL_VAL 0x02
#define BM_PGM_HCI_EVENT_VAL    0x04

typedef enum _bm_program_hci_event_id
{
    BM_PROGRAM_HCI_COMPLETE = 0x03,
	BM_PROGRAM_HCI_STATUS = 0x0F,
    BM_PROGRAM_HCI_NOCP = 0x13,            
    BM_PROGRAM_HCI_ERROR = 0xFF
} BM_PROGRAM_HCI_EVENT_ID;

typedef enum _bm_program_hci_event_status
{
    BM_PROGRAM_HCI_SUCCESS = 0x00,
    BM_PROGRAM_HCI_HANDLE = 0x01,        
	BM_PROGRAM_HCI_FAIL
} BM_PROGRAM_HCI_EVENT_STATUS;

typedef struct _bm_program_event 
{
   	BM_PROGRAM_HCI_EVENT_ID         eventID;
    void*                           data;
    uint16_t                        length;
} BM_PROGRAM_EVENT;

/*! \fn BM_PROGRAM_CMDPKT* BM_PROGRAM_Init(uint8_t bmxxDevice)
 *  \brief Initializes PROGRAM configuration library.
 *  \param bmxxDevice Bluetooth device type used. Refer BMxx_BLUETOOTH_DEVICE.
 *  \pre None.
 *  \return Handle to the PROGRAM command packet.
 */
BM_PROGRAM_CMDPKT* BM_PROGRAM_Init(void);

/*! \fn void BM_PROGRAM_DeInit(BM_PROGRAM_CMDPKT* programCmdPkt)
 *  \brief De-initializes PROGRAM mode configuration library.
 *  \param programCmdPkt Handle to the PROGRAM mode command packet created by init function.
 *  \pre PROGRAM configuration library initialization function must be used to initialize the programCmdPkt.
 *  \return None.
 */
void BM_PROGRAM_DeInit(BM_PROGRAM_CMDPKT* programCmdPkt);

/*! \fn void BM_PROGRAM_Connect(BM_PROGRAM_CMDPKT* programCmdPkt)
 *  \brief Connect command to connect to BM70 in PROGRAM mode.
 *  \param programCmdPkt Handle to the PROGRAM mode command packet created by connect function.
 *  \pre PROGRAM configuration library initialization function must be used to initialize the programCmdPkt.
 *  \return None.
 */
void BM_PROGRAM_Connect(BM_PROGRAM_CMDPKT* programCmdPkt);


/*! \fn void BM_PROGRAM_Disconnect(BM_PROGRAM_CMDPKT* programCmdPkt)
 *  \brief Disconnect command to disconnect from BM70 in PROGRAM mode.
 *  \param programCmdPkt Handle to the PROGRAM mode command packet created by connect function.
 *  \pre PROGRAM configuration library initialization function must be used to initialize the programCmdPkt. 
 *  	 The PROGRAM configuration library de-initialization function must be called after calling disconnect function.
 *  \return None.
 */
void BM_PROGRAM_Disconnect(BM_PROGRAM_CMDPKT* programCmdPkt);


/*! \fn void BM_PROGRAM_Erase(BM_PROGRAM_CMDPKT* programCmdPkt)
 *  \brief Erase command to erase configuration on BM70 in PROGRAM mode.
 *  \param programCmdPkt Handle to the PROGRAM mode command packet created by connect function.
 *  \pre PROGRAM configuration library initialization and connect functions must be called before calling the erase function.
 *  \return None.
 */
void BM_PROGRAM_Erase(BM_PROGRAM_CMDPKT* programCmdPkt, BM_PROGRAM_CMD* pgm_cmd);


void BM_PROGRAM_Write(BM_PROGRAM_CMDPKT* programCmdPkt, BM_PROGRAM_CMD* pgm_cmd);
void BM_PROGRAM_Write_Continue(BM_PROGRAM_CMDPKT* programCmdPkt, BM_PROGRAM_CMD* pgm_cmd);
void BM_PROGRAM_Read(BM_PROGRAM_CMDPKT* programCmdPkt, BM_PROGRAM_CMD* pgm_cmd);
void BM_PROGRAM_CRC_Get(BM_PROGRAM_CMDPKT* programCmdPkt, BM_PROGRAM_CMD* pgm_cmd);


bool BM_PROGRAM_ResponseCheck(uint8_t* data, uint8_t len);

#endif