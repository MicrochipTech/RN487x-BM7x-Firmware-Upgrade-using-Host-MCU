/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_init_lib.c
 * Dependencies:	Rtcc.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE Vxx
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
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
 * $Id:$
 * $Name:  $
 *
 ********************************************************************/


#include <peripheral/rtcc.h>
#include <peripheral/lock.h>


#include "_rtcc_include.h"

/* Notes regarding the disabling/enabling of the interrupts in the implememntation of this API:
 * all operations that perform the read/write update of a 32 bit peripheral register are considered to
 * be atomic and generally the disabling of the interrupts is not required.
 * The disabling of the interrupts is performed just for un-interruptible hardware access sequences
 * that span over multiple instructions.
 * */


/*********************************************************************
 * Function:        rtccRes RtccInit(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          RTCC_CLK_ON if the RTCC clock is actually running
 * 					an error code otherwise
 * Side Effects:    None
 * Overview:        The function initializes the RTCC device. It enables the RTCC clock,
 * 					enables the RTCC and disables RTCC write. Disables the Alarm and the OE.
 * 					Clears the alarm interrupt flag and disables the alarm interrupt.
 * Note:            It usually takes 256 clock cycles (approx 7.8 ms) for the oscillator signal to be available
 * 					to the RTCC. The user must make sure that the clock is actually running using RtccGetClkOn()
 * 					before expecting the RTCC to count.
 ********************************************************************/
rtccRes RtccInit(void)
{
	INTEnable(INT_RTCC, INT_DISABLED);	// disable RTCC interrupts

	// be sure the SOSC is enabled, enable RTCC writes
	mSysUnlockOpLock((OSCCONSET=_OSCCON_SOSCEN_MASK, RTCCONSET=_RTCCON_RTCWREN_MASK));

	_RtccStop();

	RTCALRMCLR=_RTCALRM_ALRMEN_MASK;// disable the alarm
	INTClearFlag(INT_RTCC);		// clear the interrupt flag

	RTCCONSET=_RTCCON_ON_MASK;

	RtccWrEnable(0);
	RtccOutputEnable(0);


	return RtccGetClkStat();
}


