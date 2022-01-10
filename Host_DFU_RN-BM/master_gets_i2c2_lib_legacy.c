/******************************************************************************
 *
 *                  I2C PERIPHERAL LIBRARY API
 *
 ******************************************************************************
 * FileName:        I2c Lib API
 * Dependencies:    See include below
 * Processor:       PIC32
 * Compiler:        MPLAB XC32
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
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
 * ****************************************************************************
 *
 * $Id: $
 *
 * $Name:  $
 *
 *****************************************************************************/

#include <xc.h>
#include <peripheral/i2c.h>

#ifdef _I2C2

/************************************************************************
*    Function Name:  MastergetsI2C2
*    Description:    This routine reads predetermined data string length
*                    from the I2C bus.
*    Parameters:     unsigned int    : length
*                    unsigned char * : rdptr
*    Return Value:   unsigned int
*************************************************************************/

unsigned int MastergetsI2C2(unsigned int length, unsigned char * rdptr, unsigned int i2c2_data_wait)
{
    int wait = 0;
    while(length)                    /* Receive the number of bytes specified by length */
    {
        I2C2CONbits.RCEN = 1;
        while(!DataRdyI2C2())
        {
            if(wait < i2c2_data_wait)
                wait++ ;
            else
            return(length);          /* Time out, return number of byte/word to be read */
        }
        wait = 0;
        *rdptr = I2C2RCV;             /* save byte received */
        rdptr++;
        length--;
        if(length == 0)              /* If last char, generate NACK sequence */
        {
            I2C2CONbits.ACKDT = 1;
            I2C2CONbits.ACKEN = 1;
        }
        else                         /* For other chars,generate ACK sequence */
        {
            I2C2CONbits.ACKDT = 0;
            I2C2CONbits.ACKEN = 1;
        }
            while(I2C2CONbits.ACKEN == 1);    /* Wait till ACK/NACK sequence is over */
    }
    return 0;    /* return status that number of bytes specified by length was received */
}

#endif
