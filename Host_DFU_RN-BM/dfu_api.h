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
#ifndef _DFU_API_H_
#define _DFU_API_H_

#include "bm_program_mode.h"
#include "ble_api.h"

#define DFU_MAX_DATA_LENGTH 192

typedef enum
{
	//Success
	DFU_SUCCESS  = 0x00,
	DFU_FAIL
} dfu_status_t;

typedef enum
{
	DFU_WRITE_CONTINUE_START,
	DFU_WRITE_CONTINUE_PROCEED,
	DFU_WRITE_CONTINUE_STOP,
} dfu_write_continue_mode_t;

dfu_status_t dfu_init(platform_init_t *platform_init);
dfu_status_t dfu_deinit(void);
dfu_status_t dfu_program_memory_erase(uint32_t address, uint8_t length);
dfu_status_t dfu_program_memory_write(uint32_t address, uint8_t* data, uint8_t length, bool write_continue);
dfu_status_t dfu_program_memory_write_continue(uint32_t address, uint8_t* data, uint8_t length, uint8_t continue_mode, uint32_t continue_length);
dfu_status_t dfu_program_memory_read(uint32_t address, uint8_t* data, uint8_t length);
bool dfu_response_check(uint8_t byte);

#endif //_DFU_API_H_