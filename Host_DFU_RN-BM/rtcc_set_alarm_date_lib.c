/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_set_alarm_date_lib.c
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
 * Function:        void RtccSetAlarmDate(unsigned long dt)
 *
 * PreCondition:    dt a valid rtccDate having proper values:
 * 						- wday:	BCD codification, 00-06
 * 						- mday: BCD codification, 01-31
 * 						- mon: BCD codification, 01-12
 *
 * Input:           dt - the alarm date to be set
 *
 * Output:          None
 * Side Effects:    None
 * Overview:        The function sets the alarm date in the RTCC device.
 *
 * Note:            - The function might wait for the proper Alarm window
 * 					to safely perform the update of the ALRMDATE register.
 * 					- Interrupts are disabled shortly when properly probing the RTCSYNC/ALRMSYNC needed.
 * 					- Note that the alarm time does not contain a year field.
 ********************************************************************/
void RtccSetAlarmDate(unsigned long dt)
{
	_RtccSetAlrmTimeAndDate(0, (rtccDate*)&dt);
}

