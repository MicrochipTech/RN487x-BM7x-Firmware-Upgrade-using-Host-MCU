/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_get_txfer_lib.c
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
 * Function:        void DmaChnGetTxfer(DmaChannel chn, DmaTxferCtrl* pTxCtrl, int mapToK0)
 *
 * PreCondition:    chn		- valid DMA channel
 * 					pTxCtrl	- valid pointer
 *
 * Input:			chn			- DMA channel number
 * 					pTxCtrl		- pointer to a DmaTxferCtrl that will carry the following info:
 * 								- vSrcAdd: source of the DMA transfer
 * 								- vDstAdd: destination of the DMA transfer
 * 								- srcSize: source buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped arround
 * 								- dstSize: destination buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped around
 * 								- cellSize: cell transfer size, 1 to DmaGetMaxTxferSize() bytes.
 *					mapToK0		- if TRUE, a Kernel address is mapped to KSeg0, else KSeg1.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function retrieves the transfer characteristics for a DMA channel transfer:
 * 					the source and the destination addresses.
 * 					It also retrieves the source and destination lengths
 * 					and the number of bytes	transferred per event.
 *
 * Note:            None
 ********************************************************************/
void DmaChnGetTxfer(DmaChannel chn, DmaTxferCtrl* pTxCtrl, int mapToK0)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	pTxCtrl->vSrcAdd=mapToK0?_PhysToVirtK0(pReg->ssa):_PhysToVirtK1(pReg->ssa);	// get src address
	pTxCtrl->vDstAdd=mapToK0?_PhysToVirtK0(pReg->dsa):_PhysToVirtK1(pReg->dsa);	// get dst address

	pTxCtrl->srcSize=pReg->ssiz?pReg->ssiz:DmaGetMaxTxferSize();		// get src size
	pTxCtrl->dstSize=pReg->dsiz?pReg->dsiz:DmaGetMaxTxferSize();		// get dst size
	pTxCtrl->cellSize=pReg->csiz?pReg->csiz:DmaGetMaxTxferSize();		// get transfer (cell) size
}



#endif	// _DMA_CHANNELS

