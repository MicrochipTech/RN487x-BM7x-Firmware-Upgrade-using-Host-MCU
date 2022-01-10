/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_getc_spi2_lib_legacy.c
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
 * Function:         unsigned int getcSPI2(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          the contents of SPIBUF register in byte/hword/word format
 * Side Effects:    None
 * Overview:        This function waits for receive data to be available.
 * 					It will then read single byte/half word/word from SPI bus.
 * Note:            Having byte/hword/word accesses will perform correctly.
 *
 *                  When a new data word has been shifted into shift register SPIxSR and 
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit (SPIxSTAT<6>) will be set.The 
 *                  module will not transfer the received data from SPIxSR to the SPIxRXB. 
 *                  Further data reception is disabled until the SPIROV bit is cleared. 
 *                  The SPIROV bit is not cleared automatically by the module and must be 
 *                  cleared by the user software.
 ********************************************************************/
unsigned int getcSPI2(void)
{
	while(!DataRdySPI2());		// wait receive data available
	return ReadSPI2();			// TODO: use return SPI2BUF; directly?
}
#endif	//_SPI2

