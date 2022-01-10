/*********************************************************************
 *
 *                  UART lib routines
 *
 *********************************************************************
 * FileName:        gets_uartx_lib.c
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
 * Function:        unsigned int getsUART1(unsigned int length,
 *											char* buffer,
 *											unsigned int uart_data_wait);
 *
 * Description:		Checks to see if a data is ready is in UARTx
 *
 * PreCondition:    None
 *
 * Inputs:			None
 *
 * Output:          None
 *
 * Example:			DataRdyUART1();
 *
 *****************************************************************************/
#if defined(_UART1)
unsigned int getsUART1(unsigned int length, char* buffer, unsigned int uart_data_wait)
{
    int wait;

    wait = 0;
    while(length)                         /* read till length is 0 */
    {
        while(!DataRdyUART1())
        {
            if(wait < uart_data_wait)
                wait++ ;                  /*wait for more data */
            else
                return(length);           /*Time out- Return words/bytes to be read */
        }
        wait=0;

        *buffer++ = getcUART1();

        length--;
    }

    return(length);                       /* number of data yet to be received i.e.,0 */
}
#endif

#if defined(_UART2)
unsigned int getsUART2(unsigned int length, char* buffer, unsigned int uart_data_wait)
{
    int wait;

    wait = 0;
    while(length)                         /* read till length is 0 */
    {
        while(!DataRdyUART2())
        {
            if(wait < uart_data_wait)
                wait++ ;                  /*wait for more data */
            else
                return(length);           /*Time out- Return words/bytes to be read */
        }
        wait=0;

        *buffer++ = getcUART2();

        length--;
    }

    return(length);                       /* number of data yet to be received i.e.,0 */
}
#endif
