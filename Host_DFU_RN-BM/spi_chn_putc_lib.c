/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_putc_lib.c
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


/*********************************************************************
 * Function:        void SpiChnPutC(SpiChannel chn, unsigned int data)
 *
 * PreCondition:    None
 *
 * Input:			chn			- the channel to check
 * 					data	- the data to be written to the port
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine writes a single byte/half word/word to the SPI bus.
 * 					It waits so that it doesn't overwrite the previous untransmitted data.
 *
 * Note:            byte/hword/word accesses will perform correctly.
 *
 ********************************************************************/
void SpiChnPutC(SpiChannel chn, unsigned int data)
{
	volatile _SpiRegMap*	pReg=_SpiMapTbl[chn];
    
    while(!_SpiIsTxAvlbl(pReg));	// wait tx buff not full     
    pReg->buf=data;			// write data to the buffer
       
}


/*********************************************************************
 * Function:        void SpiChnWriteC(SpiChannel chn, unsigned int data)
 *
 * PreCondition:    None
 *
 * Input:           chn  - the channel to use
 *                  data - the data to be written to the port
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine writes inmmediately a character (byte/half word/word) to the SPI buffer register.
 *
 * Note:            byte/hword/word accesses will perform correctly.
 *
 * Example:         SpiChnWriteC(SPI_CHANNEL1, 0x1b);		// send an ESC character
 ********************************************************************/
void SpiChnWriteC(SpiChannel chn, unsigned int data)
{
	_SpiMapTbl[chn]->buf=data;
}


/*********************************************************************
 * Function:        volatile void* SpiChnBuffer(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the required channel
 *
 * Output:          the address of the SPI buffer associated to the selected channel.
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the address of the SPI channel buffer.
 *
 * Note:            The same address is valid for both read and write operations.
 *
 *                  The function is useful when the corresponding SPI channel
 *                  has to be used as the source or destination of a DMA transfer.
 *
 * Example:         volatile unsigned short* spiBuffAdd=(unsigned short*)SpiChnBuffer(SPI_CHANNEL1);
 ********************************************************************/
volatile void* SpiChnBuffer(SpiChannel chn)
{
    return &_SpiMapTbl[chn]->buf;
}



#endif	// _SPI_DEF_CHN_


