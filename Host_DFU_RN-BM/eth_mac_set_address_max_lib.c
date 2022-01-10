/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        eth_mac_set_address_max_lib.c
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

#include <string.h>

/****************************************************************************
 * Function:        EthMACSetAddress
 *
 * PreCondition:    None
 *
 * Input:           bAddress - standard MAC address, 6 bytes, Network order!
 *
 * Output:          None  
 *
 * Side Effects:    None
 *
 * Overview:        This function sets the MAC address.
 *
 * Note:            The default MAC address is loaded by the device at reset from the fuses.
 *****************************************************************************/
void EthMACSetAddress(unsigned char bAddress[6])
{
    union
    {
        double          align;          // 8 bytes aligned
        unsigned char   addr[6];        // MAC address, network order
    }uA;       // aligned MAC address

    memcpy(uA.addr, bAddress, sizeof(uA.addr)); // align properly
    unsigned short* pS=(unsigned short*)uA.addr;
	EMACxSA2=*pS++;
	EMACxSA1=*pS++;
	EMACxSA0=*pS;
}


/****************************************************************************
 * Function:        EthMACGetAddress
 *
 * PreCondition:    None
 *
 * Input:           bAddress - address to store a standard MAC address, 6 bytes, Network order!
 *
 * Output:          None  
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the current MAC address.
 *
 * Note:            None
 *****************************************************************************/
void EthMACGetAddress(unsigned char bAddress[6])
{
    union
    {
        double          align;          // 8 bytes aligned
        unsigned char   addr[6];        // MAC address, network order
    }uA;       // aligned MAC address

    unsigned short* pS=(unsigned short*)uA.addr;    // align properly
	*pS++=EMACxSA2;
	*pS++=EMACxSA1;
	*pS=EMACxSA0;

    memcpy(bAddress, uA.addr, sizeof(uA.addr));     // copy to user
}
    


/****************************************************************************
 * Function:        EthMACSetMaxFrame
 *
 * PreCondition:    Should be called after EthInit()
 *
 * Input:           maxFrmSz - maximum frame for the MAC to tx/rx
 *
 * Output:          None  
 *
 * Side Effects:    None
 *
 * Overview:        This function sets the MAC maximum frame size.
 *
 * Note:            The default MAC frame size (0x600) is set by the EthInit() call.
 *****************************************************************************/
void EthMACSetMaxFrame(unsigned short maxFrmSz)
{

	EMACxMAXF=maxFrmSz;
}


#endif	// _ETH


