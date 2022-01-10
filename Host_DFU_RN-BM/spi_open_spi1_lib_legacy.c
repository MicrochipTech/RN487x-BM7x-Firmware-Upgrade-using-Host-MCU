/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_open_spi1_lib_legacy.c
 * Dependencies:	Spi.h
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
#include <peripheral/legacy/spi_legacy.h>


#ifdef _SPI1

extern const int	_SpiBrgConvTbl[32];


/*********************************************************************
 * Function:        void OpenSPI1(unsigned int config1,unsigned int config2)
 *
 * Condition:    	None
 *
 * Input:           config1	- sets the module behavior using the SpiOpenConfig1 bits:
 *
 *					  	typedef union
 *						{
 *							struct
 *							{
 *							    unsigned PPRE:		2;		// primary prescaler
 *							    unsigned SPRE:		3;		// secondary prescaler
 *							    unsigned MSTEN:		1;		// master mode enable
 *							    unsigned CKP:		1;		// clock polarity
 *							    unsigned SSEN:		1;		// slave select
 *							    unsigned CKE:		1;		// clock edge
 *							    unsigned SMP:		1;		// sample phase
 *							    unsigned MODE16:	1;		// word/hword/byte communication select
 *							    unsigned MODE32:	1;		// word/hword/byte communication select
 *							    unsigned DISSDO:	1;		// disable SDO pin
 *							    unsigned:			17;		// reserved
 *							    unsigned FRMSYNC:	1;		// frame sync direction
 *								unsigned FRMEN:		1;		// framed SPI
 *							};								// field access
 *							unsigned int			w;		// word access
 *						}SpiOpenConfig1;
 *
 *
 *
 *
 *
 * 					config2	- sets the module behavior using the SpiOpenConfig2 bits:
 *						typedef union
 *						{
 *							struct
 *							{
 *								unsigned:			6;		// reserved
 *								unsigned SPIROV:	1;		// receiver overflow
 *								unsigned:			6;		// reserved
 *								unsigned SIDL:		1;		// stop in idle
 *								unsigned:   		1;		// 
 *								unsigned ON:		1;		// enable peripheral
 *								unsigned:			1;		// reserved
 *								unsigned SPIFE:		1;		// frame edge select
 *								unsigned:			11;		//
 *							    unsigned FRMPOL:	1;		// frame sync polarity
 *							};								// field access
 *							unsigned int			w;		// word access
 *						}SpiOpenConfig2;
 *
 * Output:          None
 * Side Effects:    None
 * Overview:        This function initializes and enables the SPI module.
 *
 * Note:            1. SpiOpenConfig1::PPRE and SpiOpenConfig1::SPRE fields are use only for
 * 					backward compatibility reasons only. They don't correspond to physical
 * 					bits into the SPI control register.
 * 					2. When selecting the number of bits per character, MODE32 has the highest priority.
 * 					If MODE32 is not set, then MODE16 selects the character width.
 * 					3. The format of configuration words is chosen for backward compatibility reasons.
 * 					The config words don't reflect the actual register bits.
 ********************************************************************/
void OpenSPI1(unsigned int config1, unsigned int config2)
{
	SPI1BRG=_SpiBrgConvTbl[config1&0x1f];	// keep the prescaler 5 bits

	if( !((SpiOpenConfig2)config2).SPIROV )
	{
		SPI1STATCLR=_SPI1STAT_SPIROV_MASK;		// clear overrun
	}

	SPI1CON=(config1&0xc0001fe0)|(config2&0x2002a000);		// get FRMEN, FRMSYNC, DISSDO-MSTEN; get FRMPOL, SPIFE, ON, SIDL
															// set control word
}
#endif	//_SPI1

