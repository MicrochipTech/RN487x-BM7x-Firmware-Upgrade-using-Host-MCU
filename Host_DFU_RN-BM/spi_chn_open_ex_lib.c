/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_open_lib.c
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
#include <peripheral/spi.h>
#include <peripheral/ports.h>
#include <peripheral/int.h>

#include "_spi_io_tbl.h"
#include "_spi_map_tbl.h"
#include "_spi_got_new_spi_port_question.h"

/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_


/*********************************************************************
 void SpiChnOpen(SpiChannel chn, SpiOpenFlags oFlags, SpiOpen2Flags oFlags2, unsigned int fpbDiv)
 *
 * PreCondition:    fpbDiv  - valid value between 2 and 1024
 *
 * Input:           chn     - the channel to set
 *                  oFlags  - a SpiOpenFlags or __SPIxCONbits_t structure that sets the module behavior
 *                  oFlags2 - SpiOpen2Flags
 *                  fpbDiv  - Fpb divisor to extract the baud rate: BR=Fpb/fpbDiv.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initializes the SPI channel and also sets the brg register.
 *                  The SPI baudrate BR is given by: BR=Fpb/(2*(SPIBRG+1))
 *                  The input parametes fpbDiv specifies the Fpb divisor term (2*(SPIBRG+1)),
 *                  so the BRG is calculated as SPIBRG=fpbDiv/2-1.
 *
 * Note:            - The baud rate is always obtained by dividing the Fpb to an even number
 *                  between 2 and 1024.
 *                  - When selecting the number of bits per character, SPI_OPEN_MODE32 has the highest priority.
 *                  If SPI_OPEN_MODE32 is not set, then SPI_OPEN_MODE16 selects the character width.
 *                  - The SPI_OPEN_SSEN is taken into account even in master mode. If it is set the library
 *                  will properly se the SS pin as an digital output.
 ********************************************************************/
#if defined( _GOT_NEW_SPI_PORT )
  void SpiChnOpenEx(SpiChannel chn, SpiOpenFlags oFlags, SpiOpen2Flags oFlags2, unsigned int fpbDiv)
#else
  void SpiChnOpenEx(SpiChannel chn, SpiOpenFlags oFlags,                        unsigned int fpbDiv)
#endif
{
    unsigned int    dummyRd;

    __SPIxCONbits_t     configR;
  #if defined( _GOT_NEW_SPI_PORT )
    __SPIxCON2bits_t        configR2;
  #endif
    volatile _SpiRegMap*    pReg=_SpiMapTbl[chn];
  #if !defined( _GOT_NEW_SPI_PORT )
    fConfPorts      fPorts;
    const _SpiIoDcpt*   pDcpt=_SpiIoTbl+chn;
  #endif

    INTEnable(INT_SOURCE_SPI(chn), INT_DISABLED);   // disable the channel interrupts
    pReg->conClr=__SPIxCON_MASK_(ON_MASK);      // turn off and reset

    configR.w=oFlags|__SPIxCON_MASK_(ON_MASK);  // channel configuration. make sure we turn the channel on
  #if defined( _GOT_NEW_SPI_PORT )
    configR2.w=oFlags2;
  #endif

  #if !defined( _GOT_NEW_SPI_PORT )
    // configure the output ports

    PORTSetPinsDigitalOut(pDcpt->portSdo, pDcpt->sdoMask);
    PORTSetPinsDigitalIn(pDcpt->portSdi, pDcpt->sdiMask);

    fPorts=configR.MSTEN?PORTSetPinsDigitalOut:PORTSetPinsDigitalIn;
    (*fPorts)(pDcpt->portSck, pDcpt->sckMask);      // configure the SCK

    if(configR.FRMEN || configR.SSEN)
    {
        if(configR.FRMEN)
        {
            fPorts=configR.FRMSYNC?PORTSetPinsDigitalIn:PORTSetPinsDigitalOut;
        }
        else
        {
            fPorts=configR.MSTEN?PORTSetPinsDigitalOut:PORTSetPinsDigitalIn;
        }
        (*fPorts)(pDcpt->portSS, pDcpt->ssMask);    // configure the FrmSync/SS
    }
  #endif

    INTClearFlag(INT_SOURCE_SPI(chn));      // clear the existing channel interrupt flags


    pReg->brg=(fpbDiv>>1)-1;    // set the brg
    dummyRd=pReg->buf;          // clear the receive buffer
    pReg->statClr=__SPIxSTAT_MASK_(SPIROV_MASK);    // clear overflow
  #if defined( _GOT_NEW_SPI_PORT )
    pReg->con2.w=configR2.w;    // set configuration 2
  #endif
    pReg->con.w=configR.w;      // set the configuration word


}

#endif  // _SPI_DEF_CHN_


