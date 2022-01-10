/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        Eth.c
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

#include <peripheral/eth.h>

#ifdef _ETH	// the Ethernet device is present

#include <sys/kmem.h>

#include <peripheral/int.h>

#include "_eth_dcpt_lists.h"


// local definitions
//


// local prototypes
// 

sEthDNode*	_EthFindPacket(const void* pBuff, sEthDcptList* pList);

eEthRes		_EthAckPacket(const void* pBuff, sEthDcptList* pRemList, sEthDcptList* pAddList, pEthBuffAck ackFnc, void* fParam);

void		_EthAppendBusyList(sEthDcptList* pBusyList, sEthDcptList* pNewList, int rxAck);

void        _EthPoolFreeDcptList(sEthDcptList* pList, pEthDcptFree fFree, void* fParam);

void		_EthFreeDcptList(sEthDcptList* pList, pEthDcptFreeF fFree);

// local data
// 
extern sEthDcptList _EthTxFreeList;		// transmit list of free descriptors
extern sEthDcptList _EthTxBusyList;		// transmit list of descriptors passed to the Tx Engine
						// the TxBusyList always ends with an sw owned descriptor (hdr.EOWN=0);
					
extern sEthDcptList _EthRxFreeList;		// receive list of free descriptors
extern sEthDcptList _EthRxBusyList;		// receive list of descriptors passed to the Rx Engine




// local function implementation
//

extern __inline__ void __attribute__((always_inline)) _EthMacReset(void)
{
	EMACxCFG1=_EMACxCFG1_SOFTRESET_MASK;	// reset
	EMACxCFG1=0;				// clear reset
}

extern __inline__ void __attribute__((always_inline)) _EthMacInit(void)
{
	_EthMacReset();
	EMACxMAXF=0x600;			// allow VLAN tagged frames
}



#endif	// _ETH


