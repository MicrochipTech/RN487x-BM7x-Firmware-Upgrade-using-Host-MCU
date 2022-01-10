/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_set_src_add_lib.c
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
 * Function:        void DmaChnSetSrcAdd(DmaChannel chn, const void* vSrcAdd)
 *
 * PreCondition:    chn		- valid DMA channel
 *
 * Input:			chn			- DMA channel number
 * 								- vSrcAdd: source (virtual) of the DMA transfer
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function is a helper to set directly the transfer source address.
 *
 * Note:			None
 *
 * Example:			DmaChnSetSrcAdd(2, srcBuff+sizeof(srcBuff));
 ********************************************************************/
void DmaChnSetSrcAdd(DmaChannel chn, const void* vSrcAdd)
{
	(_DmaMapTbl+chn)->ssa=_VirtToPhys(vSrcAdd);		// set src address
}

#endif	// _DMA_CHANNELS

