/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_open_lib.c
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
#include <peripheral/int.h>

#include "_dma_include.h"


#ifdef _DMA_CHANNELS


/*********************************************************************
 * Function:        void DmaChnOpen(DmaChannel chn, DmaChannelPri chPri, DmaOpenFlags oFlags)
 *
 * PreCondition:    chPri  - valid channel priority, 0-3
 *
 * Input:           chn    - channel to be configured in the DMA controller
 *                  chPri  - the priority given to the channel, 0-3
 *                  oFlags - orred flags specifying the open mode:
 *                           DMA_OPEN_DEFAULT: DMA default operation mode
 *                           DMA_OPEN_AUTO:	DMA channel is auto enabled
 *                           DMA_OPEN_CHAIN_LOW: DMA channel is chained to lower channel
 *                           DMA_OPEN_CHAIN_HI: DMA channel is chained to higher channel
 *                           DMA_OPEN_DET_EN: events detection enabled while channel off
 *                           DMA_OPEN_ENABLE: DMA channel is enabled when opened
 *                           DMA_OPEN_MATCH:	DMA channel stops on match
 *
 *
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function opens and configures the selected DMA channel using the supplied user flags and priority.
 *
 * Note:            - This is a high level access function that doesn't give access to all the settings possible for a DMA channel.
 *                  Use the low level functions to address special settings.
 *                  - The channel is turned off, the pending interrupts are cleared, interrupts are disabled.
 *                  After that the channel is configured.
 *                  - After calling this function, the channel should be enabled using DmaChnEnable(chn) call
 *                  if DMA_OPEN_ENABLE flag was not specified.
 *                  - If the CRC is attached to the submitted channel, the CRC append mode will be turned off.
 *                  This way, the transfer will occur correctly together with CRC calculation.
 *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
 *                  User has to call event channel functions to enable the event flags if needed.
 *
 * Example:         DmaChnOpen(DMA_CHANNEL2, DMA_CHN_PRI2, DMA_OPEN_AUTO|DMA_OPEN_MATCH|DMA_OPEN_ENABLE);
 ********************************************************************/
void DmaChnOpen(DmaChannel chn, DmaChannelPri chPri, DmaOpenFlags oFlags)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;
	__DCRCCONbits_t		crcCon;

	INTEnable(INT_SOURCE_DMA(chn), INT_DISABLED);	// disable the channel interrupts
	_DmaChnOpenOp(pReg);		// abort operation, DMA controller ON
	
	
	crcCon.w=DCRCCON;				// read current CRC control word
	if(crcCon.CRCCH==chn)
	{
		DCRCCONCLR=_DCRCCON_CRCAPP_MASK;			// clear append mode
	}


	pReg->econClr=__DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK);		// disable start and abort irqs, no pattern enabled
	
	pReg->intrClr=__DCHxINT_MASK_(w_MASK);		// disable events, clear existing flags

	INTClearFlag(INT_SOURCE_DMA(chn));		// clear the existing channel interrupt flags
	
	if(oFlags&DMA_OPEN_MATCH)
	{
		pReg->econSet=__DCHxECON_MASK_(PATEN_MASK);
	}
	
	pReg->con.w=(chPri&__DCHxCON_MASK_(CHPRI_MASK))|(oFlags&(~DMA_OPEN_MATCH));	// set the control word

}


#endif	// _DMA_CHANNELS

