/*********************************************************************
 *
 *                  PORTSetBits lib function
 *
 *********************************************************************
 * FileName:        port_set_bits_lib.c
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
#include <xc.h>
#include <peripheral/ports.h>
#include "_ports_tbl_libp.h"

extern const PortRegDcpt	PortRegTbl[];

/******************************************************************************
 * Sets digital port bits
 *
 * Function:        void	PORTSetBits(IoPortId portId, unsigned int bits);
 *
 * Description:		Writes selected bits to PORTSET register
 *
 * PreCondition:    None
 *
 * Inputs:			portID: Enumerated PORT Identifier - see ports.h
 *
 *					bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:			PORTSetBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *					Note: Bit definitions are located in \include\proc\ppic32mx.h
 *****************************************************************************/
	void	PORTSetBits(IoPortId portId, unsigned int bits)
	{
		const PortRegDcpt* pDcpt=PortRegTbl+portId;
		pDcpt->pPortReg->latSet = bits;
	}

