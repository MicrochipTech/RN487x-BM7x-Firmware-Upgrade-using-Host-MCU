/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        eth_config_lib.c
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

/*********************************************************************
 * Function:        void EthEnable(int enable)
 *
 * PreCondition:    None
 *
 * Input:           enable - boolean to enable/disable the ETHC
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *                  It can turn on/off the controller.
 *
 * Note:            The Eth controller should be turned off before configured.
 *
 * Example:         EthEnable(0);
 ********************************************************************/
void EthEnable(int enable)
{
	if(enable)
	{
		ETHCON1SET=_ETHCON1_ON_MASK;
	}
	else
	{
		ETHCON1CLR=_ETHCON1_ON_MASK;
	}
}

/*********************************************************************
 * Function:        void EthConfig(eEthConfigFlags cFlags)
 *
 * PreCondition:    cFlags - valid configuration flags
 *
 * Input:           cFlags - configuration flags
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *
 * Note:            The Eth controller should be configured when disabled.
 *
 * Example:         EthEnable(0); EthConfig(ETH_CONFIG_MANFC|ETH_CONFIG_RXEN|ETH_CONFIG_SIDL); EthEnable(1); 
 ********************************************************************/
void EthConfig(eEthConfigFlags cFlags)
{
	ETHCON1=cFlags;
}

/*********************************************************************
 * Function:        void EthConfigSetFlags(eEthConfigFlags cFlags)
 *
 * PreCondition:    cFlags - valid configuration flags
 *
 * Input:           cFlags - configuration flags to be set
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *                  Any flag set in the cFlags will be set, the other flags won't be touched. 
 *
 * Note:            The Eth controller should be configured when disabled.
 *
 * Example:         EthConfigSetFlags(ETH_CONFIG_MANFC|ETH_CONFIG_RXEN|ETH_CONFIG_SIDL);
 ********************************************************************/
void EthConfigSetFlags(eEthConfigFlags cFlags)
{
	ETHCON1SET=cFlags;
}


/*********************************************************************
 * Function:        void EthConfigClrFlags(eEthConfigFlags cFlags)
 *
 * PreCondition:    cFlags - valid configuration flags
 *
 * Input:           cFlags - configuration flags to be cleared
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *                  Any flag set in the cFlags will be cleared, the other flags won't be touched. 
 *
 * Note:            The Eth controller should be configured when disabled.
 *
 * Example:         EthConfigClrFlags(ETH_CONFIG_MANFC|ETH_CONFIG_RXEN|ETH_CONFIG_SIDL);
 ********************************************************************/
void EthConfigClrFlags(eEthConfigFlags cFlags)
{
	ETHCON1CLR=cFlags;
}
	
/*********************************************************************
 * Function:        void EthConfigTxStAddress(void* address)
 *
 * PreCondition:    address - valid physical address
 *
 * Input:           address - starting physical address of the first TX descriptor
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *                  It sets the address of the TX descriptors in memory.
 *
 * Note:            - The address should be 4-byte aligned.
 *                  - The address should be a physical address.
 *                  - The address should not be written while any transmit or DMA operations are in progress.
 *
 * Example:         EthConfigTxStAddress(VirtToPhys(myTxDcpt));
 ********************************************************************/
void EthConfigTxStAddress(void* address)
{
	ETHTXST=(unsigned int)address;
}

/*********************************************************************
 * Function:        void EthConfigRxStAddress(void* address)
 *
 * PreCondition:    address - valid physical address
 *
 * Input:           address - starting physical address of the first RX descriptor
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function gives access to low level Eth controller configuration.
 *                  It sets the address of the RX descriptors in memory.
 *
 * Note:            - The address should be 4-byte aligned.
 *                  - The address should be a physical address.
 *                  - The address should not be written while any receive or DMA operations are in progress.
 *
 * Example:         EthConfigRxStAddress(VirtToPhys(myRxDcpt));
 ********************************************************************/
void EthConfigRxStAddress(void* address)
{
	ETHRXST=(unsigned int)address;
}



#endif	// _ETH


