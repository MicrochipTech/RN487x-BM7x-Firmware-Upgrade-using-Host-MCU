/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_get_status_lib.c
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
 * Function:        void DmaGetStatus(DmaStatus* pStat)
 *
 * PreCondition:    pStat	- valid pointer
 *
 * Input:			pStat	- pointer to a DmaStatus structure to store the current DMA controller
 * 							status, carrying the following info:
 * 								- chn:	the last active DMA channel
 * 								- rdOp: the last DMA operation, read/write
 * 								- lastAddress: the most recent DMA address
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function updates the info for the current DMA controller status.
 * 					It updates the last DMA: operation, channel used and address.
 *
 * Note:            None.
 ********************************************************************/
void DmaGetStatus(DmaStatus* pStat)
{
	pStat->lastAccess.w=DMASTAT;			// update the last access
	pStat->lastAddress=(void*)DMAADDR;		// update the last DMA address
}

#endif	// _DMA_CHANNELS

