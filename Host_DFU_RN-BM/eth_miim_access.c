/*********************************************************************
 *
 *                  MIIM access to the PHY registers
 *
 *********************************************************************
 * FileName:        eth_miim_acess.c
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


static const short _EthMIIClkDivTbl[]=
{
	4, 6, 8, 10, 14, 20, 28, 40
};	// divider values for the Host clock


// definitions
// 

/****************************************************************************
 * Function:        mRegIxPhyAddToEMACxMADR
 *
 * PreCondition:    rIx a valid PHY register, 0-31
 *                  phyAdd a valid PHY address, 0-31
 *
 * Input:           rIx: 	PHY register to be accessed
 *                  phyAdd:	PHY to be accessed
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This macro converts a register index and PHY address to a EMACxMADR format;
 *
 * Note:            None
 *****************************************************************************/
#define		mRegIxPhyAddToEMACxMADR(rIx, phyAdd)	((rIx)<<_EMACxMADR_REGADDR_POSITION)|((phyAdd)<<_EMACxMADR_PHYADDR_POSITION)	



// interface functions
//


/****************************************************************************
 * Function:        EthMIIMReadStart
 *
 * PreCondition:    rIx a valid PHY register, 0-31
 *                  phyAdd a valid PHY address, 0-31
 *
 * Input:           rIx: PHY register to be accessed
 *                  phyAdd: PHY address
 *
 * Output:          None 
 *
 * Side Effects:    None
 *
 * Overview:        This function initiates a read operation from a PHY register using the MIIM interface.
 *                  It returns immediately without waiting for the transactions to be performed.
 *
 * Note:            It assumes that no scan operation is in progress!
 *
 *                  Before initiating the read operation it waits for the MIIM interface not busy.
 *                  Call EthMIIMBusy() before if no polling needed!
 *****************************************************************************/
void EthMIIMReadStart(unsigned int rIx, unsigned int phyAdd)
{
	while(EMACxMINDbits.MIIMBUSY);		// wait in case of some previous operation
	EMACxMADR=mRegIxPhyAddToEMACxMADR(rIx, phyAdd);
	EMACxMCMD=_EMACxMCMD_READ_MASK;			// read order
	__asm__ __volatile__ ("nop; nop; nop; nop;");	// there's 4 clock cycles till busy is set for a read op 
}

/*******************************************************************************
  Function:
    unsigned short EthMIIMReadResult ( void )

  Summary:
    Returns the result of a previously started read operation

  Description:
    This function returns the result of a previously started read operation 
    (using EthMIIMReadStart()).

  Precondition:
    EthMIIMConfig() called
    
    EthMIIMReadStart() called

  Parameters:
    None.

  Returns:
    PHY register value 

  Example:
    <code>
    regValue = EthMIIMReadResult();
    </code>

  Remarks:
    It assumes that no scan operation is in progress!
    
    It waits for the read operation to be complete.
    Call EthMIIMBusy() before if no polling needed!
 *****************************************************************************/
unsigned short EthMIIMReadResult ( void )
{
	while(EMACxMINDbits.MIIMBUSY);			// wait op complete
    EMACxMCMD=0;
    return EMACxMRDD;       // The read register
}

/****************************************************************************
 * Function:        EthMIIMWriteStart
 *
 * PreCondition:    rIx a valid PHY register, 0-31
 *                  phyAdd a valid PHY address, 0-31
 *
 * Input:           rIx:    PHY register to be accessed
 *                  phyAdd: PHY address
 * 		            wData:  data to be written
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initiates a write operation to a PHY register using the MIIM interface.
 *                  It doesn't wait for the write to take effect.
 *
 * Note:            It assumes that no scan operation is in progress!
 * 
 *                  Before initiating the write operation it waits for the MIIM interface not busy.
 *                  Call EthMIIMBusy() before if no polling needed!
 *
 *                  After write started call EthMIIMBusy() to check if the operation
 *                  has been completed. 
 *****************************************************************************/
void EthMIIMWriteStart(unsigned int rIx, unsigned int phyAdd, unsigned short wData)
{
	while(EMACxMINDbits.MIIMBUSY);		// wait in case of some previous operation

	EMACxMADR=mRegIxPhyAddToEMACxMADR(rIx, phyAdd);
	EMACxMWTD=wData;
	__asm__ __volatile__ ("nop; nop;");	// there's 2 clock cycles till busy is set for a write op
                                        // make sure busy doesn't get cj=hecked too soon!
}


/****************************************************************************
 * Function:        EthMIIMScanStart
 *
 * PreCondition:    rIx a valid PHY register, 0-31
 *                  phyAdd a valid PHY address, 0-31
 *
 * Input:           rIx: 	PHY register to be accessed
 *                  phyAdd: PHY address
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initiates a scan operation to a PHY register using the MIIM interface.
 *
 * Note:            It assumes that no scan operation is in progress!
 *
 *                  Before initiating the scan operation it waits for the MIIM interface not busy.
 *                  Call EthMIIMBusy() before if no polling needed!
 *****************************************************************************/
void EthMIIMScanStart(unsigned int rIx, unsigned int phyAdd)
{
	while(EMACxMINDbits.MIIMBUSY);		// wait in case of some previous operation

	EMACxMADR=mRegIxPhyAddToEMACxMADR(rIx, phyAdd);
	EMACxMCMD=_EMACxMCMD_SCAN_MASK;		// scan order
}

/****************************************************************************
 * Function:        EthMIIMScanResult
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function reads the result of a previously initiated
 *                  scan operation from a PHY register using the MIIM interface.
 *
 * Note:            It assumes that a scan operation is in progress!
 *
 *                  Before returning it waits for the scan result to be valid.
 *                  Call EthMIIMScanValid() before if no polling needed!
 *****************************************************************************/
unsigned short EthMIIMScanResult(void)
{
	while(EMACxMINDbits.NOTVALID);	// wait data valid

	return EMACxMRDD;		// the scan register
}


/****************************************************************************
 * Function:        EthMIIMConfig
 *
 * PreCondition:    None
 *
 * Input:           hostClock: the value of the host clock, Hz
 *                  miimClock: the maximum clock frequency that the PHY can use for the MIIM transactions 
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initializes and configures the MIIM interface for access of a PHY.
 *
 * Note:            - Any previous MIIM operation will be aborted!
 *****************************************************************************/
void EthMIIMConfig(unsigned int hostClock, unsigned int miimClock)
{
	int		ix;
	
	EMACxMCFG=_EMACxMCFG_RESETMGMT_MASK;	// issue MIIM reset
	
	EMACxMCFG=0;	// clear reset
	
	for(ix=0; ix<sizeof(_EthMIIClkDivTbl)/sizeof(*_EthMIIClkDivTbl); ix++)
	{
		if(hostClock/_EthMIIClkDivTbl[ix]<=miimClock)
		{	// found it
			break;
		}
	}
	if(ix==sizeof(_EthMIIClkDivTbl)/sizeof(*_EthMIIClkDivTbl))
	{
		ix--;	// max divider; best we can do
	}

	EMACxMCFG=(ix+1)<<_EMACxMCFG_CLKSEL_POSITION;	// program the clock
}



#endif /* _ETH */


