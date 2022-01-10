/*********************************************************************
 *
 *                  isWU lib function
 *
 *********************************************************************
 * FileName:        reset_iswu_lib.c
 * Dependencies:
 *
 * Processor:       PIC32MX
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32MX Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32MX Microcontroller products.
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
#include <xc.h>
#include <peripheral/reset.h>

/******************************************************************************
 * Check status of wakeup event
 *
 * Function:        isWU()
 *
 * Description:		Checks if wakeup from sleep was caused by MCLR, POR or BOR
 *					or interrupt
 *
 * PreCondition:    None
 *
 * Inputs:			none
 *
 * Output:          Return codes:	0= no wake from sleep
 *									1 = wake from sleep due to interrupt
 *									2 = wake from sleep due to MCLR
 *									4 = wake from sleep due to BOR
 *
 * Example:			isWU();
 *
 *****************************************************************************/
char isWU(void)
{
   if( RCONbits.SLEEP )
   {
       if(RCONbits.EXTR)
       {
           return 2;        /* wakeup is due to MCLR */
       }

       if(RCONbits.BOR)
       {
           return 4;        /* wakeup is due to BOR */
       }
       else
           return 1;        /* else, wakeup is due to interrupt. */
   }
  return 0;
}
