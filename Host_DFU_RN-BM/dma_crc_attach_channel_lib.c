/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_crc_attach_chanel_lib.c
 * Dependencies:	Dma.h
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
 * (the “Company”) for its PIC32/PIC24F Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24F Microcontroller products.
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
 * $Id:$
 * $Name:  $
 *
 ********************************************************************/
#include <peripheral/dma.h>
#include "_dma_include.h"



#ifdef _DMA_CHANNELS

#ifdef	_DMA_REV_3XX_

/*********************************************************************
 * Function:        void CrcAttachChannel(DmaChannel chn, int appendMode)
 *
 * PreCondition:    chn		- valid DMA channel
 *
 * Input:			chn			- the DMA channel to be attached to the CRC generator module.
 * 					appendMode	- if TRUE the data passed to the CRC generator is not transferred to destination
 * 									but it's written to the destination address when the block transfer is complete.
 * 								- if FALSE the data is transferred normally while the CRC is calculated. The CRC will
 * 									be available using the CrcResult function.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function attaches the CRC module to an DMA channel and enables the CRC generator.
 * 					From now on, all the DMA traffic is directed to the CRC generator. Once the DMA block transfer
 * 					is complete, the CRC result is available both at the DMA destination address and in the CRC data register.
 *
 * Note:            None
 ********************************************************************/
void CrcAttachChannel(DmaChannel chn, int appendMode)
{
	__DCRCCONbits_t crcCon;

	crcCon.w=DCRCCON;		// read current control word
	crcCon.CRCCH=chn;
	crcCon.CRCEN=1;
	crcCon.CRCAPP=appendMode?1:0;

	DCRCCON=crcCon.w;		// write back
}

#endif	// _DMA_REV_3XX_

#endif	// _DMA_CHANNELS

