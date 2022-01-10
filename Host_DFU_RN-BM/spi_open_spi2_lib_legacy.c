/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_open_spi2_lib_legacy.c
 * Dependencies:    Spi.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB C Compiler for PIC32 MCUs
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
#include <peripheral/legacy/spi_legacy.h>

#ifdef _SPI2

extern const int _SpiBrgConvTbl[32];

/*********************************************************************
 * Function:      void OpenSPI2(unsigned int config1,unsigned int config2)
 *
 * Condition:     None
 *
 * Input:         config1 - same as in OpenSPI1
 *      config2 - sets the module behavior using the SpiOpenConfig2 bits:
 *      typedef union
 *     {
 *      struct
 *      {
 *       unsigned:   6;  // reserved
 *       unsigned SPIROV: 1;  // receiver overflow
 *       unsigned:   25;  // reserved
 *      };        // field access
 *      unsigned int   w;  // word access
 *     }SpiOpenConfig2;
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initializes and enables the SPI module.
 *
 * Note:  1. SpiOpenConfig1::PPRE and SpiOpenConfig1::SPRE fields are use only 
 *           for backward compatibility reasons only. They don't correspond to 
 *           physical bits into the SPI control register.
 *        2. When selecting the number of bits per character, MODE32 has the 
 *           highest priority. If MODE32 is not set, then MODE16 selects the 
 *           character width.
 *        3. The format of configuration words is chosen for backward 
 *           compatibility reasons. The config words don't reflect the actual 
 *           register bits.
 ********************************************************************/
void OpenSPI2(unsigned int config1, unsigned int config2)
{
  SPI2BRG=_SpiBrgConvTbl[config1&0x1f]; /* keep the prescaler 5 bits */

  if ( !((SpiOpenConfig2)config2).SPIROV )
    {
#if defined (_SPI2STAT_SPIROV_MASK)
      SPI2STATCLR=_SPI2STAT_SPIROV_MASK;  /* clear overrun */
#else
#error _SPI2STAT_SPIROV_MASK is not defined for this device
#endif
    }
  /* get FRMEN, FRMSYNC, DISSDO-MSTEN; get FRMPOL, SPIFE, ON, SIDL */
  SPI2CON=(config1&0xc0001fe0u)|(config2&0x2002a000u);
}

#endif /* _SPI2 */

