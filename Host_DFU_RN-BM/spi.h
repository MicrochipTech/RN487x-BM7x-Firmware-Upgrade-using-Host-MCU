/*********************************************************************
 *
 *                  SPI Library definitions
 *
 *********************************************************************
 * FileName:        spi.h
 * Dependencies:
 * Processor:       PIC32
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
 *
 ********************************************************************/

#ifndef _PIC32SPI_HEADER_FILE
#define _PIC32SPI_HEADER_FILE

#include <xc.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
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
  #include <peripheral/spi_1xx_2xx_5xx.h>
#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #include <peripheral/spi_1xx_2xx.h>
#elif  ((__PIC32_FEATURE_SET__ >= 300) && (__PIC32_FEATURE_SET__ <= 499))
  #include <peripheral/spi_3xx_4xx.h>
#elif  ((__PIC32_FEATURE_SET__ >= 500) && (__PIC32_FEATURE_SET__ <= 799))
  #include <peripheral/spi_5xx_6xx_7xx.h>
#else
  #error "Device not supported by the SPI peripheral library"
#endif

#endif  // _PIC32SPI_HEADER_FILE



