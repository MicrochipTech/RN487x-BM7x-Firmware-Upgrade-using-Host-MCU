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
#include "stdlib.h"
#include "string.h"
#include "config.h"
#include "bm_mode.h"
#include "bm_program_mode.h"
#include "bm_application_mode.h"
#include "bm_utils.h"
#include "event_mem.h"
#include "ble_api.h"
#include "dfu_api.h"
#include "interface.h"

BM_PROGRAM_CMDPKT* program_cmdpkt = NULL;
static uint16_t program_handle;
static dfu_status_t dfu_status_report_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id);
static dfu_status_t dfu_response_report_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id);
static uint16_t dfu_status_handle_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id);
static uint8_t* dfu_response_read_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id);

dfu_status_t dfu_init(platform_init_t *platform_init)
{ 
    dfu_status_t status = DFU_SUCCESS;
	status = interface_init(platform_init);
	if(DFU_SUCCESS != status)
	{
		return status;
	}
    
	program_cmdpkt = (BM_PROGRAM_CMDPKT*)BM_PROGRAM_Init();
	
	//Set operating mode
	platform_init->platform_api_list.mode_set(BM_MODE_PROGRAM);
                     
	BM_PROGRAM_Connect(program_cmdpkt);
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	if(DFU_SUCCESS == status)
	{
		/* Check the status in status-report event */
		status = dfu_status_report_parser(BM_PROGRAM_HCI_SUCCESS);
        
        interface_cmd_wait(EVENT_PKT_TYPE);
        status = dfu_status_report_parser(BM_PROGRAM_HCI_SUCCESS);
        program_handle = dfu_status_handle_parser(BM_PROGRAM_HCI_SUCCESS);
	}
		
	return status;
}

dfu_status_t dfu_deinit(void)
{ 
    dfu_status_t status = DFU_SUCCESS;
	
	BM_PROGRAM_Disconnect(program_cmdpkt);
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	
	return status;
}


dfu_status_t dfu_program_memory_erase(uint32_t address, uint8_t length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    BM_PROGRAM_CMD pgm_cmd;
    pgm_cmd.handle = program_handle;
    pgm_cmd.address = address;
    pgm_cmd.data = NULL;
    pgm_cmd.length = length;
    pgm_cmd.write_continue = 0;
    
    BM_PROGRAM_Erase(program_cmdpkt, &pgm_cmd);
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	if(DFU_SUCCESS == status)
	{
		/* Check the status in status-report event */
		status = dfu_status_report_parser(BM_PROGRAM_HCI_HANDLE);
        
        interface_cmd_wait(DATA_ACL_PKT_TYPE);
        status = dfu_response_report_parser(BM_PROGRAM_HCI_SUCCESS);
	}
		
	return status;   
}

dfu_status_t dfu_program_memory_write(uint32_t address, uint8_t* data, uint8_t length, bool write_continue)
{
    dfu_status_t status = DFU_SUCCESS;
    
    BM_PROGRAM_CMD pgm_cmd;
    pgm_cmd.handle = program_handle;
    pgm_cmd.address = address;
    pgm_cmd.data = data;
    pgm_cmd.length = length;
    pgm_cmd.write_continue = write_continue;
    
    BM_PROGRAM_Write(program_cmdpkt, &pgm_cmd);
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	if(DFU_SUCCESS == status)
	{
		/* Check the status in status-report event */
		status = dfu_status_report_parser(BM_PROGRAM_HCI_SUCCESS);
        
        interface_cmd_wait(DATA_ACL_PKT_TYPE);
        status = dfu_response_report_parser(BM_PROGRAM_HCI_SUCCESS);
	}
		
	return status;   
}


dfu_status_t dfu_program_memory_write_continue(uint32_t address, uint8_t* data, uint8_t length, uint8_t continue_mode, uint32_t continue_length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    BM_PROGRAM_CMD pgm_cmd;
    pgm_cmd.handle = program_handle;
    pgm_cmd.address = 0x00000000;
    pgm_cmd.data = data;
    pgm_cmd.length = length;
    pgm_cmd.write_continue = true;
    
    if (continue_mode == DFU_WRITE_CONTINUE_START)
    {
        pgm_cmd.address = address;
        pgm_cmd.write_continue_length = continue_length;
        BM_PROGRAM_Write(program_cmdpkt, &pgm_cmd);
    }
    else if (continue_mode == DFU_WRITE_CONTINUE_PROCEED)
    {
        BM_PROGRAM_Write_Continue(program_cmdpkt, &pgm_cmd);
    }
    else if (continue_mode == DFU_WRITE_CONTINUE_STOP)
    {
        pgm_cmd.write_continue = false;
        BM_PROGRAM_Write_Continue(program_cmdpkt, &pgm_cmd);
    }
    
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	if(DFU_SUCCESS == status)
	{
		/* Check the status in status-report event */
		status = dfu_status_report_parser(BM_PROGRAM_HCI_HANDLE);
        
        interface_cmd_wait(DATA_ACL_PKT_TYPE);
        status = dfu_response_report_parser(BM_PROGRAM_HCI_SUCCESS);
	}
		
	return status;   
}

dfu_status_t dfu_program_memory_read(uint32_t address, uint8_t* data, uint8_t length)
{
    dfu_status_t status = DFU_SUCCESS;
    
    BM_PROGRAM_CMD pgm_cmd;
    pgm_cmd.handle = program_handle;
    pgm_cmd.address = address;
    pgm_cmd.data = data;
    pgm_cmd.length = length;
    
    BM_PROGRAM_Read(program_cmdpkt, &pgm_cmd);
	status = interface_cmd_send_wait(program_cmdpkt->cmdPkt, (uint32_t) program_cmdpkt->length, EVENT_PKT_TYPE);
	if(DFU_SUCCESS == status)
	{
        uint8_t* buff; 
		/* Check the status in status-report event */
		status = dfu_status_report_parser(BM_PROGRAM_HCI_HANDLE);
        
        interface_cmd_wait(DATA_ACL_PKT_TYPE);
        status = dfu_response_report_parser(BM_PROGRAM_HCI_SUCCESS);
        
        buff = dfu_response_read_parser(BM_PROGRAM_HCI_SUCCESS);
        if(buff != NULL)
        {
            memcpy(data, buff, length);
        }
	}
		
	return status;   
}

static dfu_status_t dfu_status_report_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id)
{
	event_t *cmd_frame = (event_t *) get_received_cmd_frame();
	
	if(status_id == cmd_frame->event_msg.data[0])
	{
		return DFU_SUCCESS;
	}
	
	return DFU_FAIL;
}

static dfu_status_t dfu_response_report_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id)
{
	event_t *cmd_frame = (event_t *) get_received_cmd_frame();
	
	if(status_id == (cmd_frame->event_msg.data[4] | cmd_frame->event_msg.data[5]<<8))
	{
		return DFU_SUCCESS;
	}
	
	return DFU_FAIL;
}

static uint16_t dfu_status_handle_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id)
{
	event_t *cmd_frame = (event_t *) get_received_cmd_frame();
	
	if(status_id == cmd_frame->event_msg.data[0])
	{
		return ((cmd_frame->event_msg.data[2]<<8) | cmd_frame->event_msg.data[1]);
	}
	
	return 0;
}

static uint8_t* dfu_response_read_parser(BM_PROGRAM_HCI_EVENT_STATUS status_id)
{
	event_t *cmd_frame = (event_t *) get_received_cmd_frame();
	
	if(status_id == (cmd_frame->event_msg.data[4] | cmd_frame->event_msg.data[5]<<8))
	{
		return &(cmd_frame->event_msg.data[6]);
	}
	
	return NULL;
}

bool dfu_response_check(uint8_t byte)
{
    return (BM_PROGRAM_ResponseCheck(&byte, 1));
}