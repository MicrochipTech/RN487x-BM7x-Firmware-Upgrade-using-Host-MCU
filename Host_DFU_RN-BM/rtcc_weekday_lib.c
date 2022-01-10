/*********************************************************************
 *
 *                  RTCC API implementation file
 *
 *********************************************************************
 * FileName:        rtcc_weekday_lib.c
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

// month table
static const int mnthTbl[]=
{	// Jan, Feb....to Dec
	0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 12
};


/*********************************************************************
 * Function:        int	RtccWeekDay(int year, int month, int day)
 *
 * PreCondition:    Date greater than 14 Sep 1752.
 * Input:           year	- year value
 * 					month	- month value, 1-12
 * 					day		- day value, 1-31
 * Output:          the week of the day, 0 for Sun, 1 for Mon and so on
 * Side Effects:    None
 * Overview:        The algorithm calculates the week of the day for new style
 * 					dates, beginning at 14 Sep 1752.
 * 					Based on an algorithm by Lewis Carroll.

 * Note:            None
 ********************************************************************/
int			RtccWeekDay(int year, int month, int day)
{
	int y=year%100;			// just the year, remove the century part

	int centItem=(3-((year/100)%4))*2;
	int yearItem=y/12+y%12+(y%12)/4;

	int wDay=centItem+yearItem+mnthTbl[month-1]+day;
	if(month==1 || month==2)
	{	// Jan Feb correction, if leap year
		if( (y!=0 && y%4==0) || year%400==0)
		{
			wDay--;
		}
	}

	return wDay%7;
}


