/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_set_txfer_lib.c
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

/*********************************************************************
 * Function:        void DmaChnSetTxfer(DmaChannel chn, const void* vSrcAdd, void* vDstAdd, int srcSize, int dstSize, int cellSize)
 *
 * PreCondition:    chn		- valid DMA channel
 * 				vSrcAdd, vDstAdd - valid pointers
 *                              0 < srcSize <= DmaGetMaxTxferSize()
 *                              0 < dstSize <= DmaGetMaxTxferSize()
 *                              0 < cellSize <= DmaGetMaxTxferSize()
 *
 * Input:			chn			- DMA channel number
 * 				- vSrcAdd: source of the DMA transfer
 * 				- vDstAdd: destination of the DMA transfer
 * 				- srcSize: source buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped arround
 * 				- dstSize: destination buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped around
 * 				- cellSize: cell transfer size, 1 to DmaGetMaxTxferSize() bytes.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function sets the transfer characteristics for a DMA channel transfer:
 * 					the source and the destination addresses.
 * 					the source and destination lengths
 * 					and the number of bytes	transferred per event.
 *
 * Note:			The function clears the existing DMA channel event flags.
 *
 * Example:			DmaChnSetTxfer(3, &U2RXREG, dstBuff, 1, 200, 1);
 ********************************************************************/
void DmaChnSetTxfer(DmaChannel chn, const void* vSrcAdd, void* vDstAdd, int srcSize, int dstSize, int cellSize)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	pReg->ssa=_VirtToPhys(vSrcAdd);		// set src address
	pReg->dsa=_VirtToPhys(vDstAdd);		// set dst address

	pReg->ssiz=srcSize;	// set src size
	pReg->dsiz=dstSize;	// set dst size
	pReg->csiz=cellSize;	// set transfer (cell) size

	pReg->intrClr=DMA_IFLAG_MASK;	// clear any previous set flags	
}

#endif	// _DMA_CHANNELS

