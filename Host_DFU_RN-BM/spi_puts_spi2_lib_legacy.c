/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_puts_spi2_lib_legacy.c
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
#include <peripheral/legacy/spi_legacy.h>


#ifdef _SPI2
/*********************************************************************
 * Function:        void putsSPI2(unsigned int length, unsigned int *wrptr)
 *
 * PreCondition:    None
 * Input:           length	- length of bytes/words to be written
 * 					wrptr	- address of buffer storing the data to be transmitted.
 * Output:          None
 * Side Effects:    None
 * Overview:        This function writes the specified length of data words/bytes
 * 					from the specified buffer.
 * Note:            wrptr is considered to be 8/16/32 bits data pointer, according to the
 * 					current SPI mode!
 ********************************************************************/
void putsSPI2(unsigned int length, unsigned int *wrptr)
{
	unsigned char*			pBuff8=(unsigned char*)wrptr;
	__SPI2CONbits_t 		conBits;
	unsigned short*			pBuff16=(unsigned short*)wrptr;

	conBits.w=SPI2CONbits.w;

    while (length--)                   /* write byte/word until length is 0 */
    {
		while(TxBufFullSPI2());  /* wait until there's room in the buffer */
		if(conBits.MODE32)
		{
			SPI2BUF=*wrptr++;
		}
		else if(conBits.MODE16)
		{
			SPI2BUF=*pBuff16++;
		}
		else
		{
			SPI2BUF=*pBuff8++;
		}
    }
}
#endif	//_SPI2


