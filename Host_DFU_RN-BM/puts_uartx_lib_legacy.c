/*********************************************************************
 *
 *                  UART lib routines
 *
 *********************************************************************
 * FileName:        puts_uartx_lib.c
 * Dependencies:	Generic.h
 * 					uart.h
 *
 * Processor:       PIC32
 *
 * Compiler:        C32 Compiler
 *
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * $Id$
 *
 ********************************************************************/
#include <xc.h>
#include <peripheral/uart.h>

/******************************************************************************
 * Function:        void putsUARTx(const char *buffer)
 *
 * Description:		Transmit a NULL transmitted string via UARTx
 *
 * PreCondition:    None
 *
 * Inputs:			buffer:		NULL terminated string to be transmitted
 *
 * Output:          None
 *
 * Example:			putsUART1(myString);
 *					putsUART1("Hello World!");
 *
 *****************************************************************************/
#if defined(_UART1)
void putsUART1(const char* buffer)
{
    /* transmit till NULL character is encountered */
	while(*buffer != '\0')
	{
		while( BusyUART1() );
		putcUART1(*buffer++);
	}
}

#endif

#if defined(_UART2)
void putsUART2(const char* buffer)
{
    /* transmit till NULL character is encountered */
	while(*buffer != '\0')
	{
		while( BusyUART2() );
		putcUART2(*buffer++);
	}
}
#endif

