/********************************************************************
 * FileName:		int_get_pending_int_lib.c
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

/*********************************************************************
 * Function:        unsigned int INTGetPendingInterrupt(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          The pending interrupt or invalid data
 *
 * Side Effects:    None
 *
 * Overview:        Gets the pending interrupt
 ********************************************************************/
unsigned int INTGetPendingInterrupt(void)
{
    unsigned int result;
    unsigned int i;
    unsigned int mask;
    unsigned int value;

    result = INT_NUM;

    if((value = IFS0))
    {

        for(mask = 1, i = 0; mask > 0; mask <<= 1, i++)
        {
            if(mask & value)
                return i;
        }
    }

    if((value = IFS1))
    {

        for(mask = 1, i = 32; mask > 0; mask <<= 1, i++)
        {
            if(mask & value)
                return i;
        }
    }

    return INT_NUM;
}
