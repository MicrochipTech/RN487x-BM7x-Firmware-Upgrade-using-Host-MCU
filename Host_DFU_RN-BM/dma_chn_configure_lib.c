/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_configure_lib.c
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
 * Function:        void DmaChnConfigure(DmaChannel chn, DmaChannelPri chPri, DmaConfigFlags cFlags)
 *
 * PreCondition:    chPri  - valid channel priority, 0-3
 *
 * Input:           chn    - channel to be configured in the DMA controller
 *                  chPri  - the priority given to the channel, 0-3
 *                  cFlags - orred flags specifying the configuration:
 *                           DMA_CONFIG_DEFAULT: DMA default operation mode
 *                           DMA_CONFIG_AUTO:	DMA channel is auto enabled
 *                           DMA_CONFIG_CHAIN_LOW: DMA channel is chained to lower channel
 *                           DMA_CONFIG_CHAIN_HI: DMA channel is chained to higher channel
 *                           DMA_CONFIG_DET_EN: events detection enabled while channel off
 *                           DMA_CONFIG_ENABLE: DMA channel is enabled when opened
 *                           DMA_CONFIG_MATCH:	DMA channel stops on match
 *
 *
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function configures the selected DMA channel using the supplied user flags and priority.
 *
 * Note:            - The channel is NOT turned off. It should be turned off before calling this function.
 *                  The channel is just configured.
 *                  - After calling this function, the channel should be enabled using DmaChnEnable(chn) call
 *                  if DMA_CONFIG_ENABLE flag was not specified.
 *                  - The function does not touch the interrupt flags, interrupt enables, etc.
 *                  The interrupt flags should have been previously cleared and interrupts disabled before calling this function.
 *                  - The start and abort Irqs, the channel event enable flags are not touched/cleared by this function.
 *                  User has to call event channel functions to clear/enable the event flags if needed.
 *
 * Example:         DmaChnDisable(DMA_CHANNEL2); DmaChnConfigure(DMA_CHANNEL2, DMA_CHN_PRI2, DMA_CONFIG_AUTO|DMA_CONFIG_MATCH|DMA_CONFIG_ENABLE);
 ********************************************************************/
void DmaChnConfigure(DmaChannel chn, DmaChannelPri chPri, DmaConfigFlags cFlags)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	
	if(cFlags&DMA_CONFIG_MATCH)
	{
		pReg->econSet=__DCHxECON_MASK_(PATEN_MASK);
	}
	else
	{
		pReg->econClr=__DCHxECON_MASK_(PATEN_MASK);
	}
	
	pReg->con.w=(chPri&__DCHxCON_MASK_(CHPRI_MASK))|(cFlags&(~DMA_CONFIG_MATCH));	// set the control word

}


#endif	// _DMA_CHANNELS

