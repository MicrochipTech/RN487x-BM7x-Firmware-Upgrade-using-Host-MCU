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
#ifndef _EVENT_MEM_H_
#define _EVENT_MEM_H_



typedef enum
{
	BLE_EVENT_SUCCESS,
	BLE_EVENT_Q_OVERFLOW,
	BLE_EVENT_Q_EMPTY,
	BLE_EVENT_Q_INSUFFICIENT_MEMORY,
}event_status_t;

typedef struct
{
	uint8_t *data;
	uint32_t data_len;
}event_msg_t;

typedef struct
{
	event_msg_t event_msg;
	uint8_t event_id;
}event_t;

typedef struct _event_fifo_t
{
	uint16_t head;
	uint16_t tail;
    bool     wrap_flag;
	uint16_t size;
	event_t* buffer;
} event_fifo_t;

bool event_fifo_init(event_t* event_mem, uint16_t event_mem_size);
bool event_fifo_empty(void);
bool event_fifo_full(void);
event_status_t event_fifo_write(event_t *event);
event_status_t event_fifo_read(event_t* event);
event_status_t ble_event_get(event_t *event_param);

#endif //_EVENT_MEM_H_
