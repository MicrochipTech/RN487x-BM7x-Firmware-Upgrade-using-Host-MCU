/*******************************************************************************
FileName:       I2CStart.c
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
    I2C_RESULT I2CStart( I2C_MODULE id )

  Summary:
    Routine to start a transfer on the I2C bus
    
  Description:
    This routine sends the "start" signal (a falling edge on SDA while SCL is
    high) on the I2C bus, to start a transfer on the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled and the I2C
    bus must currently be idle.

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    None

  Example:
    <code>
    if (I2CBusIdle(I2C1))
    {
        result = I2CStart(I2C1);
    }
    </code>

  Remarks:
    Only an I2C master can start a transfer on the bus.  The bus is considered
    "busy" after a start condition.
  *****************************************************************************/

I2C_RESULT I2CStart( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];


    // Enable the Start condition
    i2cRegisters->I2CxCONSET = _I2CCON_SEN_MASK;

    // Check for collisions
	if(i2cRegisters->I2CxSTATbits.BCL)
    {
		return(I2C_MASTER_BUS_COLLISION); 
    }
	else
    {
		return(I2C_SUCCESS);
    }		
}
