/******************************************************************************
 *
 *                  Parallel Master Port (PMP) Implementation file
 *
 ******************************************************************************
 * FileName:        pmp_master_read_word_block_lib.c
 * Dependencies:	pmp.h, int.h
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
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
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
 * $Id: $
 *
 *****************************************************************************/
 #include <xc.h>
#include <peripheral/int.h>
#include <peripheral/pmp.h>


/******************************************************************************
 * Parallel Master Port Read a block of words (16-bit)
 *
 * Function:        void PMPMasterReadWordBlock(unsigned int, unsigned int,
 *                                              unsigned short*)
 *
 * PreCondition:    None
 *
 * Input:           Argument #1 (unsigned int) addrs = starting address
 *                  Argument #2 (unsigned int) words = number of words to read
 *                  Argument #3 (unsigned short*) _pDest = byte data destination
 *
 * Output:          None
 *
 * Example:         PMPMasterReadWordBlock(0x6400, 16, &myArray);
 *
 * Note:            Reads N words (argument #2) starting at location specified
 *                  in (argument #1) and stores the data at destination
 *                  specified by byte pointer (argument #3)
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
void PMPMasterReadWordBlock(unsigned int addrs, unsigned int words, unsigned short* pDest)
{
    unsigned int ix, incMode;

    while(mIsPMPBusy());

    // Save PMMODE.INCM bits so they can be restored later
    incMode = (PMMODE & 0x1800);

    // Temporarily switch to auto-inc mode for efficiency
    PMMODESET = 0x0800;

    for(ix=0; ix < words; ix++)
	{
        if(ix == 0)
        {
            // Setup the initial address
            PMPSetAddress(addrs);
            // trash old data/latch new data at initial address
            PMPMasterRead();
        }
        else
        {
            // Read previous data and latch new data
            *pDest++ =  PMPMasterRead();
        }
    }
    // Must read the last latched value
    *pDest = PMPMasterRead();

    // Restore the previous inc mode
    PMMODECLR = 0x1800;
    PMMODESET = incMode;
}
