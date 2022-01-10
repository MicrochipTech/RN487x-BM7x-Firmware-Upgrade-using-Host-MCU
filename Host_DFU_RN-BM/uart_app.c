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
#include "uart_app.h"
#include "time.h"
#include "uart_drv.h"
#include "config.h"

#define DELAY_100MS 100


void UART_Init(void)
{
    // Initialize UART2
    uart_init(UART2_MODULE_ID);
    uart_open(UART2_MODULE_ID);

    // Initialize UART1
    uart_init(UART1_MODULE_ID);
    uart_open(UART1_MODULE_ID);
}

void UART_Write(unsigned short dev_id, unsigned char *buffer, unsigned long int size)
{
    uart_write(dev_id, buffer, size);
}

void UART_WriteByte(unsigned short dev_id, unsigned char *buffer)
{
    uart_write_byte(dev_id, buffer);
}

void UART_Read(unsigned short dev_id, unsigned char *buffer, uint16_t* pbuffer_index)
{
    uint16_t time_ms;
    // Read the response from BM7x and timeout if no response
    time_ms = TimeGet1ms()+DELAY_100MS;
    while(!TimeElapsed1ms(time_ms))
    {
        if(uart_read_byte(dev_id, &buffer[*pbuffer_index]))
            (*pbuffer_index)++;
    }
}

bool UART_ReadByte(unsigned short dev_id, unsigned char *buffer)
{
    return (uart_read_byte(dev_id, buffer));
}

void UART_Readl(unsigned short dev_id, unsigned char *buffer, uint16_t pbuffer_index)
{
    uart_read(dev_id, buffer,pbuffer_index);
}

void UART_Close()
{
    uart_close(UART1_MODULE_ID);
    uart_close(UART2_MODULE_ID);
}


void putch(char txData)
{
    UART_WriteByte(UART1_MODULE_ID, &txData);
}