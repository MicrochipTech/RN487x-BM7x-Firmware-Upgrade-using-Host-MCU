/*******************************************************************************
FileName:       I2CRepeatStart.c
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
    I2C_RESULT I2CRepeatStart ( I2C_MODULE id )

  Summary:
    Routine to send a repeated-start condition during an ongoing transfer

  Description:
    This routine supports sending a repeated start condition to change slave 
    targets or transfer direction to support certain I2C transfer formats.

  Precondition:
    The module must have been configured appropriately and enabled and the a 
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    None

  Example:
    <code>
    result = I2CRepeatStart (I2C1);
    </code>

  Remarks:
    Only an I2C master that has already started a transfer can send a repeated-
    start condition.
  *****************************************************************************/

I2C_RESULT I2CRepeatStart ( I2C_MODULE id )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

    // Send the repeated Start
	i2cRegisters->I2CxCONSET = _I2CCON_RSEN_MASK;
	
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
