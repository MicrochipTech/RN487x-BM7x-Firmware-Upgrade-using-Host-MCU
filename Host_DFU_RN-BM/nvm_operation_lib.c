/*********************************************************************
 *
 *                  NVM Operation Library Source
 *
 *********************************************************************
 * FileName:        nvm_operation_lib.c
 * Dependencies:
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
 * $Id: NVM.h,v 1.1 2006/10/16 20:30:29 C10737 Exp $
 * $Name: $
 *
 ********************************************************************/
#include <plib.h>

unsigned int __attribute__((nomips16)) _NVMOperation(unsigned int nvmop)
{
    int	int_status;
    int	susp;

    // Disable DMA & Disable Interrupts
	#ifdef _DMAC
	int_status = INTDisableInterrupts();
	susp = DmaSuspend();
	#else
	int_status = INTDisableInterrupts(); 
	#endif	// _DMAC

    // Enable Flash Write/Erase Operations
    NVMCON = NVMCON_WREN | nvmop;

    // wait at least 6 us for LVD start-up
    // assume we're running at max frequency
    // (80 MHz) so we're always safe
    {
        unsigned long t0 = _CP0_GET_COUNT();
        while (_CP0_GET_COUNT() - t0 < (80/2)*6);
    }
    
    NVMKEY 		= 0xAA996655;
    NVMKEY 		= 0x556699AA;
    NVMCONSET 	= NVMCON_WR;

    // Wait for WR bit to clear
    while(NVMCON & NVMCON_WR);

    // Disable Flash Write/Erase operations
    NVMCONCLR = NVMCON_WREN;

	// Enable DMA & Enable Interrupts
	#ifdef _DMAC
	DmaResume(susp);
	INTRestoreInterrupts(int_status);
	#else
	INTRestoreInterrupts(int_status);
	#endif // _DMAC

	// Return Error Status
    return(NVMIsError());
}
