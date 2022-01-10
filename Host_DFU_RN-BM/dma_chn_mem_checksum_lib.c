/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_mem_crc_lib.c
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

#ifdef _DMA_REV_5XX_


/*********************************************************************
 * Function:        DmaTxferRes DmaChnMemChecksum(void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri)
 *
 * PreCondition:    chn    - a valid DMA channel
 *                  d, s   - valid memory pointer
 *                  n>0, n<=DmaGetMaxTxferSize()
 *
 * Input:           d     - address where to deposit the result
 *                  s     - source buffer pointer
 *                  n     - number of bytes in the pointer
 *                  chn   - the DMA channel to use
 *                  chPri - the desired channel priority
 * 
 * Output:          DMA_TXFER_OK if the transfer ended normally,
 *                  an DmaTxferRes error code  otherwise
 *
 * Side Effects:    None
 *
 * Overview:        The function is a helper that calculates the IP checksum of a memory block.
 *                  The function configures the DMA channel for a fast memory transfer and calculates the IP checksum.
 *
 *
 * Note:            - The checksum generator must have been previously seeded using DmaSfmSetSeed()
 *                  - No transfer is done, just the checksum is calculated.
 *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
 *                  - Append mode is enabled and the data transfer re-ordering is disabled (illegal combination, see DmaSfmTxferReorder()).
 *                  - The checksum type is switched to IP checksum.
 *                  - The way the data is fed into the checksum calculation block is affected by DmaSfmConfigure().
 *                  
 ********************************************************************/
DmaTxferRes DmaChnMemChecksum(void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	DCRCCONCLR=_DCRCCON_CRCEN_MASK;		// stop the SFM
	
	_DmaChnInitOp(pReg);		// DMA controller on, abort previous operation

	pReg->con.w=chPri;	// not enabled, +CHPRI
	pReg->econClr=(__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK));		// disable start and abort irqs, no pattern enabled

	pReg->intrClr=__DCHxINT_MASK_(w_MASK);	// disable events, clear existing flags


	DCRCCONCLR=_DCRCCON_CRCCH_MASK|_DCRCCON_WBO_MASK;		// clear channel no; append+ WBO is illegal!

	DCRCCONSET=_DCRCCON_CRCTYP_MASK|_DCRCCON_CRCEN_MASK|_DCRCCON_CRCAPP_MASK|(chn<<_DCRCCON_CRCCH_POSITION);		// set channel number; switch to IP chksum; CRCEN, CRCAPP

	pReg->ssa=_VirtToPhys(s);		// set src address
	pReg->dsa=_VirtToPhys(d);		// set dst address

	pReg->ssiz=pReg->dsiz=pReg->csiz=n;		// 0 size is max 
	
	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}

#endif	// _DMA_REV_5XX_

#endif	// _DMA_CHANNELS

