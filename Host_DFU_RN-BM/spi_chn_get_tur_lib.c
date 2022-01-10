/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_get_tur_lib.c
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

#include "_spi_map_tbl.h"


/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_

#ifdef _SPI_REV_5XX_


/*********************************************************************
 * Function:        int SpiChnGetTur(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the channel to check
 *
 * Output:          TRUE  - if channel is transmit underrun occurred
 *                  FALSE - otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel transmit underrun condition.
 *                  This condition can occur only in framed mode when there's more than 1 characters per frame.
 *                  If the SPI channel has to transmit another character for the current frame and the character is not available,
 *                  a TX underrun condition occurs.
 *
 * Note:            The Tx Underrun condition must be cleared by disabling /re-enabling the Spi channel.
 *                  No transmission can further occur once this condition is set.
 *
 * Example:         int isUnderrun=SpiChnGetTur(SPI_CHANNEL1);
 ********************************************************************/
int SpiChnGetTur(SpiChannel chn)
{
	return _SpiMapTbl[chn]->stat.SPITUR;
}

#endif	// _SPI_REV_5XX_

#endif	// _SPI_DEF_CHN_


