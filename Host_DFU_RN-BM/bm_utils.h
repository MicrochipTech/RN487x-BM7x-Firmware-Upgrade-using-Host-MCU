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

#ifndef _BM_UTILS_H_
#define _BM_UTILS_H_

#include "stdint.h"

uint8_t set_to_upper(uint8_t lower);
uint8_t get_hex_byte(uint8_t * str, uint8_t * val);
uint8_t get_hex(uint8_t * str, uint16_t * val);
uint8_t get_hex_24bit(uint8_t * str, uint32_t * val);
uint8_t get_hex_dword(uint8_t * str, uint32_t * val);
uint8_t get_hex_bdaddrs(uint8_t * str, uint64_t * val);
uint8_t get_hex_long(uint8_t * str, uint64_t * val);

void format_hex_byte(uint8_t * str, uint8_t val);
void format_hex_byte2(uint8_t * str, uint8_t val);
void format_hex(uint8_t * str, uint16_t val);
void format_hex_24bit(uint8_t * str, uint32_t val);
void format_hex_dword(uint8_t * str, uint32_t val);
void format_hex_bdaddrs(uint8_t * str, uint64_t val);
void format_hex_bdaddrs2(uint8_t * str, uint8_t* val);
void format_hex_long(uint8_t * str, uint64_t val);

void memcpy_ascii_reorder(uint8_t* a, uint8_t* b, int len);
void memcpy_ascii_order(uint8_t* a, uint8_t* b, int len);
void memcpy_reorder(uint8_t* a, uint8_t* b, int len);
void memcpy_nibble_reorder(uint8_t* a, uint8_t* b, int len);
uint8_t* memcpy_inplace_reorder(uint8_t* data, uint16_t len);
uint8_t* memcpy_nibble_inplace_reorder(uint8_t* data, uint16_t len);

uint8_t calc_chksum_8bit(uint8_t* data, uint16_t length);
#endif
