/*********************************************************************
 *
 *                  Ports device specific table defs
 *
 *********************************************************************
 * FileName:        _ports_tbl_libp.h
 * Dependencies:
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
 * (the “Company”) for its PIC32/PIC24 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24 Microcontroller products.
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
 *
 ********************************************************************/
#ifndef _PORTS_TBL_LIPB_H
#define _PORTS_TBL_LIPB_H

typedef struct
{
	volatile unsigned int	tris;
	volatile unsigned int	trisClr;
	volatile unsigned int	trisSet;
	volatile unsigned int	trisInv;
	volatile unsigned int	port;
	volatile unsigned int	portClr;
	volatile unsigned int	portSet;
	volatile unsigned int	portInv;
	volatile unsigned int	lat;
	volatile unsigned int	latClr;
	volatile unsigned int	latSet;
	volatile unsigned int	latInv;
	volatile unsigned int	odcfg;
	volatile unsigned int	odcfgClr;
	volatile unsigned int	odcfgSet;
	volatile unsigned int	odcfgInv;
}PortRegMap;	// port registers layout


typedef struct
{
	volatile unsigned int	reg;
	volatile unsigned int	regClr;
	volatile unsigned int	regSet;
	volatile unsigned int	regInv;
}AnConReg;


typedef struct
{
	PortRegMap*	    pPortReg;
	unsigned int	analogMask;
	AnConReg*	    pConR;
}PortRegDcpt;

#endif
