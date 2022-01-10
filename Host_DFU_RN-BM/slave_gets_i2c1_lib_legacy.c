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

#ifdef _I2C1

/************************************************************************
*    Function Name:  SlavegetsI2C1
*    Description:    This routine reads bytes from the I2C bus until
*                    stop bit is received.
*    Parameters:     unsigned char * : rdptr
*                    unsigned int    : i2c_data_wait
*    Return Value:   unsigned int    : number of bytes received
*************************************************************************/

unsigned int SlavegetsI2C1(unsigned char * rdptr, unsigned int i2c1_data_wait)
{
    int i = 0;                          /* i indicates number of bytes received */
    int wait = 0;
    unsigned char temp = I2C1RCV;        /* flush out old data already on I2CRCV to clear RBF flag */

    I2C1STATbits.I2COV = 0;              /* clear OV flag */

    while(!I2C1STATbits.P)               /* check for stop bit */
    {
        while(!DataRdyI2C1())
        {
            if(wait < i2c1_data_wait)    /* timeout check */
                wait++ ;
            else
                return i;               /* return the number of bytes received */
        }
        wait = 0;
        *rdptr++ = I2C1RCV;              /* save byte received */

        i++;                            /* Increment the number of bytes read */

        I2C1CONbits.ACKDT = 0;      /* generate ACK sequence */
        I2C1CONbits.ACKEN = 1;
        while(I2C1CONbits.ACKEN == 1);  /* Wait till ACK sequence is over */

        if((I2C1CONbits.STREN) && (!I2C1CONbits.SCLREL))
            I2C1CONbits.SCLREL = 1; /* Clock is released after ACK */

    }
    return i;               /* return the number of bytes received */
}

#endif

