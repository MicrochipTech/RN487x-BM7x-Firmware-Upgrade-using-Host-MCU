/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_disable_lib.c
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
 * Function:        void DmaChnDisable(DmaChannel chn)
 *
 * PreCondition:    None
 *
 * Input:			chn		- selected channel in the DMA controller
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function disables a DMA channel. The channel operation stops.
 *
 * Note:            None.
 ********************************************************************/
void DmaChnDisable(DmaChannel chn)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	pReg->conClr=__DCHxCON_MASK_(CHEN_MASK);	// disable the channel
	_DmaChnWaitStop(pReg);			// wait to actually stop
}

#endif	// _DMA_CHANNELS

