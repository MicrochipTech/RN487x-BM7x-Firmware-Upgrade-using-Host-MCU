/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        _rtcc_include.h
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

#ifndef __RTCCINCLUDE_H_
#define	__RTCCINCLUDE_H_


#include <peripheral/rtcc.h>
#include <peripheral/lock.h>
#include <peripheral/int.h>


// definitions of private RTCC functions
extern void	 	_RtccWriteInAlarmWindow(volatile unsigned int* pR1, unsigned int v1, volatile unsigned int* pR2, unsigned int v2);
extern void		_RtccSetTimeAndDate(const rtccTime* pTm, const rtccDate* pTD);
extern void		_RtccSetAlrmTimeAndDate(const rtccTime* pTm, const rtccDate* pDt);
extern rtccRes	_RtccWaitClockOff(void);


// private RTCC API inline functions.


/*********************************************************************
 * Function:        __inline__ void _RtccWaitSync(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Inline helper to wait until RTCCON.RTCSYNC signals read/write is safe.
 * Note:            In order to be sure that the write/read op is safe, interrupts should be disabled
 * 					or kept very short (worst case scenario, sync can be asserted for 32 RTCC clocks,
 * 					i.e. almost 1ms, so it's not advisable to disable the interrupts for such a long period
 * 					of time. Care must be taken under these circumstances).
 ********************************************************************/
static __inline__ void __attribute__((always_inline)) _RtccWaitSync(void)
{
	while(RtccGetSync());
}

/*********************************************************************
 * Function:        __inline__ void _RtccWaitAlrmSync(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Inline helper to wait until RTCALRM.ALRMSYNC signals read/write is safe.
 * Note:            In order to be sure that the write/read op is safe, interrupts should be disabled
 * 					or kept very short (worst case scenario, sync can be asserted for 32 RTCC clocks,
 * 					i.e. almost 1ms, so it's not advisable to disable the interrupts for such a long period
 * 					of time. Care must be taken under these circumstances).
 ********************************************************************/
static __inline__ void __attribute__((always_inline)) _RtccWaitAlrmSync(void)
{
	while(RtccGetAlrmSync());
}


/*********************************************************************
 * Function:        __inline__ void _RtccStop(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Inline helper to stop the module. Waits for the clock to be actually stopped.
 * Note:            The function relies on the OSCCON.SOSCRDY bit functionality
 ********************************************************************/
static __inline__ void __attribute__((always_inline)) _RtccStop(void)
{
	RTCCONCLR=_RTCCON_ON_MASK;	// stop the module
	_RtccWaitClockOff();
}



#endif	// __RTCCINCLUDE_H_

