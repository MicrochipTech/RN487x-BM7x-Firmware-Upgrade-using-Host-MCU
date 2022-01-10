/*******************************************************************************
FileName:       I2CClearStatus.c
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
    void I2CClearStatus ( I2C_MODULE id, I2C_STATUS status )

  Summary:
    Routine to clear the specified I2C module status conditions

  Description:
    This routine clears (if possible) the specified status conditions in the 
    I2C module.

  Precondition:
    The I2C module must be enabled.

  Parameters:
    id      - Identifies the desired I2C module
    
    status  - A bit-wise OR of the I2C_STATUS values to be cleared.

  Returns:

  Example:
    <code>
    status = I2CGetStatus(I2C1);
    if(I2C_ARBITRATION_LOSS & status)
    {
        // Handle arbitration loss
        //...
        I2CClearStatus(I2C1, I2C_ARBITRATION_LOSS);
    }
    </code>

  Remarks:
    Some status conditions are automatically cleared by hardware and it is not
    necessary for software to clear them.
  *****************************************************************************/

void I2CClearStatus ( I2C_MODULE id, I2C_STATUS status )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

	i2cRegisters->I2CxSTATCLR = status;
}
