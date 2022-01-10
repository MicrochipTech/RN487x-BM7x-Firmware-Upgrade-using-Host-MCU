/*********************************************************************
 *
 *                  SoftReset lib function
 *
 *********************************************************************
 * Filename:        soft_reset_lib.c
 * Dependencies:
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB C Compiler for PIC32 MCUs
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
#include <xc.h>
#include <peripheral/lock.h>

/******************************************************************************
 * Function:        	void SoftReset(void)
 *
 * Description:			software device reset
 *
 * PreCondition:    	None
 *
 * Inputs:				None
 *
 * Output:				None
 *
 * Example:				SoftReset();
 *
 * How it works:		The following steps are performed by this function:
 *						Step 1 - Execute "unlock" sequence to access the RSWRST register.
 *						Step 2 - Write a '1' to RSWRST.SWRST bit to arm the software reset.
 *						Step 3 - A Read of the RSWRST register must follow the write.  This
 *						action triggers the software reset, which should occur on the next
 *						clock cycle.
 * Note:				The read instruction must be following with either 4 nop
 *						instructions (fills the instruction pipe) or a while(1)loop to
 *						ensure no instructions can access the bus before reset occurs.
 *****************************************************************************/
 void __attribute__((noreturn)) SoftReset(void)
{
	int	intStat;
	int	dmaSusp;
	volatile int* p = &RSWRST;

	mSYSTEMUnlock(intStat, dmaSusp);
	RSWRSTSET=_RSWRST_SWRST_MASK;
	*p;

	while(1);

}
