/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_tx_buff_count_lib.c
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
 * Function:        int SpiChnTxBuffCount(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to check
 *
 * Output:          the number of characters available in the TX buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the number of characters in the SPI channel TX Buffer.
 *
 * Note:            Valid only in enhanced buffer (FIFO) mode.
 *
 * Example:         int nCharsToTx=SpiChnTxBuffCount(SPI_CHANNEL1);
 ********************************************************************/
int SpiChnTxBuffCount(SpiChannel chn)
{
	return _SpiMapTbl[chn]->stat.TXBUFELM;
}

#endif	// _SPI_REV_5XX_

#endif	// _SPI_DEF_CHN_


