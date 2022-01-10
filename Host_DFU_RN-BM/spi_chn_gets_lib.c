/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_gets_lib.c
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
 * Function:        void SpiChnGetS(SpiChannel chn, unsigned int *pBuff, unsigned int nChars)
 *
 * PreCondition:    pBuff has to be a valid pointer to a buffer large enough to store all the received characters
 *
 * Input:			chn				- the SPI channel
 * 		           pBuff			- address of buffer to store data
 * 					nChars			- number of characters expected expected
 *
 * Output:          None

 * Side Effects:    None
 *
 * Overview:        This routine reads a buffer from the SPI receive buffer.
 * 					The number of byte/hword/word to be read is determined by parameter 'length'.
 *
 * Note:            - pBuff is considered to be 8/16/32 bits data pointer, according to the
 * 					current SPI mode!
 * 					- The function blocks waiting for the whole buffer to be received.
 *
 *                  When a new data word has been shifted into shift register SPIxSR and 
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit (SPIxSTAT<6>) will be set.The 
 *                  module will not transfer the received data from SPIxSR to the SPIxRXB. 
 *                  Further data reception is disabled until the SPIROV bit is cleared. 
 *                  The SPIROV bit is not cleared automatically by the module and must be 
 *                  cleared by the user software.
 ********************************************************************/
void SpiChnGetS(SpiChannel chn, unsigned int *pBuff, unsigned int nChars)
{
	unsigned int		rxData;
	__SPIxCONbits_t 			conBits;
	unsigned char*				pBuff8=(unsigned char*)pBuff;
	unsigned short*				pBuff16=(unsigned short*)pBuff;
	volatile _SpiRegMap*	pReg=_SpiMapTbl[chn];

	conBits.w=pReg->con.w;

	while (nChars--)
	{
		while(!_SpiIsRxAvlbl(pReg));	// wait data ready

		rxData=pReg->buf;
		if(conBits.MODE32)
		{
			*pBuff++=rxData;			// 32 bits
		}
		else if(conBits.MODE16)
		{
			*pBuff16++=(unsigned short)rxData;	// 16 bits
		}
		else
		{
			*pBuff8++=(unsigned char)rxData;		// 8 bits
		}
    }
}



#endif	// _SPI_DEF_CHN_


