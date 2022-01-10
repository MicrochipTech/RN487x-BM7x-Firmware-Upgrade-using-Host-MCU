/*********************************************************************
 *
 *                  NVM Clear Error Library Source
 *
 *********************************************************************
 * FileName:        nvm_clear_error_lib.c
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

#define NVMOP_NOP               0x4000      // NOP operation

extern unsigned int _NVMOperation(unsigned int nvmop);

/*********************************************************************
 * Function:        unsigned int NVMClearError(void)
 *
 * Description:		Clears the NVMCON error flag.
 *
 * PreCondition:    None
 *
 * Inputs:			None
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:			NMVClearError()
 ********************************************************************/
unsigned int NVMClearError(void)
{
    unsigned int res;

    res = _NVMOperation(NVMOP_NOP);

    return res;
}
