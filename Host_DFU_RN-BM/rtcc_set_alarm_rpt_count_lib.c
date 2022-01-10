/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_set_alarm_rpt_count_lib.c
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

#include "_rtcc_include.h"

/* Notes regarding the disabling/enabling of the interrupts in the implememntation of this API:
 * all operations that perform the read/write update of a 32 bit peripheral register are considered to
 * be atomic and generally the disabling of the interrupts is not required.
 * The disabling of the interrupts is performed just for un-interruptible hardware access sequences
 * that span over multiple instructions.
 * */


/*********************************************************************
 * Function:        void RtccSetAlarmRptCount(int rptCnt)
 *
 * PreCondition:    rptCnt has to be a value less then 256
 * Input:           rpt 		- value of the desired alarm repeat rate
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function sets the RTCC alarm repeat count.
 * 					The number of alarm triggers will be rptCnt+1:
 * 						- one alarm trigger if rptCnt==0
 * 						- ....
 * 						- 256 alarm triggers if rptCnt=255
 *
 * Note:            - rptCnt will be truncated to fit into 8 bit representation.
 * 		            - The function might wait for the proper Alarm window
 * 					to safely perform the update of the RTCALRM register.
 * 					- Interrupts are disabled shortly when properly probing the RTCSYNC/ALRMSYNC needed.
 ********************************************************************/
void RtccSetAlarmRptCount(int rptCnt)
{
	_RtccWriteInAlarmWindow(&RTCALRMCLR, _RTCALRM_ARPT_MASK, &RTCALRMSET, rptCnt&0xff);
}


