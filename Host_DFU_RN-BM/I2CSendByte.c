/*******************************************************************************
FileName:       I2CSendByte.c
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
    I2C_RESULT I2CSendByte ( I2C_MODULE id, BYTE data )

  Summary:
    Routine to send a byte of data on the I2C bus

  Description:
    This routine allows the caller to send a byte of data on the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and the transmitter must be ready to 
    accept a byte of data to send.

  Parameters:
    id      - Identifies the desired I2C module
    
    data    - Data byte to send on the I2C bus

  Returns:
    An I2C operation result indicating if the operation succeeded or if an error
    occured.
    * I2C_SUCCESS     - The data has been buffered to be sent on the bus
    * I2C_ERROR       - The transmitter was not ready to accept the data

  Example:
    <code>
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte(I2C1, data);
    }
    </code>

  Remarks:
    This routine should be used by both master and slave transmitters.
  *****************************************************************************/

I2C_RESULT I2CSendByte ( I2C_MODULE id, BYTE data )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

    // Send the byte
    i2cRegisters->I2CxTRN = data;

    // Check for collisions
	if( i2cRegisters->I2CxSTAT & (_I2CSTAT_BCL_MASK|_I2CSTAT_IWCOL_MASK) )
    {
		return(I2C_MASTER_BUS_COLLISION); 
    }
	else
    {
		return(I2C_SUCCESS);
    }
}
