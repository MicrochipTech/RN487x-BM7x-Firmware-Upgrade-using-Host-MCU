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
#ifndef _MEMORY_H_
#define _MEMORY_H_

#define EVENT_ID_START				0
#define EVENT_ID_SIZE				1
#define EVENT_DATA_LEN_HIGH_START	(EVENT_ID_START + EVENT_ID_SIZE)
#define EVENT_DATA_LEN_HIGH_SIZE	1
#define EVENT_DATA_LEN_LOW_START	(EVENT_DATA_LEN_HIGH_START + EVENT_DATA_LEN_HIGH_SIZE)
#define EVENT_DATA_LEN_LOW_SIZE		1

enum
{
	MEM_DEALLOC_SUCCESS,
	MEM_DEALLOC_FAILURE,
	MEM_INVALID_ADDRESS,
};

void mem_init(uint8_t *base_addr, uint32_t size);
void* mem_alloc(uint32_t size);
uint8_t mem_free(void *ptr, uint32_t size);

#endif //_MEMORY_H_
