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

/***********************************************************************
*    Function Name:  MasterputsI2C1
*    Description:    This routine is used to write out a string to the
*                    I2C bus.If write collision occurs,-3 is sent.If
*                    Nack is received, -2 is sent.If string is written
*                    and null char reached, 0 is returned.
*    Parameters:     unsigned char * : wrptr
*    Return Value:   char
************************************************************************/

unsigned int MasterputsI2C1(unsigned char * wrptr)
{
    while(*wrptr)                           //transmit data until null char
    {
        if(MasterputcI2C1(*wrptr) == -1)        // write a byte
        return -3;                          //return with write collison error

        while(I2C1STATbits.TBF);             //Wait till data is transmitted.

        IdleI2C1();
        wrptr++;
    }
    return 0;
}

#endif
