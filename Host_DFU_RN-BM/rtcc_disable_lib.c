/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_disable_lib.c
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
 * Function:        int RtccDisable(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          TRUE if the RTCC was disabled,
 * 					FALSE otherwise
 *
 * Side Effects:    None
 *
 * Overview:        The function disables the RTCC.
 *
 * Note:            1. The write operations have to be enabled in order to be able to toggle the ON control bit.
 * 					Otherwise the function will fail.
 * 					See RtccWrEnable() function.
 * 					2. When ON control bit is set to 0, RTCCON.RTCSYNC, RTCCON.HALFSEC and
 * 					RTCCON.RTCOE are asynchronously reset.
 * 					- The function waits for the RTC clock to be off.
 *
 * Example:			RtccDisable();
 ********************************************************************/
int RtccDisable(void)
{
	int	res;
	if(RTCCONbits.ON)
	{
		if(RtccGetWrEnable())
		{
			_RtccStop();
			res=1;
		}
		else
		{
			res=0;
		}
	}
	else
	{
		_RtccWaitClockOff();	// make sure clock is stopped
		res=1;
	}

	return res;
}



