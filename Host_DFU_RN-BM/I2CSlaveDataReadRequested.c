/*******************************************************************************
FileName:       I2CSlaveDataReadRequested.c
Processor:      PIC32MX
Compiler:       Microchip MPLAB XC32 v1.00 or higher

Copyright © 2008-2009 released Microchip Technology Inc.  All rights
reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

#include <peripheral/i2c.h>
#include "I2CPrivate.h"

/*******************************************************************************
  Function:
    BOOL I2CSlaveDataReadRequested ( I2C_MODULE id )

  Summary:
    Routine to detect if request from the master was a read or write

  Description:
    This routine identifies if a slave read (transmit) or a slave write 
    (receive) a was requested by the master that addressed the module.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    Boolean identifying if the request was a slave read or write
    * TRUE    - If an external master is requesting data (slave read/transmit)
    * FALSE   - If an external is sending data (slave write/receive)
    
  Example:
    <code>
    if (I2CSlaveDataReadRequested(I2C1))
    {
        if (I2CTransmitterIsReady(I2C1))
        {
            result = I2CSendByte(I2C1, slaveTxData);
        }
    }
    else
    {
        slaveRxData = I2CGetByte(I2C1);
    }
    </code>

  Remarks:
    This routine should be used by both master and slave receivers.
  *****************************************************************************/

BOOL I2CSlaveDataReadRequested ( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];
	
	return(i2cRegisters->I2CxSTATbits.R_W);
}
