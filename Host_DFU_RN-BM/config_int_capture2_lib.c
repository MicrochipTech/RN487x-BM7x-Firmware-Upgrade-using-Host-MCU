/*********************************************************************
 *
 *                  ICAP LIB Functions
 *
 *********************************************************************
 * FileName:        input capture lib functions
 * Dependencies:	None
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement:
 *
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
 *
 * $Id $
 * $Name $
 *
 ********************************************************************/

#include <xc.h>
#include <peripheral/incap.h>


/********************************************************************
*    Function Name:  ConfigIntCapture2                              *
*    Description:    Set the Enable Interrupts and Interrupt        *
*                    Priorites  to the Interrupt Control and        *
*                    Interrupt Priority Register respectively       *
*    Parameters:     unsigned int config                            *
*    Return Value:   None                                           *
********************************************************************/
void ConfigIntCapture2(unsigned int config)
{
	mIC2ClearIntFlag();
	mIC2SetIntPriority( config & 0x0007 );
	mIC2IntEnable((config>>3)&1);
}

