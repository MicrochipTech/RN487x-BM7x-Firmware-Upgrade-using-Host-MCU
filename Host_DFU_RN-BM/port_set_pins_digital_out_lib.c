/*********************************************************************
 *
 *                  PORTSetPinsDigitalOut lib function
 *
 *********************************************************************
 * FileName:        port_set_pins_digital_out_lib.c
 * Dependencies:
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
 * (the “Company”) for its PIC32/PIC24 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24 Microcontroller products.
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
 * $Id$
 *
 ********************************************************************/
#include <xc.h>
#include <peripheral/ports.h>
#include "_ports_tbl_libp.h"


extern const PortRegDcpt    PortRegTbl[];

/******************************************************************************
 * Set Pins as Digital Output
 *
 * Function:        PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as digital outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalOut(IOPORT_C, BIT_6 | BIT_7);
 *
 *                  Note: Bit definitions are located in \include\proc\ppic32mx.h
 *****************************************************************************/
    void    PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs)
    {
        const PortRegDcpt* pDcpt=PortRegTbl+portId;

        pDcpt->pPortReg->trisClr=outputs;

        if(pDcpt->pConR)
        {
          #if (  defined(__32MX120F064H__)    || \
                 defined(__32MX130F128H__)    || \
                 defined(__32MX130F128L__)    || \
                 defined(__32MX150F256H__)    || \
                 defined(__32MX150F256L__)    || \
                 defined(__32MX170F512H__)    || \
                 defined(__32MX170F512L__)    || \
                 defined(__32MX230F128H__)    || \
                 defined(__32MX230F128L__)    || \
                 defined(__32MX250F256H__)    || \
                 defined(__32MX250F256L__)    || \
                 defined(__32MX270F512H__)    || \
                 defined(__32MX270F512L__)    || \
                 defined(__32MX530F128H__)    || \
                 defined(__32MX530F128L__)    || \
                 defined(__32MX550F256H__)    || \
                 defined(__32MX550F256L__)    || \
                 defined(__32MX570F512H__)    || \
                 defined(__32MX570F512L__)    || \
               (__PIC32_FEATURE_SET__ == 330) || \
               (__PIC32_FEATURE_SET__ == 350) || \
               (__PIC32_FEATURE_SET__ == 370) || \
               (__PIC32_FEATURE_SET__ == 430) || \
               (__PIC32_FEATURE_SET__ == 450) || \
               (__PIC32_FEATURE_SET__ == 470) || \
               ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299))\
              )
            pDcpt->pConR->regClr = pDcpt->analogMask & outputs;
          #else
            pDcpt->pConR->regSet = pDcpt->analogMask & outputs;
          #endif
        }
    }

