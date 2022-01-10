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

#include "_spi_io_tbl.h"
#include "_spi_map_tbl.h"
#include "_spi_got_new_spi_port_question.h"


/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_


/*********************************************************************
 * Function:        void SpiChnConfigureEx(SpiChannel chn, SpiConfigFlags config, SpiConfig2Flags config2)
 *
 * PreCondition:    chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set
 *                  config - any of the values from SpiConfigFlags:
 *                             master slave configure: SPI_CONFIG_MSTEN, SPI_CONFIG_SLVEN, SPI_CONFIG_SSEN
 *                             clocking and character configuration: SPI_CONFIG_CKP, SPI_CONFIG_CKE, SPI_CONFIG_SMP, SPI_CONFIG_MODE8, SPI_CONFIG_MODE16, SPI_CONFIG_MODE32
 *                             framed mode configuration: SPI_CONFIG_SPIFE, SPI_CONFIG_FRMPOL, SPI_CONFIG_FRMSYNC, SPI_CONFIG_FRMEN
 *                             general configuration: SPI_CONFIG_DISSDO, SPI_CONFIG_SIDL, SPI_CONFIG_ON
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is an alternative to SpiChnOpen. The application can first configure and then turn ON the channel.
 *                  The function performs the configuration of the SPI channel according to the config input parameter.
 *
 * Note:            - The channel is NOT turned off by this function; It should be turned off before calling this function.
 *                  - The pending interrupts are NOT cleared or disabled.
 *                  - The function does NOT set the SPI pins as digital i/o pins.
 *                  - The SPI channel is configured but NOT turned ON. Use SpiChnEnable(1) to turn ON the channel.
 *                  - When selecting the number of bits per character, SPI_CONFIG_MODE32 has the highest priority.
 *                  If SPI_CONFIG_MODE32 is not set, then SPI_CONFIG_MODE16 selects the character width.
 *
 * Example:        SpiChnEnable(SPI_CHANNEL1, 0);
 *                 SpiChnConfigureEx(SPI_CHANNEL1, SPI_CONFIG_MSTEN|SPI_CONFIG_SMP|SPI_CONFIG_MODE32, SPI_OPEN2_AUDEN|SPI_OPEN2_AUDMOD_I2S);
 *                 SpiChnEnable(SPI_CHANNEL1, 1);
 *                 will configure and then enable the SPI1.
 ********************************************************************/
#if defined( _GOT_NEW_SPI_PORT )
  void SpiChnConfigureEx(SpiChannel chn, SpiConfigFlags config, SpiConfig2Flags config2)
#else
  void SpiChnConfigureEx(SpiChannel chn, SpiConfigFlags config                         )
#endif
{
    unsigned int        dummyRd;
    __SPIxCONbits_t     configR;
    volatile _SpiRegMap*    pReg=_SpiMapTbl[chn];

    configR.w=config&(~__SPIxCON_MASK_(ON_MASK));   // channel configuration. make sure we don't turn the channel on

    dummyRd=pReg->buf;              // clear the receive buffer
    pReg->statClr=__SPIxSTAT_MASK_(SPIROV_MASK);    // clear overflow
  #if defined( _GOT_NEW_SPI_PORT )
    pReg->con2.w=config2;
  #endif
    pReg->con.w=configR.w;              // set the configuration word

}

#endif  // _SPI_DEF_CHN_


