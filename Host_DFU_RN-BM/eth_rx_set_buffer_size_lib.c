/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        eth_rx_set_buffer_size_lib.c
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
 * Function:        EthRxSetBufferSize
 *
 * PreCondition:    0 < rxBuffSize <= 2032
 *
 * Input:           rxBuffSize - size of the rx buffers
 *
 * Output:          ETH_RES_OK for success,
 *                  an error code otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function sets the required buffer size for the receive operation.
 *                  In this implementation, all receive descriptors use the same buffer size (unlike the transmission flow
 *                  where each descriptor can have a different buffer size).
 *
 * Note:            - This function should be part of the initialization process and shoult NOT be called when the rx process is active!
 *                  - The receive buffer size is always TRUNCATED to a multiple of 16 bytes.
 *****************************************************************************/
eEthRes EthRxSetBufferSize(int rxBuffSize)
{
	rxBuffSize/=16;		// truncate
	if(!rxBuffSize)
	{
		return ETH_RES_RX_SIZE_ERR;
	}
	
	ETHCON2=rxBuffSize<<_ETHCON2_RXBUF_SZ_POSITION;
	return ETH_RES_OK;
}


#endif	// _ETH


