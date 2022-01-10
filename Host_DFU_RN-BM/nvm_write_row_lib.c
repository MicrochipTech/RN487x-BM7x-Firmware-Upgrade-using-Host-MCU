/*********************************************************************
 *
 *                  NVM Write Row Library Source
 *
 *********************************************************************
 * FileName:        nvm_write_row_lib.c
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

#define NVMOP_ROW_PGM           0x4003      // Row program operation

extern unsigned int _NVMOperation(unsigned int nvmop);

/*********************************************************************
 * Function:        unsigned int NVMWriteRow(void* address, void* data)
 *
 * Description:     The largest block of data that can be programmed in
 *                  a single operation is 1 row 128 instructions (512 Bytes).  The row at
 *                  the location pointed to by NVMADDR is programmed with the data buffer
 *                  pointed to by NVMSRCADDR.
 *
 * PreCondition:    The row of data must be pre-loaded into a buffer in RAM.
 *
 * Inputs:          address:  Destination Row address to write.
 *                  data:  Location of data to write.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMWriteRow((void*) 0xBD000000, (void*) 0xA0000000)
 ********************************************************************/
unsigned int NVMWriteRow(void* address, void* data)
{
    unsigned int res;

    // Set NVMADDR to Address of row t program
    NVMADDR = KVA_TO_PA((unsigned int)address);

    // Set NVMSRCADDR to the SRAM data buffer Address
    NVMSRCADDR = KVA_TO_PA((unsigned int)data);

    // Unlock and Write Row
    res = _NVMOperation(NVMOP_ROW_PGM);

    return res;
}
