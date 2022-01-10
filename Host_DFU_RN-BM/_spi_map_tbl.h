/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        _spi_map_tbl.h
 * Dependencies:    Spi.h
 *                  _SPIMapTbl.h
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
 * $Id$
 * $Name$
 *
 ********************************************************************/
#ifndef __SPIMapTbl_H_
#define __SPIMapTbl_H_

#include <peripheral/spi.h>

#ifdef _SPI_DEF_CHN_

#if (\
        defined(__32MX120F064H__)    || \
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
     ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || \
      (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470) || \
      defined(__32MXGENERIC__) \
    )
  #define  _SPI_REV_1XX_
#elif  ((__PIC32_FEATURE_SET__ >= 300) && (__PIC32_FEATURE_SET__ <= 499))
  #define  _SPI_REV_3XX_
#elif  ((__PIC32_FEATURE_SET__ >= 500) && (__PIC32_FEATURE_SET__ <= 799))
  #define  _SPI_REV_5XX_
#else
  #error "Device not supported by the SPI peripheral library"
#endif

// translation macros to use the definitions of the available channel

// __SPIxREGbits_t definition
#define _SPI_REG_BITS_(x, REG)      __SPI ## x ## REG ## bits_t
#define _X_SPI_REG_BITS_(x, REG)    _SPI_REG_BITS_(x, REG)      // concat macro

#define __SPIxCONbits_t         _X_SPI_REG_BITS_(_SPI_DEF_CHN_, CON)
#ifdef _SPI_REV_1XX_
#define __SPIxCON2bits_t        _X_SPI_REG_BITS_(_SPI_DEF_CHN_, CON2)
#endif
#define __SPIxSTATbits_t        _X_SPI_REG_BITS_(_SPI_DEF_CHN_, STAT)


// corresponding reg masks definitions
#define _SPI_REG_MASK_(x, REG, m)   _SPI ## x ## REG ##_ ## m
#define _X_SPI_REG_MASK_(x, REG, m) _SPI_REG_MASK_(x, REG, m)           // concatenation macro


#define __SPIxCON_MASK_(m)      _X_SPI_REG_MASK_(_SPI_DEF_CHN_, CON, m)
#define __SPIxCON2_MASK_(m)     _X_SPI_REG_MASK_(_SPI_DEF_CHN_, CON2, m)
#define __SPIxSTAT_MASK_(m)     _X_SPI_REG_MASK_(_SPI_DEF_CHN_, STAT, m)


    typedef struct
    {
        __SPIxCONbits_t     con;
        unsigned int        conClr;
        unsigned int        conSet;
        unsigned int        conInv;
        __SPIxSTATbits_t    stat;
        unsigned int        statClr;
        unsigned int        statSet;
        unsigned int        statInv;
        unsigned int        buf;
        unsigned int        rsvdBuf[3];
        unsigned int        brg;
        unsigned int        brgClr;
        unsigned int        brgSet;
        unsigned int        brgInv;
        #ifdef _SPI_REV_1XX_
        __SPIxCON2bits_t    con2;
        unsigned int        con2Clr;
        unsigned int        con2Set;
        unsigned int        con2Inv;
        #endif
    }_SpiRegMap;        // layout of SPI registers


extern volatile _SpiRegMap* const _SpiMapTbl[];


#ifdef  _SPI_REV_3XX_
    #define _SpiIsRxAvlbl(pReg) ((pReg)->stat.SPIRBF!=0)
    #define _SpiIsTxAvlbl(pReg) ((pReg)->stat.SPITBE!=0)
#else

extern __inline__ int __attribute__((always_inline))    _SpiIsRxAvlbl(volatile _SpiRegMap* pReg)
{
    if(pReg->con.ENHBUF)
    {
        return pReg->stat.SPIRBE==0;
    }
    else
    {
        return pReg->stat.SPIRBF!=0;
    }
}

extern __inline__ int __attribute__((always_inline))    _SpiIsTxAvlbl(volatile _SpiRegMap* pReg)
{
    if(pReg->con.ENHBUF)
    {
        return pReg->stat.SPITBF==0;
    }
    else
    {
        return pReg->stat.SPITBE!=0;
    }

}
#endif


#endif  // _SPI_DEF_CHN_


#endif  // __SPIMapTbl_H_

