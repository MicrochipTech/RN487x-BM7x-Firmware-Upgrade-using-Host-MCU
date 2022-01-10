/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_enable_lib.c
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
 * Function:        rtccRes RtccEnable(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          RTCC_CLK_ON if the RTCC was enabled and the RTCC clock is running,
 * 					an error code otherwise
 *
 * Side Effects:    None
 *
 * Overview:        The function enables the RTCC.
 *
 * Note:            - The write operations have to be enabled in order to be able to toggle the ON control bit.
 * 					Otherwise the function will fail.
 * 					See RtccWrEnable() function.
 * 					- The function doesn't wait for the RTC clock to be on.
 *
 * Example:			RtccEnable();
 ********************************************************************/
rtccRes RtccEnable(void)
{
	rtccRes	res;

	if(RTCCONbits.ON)
	{
		res=RtccGetClkStat();
	}
	else if(RtccGetWrEnable())
	{
		RTCCONSET=_RTCCON_ON_MASK;
		res=RtccGetClkStat();
	}
	else
	{
		res=RTCC_WR_DSBL;
	}

	return res;

}


