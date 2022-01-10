/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dam_chn_set_control_flags_lib.c
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
 * Function:        void DmaChnSetControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn			- DMA channel number
 * 					dmaChnCtrl	- 	either a DmaChnCtrl structure field, carrying the following info:
 * 										- autoEn: enable/disable the automatic mode
 * 										- chainEn: enable/disable channel chaining
 * 										- detectEn: enable/disable events detection when channel disabled
 * 										- chEn: enable/disable channel functionality
 * 										- chainDir:	chain direction: chain to lower(1)/higher(0),pri channel
 * 									or any of the DmaChnCtrlFlags flags:
 * 										DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function sets the selected DMA channel control flags: 
 * 					the chaining and auto mode and events detection.
 * 					Multiple flags can be orr-ed together. Any flag that is set in the dmaChnCtrl will be
 * 					set for the selected channel, the other channel control flags won't be touched. 
 *
 * Note:            None.
 *
 * Example:			either:
 * 						DmaChnSetControlFlags(3, DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
 * 					or:
 * 						DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.autoEn=1; chCtrl.chainEn=1;
 * 						DmaChnSetControlFlags(3, chCtrl.w);
 *
 ********************************************************************/
void DmaChnSetControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
{
	(_DmaMapTbl+chn)->conSet=dmaChnCtrl;		// set the control register fields
}


#endif	// _DMA_CHANNELS

