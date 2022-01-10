/*********************************************************************
 *
 *                  NVM Erase Page Library Source
 *
 *********************************************************************
 * FileName:        nvm_erase_page_lib.c
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
#include <peripheral/nvm.h>

#define NVMOP_PAGE_ERASE        0x4004      // Page erase operation

extern unsigned int _NVMOperation(unsigned int nvmop);

/*********************************************************************
 * Function:        unsigned int NVMErasePage(void* address)
 *
 * Description:     A page erase will erase a single page of program flash,
 *                  which equates to 1k instructions (4KBytes). The page to
 *                  be erased is selected using NVMADDR. The lower bytes of
 *                  the address given by NVMADDR are ignored in page selection.
 *
 * PreCondition:    None
 *
 * Inputs:          address:  Destination page address to Erase.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMErasePage((void*) 0xBD000000)
 ********************************************************************/
unsigned int NVMErasePage(void* address)
{
    unsigned int res;

    // Convert Address to Physical Address
	NVMADDR = KVA_TO_PA((unsigned int)address);

	// Unlock and Erase Page
	res = _NVMOperation(NVMOP_PAGE_ERASE);

	// Return WRERR state.
	return res;

}
