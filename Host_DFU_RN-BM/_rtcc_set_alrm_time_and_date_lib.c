/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        _rtcc_set_alrm_time_and_date_lib.c
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
 * Function:        void _RtccSetAlrmTimeAndDate(const rtccTime* pTm, const rtccDate* pDt)
 *
 * PreCondition:    rtccTime and rtccDate structure fields have to have proper values:
 * 						- sec:	BCD codification, 00-59
 * 						- min:  BCD codification, 00-59
 * 						- hour: BCD codification, 00-24
 * 						- wday:	BCD codification, 00-06
 * 						- mday: BCD codification, 01-31
 * 						- mon: BCD codification, 01-12
 * Input:           pTm - pointer to a constant rtccTime union
 * 					pTd	- pointer to a constant rtccDate union
 * Output:          None
 * Side Effects:    None
 *
 * Overview:        The function sets the current time and date in the RTCC device.
 *
 * Note:            - The function might wait for the proper Alarm window
 * 					to safely perform the update of the ALRMTIME register.
 * 					- Interrupts are disabled shortly when properly probing the RTCSYNC/ALRMSYNC needed.
 ********************************************************************/
void _RtccSetAlrmTimeAndDate(const rtccTime* pTm, const rtccDate* pDt)
{
	unsigned int			v1, v2;
	volatile unsigned int	*pR1, *pR2;

	if(pTm)
	{
		v1=pTm->l;
		pR1=&ALRMTIME;
	}
	else
	{
		v1=0;
		pR1=0;
	}
	
	if(pDt)
	{
		v2=pDt->l;
		pR2=&ALRMDATE;
	}
	else
	{
		v2=0;
		pR2=0;
	}

	_RtccWriteInAlarmWindow(pR1, v1, pR2, v2);
}



