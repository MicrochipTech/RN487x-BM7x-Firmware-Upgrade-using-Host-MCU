/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        eth_close_lib.c
 * Dependencies:
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * Microchip Audio Library – PIC32 Software.
 * Copyright © 2008 Microchip Technology Inc.  All rights reserved.
 * 
 * Microchip licenses the Software for your use with Microchip microcontrollers
 * and Microchip digital signal controllers pursuant to the terms of the
 * Non-Exclusive Software License Agreement accompanying this Software.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY
 * OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION,
 * ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS
 * FOR A PARTICULAR PURPOSE.
 * MICROCHIP AND ITS LICENSORS ASSUME NO RESPONSIBILITY FOR THE ACCURACY,
 * RELIABILITY OR APPLICATION OF THE SOFTWARE AND DOCUMENTATION.
 * IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED
 * UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH
 * OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL,
 * SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
 * SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED
 * TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 *$Id: $
 ********************************************************************/

#include "_eth_include.h"


#ifdef _ETH	// the Ethernet device is present




/****************************************************************************
 * Function:        EthClose
 *
 * PreCondition:    None
 *
 * Input:           cFlags - closing flags
 *
 * Output:          ETH_RES_OK  
 *
 * Side Effects:    None
 *
 * Overview:        This function performs the abort of any current Eth transaction.
 *                  It disables the Eth controller and the interrupts.
 *                  It should be called after the PHY close/reset procedure. 
 *
 * Note:            It does not free any allocated memory.
 *****************************************************************************/
eEthRes EthClose(eEthCloseFlags cFlags)
{
	// disable Rx, Tx, Eth controller itself

	INTEnable(INT_ETHERNET, INT_DISABLED);	// disable ethernet interrupts

	if(cFlags&ETH_CLOSE_GRACEFUL)
	{
		ETHCON1CLR=_ETHCON1_TXRTS_MASK;	// stop tx
		while(ETHSTATbits.TXBUSY);	// wait tx down
		while(ETHSTATbits.RXBUSY);	// wait rx down
	}
	
	ETHCON1CLR=_ETHCON1_TXRTS_MASK|_ETHCON1_RXEN_MASK;	// stop rx/tx

	_EthMacReset();


	ETHCON1CLR=_ETHCON1_ON_MASK;	// disable it
	while(ETHSTATbits.ETHBUSY);	// wait everything down
	
	INTClearFlag(INT_ETHERNET);	// clear the interrupt controller flag
	ETHIRQCLR=0xffffffff;		// clear any existing interrupt event	
	

	return ETH_RES_OK;
}


#endif	// _ETH


