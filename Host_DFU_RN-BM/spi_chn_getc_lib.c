/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_getc_lic.c
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
 * Function:        unsigned int SpiChnGetC(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:			chn			- the channel to check
 *
 * Output:          data available in the SPI rx buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function waits for data to be available and returns it.
 *
 * Note:            When a new data word has been shifted into shift register SPIxSR and 
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit (SPIxSTAT<6>) will be set.The 
 *                  module will not transfer the received data from SPIxSR to the SPIxRXB. 
 *                  Further data reception is disabled until the SPIROV bit is cleared. 
 *                  The SPIROV bit is not cleared automatically by the module and must be 
 *                  cleared by the user software.
 *
 ********************************************************************/
unsigned int SpiChnGetC(SpiChannel chn)
{
	volatile _SpiRegMap*	pReg=_SpiMapTbl[chn];

	while(!_SpiIsRxAvlbl(pReg));	// wait data ready
	return pReg->buf;	// return data in the buffer
}


/*********************************************************************
 * Function:        unsigned int SpiChnReadC(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to use
 *
 * Output:          data available in the SPI rx buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function returns immediately the data from the SPI buffer.
 *                  It does not check if there's any new data available.
 *
 * Note:            When a new data word has been shifted into shift register SPIxSR and:
 *                  - in standard mode: the previous contents of receive register SPIxRXB have not been read
 *                  - in FIFO mode: the FIFO is full
 *                  then the Rx Overflow (SPIROV) bit will be set.
 *                  The module will not transfer the received data from SPIxSR to the SPIxRXB (FIFO)
 *                  Further data reception is disabled until the SPIROV bit is cleared. 
 *                  The SPIROV bit is not cleared automatically by the module and must be 
 *                  cleared by the user software.
 *
 * Example:         unsigned int newData=SpiChnReadC(SPI_CHANNEL2);
 ********************************************************************/
unsigned int SpiChnReadC(SpiChannel chn)
{
	return _SpiMapTbl[chn]->buf;
}



#endif	// _SPI_DEF_CHN_


