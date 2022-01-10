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

/**************************************************************************
*    Function Name:  SlaveputsI2C2
*    Description:    This routine is used to write out a string to the
*                    I2C bus.If write collision occurs,-3 is sent.If
*                    string is written and null char reached, 0 is returned.
*    Parameters:     unsigned char * : wrptr
*    Return Value:   unsigned int
****************************************************************************/


unsigned int SlaveputsI2C2(unsigned char * wrptr)
{
    I2C2CONbits.STREN = 1;            /* SCL clock stretch enable bit */
    while(*wrptr)                /* transmit data until null char */
    {
        SlaveputcI2C2(*wrptr++);         /* Send a byte */
    	while(I2C2STATbits.TBF);         /* wait till the transmit buffer is clear */
        while(!IFS1bits.I2C2SIF);     /* Wait till the ACK from master is received */
    }
    return 0;                        /* null char was reached */
}

#endif

