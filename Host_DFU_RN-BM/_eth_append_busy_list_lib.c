/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        _eth_append_busy_list_lib.c
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
 * Function:        _EthAppendBusyList
 *
 * PreCondition:    None
 *
 * Input:           pBusyList  - busy list under hw control to add nodes to
 *                  pNewList   - list with descriptors to be added to the busy one
 *                  rxAck      - acknowledge the hw, it's an rx list
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function appends a list to the list of busy descriptors owned by the hw.
 *                  The new list to be added is supposed to have all the descriptors properly set.
 *
 * Note:            The late acknowledge for the head of the append list is to avoid a deadlock:
 *                  if hw is stuck on the end of list descriptors, decrementing the bufcnt will force re-fetch of the same
 *                  end descriptor and won't do much good.
 *                  We have to specifically write the BUFCDEC when there's a new descriptor seen by the hw that has EOWN=1.
 *****************************************************************************/
void _EthAppendBusyList(sEthDcptList* pBusyList, sEthDcptList* pNewList, int rxAck)
{
	sEthDNode	*head, *tail, *pN;
	

	tail=pBusyList->tail;
	head=SlRemoveHead(pNewList);
	head->hwDcpt.hdr.EOWN=0;	// not hw owned yet!
		
	// add all the required new descriptors/buffers
	while((pN=SlRemoveHead(pNewList)))
	{
		SlAddTail(pBusyList, pN);
		if(rxAck && !pN->hwDcpt.hdr.rx_nack)
		{
			ETHCON1SET=_ETHCON1_BUFCDEC_MASK;	// one more descriptor added
		}
	}

	
	head->next=tail->next;
	head->hwDcpt.next_ed=tail->hwDcpt.next_ed;	// proper connection needed
	*tail=*head;			// replace the prev tail

	head->hwDcpt.hdr.w=0;	// make it invalid descriptor for searches!
	SlAddTail(pBusyList, head);	// end properly, with EOWN=0;
	tail->hwDcpt.hdr.EOWN=1;	// ready to go!	
	if(rxAck && !tail->hwDcpt.hdr.rx_nack)
	{
		ETHCON1SET=_ETHCON1_BUFCDEC_MASK;	// acknowledge the head of the list
	}

}



#endif	// _ETH


