/*******************************************************************************
FileName:       I2CTransmissionHasCompleted.c
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
    BOOL I2CTransmissionHasCompleted ( I2C_MODULE id )

  Summary:
    Routine to detect if the module has finshed transmitting the most recent 
    byte

  Description:
    This routine determines if the transmitter has finished sending the most
    recently sent byte on the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and a data or address byte must have
    been sent.

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    Boolean identifying if the transmission has completed
    * TRUE    - If the transmitter has completed sending the data byte
    * FALSE   - If the transmitter is still busy sending the data byte

  Example:
    <code>
    if (I2CTransmissionHasCompleted(I2C1))
    {
        if (I2CByteAcknowledged(I2C1, data))
        {
            // transmission successful
        }
    }
    </code>

  Remarks:
    This routing should be used by both master and slave transmitters.
  *****************************************************************************/

BOOL I2CTransmissionHasCompleted ( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

	return(!i2cRegisters->I2CxSTATbits.TRSTAT);
}

