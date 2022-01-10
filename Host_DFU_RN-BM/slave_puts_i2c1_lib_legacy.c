/******************************************************************************
 *
 *                  I2C PERIPHERAL LIBRARY API
 *
 ******************************************************************************
 * FileName:        I2c Lib API
 * Dependencies:    See include below
 * Processor:       PIC32
 * Compiler:        MPLAB XC32
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
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
 * ****************************************************************************
 *
 * $Id: $
 *
 * $Name:  $
 *
 *****************************************************************************/

#include <xc.h>
#include <peripheral/i2c.h>
#if(defined(__32MX330F064H__)||\
    defined(__32MX330F064L__)||\
    defined(__32MX350F128H__)||\
    defined(__32MX350F128L__)||\
    defined(__32MX350F256H__)||\
    defined(__32MX350F256L__)||\
    defined(__32MX370F512H__)||\
    defined(__32MX370F512L__)||\
    defined(__32MX430F064H__)||\
    defined(__32MX430F064L__)||\
    defined(__32MX450F128H__)||\
    defined(__32MX450F128L__)||\
    defined(__32MX450F256H__)||\
    defined(__32MX450F256L__)||\
    defined(__32MX470F512H__)||\
    defined(__32MX470F512L__))
 #define TableB
#endif

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
  #define TableB
#endif

#ifdef _I2C1

/**************************************************************************
*    Function Name:  SlaveputsI2C1
*    Description:    This routine is used to write out a string to the
*                    I2C bus.If write collision occurs,-3 is sent.If
*                    string is written and null char reached, 0 is returned.
*    Parameters:     unsigned char * : wrptr
*    Return Value:   unsigned int
****************************************************************************/
unsigned int SlaveputsI2C1(unsigned char * wrptr)
{
    I2C1CONbits.STREN = 1;            /* SCL clock stretch enable bit */
    while(*wrptr)                /* transmit data until null char */
    {
        SlaveputcI2C1(*wrptr++);         /* Send a byte */
        while(I2C1STATbits.TBF);         /* wait till the transmit buffer is clear */
#if (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__) || defined TableB)
        while(!IFS1bits.I2C1SIF);     /* Wait till the ACK from master is received */
#else
        while(!IFS0bits.I2C1SIF);     /* Wait till the ACK from master is received */
#endif
    }
    return 0;                        /* null char was reached */
}

#endif

