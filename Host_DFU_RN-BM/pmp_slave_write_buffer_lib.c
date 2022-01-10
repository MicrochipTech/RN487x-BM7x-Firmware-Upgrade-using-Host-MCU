/******************************************************************************
 *
 *                  Parallel Master Port (PMP) Implementation file
 *
 ******************************************************************************
 * FileName:        pmp_slave_write_buffer_lib.c
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
 * Parallel Master Port Write Slave Buffer Function
 *
 * Function:        void PMPSlaveWriteToBuffer(enum BUFFER, unsigned char)
 *
 * PreCondition:    None
 *
 * Input:           Argument #1 (enum BUFFER) = 0..3
 *                  Argument #2 (unsigned char) = value to be written
 *
 * Output:          None
 *
 * Example:         PMPSlaveWriteToBuffer(BUF2, 0x88);
 *
 * Note:            Writes the desired value into the selected output buffer.
 *                  This function does not check or modify the OBUF bit and
 *                  therefore it is the user's responsibility to check for
 *                  an overflow condition.
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *					or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11
 *****************************************************************************/
void PMPSlaveWriteBuffer(BUFFER buf, unsigned char value)
{
    volatile unsigned char* pReg;

    pReg =  (volatile unsigned char*) &PMDOUT;   // assign byte pointer
    *(pReg+=buf) = value;

}
