/********************************************************************
 * FileName:		set_core_sw0_lib.c
 * Dependencies:
 * Processor:		PIC32
 * Hardware:		N/A
 * Assembler:		N/A
 * Linker:		    N/A
 * Company:		    Microchip Technology Inc.
 *
 * Software License Agreement:
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PICmicro� Microcontroller is intended and
 * supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * $Id: set_core_sw0_lib.c 3048 2007-04-19 16:33:08Z rajbhartin $
 * $Name:  $

 ********************************************************************/

#include <xc.h>
#include <peripheral/int.h>

/******************************************************************************
 * Function:        void SetCoreSW0(void)
 *
 * Description:		Sets a core software interrupt
 *
 * PreCondition:    None
 *
 * Inputs:			None
 *
 * Output:          Count value.
 *
 * Example:			SetCoreSW0()
 *
 *****************************************************************************/
void __attribute__((nomips16)) CoreSetSoftwareInterrupt0(void)
{
   unsigned int val;
   asm volatile("mfc0 %0,$13" : "=r" (val));
   val |= CORE_SW_0;
   asm volatile("mtc0 %0,$13" : "+r" (val));
}
