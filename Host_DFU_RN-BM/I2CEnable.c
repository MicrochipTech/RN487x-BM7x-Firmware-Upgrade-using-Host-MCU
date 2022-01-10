/*******************************************************************************
FileName:       I2CEnable.c
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
    void I2CEnable( I2C_MODULE id, BOOL enable )

  Summary:
    This routine enables or disables the given I2C module.

  Description:
    This routine enables or disables the given I2C module.

  Precondition:
    The module should be appropriatly configured (using I2CConfigure and 
    I2CSetFrequency, and possibly I2CSetSlaveAddress) before being enabled.

  Parameters:
    id      - Identifies the desired I2C module
    
    enable  - Determines if the module is to be enabled or disabled
              * If TRUE, enables the I2C module
              * If FALSE, disables the I2C module

  Returns:
    None

  Example:
    <code>
    I2CEnable(I2C1, TRUE);
    </code>

  Remarks:
    None
  *****************************************************************************/

void I2CEnable( I2C_MODULE id, BOOL enable )
{
	I2C_REGISTERS * const i2cRegisters = i2cBase[id];

	i2cRegisters->I2CxCONbits.ON = enable;
}
