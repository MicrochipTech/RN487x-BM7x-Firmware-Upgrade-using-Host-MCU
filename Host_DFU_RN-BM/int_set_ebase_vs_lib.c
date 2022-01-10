/********************************************************************
 * FileName:		int_set_ebase_vs_lib.c
 * Dependencies:
 * Processor:		PIC32
 * Hardware:		N/A
 * Assembler:		N/A
 * Linker:		    N/A
 * Company:		    Microchip Technology Inc.
 *
 * Software License Agreement:
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
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
 * $Id: int_disable_interrupts_lib.c 3048 2007-04-19 16:33:08Z $
 * $Name:  $

 ********************************************************************/

#include <xc.h>
#include <peripheral/int.h>
#include <cp0defs.h>


/*********************************************************************
 * Function:        INTSetEBASEAndVectorSpacing()
 *
 * PreCondition:    None
 *
 * Input:           ebase_address - address of ebase

 *                  vector_spacing - address of ebase
 *
 * Output:          None
 *
 * Side Effects:    Interrupts are disabled
 *
 * Overview:        Interrupts are disabled by clearing the IE bit
 *                  in the status register
 ********************************************************************/
void __attribute__((nomips16)) INTSetEBASEAndVectorSpacing(unsigned int ebase_address, unsigned int vector_spacing)
{
    unsigned int temp;

    unsigned int status;


    status = INTDisableInterrupts();



    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp |= _CP0_STATUS_BEV_MASK;                           // set the BEV bit

    _CP0_SET_STATUS(temp);                                  // Update the Status register





    _CP0_SET_EBASE(ebase_address);                          // Set the EBASE Value (Kseg0 or Kseg1)

    _CP0_SET_INTCTL(vector_spacing);                      // set the vector spacing



    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp &= ~(_CP0_STATUS_BEV_MASK);                        // Clear EXL and BEV bits

    _CP0_SET_STATUS(temp);                                  // Update the Status register


    INTRestoreInterrupts(status);
        

}
