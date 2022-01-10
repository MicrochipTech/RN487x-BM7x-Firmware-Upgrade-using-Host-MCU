/*********************************************************************
 *
 *                  Ports device specific table
 *
 *********************************************************************
 * FileName:        _PortsTblLibp.c
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
#include <plib.h>
#include "_ports_tbl_libp.h"

#if ( defined(__32MX120F064H__)     || \
      defined(__32MX130F128H__)     || \
      defined(__32MX130F128L__)     || \
      defined(__32MX150F256H__)     || \
      defined(__32MX150F256L__)     || \
      defined(__32MX170F512H__)     || \
      defined(__32MX170F512L__)     || \
      defined(__32MX230F128H__)     || \
      defined(__32MX230F128L__)     || \
      defined(__32MX250F256H__)     || \
      defined(__32MX250F256L__)     || \
      defined(__32MX270F512H__)     || \
      defined(__32MX270F512L__)     || \
      defined(__32MX530F128H__)     || \
      defined(__32MX530F128L__)     || \
      defined(__32MX550F256H__)     || \
      defined(__32MX550F256L__)     || \
      defined(__32MX570F512H__)     || \
      defined(__32MX570F512L__)     || \
     (__PIC32_FEATURE_SET__ == 330) || \
     (__PIC32_FEATURE_SET__ == 350) || \
     (__PIC32_FEATURE_SET__ == 370) || \
     (__PIC32_FEATURE_SET__ == 430) || \
     (__PIC32_FEATURE_SET__ == 450) || \
     (__PIC32_FEATURE_SET__ == 470) || ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299))\
    )
  #define TableB
#else
  #define TableA
#endif


#if defined TableA
  // Case 1: implementation using IOPORT enumeration
  const PortRegDcpt   PortRegTbl[IOPORT_NUM]=
  {
    #if defined _PORTA
      {(PortRegMap*)&TRISA,       0x00000000,     0x0},
    #endif

    #if defined _PORTB
      {(PortRegMap*)&TRISB,       0x0000ffff,     (AnConReg*)&AD1PCFG},
    #endif

    #if defined _PORTC
      {(PortRegMap*)&TRISC,       0x00000000,     0x0},
    #endif

    #if defined _PORTD
      {(PortRegMap*)&TRISD,       0x00000000,     0x0},
    #endif

    #if defined _PORTE
      {(PortRegMap*)&TRISE,       0x00000000,     0x0},
    #endif

    #if defined _PORTF
      {(PortRegMap*)&TRISF,       0x00000000,     0x0},
    #endif

    #if defined _PORTG
      {(PortRegMap*)&TRISG,       0x00000000,     0x0}
    #endif
};
#endif

#if defined TableB
  const PortRegDcpt   PortRegTbl[IOPORT_NUM]=
  {
    #if defined _PORTA
      {(PortRegMap*)&TRISA,       0x0000ffff,     (AnConReg*)&ANSELA},
    #endif

    #if defined _PORTB
      {(PortRegMap*)&TRISB,       0x0000ffff,     (AnConReg*)&ANSELB},
    #endif

    #if defined _PORTC
      {(PortRegMap*)&TRISC,       0x0000ffff,     (AnConReg*)&ANSELC},
    #endif

    #if defined _PORTD
      {(PortRegMap*)&TRISD,       0x0000ffff,     (AnConReg*)&ANSELD},
    #endif

    #if defined _PORTE
      {(PortRegMap*)&TRISE,       0x0000ffff,     (AnConReg*)&ANSELE},
    #endif

    #if defined _PORTF
      {(PortRegMap*)&TRISF,       0x0000ffff,     (AnConReg*)&ANSELF},
    #endif

    #if defined _PORTG
      {(PortRegMap*)&TRISG,       0x0000ffff,     (AnConReg*)&ANSELG},
    #endif
};
#endif
