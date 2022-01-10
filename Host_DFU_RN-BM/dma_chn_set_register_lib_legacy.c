/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_set_register_lib_legacy.c
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
#include <peripheral/legacy/dma_legacy.h>

#include "../source/_dma_include.h"


#ifdef _DMA_CHANNELS


/*********************************************************************
 * Function:        void DmaChnSetRegister(DmaChannel chn, DmaChnRegIx regIx, unsigned int value)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn		- DMA channel number
 * 					regIx	- register index
 * 					value	- value to be set
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function sets directly a value into a DMA channel register.
 *
 * Note:            This is intended as a low level access channel function.
 ********************************************************************/
void DmaChnSetRegister(DmaChannel chn, DmaChnRegIx regIx, unsigned int value)
{
	*((int*)(_DmaMapTbl+chn)+regIx)=value;

}


#endif	// _DMA_CHANNELS

