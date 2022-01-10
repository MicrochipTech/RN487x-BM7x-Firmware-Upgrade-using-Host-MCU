/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        _rtcc_clock_off_lib.c
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
#include <peripheral/timer.h>

#include "_rtcc_include.h"


// data definition
// NOTE: this is an attempt to deal with the fact that OSCCON.SOSCRDY bit is not dynamically updated.
// Once this functionality is in place, no need for this software approach

unsigned int	_RtccWaitClkStepSz=360;		// number of system ticks to wait for the RTCCLKON signal to disappear
											// dependent on the system frequency
											// if 0, no attempt to wait is made
											// default value is 10us for 72MHz
unsigned int	_RtccWaitClkSteps=7;		// number of times to wait for _RtccWaitClkStepSz
											// if 0, no attempt to wait is made
											// default value is 7 so max wait time is 7*10us=70 us.
											// normally it takes 2 32.768 KHz clocks i.e. ~61us


/*********************************************************************
 * Function:        rtccRes _RtccWaitClockOff(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          actual clock status
 * Side Effects:    None
 * Overview:        Helper to wait until RTCCON.RTCCLKON signal is cleared.
 * Note:            The function relies on the OSCCON.SOSCRDY bit functionality
 ********************************************************************/
rtccRes _RtccWaitClockOff(void)
{
	if(OSCCONbits.SOSCEN)
	{	// if the SOSC is off, we cannot use the SOSCRDY bit and there's no need to wait for RTCCCLKON
		unsigned int	nSteps=_RtccWaitClkSteps;

		while(nSteps--)
		{
			unsigned int t0, t1;

			if(!(OSCCONbits.SOSCRDY) || !(RTCCONbits.RTCCLKON))
			{ // if SOSC is just warming up, nothing much we can do; same if RTCC clock is stopped, we're done
				break;	// nothing much we can do
			}

			// at this point we don't really know if the RTCCLK didn't stop yet
			// or the SOSC clock just vanished. Note that SOSCRDY doesn't clear by itself
			// .... we have to wait
			t0=ReadCoreTimer();
			do
			{
				t1=ReadCoreTimer();
			}while((t1-t0)<_RtccWaitClkStepSz);
		}
	}

	return RtccGetClkStat();
}


/*********************************************************************
 * Function:        void _RtccSetClockWait(void)
 *
 * PreCondition:    None
 * Input:           wait step size in system ticks (system frequency dependent) and the number of steps.
 * Output:          None
 * Side Effects:    None
 * Overview:        Helper to deal with the fact that the OSCCON.SOSCRDY bit is not dynamically updated.
 * 					Once that functionality will be in place, no need for this software approach
 * Note:            It is a hidden interface function.
 ********************************************************************/
void _RtccSetClockWait(unsigned int wSysTicks, unsigned int nTimes)
{
	_RtccWaitClkStepSz=wSysTicks;
	_RtccWaitClkSteps=nTimes;
}


