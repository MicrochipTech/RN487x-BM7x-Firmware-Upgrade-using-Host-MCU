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

/****************************************************************************
*    Function Name:  SlaveWriteI2C
*    Description:    This routine is used to write a byte to the I2C bus.
*                    The input parameter data_out is written to the
*                    I2CTRN register.
*    Parameters:     unsigned char : data_out
*    Return Value:   None
******************************************************************************/

void SlaveWriteI2C2(unsigned char data_out)
{
     I2C2TRN = data_out;      /* data transferred to I2C2TRN reg */
     I2C2CONbits.SCLREL = 1;    /* Release the clock */
}

#endif

