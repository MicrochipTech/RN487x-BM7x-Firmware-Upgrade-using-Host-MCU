/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_chn_close_lib.c
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
#include "_spi_got_new_spi_port_question.h"

#if defined( _GOT_NEW_SPI_PORT )
    //Do nothing.  SPI module is reponsible for port configuration.
#else
    #include "_spi_io_tbl.h"
#endif
#include "_spi_map_tbl.h"


/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_

/*********************************************************************
 * Function:        void SpiChnClose(SpiChannel chn)
 *
 * PreCondition:    chn - a valid SPI channel number
 *
 * Input:           chn     - the channel to close
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function closes the SPI channel. Some previous error conditions are cleared.
 *                  Channel interrupts are disabled.
 *
 * Note:        - The I/O pins used by the SPI module are returned to their reset configuration.
 *          - The SPI_OPEN_SSEN is used to decide if the SS pin has to be returned to the reset state.
 ********************************************************************/
void SpiChnClose(SpiChannel chn)
{
    __SPIxCONbits_t      conR;
    volatile _SpiRegMap* pReg=_SpiMapTbl[chn];
  #if defined( _GOT_NEW_SPI_PORT )
    //Do nothing.  SPI module is responsible for port configuration.
  #else
    const _SpiIoDcpt* pDcpt=_SpiIoTbl+chn;
  #endif

    conR.w=pReg->con.w;
    pReg->conClr=__SPIxCON_MASK_(ON_MASK);      // turn off and reset

    INTEnable(INT_SOURCE_SPI(chn), INT_DISABLED);       // disable the interrupts
    INTClearFlag(INT_SOURCE_SPI(chn));      // clear the existing flags

  #if defined( _GOT_NEW_SPI_PORT )
    //Do nothing.  SPI module is responsible for port configuration.
  #else
    PORTResetPins(pDcpt->portSdo, pDcpt->sdoMask);
    PORTResetPins(pDcpt->portSdi, pDcpt->sdiMask);
    PORTResetPins(pDcpt->portSck, pDcpt->sckMask);

    if(conR.FRMEN || conR.SSEN)
    {
        PORTResetPins(pDcpt->portSS, pDcpt->ssMask);
    }
  #endif
}


#endif  // _SPI_DEF_CHN_

