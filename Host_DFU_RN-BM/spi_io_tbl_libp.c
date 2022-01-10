/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        _spi_io_tbl_lipb.c
 * Dependencies:    Spi.h
 *                  Ports.h
 *                  _spi_io_tbl.h
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


#include <peripheral/spi.h>
#include <peripheral/ports.h>

#include "_spi_io_tbl.h"
#include "_spi_got_new_spi_port_question.h"

#ifdef _SPI_DEF_CHN_

#if (((__PIC32_FEATURE_SET__ >= 300) && (__PIC32_FEATURE_SET__ <= 499)) || defined(__32MXGENERIC__))
    // ADJUSTING FOR DIFFERENT NAMING PIC32MX3XXX VS PIC32MX5XXX AND HIGHER
    // SPI1_* #defines are found in ppic32mx.h, which is #included at the
    // bottom of every p32mx*.h processor header file.  The file ppic32mx.h is
    // a generic header file for backwards compatibility with old C32 v1.xx code
    #ifdef _SPI1
        #undef  _SPI1_CLK_PORT
        #define _SPI1_CLK_PORT  SPI1_CLK_PORT
        #undef  _SPI1_CLK_BIT
        #define _SPI1_CLK_BIT   SPI1_CLK_BIT

        #undef  _SPI1_SDO_PORT
        #define _SPI1_SDO_PORT  SPI1_SDO_PORT
        #undef  _SPI1_SDO_BIT
        #define _SPI1_SDO_BIT   SPI1_SDO_BIT

        #undef  _SPI1_SDI_PORT
        #define _SPI1_SDI_PORT  SPI1_SDI_PORT
        #undef  _SPI1_SDI_BIT
        #define _SPI1_SDI_BIT   SPI1_SDI_BIT

        #undef  _SPI1_SS_PORT
        #define _SPI1_SS_PORT   SPI1_SS_PORT
        #undef  _SPI1_SS_BIT
        #define _SPI1_SS_BIT    SPI1_SS_BIT
    #endif // _SPI1

    // ADJUSTING FOR DIFFERENT NAMING PIC32MX3XXX VS PIC32MX5XXX AND HIGHER
    // SPI2_* #defines are found in ppic32mx.h, which is #included at the
    // bottom of every p32mx*.h processor header file.  The file ppic32mx.h is
    // a generic header file for backwards compatibility with old C32 v1.xx code
    #ifdef _SPI2
        #undef  _SPI2_CLK_PORT
        #define _SPI2_CLK_PORT  SPI2_CLK_PORT
        #undef  _SPI2_CLK_BIT
        #define _SPI2_CLK_BIT   SPI2_CLK_BIT

        #undef  _SPI2_SDO_PORT
        #define _SPI2_SDO_PORT  SPI2_SDO_PORT
        #undef  _SPI2_SDO_BIT
        #define _SPI2_SDO_BIT   SPI2_SDO_BIT

        #undef  _SPI2_SDI_PORT
        #define _SPI2_SDI_PORT  SPI2_SDI_PORT
        #undef  _SPI2_SDI_BIT
        #define _SPI2_SDI_BIT   SPI2_SDI_BIT

        #undef  _SPI2_SS_PORT
        #define _SPI2_SS_PORT   SPI2_SS_PORT
        #undef  _SPI2_SS_BIT
        #define _SPI2_SS_BIT    SPI2_SS_BIT
    #endif // _SPI2

#endif

#if defined( _GOT_NEW_SPI_PORT )
// This initialization of this table must be done by the main application once pins have been assigned
// using PPS.
    // table with values of the SPI IO ports and pins
    _SpiIoDcpt  _SpiIoTbl[]= // Not constant because of PPS.  To be filled in by user later.
    {
        // NOTE: SPI channel number 0 is invalid. For legacy reasons, the first SPI channel is 1.
        {
            IOPORT_NUM, 0,      // invalid/unused entries
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        }

    };

#else
    // table with values of the SPI IO ports and pins
    const _SpiIoDcpt    _SpiIoTbl[]=
    {
        // NOTE: SPI channel number 0 is invalid. For legacy reasons, the first SPI channel is 1.
        {
            IOPORT_NUM, 0,      // invalid/unused entries
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },


    #ifdef _SPI1
        {
            _SPI1_CLK_PORT, _SPI1_CLK_BIT,
            _SPI1_SDO_PORT, _SPI1_SDO_BIT,
            _SPI1_SDI_PORT, _SPI1_SDI_BIT,
            _SPI1_SS_PORT,  _SPI1_SS_BIT
        },
    #else
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
    #endif  // _SPI1

    #if defined(_SPI2)
        {
            _SPI2_CLK_PORT, _SPI2_CLK_BIT,
            _SPI2_SDO_PORT, _SPI2_SDO_BIT,
            _SPI2_SDI_PORT, _SPI2_SDI_BIT,
            _SPI2_SS_PORT,  _SPI2_SS_BIT
        },
    #else
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
    #endif  // _SPI2

    #ifdef _SPI3
        {
            _SPI3_CLK_PORT, _SPI3_CLK_BIT,
            _SPI3_SDO_PORT, _SPI3_SDO_BIT,
            _SPI3_SDI_PORT, _SPI3_SDI_BIT,
            _SPI3_SS_PORT,  _SPI3_SS_BIT
        },
    #else
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
    #endif  // _SPI3

    #ifdef _SPI4
        {
            _SPI4_CLK_PORT, _SPI4_CLK_BIT,
            _SPI4_SDO_PORT, _SPI4_SDO_BIT,
            _SPI4_SDI_PORT, _SPI4_SDI_BIT,
            _SPI4_SS_PORT,  _SPI4_SS_BIT
        },
    #else
        {
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
            IOPORT_NUM, 0,
        },
    #endif  // _SPI4

    };

#endif//(((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))

#endif  // _SPI_DEF_CHN_


