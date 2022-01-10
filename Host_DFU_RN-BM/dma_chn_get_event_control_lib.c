/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_get_event_control_lib.c
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
 * Function:        DmaEvCtrlFlags DmaChnGetEventControl(DmaChannel chn)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn		- DMA channel number
 *
 * Output:          - either a DmaEvCtrl structure field, carrying the following info:
 * 							- abortIrqEn: enable/disable the abort IRQ action
 * 							- startIrqEn: enable/disable the start IRQ action
 * 							- matchEn: enable/disable the pattern match and abort
 * 							- startIrq: IRQ number to start the DMA channel transfer
 * 							- abortIrq: IRQ number to abort the DMA channel transfer
 *						or any of the DmaEvCtrlFlags flags:
 *							DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(irq)|DMA_EV_ABORT_IRQ(irq)
 *
 * Side Effects:    None
 *
 * Overview:		The function retrieves the events that start and abort the transfer
 * 					for the selected DMA channel.
 *
 * Note:            None.
 ********************************************************************/
DmaEvCtrlFlags DmaChnGetEventControl(DmaChannel chn)
{
	return (_DmaMapTbl+chn)->econ.w;			// get the current events.
}

#endif	// _DMA_CHANNELS

