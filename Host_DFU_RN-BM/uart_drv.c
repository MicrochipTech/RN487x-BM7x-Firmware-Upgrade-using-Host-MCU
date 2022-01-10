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

#include "uart_drv.h"
/** FUNCTIONS ******************************************************/

// UART Initialize
void uart_init(unsigned short module_id)
{

    UARTConfigure(module_id, (UART_ENABLE_PINS_TX_RX_ONLY));
    UARTSetFifoMode(module_id, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(module_id, (UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1));
    UARTSetDataRate(module_id, GetPeripheralClock(), GetUARTBaudrate());
    
    // Configure UART RX Interrupt
    INTEnable(INT_SOURCE_UART_RX(module_id), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(module_id), INT_PRIORITY_LEVEL_7);
    INTSetVectorSubPriority(INT_VECTOR_UART(module_id), INT_SUB_PRIORITY_LEVEL_0);

    // Enable multi-vector interrupts
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableInterrupts();
}

// UART Open
void uart_open(unsigned short module_id)
{
    UARTEnable(module_id, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}

// UART Close
void uart_close(unsigned short module_id)
{
    UARTEnable(module_id, UART_DISABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}

// UART Transmit
void uart_write(unsigned short module_id, unsigned char *buffer, unsigned long int size)
{
    while(size)
    {
        while(!UARTTransmitterIsReady(module_id));

        UARTSendDataByte(module_id, *buffer);

        buffer++;
        size--;
    }

    while(!UARTTransmissionHasCompleted(module_id));
}

// UART Transmit
bool uart_write_byte(unsigned short module_id, unsigned char *buffer)
{
    if(UARTTransmitterIsReady(module_id))
    {
        UARTSendDataByte(module_id, *buffer);
        while(!UARTTransmissionHasCompleted(module_id));
        return true;
    }
    return false;
}

// UART Receive
unsigned long int uart_read(unsigned short module_id, unsigned char *buffer, unsigned long int max_size)
{

    unsigned long int num_char;
    num_char = 0;

    while(num_char < max_size)
    {
        unsigned char character;

        while(!UARTReceivedDataIsAvailable(module_id));
        character = UARTGetDataByte(module_id);

        *buffer = character;
        if(character == '\n')
            break;
        
        num_char++;
        if(num_char >= BUFFER_LEN_MAX)
            break;

        buffer++;

    }

    return num_char;
}

// UART Receive
bool uart_read_byte(unsigned short module_id, unsigned char *buffer)
{
    if(UARTReceivedDataIsAvailable(module_id)){
        *buffer = UARTGetDataByte(module_id);
        return true;
    }
 return false;
}

void __attribute__((weak)) app_process_rxdata(unsigned short rx_data) 
{
}

extern void platform_process_rxdata(unsigned short rx_data);
extern void app_process_rxdata(unsigned short rx_data);
void uart_read_callback(unsigned short module_id, unsigned short rx_data)
{	 
	if(module_id == UART1_MODULE_ID)
        platform_process_rxdata(rx_data);
    else if(module_id == UART2_MODULE_ID)
        app_process_rxdata(rx_data);
}

// UART 2 interrupt handler, set at priority level 2
void __ISR(_UART1_VECTOR, IPL7SOFT) IntUart1Handler(void)
{
	// Is this an RX interrupt?
	if(IFS0bits.U1RXIF == 1 /*INTGetFlag(INT_SOURCE_UART_RX(UART1_MODULE_ID))*/)
	{
        unsigned short rx_data;
        // Clear the RX interrupt Flag
	    //INTClearFlag(INT_SOURCE_UART_RX(UART1_MODULE_ID));
        IFS0bits.U1RXIF = 0;
        
        //rx_data = UARTGetDataByte(UART1_MODULE_ID);
        rx_data = U1RXREG; //UARTGetDataByte(UART1_MODULE_ID);
        //uart_write_byte(UART2_MODULE_ID, &rx_data);
        uart_read_callback(UART1_MODULE_ID, rx_data);
	}

	// We don't care about TX interrupt
	//if ( INTGetFlag(INT_SOURCE_UART_TX(UART1_MODULE_ID)) )
	//{
    //        INTClearFlag(INT_SOURCE_UART_TX(UART1_MODULE_ID));
	//}
}

void __ISR(_UART2_VECTOR, IPL7SOFT) IntUart2Handler(void)
{
	// Is this an RX interrupt?
	if(IFS1bits.U2RXIF == 1 /*INTGetFlag(INT_SOURCE_UART_RX(UART2_MODULE_ID))*/)
	{
        unsigned short rx_data;
        // Clear the RX interrupt Flag
	    //INTClearFlag(INT_SOURCE_UART_RX(UART2_MODULE_ID));
		IFS1bits.U2RXIF = 0;
		
		rx_data = U2RXREG;
        uart_read_callback(UART2_MODULE_ID, rx_data);
	}

	// We don't care about TX interrupt
	//if ( INTGetFlag(INT_SOURCE_UART_TX(UART2_MODULE_ID)) )
	//{
    //        INTClearFlag(INT_SOURCE_UART_TX(UART2_MODULE_ID));
	//}
}