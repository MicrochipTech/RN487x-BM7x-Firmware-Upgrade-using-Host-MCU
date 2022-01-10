/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_gets_spi1_lib_legacy.c
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


#ifdef _SPI1
/*********************************************************************
 * Function:        unsigned int getsSPI1(unsigned int length, unsigned int *rdptr,
 * 											unsigned int spi_data_wait)
 *
 * PreCondition:    None
 * Input:           length			- The length of data expected
 * 					rdptr			- the received data to be recorded to this array
 * 					spi_data_wait	- timeout value
 * Output:          number of data bytes yet to be received
 * Side Effects:    None
 * Overview:        This routine reads a string from the SPI receive buffer.
 * 					The number of byte/word to be read is determined by parameter 'length'.
 * Note:            rdptr is considered to be 8/16/32 bits data pointer, according to the
 * 					current SPI mode!
 *
 *                  When a new data word has been shifted into shift register SPIxSR and 
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit (SPIxSTAT<6>) will be set.The 
 *                  module will not transfer the received data from SPIxSR to the SPIxRXB. 
 *                  Further data reception is disabled until the SPIROV bit is cleared. 
 *                  The SPIROV bit is not cleared automatically by the module and must be 
 *                  cleared by the user software.
 ********************************************************************/
unsigned int getsSPI1(unsigned int length, unsigned int *rdptr, unsigned int spi_data_wait)
{
	int				wait;
	unsigned int	rxData;
	unsigned char*			pBuff8=(unsigned char*)rdptr;
	__SPI1CONbits_t	conBits;
	unsigned short*			pBuff16=(unsigned short*)rdptr;

	conBits.w=SPI1CONbits.w;

	while (length)                     /* stay in loop until length = 0  */
	{
		wait = 0;
		while(!DataRdySPI1())
		{
			if(wait++ > spi_data_wait)
			{
				return length;	/* if time out, return number of byte/hword/words left to be read */
			}
		}
		rxData=SPI1BUF;
		if(conBits.MODE32)
		{
			*rdptr++=rxData;			// 32 bits
		}
		else if(conBits.MODE16)
		{
			*pBuff16++=(unsigned short)rxData;	// 16 bits
		}
		else
		{
			*pBuff8++=(unsigned char)rxData;		// 8 bits
		}

        length--;                      /* reduce string length count by 1*/
    }
    return (length);                   /* return number of bytes/hwords/words to be read i.e, 0 */
}
#endif	//_SPI1

