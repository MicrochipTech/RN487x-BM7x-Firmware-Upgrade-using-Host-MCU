/*******************************************************************************
FileName:       I2CAcknowledgeByte.c
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
    void I2CAcknowledgeByte ( I2C_MODULE id, BOOL ack )

  Summary:
    Routine to allow a receiver to acknowledge a received byte of data

  Description:
    This routine allows a receiver to positively acknowledge (ACK) or negatively
    acknowledge (NAK) a byte of data that has been received from the I2C.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and a byte of data must have been 
    received from the I2C bus.

  Parameters:
    id      - Identifies the desired I2C module
    
    ack     - Determines how the byte should be acknoweldged
              * If TRUE, positively acknowledges (ACK) the byte of data received
              * If FALSE, negatively acknowledges (NAK) the byte of data received

  Returns:
    None

  Example:
    <code>
    if (I2CReceivedDataIsAvailable(I2C1))
    {
        I2CAcknowledgeByte(I2C1, TRUE);
        data = I2CGetByte(I2C1);
    }
    </code>

  Remarks:
    This routine can be used by both master or slave receivers.
  *****************************************************************************/

void I2CAcknowledgeByte ( I2C_MODULE id, BOOL ack )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

    // Assign the ACK/NAK value
	if(ack == TRUE)
    {
		i2cRegisters->I2CxCONCLR = _I2CCON_ACKDT_MASK;
    }
	else
    {
		i2cRegisters->I2CxCONSET = _I2CCON_ACKDT_MASK;
    }

    // Send the ACK/NAK
	i2cRegisters->I2CxCONSET = _I2CCON_ACKEN_MASK;
}
