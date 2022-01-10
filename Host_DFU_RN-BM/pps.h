#if !defined(__PPS_H)
#define      __PPS_H

#include "xc.h"

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


/*
Example Code:

   // Assign UART 2 signals onto pins using PPS
    PPSInput(2,U2RX, RPA9);  //Assign U2RX to pin RPA09
    PPSInput(3,U2CTS,RPC3);  //Assign U2CTS to pin RPC3
    PPSOutput(4,RPC4,U2TX);   //Assign U2TX to pin RPC4
    PPSOutput(1,RPB15,U2RTS); //Assign U2RTS to pin RPB15

 */

/*===========================================================================*/
/*Section:  Remappable Peripheral Inputs :                                   */
/*===========================================================================*/
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

// Input Pins Group 1
#define IN_FN_PPS1_INT3          INT3RBITS.INT3R
#define IN_FN_PPS1_T2CK          T2CKRbits.T2CKR
#define IN_FN_PPS1_IC3           IC3Rbits.IC3R
#define IN_FN_PPS1_U1RX          U1RXRbits.U1RXR
#define IN_FN_PPS1_U2RX          U2RXRbits.U2RXR
#define IN_FN_PPS1_U5CTS         U5CTSRbits.U5CTSR
#define IN_FN_PPS1_SDI3          SDI3Rbits.SDI3R
#define IN_FN_PPS1_SDI4          SDI4Rbits.SDI4R
#define IN_FN_PPS1_REFCLKI       REFCLKIRbits.REFCLKIR

#define IN_PIN_PPS1_RPD2    0b0000 // RPD2
#define IN_PIN_PPS1_RPG8    0b0001 // RPG8
#define IN_PIN_PPS1_RPF4    0b0010 // RPF4
#define IN_PIN_PPS1_RPD10   0b0011 // RPD10
#define IN_PIN_PPS1_RPF1    0b0100 // RPF1
#define IN_PIN_PPS1_RPB9    0b0101 // RPB9
#define IN_PIN_PPS1_RPB10   0b0110 // RPB10
#define IN_PIN_PPS1_RPC14   0b0111 // RPC14
#define IN_PIN_PPS1_RPB5    0b1000 // RPB5
#define IN_PIN_PPS1_RSVRD1  0b1001 // Reserved
#define IN_PIN_PPS1_RPC1    0b1010 // RPC1
#define IN_PIN_PPS1_RPD14   0b1011 // RPD14
#define IN_PIN_PPS1_RPG1    0b1100 // RPG1
#define IN_PIN_PPS1_RPA14   0b1101 // RPA14
#define IN_PIN_PPS1_RSVRD2  0b1110 // Reserved
#define IN_PIN_PPS1_RPF2    0b1111 // RPF2

// Input Pins Group 2
#define IN_FN_PPS2_INT4          INT4Rbits.INT4R
#define IN_FN_PPS2_T5CK          T5CKRbits.T5CKR
#define IN_FN_PPS2_IC4           IC4Rbits. IC4R
#define IN_FN_PPS2_U3RX          U3RXRbits.U3RXR
#define IN_FN_PPS2_U4CTS         U4CTSRbits.U4CTSR
#define IN_FN_PPS2_SDI1          SDI1Rbits.SDI1R
#define IN_FN_PPS2_SDI2          SDI2Rbits.SDI2R
#define IN_FN_PPS2_C1RX          C1RXRbits.C1RXR

#define IN_PIN_PPS2_RPD3    0b0000 // RPD3
#define IN_PIN_PPS2_RPG7    0b0001 // RPG7
#define IN_PIN_PPS2_RPF5    0b0010 // RPF5
#define IN_PIN_PPS2_RPD11   0b0011 // RPD11
#define IN_PIN_PPS2_RPF0    0b0100 // RPF0
#define IN_PIN_PPS2_RPB1    0b0101 // RPB1
#define IN_PIN_PPS2_RPE5    0b0110 // RPE5
#define IN_PIN_PPS2_RPC13   0b0111 // RPC13
#define IN_PIN_PPS2_RPB3    0b1000 // RPB3
#define IN_PIN_PPS2_RPF12   0b1001 // RPF12
#define IN_PIN_PPS2_RPC4    0b1010 // RPC4
#define IN_PIN_PPS2_RPD15   0b1011 // RPD15
#define IN_PIN_PPS2_RPG0    0b1100 // RPG0
#define IN_PIN_PPS2_RPA15   0b1101 // RPA15
#define IN_PIN_PPS2_RPF2    0b1110 // RPF2
#define IN_PIN_PPS2_RPF7    0b1111 // RPF7

// Input Pins Group 3
#define IN_FN_PPS3_INT2          INT2Rbits.INT2R
#define IN_FN_PPS3_T4CK          T4CKRbits.T4CKR
#define IN_FN_PPS3_IC2           IC2Rbits. IC2R
#define IN_FN_PPS3_IC5           IC5Rbits. IC5R
#define IN_FN_PPS3_U1CTS         U1CTSRbits.U1CTSR
#define IN_FN_PPS3_U2CTS         U2CTSRbits.U2CTSR
#define IN_FN_PPS3_SS1           SS1Rbits. SS1R
#define IN_FN_PPS3_SS3           SS3Rbits. SS3R
#define IN_FN_PPS3_SS4           SS4Rbits. SS4R

#define IN_PIN_PPS3_RPD9    0b0000 // RPD9
#define IN_PIN_PPS3_RPG6    0b0001 // RPG6
#define IN_PIN_PPS3_RPB8    0b0010 // RPB8
#define IN_PIN_PPS3_RPB15   0b0011 // RPB15
#define IN_PIN_PPS3_RPD4    0b0100 // RPD4
#define IN_PIN_PPS3_RPB0    0b0101 // RPB0
#define IN_PIN_PPS3_RPE     0b0110 // RPE
#define IN_PIN_PPS3_RPB7    0b0111 // RPB7
#define IN_PIN_PPS3_RSVRD   0b1000 // Reserved
#define IN_PIN_PPS3_RPF12   0b1001 // RPF12
#define IN_PIN_PPS3_RPD12   0b1010 // RPD12
#define IN_PIN_PPS3_RPF8    0b1011 // RPF8
#define IN_PIN_PPS3_RPC     0b1100 // RPC
#define IN_PIN_PPS3_RPE9    0b1101 // RPE9
#define IN_PIN_PPS3_RPD14   0b1110 // RPD14
#define IN_PIN_PPS3_RPB2    0b1111 // RPB2

// Input Pins Group 4
#define IN_FN_PPS4_INT1          INT1Rbits.INT1R
#define IN_FN_PPS4_T3CK          T3CKRbits.T3CKR
#define IN_FN_PPS4_IC1           IC1Rbits.IC1R
#define IN_FN_PPS4_U3CTS         U3CTSRbitsU3CTSR.
#define IN_FN_PPS4_U4RX          U4RXRbits.U4RXR
#define IN_FN_PPS4_U5RX          U5RXRbits.U5RXR
#define IN_FN_PPS4_SS2           SS2Rbits.SS2R
#define IN_FN_PPS4_OCFA          OCFARbits.OCFAR

#define IN_PIN_PPS4_RPD1    0b0000 // RPD1
#define IN_PIN_PPS4_RPG9    0b0001 // RPG9
#define IN_PIN_PPS4_RPB14   0b0010 // RPB14
#define IN_PIN_PPS4_RPD0    0b0011 // RPD0
#define IN_PIN_PPS4_RPD8    0b0100 // RPD8
#define IN_PIN_PPS4_RPB6    0b0101 // RPB6
#define IN_PIN_PPS4_RPD5    0b0110 // RPD5
#define IN_PIN_PPS4_RPB2    0b0111 // RPB2
#define IN_PIN_PPS4_RPF3    0b1000 // RPF3
#define IN_PIN_PPS4_RPF13   0b1001 // RPF13
#define IN_PIN_PPS4_RSVRD1  0b1010 // Reserved
#define IN_PIN_PPS4_RPF2    0b1011 // RPF2
#define IN_PIN_PPS4_RPC2    0b1100 // RPC2
#define IN_PIN_PPS4_RPE8    0b1101 // RPE8
#define IN_PIN_PPS4_RSVRD2  0b1110 // Reserved
#define IN_PIN_PPS4_RSVRD3  0b1111 // Reserved


#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
/* Input Pins Group 1 */
#define IN_FN_PPS1_INT4          INT4Rbits.INT4R
#define IN_FN_PPS1_T2CK          T2CKRbits.T2CKR
#define IN_FN_PPS1_IC4           IC4Rbits.IC4R
#define IN_FN_PPS1_SS1           SS1Rbits.SS1R
#define IN_FN_PPS1_REFCLKI       REFCLKIRbits.REFCLKIR

#define IN_PIN_PPS1_RPA0         0   /* Assign RPA0  as Input Pin */
#define IN_PIN_PPS1_RPB3         1   /* Assign RPB3  as Input Pin */
#define IN_PIN_PPS1_RPB4         2   /* Assign RPB4  as Input Pin */
#define IN_PIN_PPS1_RPB15        3   /* Assign RPB15 as Input Pin */
#define IN_PIN_PPS1_RPB7         4   /* Assign RPB7  as Input Pin */
#define IN_PIN_PPS1_RPC7         5   /* Assign RPC4  as Input Pin */
#define IN_PIN_PPS1_RPC0         6   /* Assign RPC0  as Input Pin */
#define IN_PIN_PPS1_RPC5         7   /* Assign RPC5  as Input Pin */

/* Input Pins Group 2 */
#define IN_FN_PPS2_INT3          INT3Rbits.INT3R
#define IN_FN_PPS2_T3CK          T3CKRbits.T3CKR
#define IN_FN_PPS2_IC3           IC3Rbits.IC3R
#define IN_FN_PPS2_U1CTS         U1CTSRbits.U1CTSR
#define IN_FN_PPS2_U2RX          U2RXRbits.U2RXR
#define IN_FN_PPS2_SDI1          SDI1Rbits.SDI1R

#define IN_PIN_PPS2_RPA1         0   /* Assign RPA1  as Input Pin */
#define IN_PIN_PPS2_RPB5         1   /* Assign RPB5  as Input Pin */
#define IN_PIN_PPS2_RPB1         2   /* Assign RPB1  as Input Pin */
#define IN_PIN_PPS2_RPB11        3   /* Assign RPB11 as Input Pin */
#define IN_PIN_PPS2_RPB8         4   /* Assign RPB8  as Input Pin */
#define IN_PIN_PPS2_RPA8         5   /* Assign RPA8  as Input Pin */
#define IN_PIN_PPS2_RPC8         6   /* Assign RPC8  as Input Pin */
#define IN_PIN_PPS2_RPA9         7   /* Assign RPA9  as Input Pin */

/* Input Pins Group 3 */
#define IN_FN_PPS3_INT2          INT2Rbits.INT2R
#define IN_FN_PPS3_T4CK          T4CKRbits.T4CKR
#define IN_FN_PPS3_IC1           IC1Rbits.IC1R
#define IN_FN_PPS3_IC5           IC5Rbits.IC5R
#define IN_FN_PPS3_U1RX          U1RXRbits.U1RXR
#define IN_FN_PPS3_U2CTS         U2CTSRbits.U2CTSR
#define IN_FN_PPS3_SDI2          SDI2Rbits.SDI2R
#define IN_FN_PPS3_OCFB          OCFBRbits.OCFBR

#define IN_PIN_PPS3_RPA2         0   /* Assign RPA2  as Input Pin */
#define IN_PIN_PPS3_RPB6         1   /* Assign RPB6  as Input Pin */
#define IN_PIN_PPS3_RPA4         2   /* Assign RPA4  as Input Pin */
#define IN_PIN_PPS3_RPB13        3   /* Assign RPB13 as Input Pin */
#define IN_PIN_PPS3_RPB2         4   /* Assign RPB2  as Input Pin */
#define IN_PIN_PPS3_RPC6         5   /* Assign RPC6  as Input Pin */
#define IN_PIN_PPS3_RPC1         6   /* Assign RPC1  as Input Pin */
#define IN_PIN_PPS3_RPC3         7   /* Assign RPC3  as Input Pin */


/* Input Pins Group 4 */

#define _PPS_INPUT_BASE_ADDRESS  INT1R // Happens to be the first one
#define IN_FN_PPS4_INT1          INT1Rbits.INT1R
#define IN_FN_PPS4_T5CK          T5CKRbits.T5CKR
#define IN_FN_PPS4_IC2           IC2Rbits.IC2R
#define IN_FN_PPS4_SS2           SS2Rbits.SS2R
#define IN_FN_PPS4_OCFA          OCFARbits.OCFAR

#define IN_PIN_PPS4_RPA3         0   /* Assign RPA3  as Input Pin */
#define IN_PIN_PPS4_RPB14        1   /* Assign RPB14 as Input Pin */
#define IN_PIN_PPS4_RPB0         2   /* Assign RPB0  as Input Pin */
#define IN_PIN_PPS4_RPB10        3   /* Assign RPB10 as Input Pin */
#define IN_PIN_PPS4_RPB9         4   /* Assign RPB9  as Input Pin */
#define IN_PIN_PPS4_RPC9         5   /* Assign RPC9  as Input Pin */
#define IN_PIN_PPS4_RPC2         6   /* Assign RPC2  as Input Pin */
#define IN_PIN_PPS4_RPC4         7   /* Assign RPC4  as Input Pin */

#elif (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470)

/* Input Pins Group 1 */
#define IN_FN_PPS1_INT3          INT3Rbits.INT3R
#define IN_FN_PPS1_T2CK          T2CKRbits.T2CKR
#define IN_FN_PPS1_IC3           IC3Rbits.IC3R
#define IN_FN_PPS1_U1RX          U1RXRbits.U1RXR
#define IN_FN_PPS1_U2RX          U2RXRbits.U2RXR
#define IN_FN_PPS1_U5CTS         U5CTSRbits.U5CTSR
#define IN_FN_PPS1_REFCLKI       REFCLKIRbits.REFCLKIR

#define IN_PIN_PPS1_RPD2         0   /* Assign RPD2  as Input Pin */
#define IN_PIN_PPS1_RPG8         1   /* Assign RPG8  as Input Pin */
#define IN_PIN_PPS1_RPF4         2   /* Assign RPF4  as Input Pin */
#define IN_PIN_PPS1_RPD10        3   /* Assign RPD10 as Input Pin */
#define IN_PIN_PPS1_RPF1         4   /* Assign RPF1  as Input Pin */
#define IN_PIN_PPS1_RPB9         5   /* Assign RPB9  as Input Pin */
#define IN_PIN_PPS1_RPB10        6   /* Assign RPB10 as Input Pin */
#define IN_PIN_PPS1_RPC14        7   /* Assign RPC14 as Input Pin */
#define IN_PIN_PPS1_RPB5         8   /* Assign RPB5  as Input Pin */
#define IN_PIN_PPS1_RPC1         10  /* Assign RPC1  as Input Pin */
#define IN_PIN_PPS1_RPD14        11  /* Assign RPD14 as Input Pin */
#define IN_PIN_PPS1_RPG1         12  /* Assign RPG1  as Input Pin */
#define IN_PIN_PPS1_RPA14        13  /* Assign RPA14 as Input Pin */
#define IN_PIN_PPS1_RPF2         15  /* Assign RPF2  as Input Pin */

/* Input Pins Group 2 */
#define IN_FN_PPS2_INT4          INT4Rbits.INT4R
#define IN_FN_PPS2_T5CK          T5CKRbits.T5CKR
#define IN_FN_PPS2_IC4           IC4Rbits.IC4R
#define IN_FN_PPS2_U3RX          U3RXRbits.U3RXR
#define IN_FN_PPS2_U4CTS         U4CTSRbits.U4CTSR
#define IN_FN_PPS2_SDI1          SDI1Rbits.SDI1R
#define IN_FN_PPS2_SDI2          SDI2Rbits.SDI2R

#define IN_PIN_PPS2_RPD3         0   /* Assign RPD3  as Input Pin */
#define IN_PIN_PPS2_RPG7         1   /* Assign RPG7  as Input Pin */
#define IN_PIN_PPS2_RPF5         2   /* Assign RPF5  as Input Pin */
#define IN_PIN_PPS2_RPD11        3   /* Assign RPD11 as Input Pin */
#define IN_PIN_PPS2_RPF0         4   /* Assign RPF0  as Input Pin */
#define IN_PIN_PPS2_RPB1         5   /* Assign RPB1  as Input Pin */
#define IN_PIN_PPS2_RPE5         6   /* Assign RPE5  as Input Pin */
#define IN_PIN_PPS2_RPC13        7   /* Assign RPC13 as Input Pin */
#define IN_PIN_PPS2_RPB3         8   /* Assign RPB3  as Input Pin */
#define IN_PIN_PPS2_RPC4         10  /* Assign RPC4  as Input Pin */
#define IN_PIN_PPS2_RPD15        11  /* Assign RPD15 as Input Pin */
#define IN_PIN_PPS2_RPG0         12  /* Assign RPG0  as Input Pin */
#define IN_PIN_PPS2_RPA15        13  /* Assign RPA15 as Input Pin */
#define IN_PIN_PPS2_RPF2         14  /* Assign RPF2  as Input Pin */
#define IN_PIN_PPS2_RPF7         15  /* Assign RPF7  as Input Pin */

/* Input Pins Group 3 */
#define IN_FN_PPS3_INT2          INT2Rbits.INT2R
#define IN_FN_PPS3_T4CK          T4CKRbits.T4CKR
#define IN_FN_PPS3_IC2           IC2Rbits.IC2R
#define IN_FN_PPS3_IC5           IC5Rbits.IC5R
#define IN_FN_PPS3_U1CTS         U1CTSRbits.U1CTSR
#define IN_FN_PPS3_U2CTS         U2CTSRbits.U2CTSR
#define IN_FN_PPS3_SS1           SS1Rbits.SS1R

#define IN_PIN_PPS3_RPD9         0   /* Assign RPD9  as Input Pin */
#define IN_PIN_PPS3_RPG6         1   /* Assign RPG6  as Input Pin */
#define IN_PIN_PPS3_RPB8         2   /* Assign RPB8  as Input Pin */
#define IN_PIN_PPS3_RPB15        3   /* Assign RPB15 as Input Pin */
#define IN_PIN_PPS3_RPD4         4   /* Assign RPD4  as Input Pin */
#define IN_PIN_PPS3_RPB0         5   /* Assign RPB0  as Input Pin */
#define IN_PIN_PPS3_RPE3         6   /* Assign RPE3  as Input Pin */
#define IN_PIN_PPS3_RPB7         7   /* Assign RPB7  as Input Pin */
#define IN_PIN_PPS3_RPF12        9   /* Assign RPF12 as Input Pin */
#define IN_PIN_PPS3_RPD12        10  /* Assign RPD12 as Input Pin */
#define IN_PIN_PPS3_RPF8         11  /* Assign RPF8  as Input Pin */
#define IN_PIN_PPS3_RPC3         12  /* Assign RPC3  as Input Pin */
#define IN_PIN_PPS3_RPE9         13  /* Assign RPE9  as Input Pin */
#define IN_PIN_PPS3_RPB2         15  /* Assign RPB2  as Input Pin */


/* Input Pins Group 4 */
#define IN_FN_PPS4_INT1          INT1Rbits.INT1R
#define IN_FN_PPS4_T3CK          T3CKRbits.T3CKR
#define IN_FN_PPS4_IC1           IC1Rbits.IC1R
#define IN_FN_PPS4_U3CTS         U3CTSRbits.U3CTSR
#define IN_FN_PPS4_U4RX          U4RXRbits.U4RXR
#define IN_FN_PPS4_U5RX          U5RXRbits.U5RXR
#define IN_FN_PPS4_SS2           SS2Rbits.SS2R
#define IN_FN_PPS4_OCFA          OCFARbits.OCFAR

#define IN_PIN_PPS4_RPD1         0   /* Assign RPD1  as Input Pin */
#define IN_PIN_PPS4_RPG9         1   /* Assign RPG9  as Input Pin */
#define IN_PIN_PPS4_RPB14        2   /* Assign RPB14 as Input Pin */
#define IN_PIN_PPS4_RPD0         3   /* Assign RPD0  as Input Pin */
#define IN_PIN_PPS4_RPD8         4   /* Assign RPD8  as Input Pin */
#define IN_PIN_PPS4_RPB6         5   /* Assign RPB6  as Input Pin */
#define IN_PIN_PPS4_RPD5         6   /* Assign RPD5  as Input Pin */
#define IN_PIN_PPS4_RPB2         7   /* Assign RPB2  as Input Pin */
#define IN_PIN_PPS4_RPF3         8   /* Assign RPF3  as Input Pin */
#define IN_PIN_PPS4_RPF13        9   /* Assign RPF13 as Input Pin */
#define IN_PIN_PPS4_RPF2         11  /* Assign RPF2  as Input Pin */
#define IN_PIN_PPS4_RPC2         12  /* Assign RPC2  as Input Pin */
#define IN_PIN_PPS4_RPE8         13  /* Assign RPE8  as Input Pin */
#endif


/*********************************************************************
 Macro:             PPSInput(grp,fn,pin)

 PreCondition:     None

 Side Effects:     None

 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.

 Parameters:grp - the group number that the peripheral or pin function

            fn - function to be assigned for particular pin
            *   TxCK
            *   INTx
            *   ICx
            *   OCFx
            *   UxRX
            *   UxCTS
            *   SDIx
            *   SCKxIN
            *   SSxIN

            pin - pin number(x) for which functionality has to be assigned
            *   RPx

 Returns:       None

 Note:              None
 ********************************************************************/
#define PPSInput(grp,fn,pin) IN_FN_PPS##grp##_##fn = IN_PIN_PPS##grp##_##pin

/*===========================================================================*/
/*Section:  Remappable Peripheral Outputs:                                   */
/*===========================================================================*/
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

/* Output Pin Group 1 */
#define _PPS_OUTPUT_BASE_ADDRESS RPA14R // Happens to be the first one

#define OUT_PIN_PPS1_RPA14       RPA14Rbits.RPA14R
#define OUT_PIN_PPS1_RPB10       RPB10Rbits.RPB10R
#define OUT_PIN_PPS1_RPB5        RPB5Rbits.RPB5R
#define OUT_PIN_PPS1_RPB9        RPB9Rbits.RPB9R
#define OUT_PIN_PPS1_RPC1        RPC1Rbits.RPC1R
#define OUT_PIN_PPS1_RPC14       RPC14Rbits.RPC14R
#define OUT_PIN_PPS1_RPD10       RPD10Rbits.RPD10R
#define OUT_PIN_PPS1_RPD14       RPD14Rbits.RPD14R
#define OUT_PIN_PPS1_RPD2        RPD2Rbits.RPD2R
#define OUT_PIN_PPS1_RPF1        RPF1Rbits.RPF1R
#define OUT_PIN_PPS1_RPF4        RPF4Rbits.RPF4R
#define OUT_PIN_PPS1_RPG1        RPG1Rbits.RPG1R
#define OUT_PIN_PPS1_RPG8        RPG8Rbits.RPG8R

#define OUT_FN_PPS1_C1TX         0b1100 // C1TX
#define OUT_FN_PPS1_C2OUT        0b1101 // C2OUT
#define OUT_FN_PPS1_NULL         0b0000 // No Connect
#define OUT_FN_PPS1_OC3          0b1011 // OC3
#define OUT_FN_PPS1_RSVRD1       0b0011 // Reserved
#define OUT_FN_PPS1_RSVRD2       0b0100 // Reserved
#define OUT_FN_PPS1_RSVRD3       0b0101 // Reserved
#define OUT_FN_PPS1_RSVRD4       0b0111 // Reserved
#define OUT_FN_PPS1_RSVRD5       0b1000 // Reserved
#define OUT_FN_PPS1_RSVRD6       0b1001 // Reserved
#define OUT_FN_PPS1_RSVRD7       0b1010 // Reserved
#define OUT_FN_PPS1_SDO2         0b0110 // SDO2
#define OUT_FN_PPS1_SDO3         0b1110 // SDO3
#define OUT_FN_PPS1_SDO4         0b1111 // SDO4
#define OUT_FN_PPS1_U3TX         0b0001 // U3TX
#define OUT_FN_PPS1_U4RTS        0b0010 // U4RTS

/* Output Pin Group 2 */
#define OUT_PIN_PPS2_RPA15       RPA15Rbits.RPA15R
#define OUT_PIN_PPS2_RPB1        RPB1Rbits.RPB1R
#define OUT_PIN_PPS2_RPB3        RPB3Rbits.RPB3R
#define OUT_PIN_PPS2_RPC13       RPC13Rbits.RPC13R
#define OUT_PIN_PPS2_RPC4        RPC4Rbits.RPC4R
#define OUT_PIN_PPS2_RPD11       RPD11Rbits.RPD11R
#define OUT_PIN_PPS2_RPD15       RPD15Rbits.RPD15R
#define OUT_PIN_PPS2_RPD3        RPD3Rbits.RPD3R
#define OUT_PIN_PPS2_RPE5        RPE5Rbits.RPE5R
#define OUT_PIN_PPS2_RPF0        RPF0Rbits.RPF0R
#define OUT_PIN_PPS2_RPF3        RPF3Rbits.RPF3R
#define OUT_PIN_PPS2_RPF5        RPF5Rbits.RPF5R
#define OUT_PIN_PPS2_RPG0        RPG0Rbits.RPG0R
#define OUT_PIN_PPS2_RPG7        RPG7Rbits.RPG7R

#define OUT_FN_PPS2_C3OUT        0b1101 // C3OUT
#define OUT_FN_PPS2_NULL         0b0000 // No Connect
#define OUT_FN_PPS2_OC4          0b1011 // OC4
#define OUT_FN_PPS2_RSVRD1       0b0010 // Reserved
#define OUT_FN_PPS2_RSVRD2       0b0101 // Reserved
#define OUT_FN_PPS2_RSVRD3       0b0111 // Reserved
#define OUT_FN_PPS2_RSVRD4       0b1001 // Reserved
#define OUT_FN_PPS2_RSVRD5       0b1010 // Reserved
#define OUT_FN_PPS2_RSVRD6       0b1100 // Reserved
#define OUT_FN_PPS2_SDO1         0b1000 // SDO1
#define OUT_FN_PPS2_SDO2         0b0110 // SDO2
#define OUT_FN_PPS2_SDO3         0b1110 // SDO3
#define OUT_FN_PPS2_SDO4         0b1111 // SDO4
#define OUT_FN_PPS2_U1TX         0b0011 // U1TX
#define OUT_FN_PPS2_U2TX         0b0001 // U2TX
#define OUT_FN_PPS2_U5RTS        0b0100 // U5RTS

/* Output Pin Group 3 */
#define OUT_PIN_PPS3_RPB0        RPB0Rbits.RPB0R
#define OUT_PIN_PPS3_RPB15       RPB15Rbits.RPB15R
#define OUT_PIN_PPS3_RPB2        RPB2Rbits.RPB2R
#define OUT_PIN_PPS3_RPB7        RPB7Rbits.RPB7R
#define OUT_PIN_PPS3_RPB8        RPB8Rbits.RPB8R
#define OUT_PIN_PPS3_RPC3        RPC3Rbits.RPC3R
#define OUT_PIN_PPS3_RPD12       RPD12Rbits.RPD12R
#define OUT_PIN_PPS3_RPD4        RPD4Rbits.RPD4R
#define OUT_PIN_PPS3_RPD9        RPD9Rbits.RPD9R
#define OUT_PIN_PPS3_RPE3        RPE3Rbits.RPE3R
#define OUT_PIN_PPS3_RPE9        RPE9Rbits.RPE9R
#define OUT_PIN_PPS3_RPF12       RPF12Rbits.RPF12R
#define OUT_PIN_PPS3_RPF8        RPF8Rbits.RPF8R
#define OUT_PIN_PPS3_RPG6        RPG6Rbits.RPG6R

#define OUT_FN_PPS3_C1OUT        0b1101 // C1OUT
#define OUT_FN_PPS3_NULL         0b0000 // No Connect
#define OUT_FN_PPS3_OC5          0b1011 // OC5
#define OUT_FN_PPS3_REFCLKO      0b0011 // REFCLKO
#define OUT_FN_PPS3_RSVRD1       0b0101 // Reserved
#define OUT_FN_PPS3_RSVRD2       0b0110 // Reserved
#define OUT_FN_PPS3_RSVRD3       0b1001 // Reserved
#define OUT_FN_PPS3_RSVRD4       0b1010 // Reserved
#define OUT_FN_PPS3_RSVRD5       0b1100 // Reserved
#define OUT_FN_PPS3_SDO1         0b1000 // SDO1
#define OUT_FN_PPS3_SS1          0b0111 // SS1
#define OUT_FN_PPS3_SS3          0b1110 // SS3
#define OUT_FN_PPS3_SS4          0b1111 // SS4
#define OUT_FN_PPS3_U3RTS        0b0001 // U3RTS
#define OUT_FN_PPS3_U4TX         0b0010 // U4TX
#define OUT_FN_PPS3_U5TX         0b0100 // U5TX

/* Output Pin Group 4 */
#define OUT_PIN_PPS4_RPB14       RPB14Rbits.RPB14R
#define OUT_PIN_PPS4_RPB6        RPB6Rbits.RPB6R
#define OUT_PIN_PPS4_RPC2        RPC2Rbits.RPC2R
#define OUT_PIN_PPS4_RPD0        RPD0Rbits.RPD0R
#define OUT_PIN_PPS4_RPD5        RPD5Rbits.RPD5R
#define OUT_PIN_PPS4_RPD8        RPD8Rbits.RPD8R
#define OUT_PIN_PPS4_RPE8        RPE8Rbits.RPE8R
#define OUT_PIN_PPS4_RPF13       RPF13Rbits.RPF13R
#define OUT_PIN_PPS4_RPF2        RPF2Rbits.RPF2R
#define OUT_PIN_PPS4_RPF3        RPF3Rbits.RPF3R
#define OUT_PIN_PPS4_RPF6        RPF6Rbits.RPF6R
#define OUT_PIN_PPS4_RPG9        RPG9Rbits.RPG9R

#define OUT_FN_PPS4_NULL         0b0000 // No Connect
#define OUT_FN_PPS4_OC1          0b1100 // OC1
#define OUT_FN_PPS4_OC2          0b1011 // OC2
#define OUT_FN_PPS4_RSVRD1       0b1101 // Reserved
#define OUT_FN_PPS4_RSVRD2       0b0101 // Reserved
#define OUT_FN_PPS4_RSVRD3       0b0010 // Reserved
#define OUT_FN_PPS4_RSVRD4       0b1110 // Reserved
#define OUT_FN_PPS4_RSVRD5       0b0111 // Reserved
#define OUT_FN_PPS4_RSVRD6       0b1111 // Reserved
#define OUT_FN_PPS4_RSVRD7       0b1001 // Reserved
#define OUT_FN_PPS4_RSVRD8       0b1010 // Reserved
#define OUT_FN_PPS4_SDO1         0b1000 // SDO1
#define OUT_FN_PPS4_SS2          0b0110 // SS2
#define OUT_FN_PPS4_U1RTS        0b0011 // U1RTS
#define OUT_FN_PPS4_U2RTS        0b0001 // U2RTS
#define OUT_FN_PPS4_U5TX         0b0100 // U5TX(3)

 #elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
/* Output Pin Group 1 */
#define _PPS_OUTPUT_BASE_ADDRESS RPA0R // Happens to be the first one
#define OUT_PIN_PPS1_RPA0        RPA0Rbits.RPA0R
#define OUT_PIN_PPS1_RPB3        RPB3Rbits.RPB3R
#define OUT_PIN_PPS1_RPB4        RPB4Rbits.RPB4R
#define OUT_PIN_PPS1_RPB15       RPB15Rbits.RPB15R
#define OUT_PIN_PPS1_RPB7        RPB7Rbits.RPB7R
#define OUT_PIN_PPS1_RPC7        RPC7Rbits.RPC7R
#define OUT_PIN_PPS1_RPC0        RPC0Rbits.RPC0R
#define OUT_PIN_PPS1_RPC5        RPC5Rbits.RPC5R

#define OUT_FN_PPS1_NULL         0  /* No Connect */
#define OUT_FN_PPS1_U1TX         1  /* RPn tied to U1TX */
#define OUT_FN_PPS1_U2RTS        2  /* RPn tied to U2RTS_BAR */
#define OUT_FN_PPS1_SS1          3  /* RPn tied to SS1 */
//                               4  - RESERVED
#define OUT_FN_PPS1_OC1          5  /* RPn tied to OC1 */
//                               6  - RESERVED
#define OUT_FN_PPS1_C2OUT        7  /* RPn tied to C2OUT */


/* Output Pin Group 2 */
#define OUT_PIN_PPS2_RPA1        RPA1Rbits.RPA1R
#define OUT_PIN_PPS2_RPB5        RPB5Rbits.RPB5R
#define OUT_PIN_PPS2_RPB1        RPB1Rbits.RPB1R
#define OUT_PIN_PPS2_RPB11       RPB11Rbits.RPB11R
#define OUT_PIN_PPS2_RPB8        RPB8Rbits.RPB8R
#define OUT_PIN_PPS2_RPA8        RPA8Rbits.RPA8R
#define OUT_PIN_PPS2_RPC8        RPC8Rbits.RPC8R
#define OUT_PIN_PPS2_RPA9        RPA9Rbits.RPA9R

#define OUT_FN_PPS2_NULL         0  /* No Connect */
//                               1  - RESERVED
//                               2  - RESERVED
#define OUT_FN_PPS2_SDO1         3  /* RPn tied to SDO1 */
#define OUT_FN_PPS2_SDO2         4  /* RPn tied to SDO2 */
#define OUT_FN_PPS2_OC2          5  /* RPn tied to OC2 */
//                               6  - RESERVED
//                               7  - RESERVED


/* Output Pin Group 3 */
#define OUT_PIN_PPS3_RPA2        RPA2Rbits.RPA2R
#define OUT_PIN_PPS3_RPB6        RPB6Rbits.RPB6R
#define OUT_PIN_PPS3_RPA4        RPA4Rbits.RPA4R
#define OUT_PIN_PPS3_RPB13       RPB13Rbits.RPB13R
#define OUT_PIN_PPS3_RPB2        RPB2Rbits.RPB2R
#define OUT_PIN_PPS3_RPC6        RPC6Rbits.RPC6R
#define OUT_PIN_PPS3_RPC1        RPC1Rbits.RPC1R
#define OUT_PIN_PPS3_RPC3        RPC3Rbits.RPC3R

#define OUT_FN_PPS3_NULL         0  /* No Connect */
//                               1  - RESERVED
//                               2  - RESERVED
#define OUT_FN_PPS3_SDO1         3  /* RPn tied to SDO1 */
#define OUT_FN_PPS3_SDO2         4  /* RPn tied to SDO2 */
#define OUT_FN_PPS3_OC4          5  /* RPn tied to OC4 */
#define OUT_FN_PPS3_OC5          6  /* RPn tied to OC5 */
#define OUT_FN_PPS3_REFCLKO      7  /* RPn tied to REFCLKO */


/* Output Pin Group 4 */
#define OUT_PIN_PPS4_RPA3        RPA3Rbits.RPA3R
#define OUT_PIN_PPS4_RPB14       RPB14Rbits.RPB14R
#define OUT_PIN_PPS4_RPB0        RPB0Rbits.RPB0R
#define OUT_PIN_PPS4_RPB10       RPB10Rbits.RPB10R
#define OUT_PIN_PPS4_RPB9        RPB9Rbits.RPB9R
#define OUT_PIN_PPS4_RPC9        RPC9Rbits.RPC9R
#define OUT_PIN_PPS4_RPC2        RPC2Rbits.RPC2R
#define OUT_PIN_PPS4_RPC4        RPC4Rbits.RPC4R

#define OUT_FN_PPS4_NULL         0  /* No Connect */
#define OUT_FN_PPS4_U1RTS        1  /* RPn tied to U1RTS */
#define OUT_FN_PPS4_U2TX         2  /* RPn tied to U2TX */
//                               3  - RESERVED
#define OUT_FN_PPS4_SS2          4  /* RPn tied to SS2_BAR */
#define OUT_FN_PPS4_OC3          5  /* RPn tied to OC31 */
//                               6  - RESERVED
#define OUT_FN_PPS4_C1OUT        7  /* RPn tied to C1OUT */

#elif (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470)

/* Output Pin Group 1 */
#define OUT_PIN_PPS1_RPD2        RPD2Rbits.RPD2R
#define OUT_PIN_PPS1_RPG8        RPG8Rbits.RPG8R
#define OUT_PIN_PPS1_RPF4        RPF4Rbits.RPF4R
#define OUT_PIN_PPS1_RPD10       RPD10Rbits.RPD10R
#define OUT_PIN_PPS1_RPF1        RPF1Rbits.RPF1R
#define OUT_PIN_PPS1_RPB9        RPB9Rbits.RPB9R
#define OUT_PIN_PPS1_RPB10       RPB10Rbits.RPB10R
#define OUT_PIN_PPS1_RPC14       RPC14Rbits.RPC14R
#define OUT_PIN_PPS1_RPB5        RPB5Rbits.RPB5R
#define OUT_PIN_PPS1_RPC1        RPC1Rbits.RPC1R
#define OUT_PIN_PPS1_RPD14       RPD14Rbits.RPD14R
#define OUT_PIN_PPS1_RPG1        RPG1Rbits.RPG1R
#define OUT_PIN_PPS1_RPA14       RPA14Rbits.RPA14R

#define OUT_FN_PPS1_NULL         0  /* No Connect */
#define OUT_FN_PPS1_U3TX         1  /* RPn tied to U3TX */
#define OUT_FN_PPS1_U4RTS        2  /* RPn tied to U4RTS_BAR */
//                               3  - RESERVED
//                               4  - RESERVED
//                               5  - RESERVED
#define OUT_FN_PPS1_SDO2         6  /* RPn tied to SDO2 */
//                               7  - RESERVED
//                               8  - RESERVED
//                               9  - RESERVED
//                               10 - RESERVED
#define OUT_FN_PPS1_OC3          11 /* RPn tied to OC3 */
//                               12 - RESERVED
#define OUT_FN_PPS1_C2OUT        13 /* RPn tied to C2OUT */
//                               14 - RESERVED
//                               15 - RESERVED


/* Output Pin Group 2 */
#define OUT_PIN_PPS2_RPD3        RPD3Rbits.RPD3R
#define OUT_PIN_PPS2_RPG7        RPG7Rbits.RPG7R
#define OUT_PIN_PPS2_RPF5        RPF5Rbits.RPF5R
#define OUT_PIN_PPS2_RPD11       RPD11Rbits.RPD11R
#define OUT_PIN_PPS2_RPF0        RPF0Rbits.RPF0R
#define OUT_PIN_PPS2_RPB1        RPB1Rbits.RPB1R
#define OUT_PIN_PPS2_RPE5        RPE5Rbits.RPE5R
#define OUT_PIN_PPS2_RPC13       RPC13Rbits.RPC13R
#define OUT_PIN_PPS2_RPB3        RPB3Rbits.RPB3R
#define OUT_PIN_PPS2_RPF3        RPF3Rbits.RPF3R
#define OUT_PIN_PPS2_RPC4        RPC4Rbits.RPC4R
#define OUT_PIN_PPS2_RPD15       RPD15Rbits.RPD15R
#define OUT_PIN_PPS2_RPG0        RPG0Rbits.RPG0R
#define OUT_PIN_PPS2_RPA15       RPA15Rbits.RPA15R

#define OUT_FN_PPS2_NULL         0  /* No Connect */
#define OUT_FN_PPS2_U2TX         1  /* RPn tied to U2TX */
//                               2  - RESERVED
#define OUT_FN_PPS2_U1TX         3  /* RPn tied to U1TX */
#define OUT_FN_PPS2_U5RTS        4  /* RPn tied to U5RTS */
//                               5  - RESERVED
#define OUT_FN_PPS2_SDO2         6  /* RPn tied to SDO2 */
//                               7  - RESERVED
#define OUT_FN_PPS2_SDO1         8  /* RPn tied to SDO1 */
//                               9  - RESERVED
//                               10 - RESERVED
#define OUT_FN_PPS2_OC4          11 /* RPn tied to OC4 */
//                               12 - RESERVED
//                               13 - RESERVED
//                               14 - RESERVED
//                               15 - RESERVED


/* Output Pin Group 3 */
#define OUT_PIN_PPS3_RPD9        RPD9Rbits.RPD9R
#define OUT_PIN_PPS3_RPG6        RPG6Rbits.RPG6R
#define OUT_PIN_PPS3_RPB8        RPB8Rbits.RPB8R
#define OUT_PIN_PPS3_RPB15       RPB15Rbits.RPB15R
#define OUT_PIN_PPS3_RPD4        RPD4Rbits.RPD4R
#define OUT_PIN_PPS3_RPB0        RPB0Rbits.RPB0R
#define OUT_PIN_PPS3_RPE3        RPE3Rbits.RPE3R
#define OUT_PIN_PPS3_RPB7        RPB7Rbits.RPB7R
#define OUT_PIN_PPS3_RPB2        RPB2Rbits.RPB2R
#define OUT_PIN_PPS3_RPF12       RPF12Rbits.RPF12R
#define OUT_PIN_PPS3_RPD12       RPD12Rbits.RPD12R
#define OUT_PIN_PPS3_RPF8        RPF8Rbits.RPF8R
#define OUT_PIN_PPS3_RPC3        RPC3Rbits.RPC3R
#define OUT_PIN_PPS3_RPE9        RPE9Rbits.RPE9R


#define OUT_FN_PPS3_NULL         0  /* No Connect */
#define OUT_FN_PPS3_U3RTS        1  /* RPn tied to U3RTS */
#define OUT_FN_PPS3_U4TX         2  /* RPn tied to U4TX */
#define OUT_FN_PPS3_REFCLKO      3  /* RPn tied to REFCLKO */
#define OUT_FN_PPS3_U5TX         4  /* RPn tied to U5TX */
//                               5  - RESERVED
//                               6  - RESERVED
#define OUT_FN_PPS3_SS1          7  /* RPn tied to SS1 */
#define OUT_FN_PPS3_SDO1         8  /* RPn tied to SDO1 */
//                               9  - RESERVED
//                               10 - RESERVED
#define OUT_FN_PPS3_OC5          11 /* RPn tied to OC5 */
//                               12 - RESERVED
#define OUT_FN_PPS3_C1OUT        13 /* RPn tied to C1OUT */
//                               14 - RESERVED
//                               15 - RESERVED

/* Output Pin Group 4 */
#define OUT_PIN_PPS4_RPD1        RPD1Rbits.RPD1R
#define OUT_PIN_PPS4_RPG9        RPG9Rbits.RPG9R
#define OUT_PIN_PPS4_RPB14       RPB14Rbits.RPB14R
#define OUT_PIN_PPS4_RPD0        RPD0Rbits.RPD0R
#define OUT_PIN_PPS4_RPD8        RPD8Rbits.RPD8R
#define OUT_PIN_PPS4_RPB6        RPB6Rbits.RPB6R
#define OUT_PIN_PPS4_RPD5        RPD5Rbits.RPD5R
#define OUT_PIN_PPS4_RPF3        RPF3Rbits.RPF3R
#define OUT_PIN_PPS4_RPF6        RPF6Rbits.RPF6R
#define OUT_PIN_PPS4_RPF13       RPF13Rbits.RPF13R
#define OUT_PIN_PPS4_RPF2        RPF2Rbits.RPF2R
#define OUT_PIN_PPS4_RPC2        RPC2Rbits.RPC2R
#define OUT_PIN_PPS4_RPE8        RPE8Rbits.RPE8R

#define OUT_FN_PPS4_NULL         0  /* No Connect */
#define OUT_FN_PPS4_U2RTS        1  /* RPn tied to U2RTS */
//                               2  - RESERVED
#define OUT_FN_PPS4_U1RTS        3  /* RPn tied to U1RTS */
#define OUT_FN_PPS4_U5TX         4  /* RPn tied to U5TX */
//                               5  - RESERVED
#define OUT_FN_PPS4_SS2          6  /* RPn tied to SS2_BAR */
//                               7  - RESERVED
#define OUT_FN_PPS4_SDO1         8  /* RPn tied to SDO1 */
//                               9  - RESERVED
//                               10  -RESERVED
#define OUT_FN_PPS4_OC2          11 /* RPn tied to OC2 */
#define OUT_FN_PPS4_OC1          12 /* RPn tied to OC1 */
//                               13 - RESERVED
//                               14 - RESERVED
//                               15 - RESERVED
#endif


 /*********************************************************************
  Macro:            PPSOutput(grp,pin,fn)

  PreCondition:     None

  Side Effects:     None

  Overview:          The macro assigns given pin as output pin by configuring register RPORx.

  Parameters:
            grp - the group number that the peripheral or pin function

            pin - pin number(x) for which functionality has to be assigned
            *   RPx

            fn - function to be assigned for particular pin
            *   NULL
            *   CxOUT
            *   UxTX
            *   UxRTS
            *   SDOx
            *   SCKxOUT
            *   SSxOUT
            *   OCx
            *   CTMU

  Returns:      None

  Note:             None
 ********************************************************************/
#define PPSOutput(grp,pin,fn)   OUT_PIN_PPS##grp##_##pin = OUT_FN_PPS##grp##_##fn
/*----------------------------------------------------------------------------------------------------*/

 /*********************************************************************
  Macro:            PPSUnLock
  PreCondition:     The System must be unlocked
  Side Effects:     None
  Overview:          The macro performs the unlocking sequence for PPS assignment.
  Parameters:   None
  Returns:      None
  Note:             None
 ********************************************************************/
#define  PPSUnLock                  CFGCONbits.IOLOCK = 0;

 /*********************************************************************
  Macro:            PPSLock
  PreCondition:     The System must be unlocked
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:   None
  Returns:      None
 Note:              None
 ********************************************************************/
#define  PPSLock                    CFGCONbits.IOLOCK = 1;

#endif//!defined(__PPS_H)
