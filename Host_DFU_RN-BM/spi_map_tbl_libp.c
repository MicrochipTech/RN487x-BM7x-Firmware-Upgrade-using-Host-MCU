/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * Filename:        spi_map_tbl_libp.c
 * Dependencies:    Spi.h
 *                  _SPIMapTbl.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB C Compiler for PIC32 MCUs
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

#include "_spi_map_tbl.h"

#ifdef _SPI_DEF_CHN_

volatile _SpiRegMap* const _SpiMapTbl[]=
{
	// NOTE: SPI channel number 0 is invalid. For legacy reasons, the first SPI channel is 1. 
	(_SpiRegMap*)0,
	
#if defined(_SPI1)
	(_SpiRegMap*)&SPI1CON,
#else
	(_SpiRegMap*)0,
#endif /* _SPI1 */

#if defined(_SPI2) 
		(_SpiRegMap*)&SPI2CON,
#else
	(_SpiRegMap*)0,
#endif /* _SPI2 */

#if defined(_SPI3)
	(_SpiRegMap*)&SPI3CON,
#else
	(_SpiRegMap*)0,
#endif /* _SPI3 */


#if defined(_SPI4)
	(_SpiRegMap*)&SPI4CON,
#else
	(_SpiRegMap*)0,
#endif /* _SPI4 */

	
};

#endif	// _SPI_DEF_CHN_

