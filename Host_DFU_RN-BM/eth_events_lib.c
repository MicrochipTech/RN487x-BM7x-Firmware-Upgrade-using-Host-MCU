/*********************************************************************
 *
 *                 Ethernet Controller API 
 *
 *********************************************************************
 * FileName:        eth_events_lib.c
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
 * Function:        void EthEventsEnableSet(eEthEvents eEvents)
 *
 * PreCondition:    None
 *
 * Input:           eEvents	- events with the significance described in the eEthEvents definition.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function enables the events that will generate interrupts for the Eth controller.
 *                  Multiple events can be orr-ed together.
 *                  Any event that is set in the eEvents will be enabled , the other events won't be touched.
 *
 * Note:            None.
 *
 ********************************************************************/
void EthEventsEnableSet(eEthEvents eEvents)
{
	ETHIENSET=eEvents;
}

/*********************************************************************
 * Function:        void EthEventsEnableClr(eEthEvents eEvents)
 *
 * PreCondition:    None
 *
 * Input:           eEvents	- events with the significance described in the eEthEvents definition.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function disables the events that will generate interrupts for the Eth controller.
 *                  Multiple events can be orr-ed together.
 *                  Any event that is set in the eEvents will be disabled , the other events won't be touched.
 *
 * Note:            None.
 ********************************************************************/
void EthEventsEnableClr(eEthEvents eEvents)
{
	ETHIENCLR=eEvents;	
}

/*********************************************************************
 * Function:        void EthEventsEnableWrite(eEthEvents eEvents)
 *
 * PreCondition:    None
 *
 * Input:           eEvents	- events with the significance described in the eEthEvents definition.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The function enables the events that will generate interrupts for the Eth controller.
 *                  The enabled events are forced to the eEvents value.
 *
 * Note:            None.
 ********************************************************************/
void EthEventsEnableWrite(eEthEvents eEvents)
{
	ETHIEN=eEvents;
}	

/*********************************************************************
 * Function:        eEthEvents EthEventsEnableGet(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          eEvents	- events with the significance described in the eEthEvents definition.
 * 
 * Side Effects:    None
 *
 * Overview:        The function returns the enabled events for the Eth controller.
 *
 * Note:            None.
 ********************************************************************/
eEthEvents EthEventsEnableGet(void)
{
	return (eEthEvents)ETHIEN;
}



#endif	// _ETH


