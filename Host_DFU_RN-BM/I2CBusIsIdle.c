/*******************************************************************************
FileName:       I2CBusIsIdle.c
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
    BOOL I2CBusIsIdle( I2C_MODULE id )

  Summary:
    Routine determine if the I2C bus is idle or busy.
    
  Description:
    This routine checks to see if the I2C bus is currently idle or if there is
    some activity currently taking place.

  Precondition:
    The module must have been configured appropriately and enabled.

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    Boolean identifying if the bus is idle or not
    * TRUE    - The bus is currently idle.  It is OK to start a master transfer.
    * FALSE   - The bus is currently busy.  Do not start a master transfer.

  Example:
    <code>
    if (I2CBusIsIdle(I2C1))
    {
        I2CStart(I2C1);
    }
    </code>

  Remarks:
    Just because this routine returns TRUE does not guarantee that a bus
    arbitration loss cannot occur.  Two or more masters can start a transfer 
    within the minimum start signal hold time.  (Refer to the I2C specification
    for a definition of the minimum start condition hold time.)
  *****************************************************************************/

BOOL I2CBusIsIdle( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];
    
    // Check the status of the Start & Stop bits to determine if the bus is idle.
    return ( (i2cRegisters->I2CxSTATbits.S == 0 && i2cRegisters->I2CxSTATbits.P == 0 ) ||
             (i2cRegisters->I2CxSTATbits.S == 0 && i2cRegisters->I2CxSTATbits.P == 1 )   );
}
