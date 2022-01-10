/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_set_calibration_lib.c
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

#include "_rtcc_include.h"

/* Notes regarding the disabling/enabling of the interrupts in the implememntation of this API:
 * all operations that perform the read/write update of a 32 bit peripheral register are considered to
 * be atomic and generally the disabling of the interrupts is not required.
 * The disabling of the interrupts is performed just for un-interruptible hardware access sequences
 * that span over multiple instructions.
 * */


/*********************************************************************
 * Function:        void RtccSetCalibration(int drift)
 *
 * PreCondition:    drift has to fit into signed 10 bits representation
 * Input:           drift	- value to be added/subtracted to perform calibration
 * Output:          None
 * Side Effects:    None
 * Overview:        The function updates the value that the RTCC uses in the
 * 					auto-adjust feature, once every minute.
 * 					The drift value acts as a signed value, [-512, +511], 0 not having
 * 					any effect.
 * Note:            - Writes to the RTCCON.CAL[9:0] register should  only occur when the timer
 * 					is turned off or immediately or after the edge of the seconds pulse
 * 					(except when SECONDS=00 - due to the possibility of the auto-adjust event).
 * 					In order to speed-up the process, the API function performs the reading
 * 					of the HALFSEC field.
 * 					- The function may block for half a second, worst case, when called
 * 					at the start of the minute.
 * 					- A write to the SECONDS value resets the state of the calibration and the prescaler.
 * 					If calibration just occurred, it will occur again at the prescaler rollover.
 * 					- Interrupts can not be disabled for such a long period. However, long interrupt routines
 * 					can interfere with the proper functioning of the device. Care must be taken.
 ********************************************************************/
void RtccSetCalibration(int drift)
{
	unsigned int ulDrift=drift<<_RTCCON_CAL_POSITION;

	if(RTCCONbits.ON)
	{	// device is running
		unsigned int	t0, t1;
		do
		{
			t0=RTCTIME;
			t1=RTCTIME;
		}while(t0!=t1);		// read valid time value

		if((t0&(_RTCTIME_SEC01_MASK|_RTCTIME_SEC10_MASK))==00)
		{	// we're at second 00, wait auto-adjust to be performed
			while(!RtccGetHalfSecond());	// wait until second half...
		}
	}
	else
	{	// device is off
		_RtccWaitClockOff();	// make sure the clock is stopped
	}

	// update the CAL value
	RTCCONCLR=_RTCCON_CAL_MASK;
	RTCCONSET=ulDrift;

}




