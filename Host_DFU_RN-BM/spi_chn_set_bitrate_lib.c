/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_open_lib.c
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
#include <peripheral/ports.h>

#include "_spi_io_tbl.h"
#include "_spi_map_tbl.h"


/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_


/*********************************************************************
 * Function:        unsigned int SpiChnSetBitRate(SpiChannel chn, unsigned int srcClk, unsigned int spiClk)
 *
 * PreCondition:    srcClk/1024 <= spiClk <= srcClk/2;
 *                  chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set the bitrate for
 *                  srcClk - the SPI module Source Clock, Hz
 *                  spiClk - the desired SPI bitrate frequency, Hz
 *
 * Output:          the actual selected bitrate, Hz
 *
 * Side Effects:    None
 *
 * Overview:        This function configures the SPI channel with a desired bitrate.
 *                  The SPI bitrate is given by: spiClk=srcClk/(2*(SPIBRG+1))
 *                  The proper SPIBRG value is calculated as SPIBRG=(srcClk/spiClk)/2-1.
 *
 * Note:            - The channel has to be first configured with a valid bitrate and then enabled.
 *                  The bitrate can be changed dynamically, when no transaction is in progress.
 *                  - The bitrate is irrelevant for the Slave operation mode since the clock is provided externally, by the Master.
 *                  - For PIC32MX the srcClk is the peripheral bus clock.
 *
 ********************************************************************/
unsigned int	SpiChnSetBitRate(SpiChannel chn, unsigned int srcClk, unsigned int spiClk)
{
	unsigned int	clkDiv=srcClk/spiClk;
	
	_SpiMapTbl[chn]->brg=clkDiv/2-1;

	return srcClk/clkDiv;
}

#endif	// _SPI_DEF_CHN_


