/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_brg_tbl_lib_legacy.c
 * Dependencies:	Spi.h
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
 * $Id$
 * $Name$
 *
 ********************************************************************/

#include <peripheral/spi.h>

#ifdef _SPI_DEF_CHN_

/* table used to convert an old style prescaler value to a brg register value.
 * given the values SPRE (called S) and PPRE (called P) used for PIC24 devices, the BRG value for the
 * PIC32 can be calculated as follows:
 * For PIC24: bitrate=Fcy/[(8-S)*4exp(3-P)], with S within [0, 7] and P within [0, 3].
 * For PIC32: bitrate=Fcy/(2*(BRG+1))
 * Therefore: BRG=Fcy/(2*bitrate)-1=((8-S)*4exp(3-P))/2-1=(8-S)*2exp(5-2p)-1;
 * This is how this table is constructed, giving the corresponding BRG value for a given
 * S, P set from (0, 0) to (7, 3).
 * Truncation used where needed. For the last value in the table,
 * obtained for S=7 and P=3, the BRG=-0.5, 0 chosen.
 */

const int	_SpiBrgConvTbl[32]=
{
	255, 63, 15, 3,		// S=0, p=0-3
	223, 55, 13, 2,		// S=1, p=0-3
	191, 47, 11, 2,		// S=2, p=0-3
	159, 39, 9, 1,		// S=3, p=0-3
	127, 31, 7, 1,		// S=4, p=0-3
	95, 23, 5, 0,		// S=5, p=0-3
	63, 15, 3, 0,		// S=6, p=0-3
	31, 7, 1, 0			// S=7, p=0-3
};

#endif	// _SPI_DEF_CHN_


