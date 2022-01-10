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
#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "memory.h"

uint8_t *mem_pool_base_addr;
uint32_t mem_pool_size;
uint32_t max_count;
int32_t head;
int32_t tail;

void mem_init(uint8_t *base_addr, uint32_t size)
{
	mem_pool_base_addr = base_addr;
	mem_pool_size = size;
	head = -1;
	tail = -1;
}

void* mem_alloc(uint32_t size)
{
	uint8_t *mem;
	
	if((head == -1) && (tail == -1))
	{
		if(size > (mem_pool_size))
		{
			return NULL;
		}
		head = 0;
	}
	else if((head % mem_pool_size == (tail + 1) % mem_pool_size) ||
	(size > ((mem_pool_size -  (tail + 1)) + head) % mem_pool_size))
	{
		return NULL;
	}
	
	mem = mem_pool_base_addr + tail + 1;
	tail = (tail + size) % mem_pool_size;
	
	return mem;
}

uint8_t mem_free(void *ptr, uint32_t size)
{
	
	/* Pointer should not be NULL */
	if(NULL != ptr)
	{
		/* Deallocation should be in the same order in which it is allocated */
		if(ptr == mem_pool_base_addr + head)
		{
			/* Find next head */
			head = (head + size) % mem_pool_size;
			if(head == (int32_t)((tail + 1) % mem_pool_size))
			{
				head = tail = -1;
			}
			
			return MEM_DEALLOC_SUCCESS;
		}
		
		return MEM_INVALID_ADDRESS;
	}
	return MEM_DEALLOC_FAILURE;
}
