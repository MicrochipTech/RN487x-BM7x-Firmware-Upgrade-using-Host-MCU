/*********************************************************************
 *
 *                  Power API definitions
 *
 *********************************************************************
 * FileName:        power.h
 * Dependencies:
 * Processor:     PIC32
 *
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC Microcontroller products.
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
 * $Id: OSC.h,v 1.6 2006/10/13 21:24:31 C12532 Exp $
 *
 * $Name:  $
 ********************************************************************/

#include <xc.h>
#include <plib.h>
#include <peripheral/osc.h>

/*********************************************************************
 * Function:        void OSCREFConfig(unsigned long int source, OSCREFConfigFlags config, unsigned long int div);
 *
 * Description:     Sets Reference Oscillator options and ref clock source
 *
 * PreCondition:    Interrupts must be disabled
 *
 * Inputs:          Clock source, PLL multiplier, PLL postscaler, FRC divisor
 *
 * Output:          None
 *
 * Example:         OSCREFConfig(OSC_REFOCON_PBCLK, OSC_REFOCON_OE, 2);
 *
 * Note:            None
 ********************************************************************/
#if defined(__32MX120F064H__) || \
    defined(__32MX130F128H__) || \
    defined(__32MX130F128L__) || \
    defined(__32MX150F256H__) || \
    defined(__32MX150F256L__) || \
    defined(__32MX170F512H__) || \
    defined(__32MX170F512L__) || \
    defined(__32MX230F128H__) || \
    defined(__32MX230F128L__) || \
    defined(__32MX250F256H__) || \
    defined(__32MX250F256L__) || \
    defined(__32MX270F512H__) || \
    defined(__32MX270F512L__) || \
    defined(__32MX530F128H__) || \
    defined(__32MX530F128L__) || \
    defined(__32MX550F256H__) || \
    defined(__32MX550F256L__) || \
    defined(__32MX570F512H__) || \
    defined(__32MX570F512L__)
  #define NEED_OSCREFCONFIG
#elif ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299))
  #define NEED_OSCREFCONFIG
#elif (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470)
  #define NEED_OSCREFCONFIG
#else
  #undef  NEED_OSCREFCONFIG
#endif

#if defined( NEED_OSCREFCONFIG )
void OSCREFConfig(unsigned long int source, OSCREFConfigFlags config, unsigned long int div)
{
    int intStat;
    int dmaSusp;

    mSYSTEMUnlock(intStat, dmaSusp);

    REFOCONCLR = 0xffffffff;
    REFOCONSET = (source | config | (div << _REFOCON_RODIV_POSITION));

    mSYSTEMLock(intStat, dmaSusp);  // restore status
}

#endif//defined( NEED_OSCREFCONFIG )

#undef  NEED_OSCREFCONFIG
