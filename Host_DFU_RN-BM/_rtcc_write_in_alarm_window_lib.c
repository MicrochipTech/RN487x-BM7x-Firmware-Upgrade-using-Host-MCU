/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        _rtcc_write_in_alarm_window_lib.c
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
 * Function:        void _RtccWriteInAlarmWindow(volatile unsigned int* pR1, unsigned int v1, volatile unsigned int* pR2, unsigned int v2)
 *
 * PreCondition:    None
 *
 * Input:           pR1		- if non NULL, address of a register to update when it's safe to do so
 * 					v1		- value to be written at pR1
 * 					pR2		- if non NULL, address of a register to update when it's safe to do so
 * 					v2		- value to be written at pR2
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Helper to perform a write in a safe alarm window.
 *
 * Note:            Interrupts are disabled shortly when properly probing the ALRMSYNC is needed.
 ********************************************************************/
void  _RtccWriteInAlarmWindow(volatile unsigned int* pR1, unsigned int v1, volatile unsigned int* pR2, unsigned int v2)
{
	int	intLev=0;
	int	restoreInts=0;

	if(RTCCONbits.ON)
	{	// device is enabled, there's incoming clock, have to synchronize access
		restoreInts=1;

		while(1)
		{
			while(RTCALRMbits.ALRMSYNC);	// wait sync go away
			intLev=INTDisableInterrupts();
			if(!(RTCALRMbits.ALRMSYNC))
			{
				break;		// we're in the safe window
			}

			INTRestoreInterrupts(intLev);	// restore ints and continue waiting
		}
	}
	else
	{
		_RtccWaitClockOff();		// make sure the clock is not running
	}



	// safe to update values

	if(pR1)
	{
		*pR1=v1;
	}
	if(pR2)
	{
		*pR2=v2;
	}
	if(restoreInts)
	{
		INTRestoreInterrupts(intLev);
	}
}
