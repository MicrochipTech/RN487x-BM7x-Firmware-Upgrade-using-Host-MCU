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
/* 
   lock-free FIFO, used to receive data in ISR context,
   and process it in Main context
   for optimization size MUST be power of 2, ie 2, 4, 8, 16, 32, ...
*/
#include "fifo.h"
#include <stddef.h>
uint8_t fifo_init(fifo_t *const fifo, uint8_t *const buffer, const uint32_t size)
{
    // check buffer pointer, and buffer size
    // buffer size MUST be 2 to the power n
    if (NULL != fifo && size > 0 && (size & (size - 1)) == 0)
    {
        fifo->buffer = buffer;
        fifo->size = size;
        // valid indexes can be used to access array of size n is from 0 to n-1
        // mask used to get the valid index to access fifo buffer from wr_idx and rd_idx
        // for example size = 128 (dec) = 00000080 (hex) = 00000000000000000000000010000000 (bin)
        //             mask = 127 (dec) = 0000007F (hex) = 00000000000000000000000001111111 (bin)
        fifo->mask = size - 1;
        fifo->wr_idx = 0;
        fifo->rd_idx = 0;
        return 1;
    }
    return 0;
}
uint8_t fifo_empty(fifo_t *const fifo)
{
    return (fifo->wr_idx == fifo->rd_idx);
}
uint8_t fifo_full(fifo_t *const fifo)
{
    // fifo->wr_idx == fifo->rd_idx + fifo->size ?
    return ((fifo->wr_idx - fifo->rd_idx) == fifo->size);
}
uint8_t fifo_get(fifo_t *const fifo, uint8_t *const byte)
{
    if (!fifo_empty(fifo))
    {
        // get the valid index from rd_idx by masking current rd_idx with pre calculated mask
        // it will convert all bit to zeros except bits inside valid range of bits
        *byte = fifo->buffer[fifo->mask & fifo->rd_idx++];
        return 1;
    }
    return 0;
}
uint8_t fifo_put(fifo_t *const fifo, const uint8_t byte)
{
    if (!fifo_full(fifo))
    {
        // get the valid index from rd_idx by masking current wr_idx with pre calculated mask
        // it will convert all bit to zeros except bits inside valid range of bits
        fifo->buffer[fifo->mask & fifo->wr_idx++] = byte;
        return 1;
    }
    return 0;
}
