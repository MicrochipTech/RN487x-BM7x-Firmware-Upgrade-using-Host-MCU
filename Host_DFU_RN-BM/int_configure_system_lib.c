/********************************************************************
 * FileName:		int_enable_sv_int_lib.c
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
 * $Id:$
 * $Name:  $
 ********************************************************************/
#include <peripheral/int.h>

/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) INTConfigureSystem(INT_SYSTEM_CONFIG config);

  Summary:
    Configures system for  multi-vector interrupts.

  Description:
    This routine configures the core to receive interrupt requests and configures the 
    interrupt controller for multi-vectored mode.

  Precondition:
    None

  Parameters:
    config      - the interrupt configuration to set

  Returns:
    None

  *****************************************************************************/
void __attribute__ ((nomips16)) INTConfigureSystem(INT_SYSTEM_CONFIG config)
{
    unsigned int val;

    // set the CP0 cause IV bit high
    asm volatile("mfc0   %0,$13" : "=r"(val));
    val |= 0x00800000;
    asm volatile("mtc0   %0,$13" : "+r"(val));

    if(config == INT_SYSTEM_CONFIG_MULT_VECTOR)
        INTCONSET = _INTCON_MVEC_MASK;
    else
        INTCONCLR = _INTCON_MVEC_MASK;
}
