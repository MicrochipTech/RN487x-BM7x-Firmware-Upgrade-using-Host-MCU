/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        _dma_3xx_4xx_include.h
 * Dependencies:	Dma.h
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
 * (the “Company”) for its PIC32/PIC24F Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24F Microcontroller products.
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
 * $Id:$
 * $Name$
 *
 ********************************************************************/

#ifndef _DMA_3XX_4XX_INCLUDE_H_
#define	_DMA_3XX_4XX_INCLUDE_H_

#include <peripheral/dma.h>


#ifdef _DMA_CHANNELS

//  common DMA definitions


// translation macros to use the definitions of the available channel
// assumption that DMA channel 0 is always available

// __DCHxREGbits_t definition
#define _DCH_REG_BITS_(x, REG)		__DCH ## x ## REG ## bits_t
#define _X_DCH_REG_BITS_(x, REG)	_DCH_REG_BITS_(x, REG)		// concat macro

#define __DCHxCONbits_t			_X_DCH_REG_BITS_(0, CON)
#define __DCHxECONbits_t		_X_DCH_REG_BITS_(0, ECON)
#define __DCHxINTbits_t			_X_DCH_REG_BITS_(0, INT)



// corresponding reg masks definitions
#define _DCH_REG_MASK_(x, REG, m)	_DCH ## x ## REG ##_ ## m
#define _X_DCH_REG_MASK_(x, REG, m)	_DCH_REG_MASK_(x, REG, m)			// concat macro


#define __DCHxCON_MASK_(m)		_X_DCH_REG_MASK_(0, CON, m)
#define __DCHxECON_MASK_(m)		_X_DCH_REG_MASK_(0, ECON, m)
#define __DCHxINT_MASK_(m)		_X_DCH_REG_MASK_(0, INT, m)




typedef struct
{
	// DCHxCON
	__DCHxCONbits_t	con;
	unsigned int	conClr;
	unsigned int	conSet;
	unsigned int	conInv;
	// DCHxECON
	__DCHxECONbits_t econ;
	unsigned int 	econClr;
	unsigned int 	econSet;
	unsigned int 	econInv;
	// DCHxINT
	__DCHxINTbits_t	intr;
	unsigned int	intrClr;
	unsigned int	intrSet;
	unsigned int	intrInv;
	// DCHxSSA
	unsigned int	ssa;
	unsigned int	ssaClr;
	unsigned int	ssaSet;
	unsigned int	ssaInv;
	// DCHxDSA
	unsigned int	dsa;
	unsigned int	dsaClr;
	unsigned int	dsaSet;
	unsigned int	dsaInv;
	// DCHxSSIZ
	unsigned int	ssiz;
	unsigned int	ssizClr;
	unsigned int	ssizSet;
	unsigned int	ssizInv;
	// DCHxDSIZ
	unsigned int	dsiz;
	unsigned int	dsizClr;
	unsigned int	dsizSet;
	unsigned int	dsizInv;
	// DCHxSPTR
	unsigned int	sptr;
	unsigned int	sptrClr;
	unsigned int	sptrSet;
	unsigned int	sptrInv;
	// DCHxDPTR
	unsigned int	dptr;
	unsigned int	dptrClr;
	unsigned int	dptrSet;
	unsigned int	dptrInv;
	// DCHxCSIZ
	unsigned int	csiz;
	unsigned int	csizClr;
	unsigned int	csizSet;
	unsigned int	csizInv;
	// DCHxCPTR
	unsigned int	cptr;
	unsigned int	cptrClr;
	unsigned int	cptrSet;
	unsigned int	cptrInv;
	// DCHxDAT
	unsigned int	dat;
	unsigned int	datClr;
	unsigned int	datSet;
	unsigned int	datInv;
}_DmaRegMap;		// layout of the DMA registers
// NOTE: The layout of this structure is the same as the physical layout of a channel registers!





#define		DMA_EVENT_MASK		(__DCHxECON_MASK_(CHAIRQ_MASK)|__DCHxECON_MASK_(CHSIRQ_MASK)|__DCHxECON_MASK_(PATEN_MASK)|__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK))
								// mask in DCHxECON that preserves just the events and deletes the CFORCE and CABORT

#define		DMA_IFLAG_MASK		(__DCHxINT_MASK_(CHERIF_MASK)|__DCHxINT_MASK_(CHTAIF_MASK)|__DCHxINT_MASK_(CHCCIF_MASK)|__DCHxINT_MASK_(CHBCIF_MASK)| \
								__DCHxINT_MASK_(CHDHIF_MASK)|__DCHxINT_MASK_(CHDDIF_MASK)|__DCHxINT_MASK_(CHSHIF_MASK)|__DCHxINT_MASK_(CHSDIF_MASK))
								// mask in DCHxINT that keeps just the int flags





#define		_DmaChnWaitAbort(pReg)	while((pReg)->con.CHEN)		// waiting for the channel operation to be aborted procedure
#define		_DmaChnWaitStop(pReg)	while((pReg)->con.CHEN)		// waiting for the channel to stop




#endif	// _DMA_CHANNELS

#endif	// _DMA_3XX_4XX_INCLUDE_H_

