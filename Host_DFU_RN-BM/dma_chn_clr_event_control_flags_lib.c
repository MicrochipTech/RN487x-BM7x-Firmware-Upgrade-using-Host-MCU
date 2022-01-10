/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_clr_event_control_flags_lib.c
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
 * Function:        void DmaChnClrEventControlFlags(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn			- DMA channel number
 * 					dmaEvCtrl	- 	either a DmaEvCtrl structure field, carrying the following info:
 * 										- AIRQEN: enable/disable the abort IRQ action
 * 										- SIRQEN: enable/disable the start IRQ action
 * 										- PATEN: enable/disable the pattern match and abort
 * 									or any of the DmaEvCtrlFlags:
 * 										DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN
 *
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function clears the events that start and abort the transfer
 * 					for the selected DMA channel.
 * 					Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
 * 					disabled for the selected channel, the other channel event flags won't be touched.
 *
 * Note:            None.
 *
 * Example:			either:
 * 						DmaChnClrEventControlFlags(3, DMA_EV_MATCH_EN|DMA_EV_START_IRQ_EN);
 * 					or:
 * 						DmaEvCtrl evCtrl; evCtrl.w=0; evCtrl.PATEN=1; evCtrl.AIRQEN=1;
 * 						DmaChnClrEventControlFlags(3, evCtrl.w);
 *
 ********************************************************************/
void DmaChnClrEventControlFlags(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
{
	(_DmaMapTbl+chn)->econClr=dmaEvCtrl&DMA_EVENT_MASK;	// clear the events. Don't touch Abort and Force!
}


#endif	// _DMA_CHANNELS

