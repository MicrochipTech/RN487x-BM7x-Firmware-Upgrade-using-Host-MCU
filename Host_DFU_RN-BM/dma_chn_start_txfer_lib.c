/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_start_txfer_lib.c
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
 ********************************************************************/
#include <peripheral/dma.h>

#include "_dma_include.h"


#ifdef _DMA_CHANNELS

/*********************************************************************
 * Function:        DmaTxferRes DmaChnStartTxfer(DmaChannel chn, DmaWaitMode wMode, unsigned long retries)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn		- DMA channel number
 * 					wMode	- if DMA_WAIT_NOT, return immediately
 * 							- if DMA_WAIT_CELL, return after the cell transfer complete
 * 							- if DMA_WAIT_BLOCK, return after the whole transfer is done
 * 					retries	- retry counter: if transfer not complete after so many retries, return with tmo.
 * 								If 0, wait forever.
 *
 * Output:          DMA_TXFER_OK if not waiting for the transfer completion or if the transfer ended normally,
 * 					an DmaTxferRes error code  otherwise
 *
 * Side Effects:    None
 *
 * Overview:		The function initiates (forces) a DMA transfer for the selected DMA channel.
 * 					The channel is enabled.
 * 					If waiting for the transfer completion needed (user doesn't use an ISR to catch
 * 					this event) the function will periodically query the DMA controller for the
 * 					transfer completion status.
 *
 * Note:            None
 ********************************************************************/
DmaTxferRes DmaChnStartTxfer(DmaChannel chn, DmaWaitMode wMode, unsigned long retries)
{
	DmaTxferRes		txRes=DMA_TXFER_OK;				// operation result
	int			useRetries=retries!=0;
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	pReg->intrClr=DMA_IFLAG_MASK;	// clear any previous bits
	pReg->conSet=__DCHxCON_MASK_(CHEN_MASK);	// make sure it's enabled
	pReg->econSet=__DCHxECON_MASK_(CFORCE_MASK);	// force the transfer start

	if(wMode!=DMA_WAIT_NOT)
	{	// wait untill the cell/block transfer is done
		unsigned int		maxSize;		// max size of bytes transferred: source or destination
		unsigned int		sSize, dSize;		// source and destination size
		unsigned int		xSize;			// cell size
		unsigned int		nCells;			// no of cells to transfer

		if(wMode==DMA_WAIT_CELL)
		{
			nCells=1;					// transfer just one cell
		}
		else
		{
			sSize=pReg->ssiz?pReg->ssiz:DmaGetMaxTxferSize();
			dSize=pReg->dsiz?pReg->dsiz:DmaGetMaxTxferSize();
			xSize=pReg->csiz?pReg->csiz:DmaGetMaxTxferSize();

			maxSize=sSize>=dSize?sSize:dSize;		// max size, the actual size of the block transfer
			nCells=(maxSize+xSize-1)/xSize;
		}

		nCells--;		// first cell txfer already initiated

		while(1)
		{
			__DCHxINTbits_t	intBits;		// DMA controller event bits

			// see if transfer is done
			intBits.w=pReg->intr.w;	// read the device event register
			if(intBits.CHERIF || intBits.CHTAIF)
			{
				txRes=intBits.CHERIF?DMA_TXFER_ADD_ERR:DMA_TXFER_ABORT;		// errors or aborted
				break;
			}
			else if(intBits.CHBCIF)
			{
				break;		// block transferred, done
			}
			else if(intBits.CHCCIF)
			{
				if(wMode==DMA_WAIT_CELL)
				{
					break;		// cell transferred, we're done
				}
				else
				{
					if(nCells)
					{
						pReg->intrClr=__DCHxINT_MASK_(CHCCIF_MASK);		// clear flag
						pReg->econSet=__DCHxECON_MASK_(CFORCE_MASK);	// force another transfer start
						nCells--;
					}
					else
					{
						txRes=DMA_TXFER_BC_ERR;	// we should have had CHBCIF set! this shouldn't happen!
						break;
					}
				}
			}
			// transfer not done yet
			if(useRetries)
			{
				if(retries--==0)
				{
					txRes=DMA_TXFER_TMO;
					break;
				}
			}

		}
	}
	return txRes;
}


#endif	// _DMA_CHANNELS

