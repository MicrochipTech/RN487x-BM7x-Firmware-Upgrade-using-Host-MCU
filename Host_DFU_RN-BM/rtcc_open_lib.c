/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_open_lib.c
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
 * Function:        rtccRes RtccOpen((unsigned long tm, unsigned long dt, int drift)
 *
 * PreCondition:    tm an unsigned long containing the fields of a valid rtccTime structure:
 * 						- sec:	BCD codification, 00-59
 * 						- min:  BCD codification, 00-59
 * 						- hour: BCD codification, 00-24
 * 			dt is an unsigned long conatining the valid fields of a rtccDate structure:
 * 						- wday:	BCD codification, 00-06
 * 						- mday: BCD codification, 01-31
 * 						- mon: BCD codification, 01-12
 * 						- year: BCD codification, 00-99
 * 			drift has to fit into signed 10 bits representation
 *
 * Input:           	tm - the time value to be set
 * 			dt - the date value to be set
 * 			drift	- value to be added/subtracted to perform calibration
 *
 * Output:          RTCC_CLK_ON if the RTCC clock is actually running
 * 					a clock status code otherwise
 *
 * Side Effects:    None
 *
 * Overview:        The function initializes the RTCC device. It starts the RTCC clock, sets the desired time and calibration
 * 					and enables the RTCC. Disables the Alarm and the OE and further RTCC writes.
 * 					Clears the alarm interrupt flag and disables the alarm interrupt.
 *
 * Note:            It usually takes 4x256 clock cycles (approx 31.2 ms) for the oscillator signal to be available
 * 					to the RTCC. The user must make sure that the clock is actually running using RtccGetClkStat()
 * 					before expecting the RTCC to count.
 *
 * Example:		rtccDate dt; dt.wday=05; dt.mday=0x28; dt.mon=0x2; dt.year=0;
 * 			rtccTime tm; tm.sec=0x15; tm.min=0x30; tm.hour=01;
 * 			rtccRes res=RtccOpen(tm.l, dt.l, 10);
 * 					or
 * 			rtccRes res=RtccOpen(0x01301500, 0x00022805, 10);
 ********************************************************************/
rtccRes RtccOpen(unsigned long tm, unsigned long dt, int drift)
{
	unsigned int ulDrift=drift<<_RTCCON_CAL_POSITION;

	INTEnable(INT_RTCC, INT_DISABLED);	// disable RTCC interrupts

	// be sure the SOSC is enabled, enable RTCC writes
	mSysUnlockOpLock((OSCCONSET=_OSCCON_SOSCEN_MASK, RTCCONSET=_RTCCON_RTCWREN_MASK));

	_RtccStop();

	RTCALRMCLR=_RTCALRM_ALRMEN_MASK;// disable the alarm
	INTClearFlag(INT_RTCC);		// clear the interrupt flag

	RTCTIME=tm;
	RTCDATE=dt;

	RTCCONCLR=_RTCCON_CAL_MASK;
	RTCCONSET=ulDrift;

	RTCCONSET=_RTCCON_ON_MASK;

	RtccWrEnable(0);
	RtccOutputEnable(0);


	return RtccGetClkStat();
}


