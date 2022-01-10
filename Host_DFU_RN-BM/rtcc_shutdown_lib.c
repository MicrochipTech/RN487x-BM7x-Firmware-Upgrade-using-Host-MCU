/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_shutdown_lib.c
 * Dependencies:	Rtcc.h
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
 * Function:        void RtccShutdown(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        The function shutdowns the RTCC device. It stops the RTCC clock,
 * 					sets the RTCC Off and disables RTCC write. Disables the Alarm and the OE.
 * 					Clears the alarm interrupt flag and disables the alarm interrupt.
 * Note:            None
 ********************************************************************/
void RtccShutdown(void)
{
	INTEnable(INT_RTCC, INT_DISABLED);	// disable RTCC interrupts

	// disable the SOSC, disable RTCC writes
	mSysUnlockOpLock((OSCCONCLR=_OSCCON_SOSCEN_MASK, RTCCONSET=_RTCCON_RTCWREN_MASK));

	_RtccStop();			// make sure RTCC clock is stopped

	RTCALRMCLR=_RTCALRM_ALRMEN_MASK;		// disable the alarm
	INTClearFlag(INT_RTCC);		// clear the interrupt flag

	RtccWrEnable(0);
	RtccOutputEnable(0);
}


