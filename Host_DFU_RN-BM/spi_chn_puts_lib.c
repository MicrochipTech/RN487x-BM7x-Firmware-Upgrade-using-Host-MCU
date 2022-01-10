/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_puts_lib.c
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
 * Function:        void SpiChnPutS(SpiChannel chn, unsigned int* pBuff, unsigned int nChars)
 *
 * PreCondition:    None
 *
 * Input:           chn		- the SPI channel
 * 					pBuff	- address of buffer storing the data to be transmitted.
 * 					nChars	- number of characters to be transmitted

 * Output:          None

 * Side Effects:    None

 * Overview:        This function writes the specified number of 8/16/32 bit characters
 * 					from the specified buffer.

 * Note:            pBuff is considered to be 8/16/32 bits data pointer, according to the
 * 					current SPI mode!
 ********************************************************************/
void SpiChnPutS(SpiChannel chn, unsigned int* pBuff, unsigned int nChars)
{
	__SPIxCONbits_t		conBits;
	unsigned char*		pBuff8=(unsigned char*)pBuff;
	unsigned short*		pBuff16=(unsigned short*)pBuff;
	volatile _SpiRegMap*	pReg=_SpiMapTbl[chn];

	conBits.w=pReg->con.w;

    while (nChars--)                 /* write byte/word until length is 0 */
    {
		while(!_SpiIsTxAvlbl(pReg));  /* wait until there's room in the buffer */
		if(conBits.MODE32)
		{
			pReg->buf=*pBuff++;
		}
		else if(conBits.MODE16)
		{
			pReg->buf=*pBuff16++;
		}
		else
		{
			pReg->buf=*pBuff8++;
		}
    }
}


#endif	// _SPI_DEF_CHN_


