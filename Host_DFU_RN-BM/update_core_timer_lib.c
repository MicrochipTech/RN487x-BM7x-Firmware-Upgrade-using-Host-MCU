/*********************************************************************
 *
 *                  UpdateCoreTimer lib function
 *
 *********************************************************************
 * FileName:        update_core_timer_lib.c
 * Dependencies:
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32MX Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip Microcontroller products.
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
 *
 * $Id$
 *
 ********************************************************************/
/* This module is built for the generic library in addition to the 
   device-specific libraries. */
#ifndef __32MXGENERIC__
#define __32MXGENERIC__
#endif
#include <xc.h>
#include <peripheral/timer.h>

/*********************************************************************
 * Core Timer
 *
 * Function:        void UpdateCoreTimer(unsigned int period)
 *
 * PreCondition:    None
 *
 * Inputs:			period - 32 bit value for the timer
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
void __attribute__((nomips16)) UpdateCoreTimer(unsigned int period)
{
    unsigned int old_period;

    // get the old compare time
    asm volatile("mfc0   %0, $11" : "=r"(old_period));
    period += old_period;
    // set up the period in the compare reg
    asm volatile("mtc0   %0,$11" : "+r"(period));
}
