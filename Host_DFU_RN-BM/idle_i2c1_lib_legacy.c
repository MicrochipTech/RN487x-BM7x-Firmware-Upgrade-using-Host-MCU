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
*    Function Name:  IdleI2C1
*    Description:    This routine generates wait condition intil I2C
*                    bus is Idle.
*    Parameters:     void
*    Return Value:   void
*************************************************************************/


void IdleI2C1(void)
{
    /* Wait until I2C Bus is Inactive */
    while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN || I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
}

#endif

