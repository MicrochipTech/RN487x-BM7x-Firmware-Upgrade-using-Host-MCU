/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        RtccSetTimerLib.c
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
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * $Id: PIC32RTCCLib.c,v 1.8 2007/01/16 20:31:29 C12878 Exp $
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
 * Function:        void RtccSetTime(unsigned long tm)
 *
 * PreCondition:    tm a valid rtccTime structure having proper values:
 * 						- sec:	BCD codification, 00-59
 * 						- min:  BCD codification, 00-59
 * 						- hour: BCD codification, 00-24
 * Input:           tm - an unsigned long rtccTime union
 *
 * Output:          None
 * Side Effects:    None
 * Overview:        The function sets the current time in the RTCC device.
 * Note:            - The write is successful only if Wr Enable is set.
 * 					The function will enable the write itself, if needed.
 * 					- The device could be stopped in order
 * 					to safely perform the update of the RTC time register.
 * 					However, the device status will be restored but	the routine won't wait
 * 					for the CLK to be running before returning. User has to check RtccGetClkOn() (will take approx 30us).
 * 					- The routine could disable the interrupts for a very short time to be able
 * 					to update the time and date registers.
 ********************************************************************/
void RtccSetTime(unsigned long tm)
{
	_RtccSetTimeAndDate((rtccTime*)&tm, 0);
}

