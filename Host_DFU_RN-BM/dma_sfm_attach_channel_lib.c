/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_crc_attach_chanel_lib.c
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

#ifdef _DMA_REV_5XX_


/*********************************************************************
 * Function:        void DmaSfmAttachChannel(DmaChannel chn, int appendMode)
 *
 * PreCondition:    chn	   - valid DMA channel
 *
 * Input:           chn         - the DMA channel to be attached to the checksum module.
 *                  appendMode	- if TRUE the data passed to the checksum generator is not transferred to destination
 *                                but it's written to the destination address when the block transfer is complete.
 *                              - if FALSE the data is transferred normally while the checksum is calculated.
 *                                The checksum will be available using the DmaSfmChecksum function.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function attaches the SFM checksum module to a DMA channel and enables the checksum generator.
 *                  From now on, all the DMA traffic is directed to the SFM checksum generator. Once the DMA block transfer
 *                  is complete, the checksum result is available in the checksum data register.
 *                  If append mode is enabled, no data transfer takes place but the checksum result will be deposited at the DMA destination address.

 *
 * Note:            If append mode is enabled the data transfer re-ordering is disabled (illegal combination, see DmaSfmTxferReorder()).
 * 
 * Example:         DmaSfmAttachChannel(0, TRUE);
 ********************************************************************/
void DmaSfmAttachChannel(DmaChannel chn, int appendMode)
{
	unsigned int	conClr, conSet;
	
	conClr=_DCRCCON_CRCEN_MASK|_DCRCCON_CRCCH_MASK;			// stop the crc
	conSet=_DCRCCON_CRCEN_MASK|(chn<<_DCRCCON_CRCCH_POSITION);	// re-enable, set the channel no
	if(appendMode)
	{
		conSet|=_DCRCCON_CRCAPP_MASK;
		conClr|=_DCRCCON_WBO_MASK;	// append+ WBO is illegal!
	}
	else
	{
		conClr|=_DCRCCON_CRCAPP_MASK;
	}

	DCRCCONCLR=conClr;	// clear
	DCRCCONSET=conSet;	// write back

}

#endif	// _DMA_REV_5XX_

#endif	// _DMA_CHANNELS

