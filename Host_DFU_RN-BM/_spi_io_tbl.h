/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        _spi_io_tbl.h
 * Dependencies:    Spi.h
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

// definition for the SpiIoDcpt structure

#ifndef __SPIIOTbl_H_
#define __SPIIOTbl_H_


#include <peripheral/spi.h>
#include <peripheral/ports.h>
#include "_spi_got_new_spi_port_question.h"

#ifdef _SPI_DEF_CHN_

  typedef struct
  {
      unsigned int    portSck;
      unsigned int    sckMask;

      unsigned int    portSdo;
      unsigned int    sdoMask;

      unsigned int    portSdi;
      unsigned int    sdiMask;

      unsigned int    portSS;
      unsigned int    ssMask;
  }_SpiIoDcpt;

  #if defined( _GOT_NEW_SPI_PORT )
    extern _SpiIoDcpt _SpiIoTbl[]; // Cannot be constant because of PPS!
  #else
    extern  const _SpiIoDcpt    _SpiIoTbl[];
  #endif

  typedef void (*fConfPorts)(IoPortId portId, unsigned int inputs);   // function to configure ports IO as in/out

#endif  // _SPI_DEF_CHN_

#endif  // __SPIIOTbl_H_


