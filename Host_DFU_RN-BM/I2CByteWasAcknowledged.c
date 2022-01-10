/*******************************************************************************
FileName:       I2CByteWasAcknowledged.c
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
    BOOL I2CByteWasAcknowledged ( I2C_MODULE id )

  Summary:
    Routine to determine if the most recently sent byte was acknowledged

  Description:
    This routine allows a transmitter to determine if the byte just sent was 
    positively acknowledged (ACK'd) or negatively acknowledge (NAK'd) by the
    receiver.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and a byte of data must have been sent 
    on the I2C bus, and the transmission must have completeed.

  Parameters:
    id      - Identifies the desired I2C module
    
  Returns:
    Boolean identifying if the byte was acknowleded or not
    * TRUE    - If the receiver ACK'd the byte
    * FALSE   - If the receiver NAK'd the byte

  Example:
    <code>
    if (I2CTransmissionComplete(I2C1))
    {
        if (I2CByteWasAcknowledged(I2C1))
        {
            // transmission successful
        }
    }
    </code>

  Remarks:
    This routine can be used by both master or slave receivers.
  *****************************************************************************/

BOOL I2CByteWasAcknowledged ( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

	return(!i2cRegisters->I2CxSTATbits.ACKSTAT);
}
