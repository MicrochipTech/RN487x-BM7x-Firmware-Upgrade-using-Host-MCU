/*******************************************************************************
  I2C Library Interface Definition

  Summary:
    This file contains the Application Program Interface (API) definition  for
    the I2C peripheral library.

  Description:
    This library provides a low-level abstraction of the I2C (Inter-Integrated
    Circuit) module on Microchip PIC32MX family microcontrollers with a
    convenient C language interface.  It can be used to simplify low-level
    access to the module without the necessity of interacting directly with the
    module's registers, thus hiding differences from one microcontroller
    variant to another.
*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
FileName:       i2c.h
Processor:      PIC32MX
Compiler:       Microchip MPLAB XC32 v1.00 or higher

Copyright � 2008-2009 released Microchip Technology Inc.  All rights
reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND,
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
//DOM-IGNORE-END

#ifndef _I2C_H_
#define _I2C_H_

#include <xc.h>
#include <GenericTypeDefs.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


#ifndef _PLIB_DISABLE_LEGACY
    #include <peripheral/legacy/i2c_legacy.h>  // Legacy definitions, do not use
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Constants & Data Types
// *****************************************************************************
// *****************************************************************************

/* I2C Module

  Summary:
    I2C Modules Supported.

  Description:
    This enumeration identifies the available I2C modules.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor ot the next.

    Not all modules will be available on all microcontrollers.  Refer to the
    data sheet for the specific controller in use.
*/

typedef enum
{
#ifdef _I2C1
    // I2C Module 1 ID
    I2C1,
#endif

#ifdef _I2C2
    // I2C Module 2 ID
    I2C2,
#endif

#ifdef _I2C3
    // I2C Module 3 ID
    I2C3,
#endif

#ifdef _I2C4
    // I2C Module 4 ID
    I2C4,
#endif

#ifdef _I2C5
    // I2C Module 5 ID
    I2C5,
#endif

    // Number of available I2C modules.
    I2C_NUMBER_OF_MODULES

} I2C_MODULE;


// *****************************************************************************
/* I2C 7-Bit Address

  Summary:
    Structure of a 7-bit I2C address.

  Description:
    This union defines the format of a 7-bit I2C slave address.
*/

typedef union
{
    // Access to the 8-bit format with the 7-bit address and the read/write
    // direction defined.
    UINT8       byte;

    struct
    {
        // The read/write bit of the I2C address.
        UINT8   rw       : 1;

        // The 7-bit slave address.
        UINT8   address  : 7;
    };

} I2C_7_BIT_ADDRESS;


// *****************************************************************************
/* I2C 10-Bit Address

  Summary:
    Structure of a 10-bit I2C address.

  Description:
    This union defines the format of a 10-bit I2C slave address.
*/

typedef union
{
    // Access to the 16-bit format.
    UINT16      both_bytes;

    struct
    {
        // Access to the first byte.
        BYTE    first_byte;

        // Access to the second byte.
        BYTE    second_byte;
    };

    struct
    {
        // The read/write bit of the I2C address.
        UINT16  rw          : 1;

        // The 2 high-order bits of the 10-bit address.
        UINT16  high_bits   : 2;

        // The 5 constant bits, indicating 10-bit addressing.
        UINT16  const_bits  : 5;

        // The 8 low-order bits of the 10-bit address.
        UINT16  low_bits    : 8;
    };

} I2C_10_BIT_ADDRESS;


// *****************************************************************************
// I2C Read/Write Bits

/* I2C Read Bit

  Summary:
    Used to indicate that the following data transfer is from slave to master.

  Description:
    This definition can be used to set the read/write direction bit
    (indicating a read) when addressing I2C slave devices.
*/

#define I2C_READ    1


/* I2C Read Bit

  Summary:
    Used to indicate that the following data transfer is from master to slave.

  Description:
    This definition can be used to clear the read/write direction bit
    (indicating a write) when addressing I2C slave devices.
*/

#define I2C_WRITE   0


// *****************************************************************************
// I2C Reserved Slave Addresses

/* I2C General Call Reserved Slave Addresses

  Summary:
    Used to send a long pulse to get the attention of a slow slave device.

  Description:
    The General Call address can be used to broadcast a message to every slave
    device at the same time.
*/

#define I2C_GENERAL_CALL_ADDRESS        0x00


/* I2C "Start Byte" Reserved Slave Addresses

  Summary:
    Used to send a long pulse.

  Description:
    The start byte can be used to send a long pulse to get the attention of a
    slow slave device.
*/

#define I2C_START_BYTE                  0x01


/* I2C 10-Bit Address Reserved Slave Addresses

  Summary:
    Used to form a 10-bit address.

  Description:
    This constant is used by the I2C_INITIALIZE_10_BIT_ADDRESS macro to form
    a 10-bit address so that it can be correctly transmitted and recognized
    as a 2-byte sequence.
*/

#define I2C_10_BIT_ADDRESS_CONST_BITS   0x1E


// *****************************************************************************
/* I2C Result Codes

  Summary:
    Defines the possible results of I2C operations that can succeed or fail.

  Description:
    This enumeration defines the possible results of any of the I2C operations
    that have the possiblity of failing.  This result should be checked to
    ensure that the operation achieved the desired result.

  Remarks:
    I2C_SUCCESS is guaranteed to equal zero (0).  The caller should not rely
    on the number assigned to any of the other values.
*/

typedef enum
{
    // The I2C operation was successful.
    I2C_SUCCESS = 0,

    // An error occurred during the I2C operation.
    I2C_ERROR,

    // Arbitration has been lost during a master transfer.
    I2C_MASTER_BUS_COLLISION,

    // Data was not read from the receive buffer quick enough and new data
    // was lost.
    I2C_RECEIVE_OVERFLOW

} I2C_RESULT;


// *****************************************************************************
/* I2C Configuration Settings

  Summary:
    Supported configuration flags for the I2C module.

  Description:
    This enumeration defines the various configuration options for the I2C
    module.  These values can be OR'd together to create a configuration mask
    passed to the I2CConfigure routine.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor ot the next.
*/

typedef enum
{
    // Setting this bit allows the software to throttle the clock (holding SCL
    // low) between bytes using I2CSlaveClockHold and I2CSlaveClockRelease.
    I2C_ENABLE_SLAVE_CLOCK_STRETCHING
        /*DOM-IGNORE-BEGIN*/ = 0x00000040 /*DOM-IGNORE-END*/,

    // Setting this bit switches the I2C module's signaling levels so that they
    // are compatible with the SM Bus specification.
    I2C_ENABLE_SMB_SUPPORT
        /*DOM-IGNORE-BEGIN*/ = 0x00000100 /*DOM-IGNORE-END*/,

    // Setting this bit switches the I2C module to high-speed I2C signaling.
    I2C_ENABLE_HIGH_SPEED
        /*DOM-IGNORE-BEGIN*/ = 0x00000200 /*DOM-IGNORE-END*/,

    // Setting this bit stops the I2C module when the processor enters Idle mode.
    I2C_STOP_IN_IDLE
        /*DOM-IGNORE-BEGIN*/ = 0x00002000 /*DOM-IGNORE-END*/

} I2C_CONFIGURATION;


// *****************************************************************************
/* I2C Slave Address Modes

  Summary:
    Supported I2C slave addressing modes

  Description:
    This enumeration defines the I2C addressing modes that can be recognized by
    the I2C module.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor ot the next.
*/

typedef enum
{
    // Enable recognition of 7-bit addresses in in slave mode.
    I2C_USE_7BIT_ADDRESS
        /*DOM-IGNORE-BEGIN*/ = 0x00000000 /*DOM-IGNORE-END*/,

    // Enable recognition of 10-bit addresses in in slave mode.
    I2C_USE_10BIT_ADDRESS
        /*DOM-IGNORE-BEGIN*/ = 0x00000400 /*DOM-IGNORE-END*/,

    // Enable general call address identification.  Setting this bit configures
    // the module to identify the general call address (0) in slave mode.
    I2C_ENABLE_GENERAL_CALL_ADDRESS
        /*DOM-IGNORE-BEGIN*/ = 0x00000080 /*DOM-IGNORE-END*/,

    // Disable reserved address protection, allowing respones to reserved
    // addresses (violates I2C specification)
    I2C_USE_RESERVED_ADDRESSES
        /*DOM-IGNORE-BEGIN*/ = 0x00000800 /*DOM-IGNORE-END*/

} I2C_ADDRESS_MODE;


// *****************************************************************************
/* I2C Status Flags

  Summary:
    I2C status bitmask flags.

  Description:
    This enumeration defines the possible I2C status bits.  These values are
    OR'd together to make up the bitmask returned by I2CGetStatus or passed to
    I2CClearStatus.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor ot the next.
*/

typedef enum
{
    // Transmit buffer full.  Set if the transmit buffer is full (unable to
    // accept more data to transmit.
    I2C_TRANSMITTER_FULL
        /*DOM-IGNORE-BEGIN*/ = 0x00000001 /*DOM-IGNORE-END*/,

    // Received data available.  Set if data is available in the receiver
    // buffer.  Cleared if not.  (Valid for both master and slave transfers.)
    I2C_DATA_AVAILABLE
        /*DOM-IGNORE-BEGIN*/= 0x00000002 /*DOM-IGNORE-END*/,

    // Slave read.  Set if the current (or most recent) slave operation
    // was a read.  Cleared if it was a write.  (Not valid during master
    // operations).
    I2C_SLAVE_READ
        /*DOM-IGNORE-BEGIN*/ = 0x00000004 /*DOM-IGNORE-END*/,

    // Start condition detected.
    I2C_START
        /*DOM-IGNORE-BEGIN*/ = 0x00000008 /*DOM-IGNORE-END*/,

    // Stop  condition detected.
    I2C_STOP
        /*DOM-IGNORE-BEGIN*/ = 0x00000010 /*DOM-IGNORE-END*/,

    // Slave data byte (sent or received).  If cleared, the most recently
    // sent or received data byte was an address byte.
    I2C_SLAVE_DATA
        /*DOM-IGNORE-BEGIN*/ = 0x00000020 /*DOM-IGNORE-END*/,

    // Receiver overflow error.  Data was received while the receiver buffer
    // was full.  The incoming data was lost.
    I2C_RECEIVER_OVERFLOW
        /*DOM-IGNORE-BEGIN*/ = 0x00000040 /*DOM-IGNORE-END*/,

    // Transmitter overflow error.  The software attempted to write new data
    // to the transmitter buffer and the write was ignored.
    I2C_TRANSMITTER_OVERFLOW
        /*DOM-IGNORE-BEGIN*/ = 0x00000080 /*DOM-IGNORE-END*/,

    // A 10-bit slave address matching the current slave address and mask
    // settings has been received.
    I2C_10BIT_ADDRESS
        /*DOM-IGNORE-BEGIN*/ = 0x00000100 /*DOM-IGNORE-END*/,

    // The General Call address has been received.
    I2C_GENERAL_CALL
        /*DOM-IGNORE-BEGIN*/ = 0x00000200 /*DOM-IGNORE-END*/,

    // A master transmitter has lost arbitration and transmission has been
    // aborted.
    I2C_ARBITRATION_LOSS
        /*DOM-IGNORE-BEGIN*/ = 0x00000400 /*DOM-IGNORE-END*/,

    // The module is currently transmitting data.
    I2C_TRANSMITTER_BUSY
        /*DOM-IGNORE-BEGIN*/ = 0x00004000 /*DOM-IGNORE-END*/,

    // The most recently transmitted byte was acknowledged by the receiver.
    I2C_BYTE_ACKNOWLEDGED
        /*DOM-IGNORE-BEGIN*/ = 0x00008000 /*DOM-IGNORE-END*/

} I2C_STATUS;


// *****************************************************************************
// *****************************************************************************
// Section: I2C Addressing Macros
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Macro:
    void I2C_FORMAT_7_BIT_ADDRESS( I2C_7_BIT_ADDRESS variable, BYTE address,
                                   BOOL read )

  Summary:
    This macro simplifies the process of initializing a I2C_7_BIT_ADDRESS
    variable 7-bit I2C slave address.

  Description:
    This is a convenience macro that simplifies the process of initializing a
    variable with a correctly formed 7-bit address.

  Precondition:
    None.

  Parameters:
    variable    - The variable to be initialized (by direct reference).

    address     - The 7-bit slave address, right-aligned.

    read        - One bit, indicating the desired Read/Write operation.

                  * I2C_READ    - if a Read operation is desired
                  * I2C_WRITE   - if a Write operation is desired

  Returns:
    None.

  Example:
    <code>
    I2C_7_BIT_ADDRESS slave7BitAddress;

    I2C_FORMAT_7_BIT_ADDRESS(slave7BitAddress, SLAVE_ADDRESS_7_BIT, I2C_READ);
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte( I2C1, I2C_GET_7_BIT_ADDRESS_BYTE(slave7BitAddress) );
    }
    </code>

  Remarks:
    This macro directly references the variable by name, so the first parameter
    must resolve to a valid C language L-value.
  *****************************************************************************/

#define I2C_FORMAT_7_BIT_ADDRESS(v,a,r) ( (v).address=(a), (v).rw=(r) )


/*******************************************************************************
  Macro:
    void I2C_GET_7_BIT_ADDRESS_BYTE( I2C_7_BIT_ADDRESS variable )

  Summary:
    This macro provides access to the byte value for a 7-bit I2C slave address.

  Description:
    This is a convenience macro that provides access to the byte value for
    an appropriately initialized 7-bit slave address variable.

  Precondition:
    The variable must have been appropriately initialized using the
    INITIALIZE_7_BIT_ADDRESS macro or equivalent.

  Parameters:
    variable    - The I2C_7_BIT_ADDRESS variable containing the desired address
                  byte value (accessed by direct reference).

  Returns:
    The I2C address byte value (as trasnferrred) from the correctly initialized
    7-bit I2C slave address variable.

  Example:
    <code>
    I2C_7_BIT_ADDRESS slave7BitAddress;

    I2C_FORMAT_7_BIT_ADDRESS(slave7BitAddress, SLAVE_ADDRESS_7_BIT, I2C_READ);
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte( I2C1, I2C_GET_7_BIT_ADDRESS_BYTE(slave7BitAddress) );
    }
    </code>

  Remarks:
    This macro directly references the variable by name, so the first parameter
    must resolve to a valid C language L-value.
  *****************************************************************************/

#define I2C_GET_7_BIT_ADDRESS_BYTE(v) ( (v).byte )


/*******************************************************************************
  Macro:
    void I2C_FORMAT_10_BIT_ADDRESS( I2C_10_BIT_ADDRESS variable, UINT16 address,
                                    BOOL read )

  Summary:
    This macro simplifies the process of initializing a I2C_10_BIT_ADDRESS
    variable with a 10-bit I2C slave address.

  Description:
    This is a convenience macro that simplifies the process of initializing a
    I2C_10_BIT_ADDRESS variable with a correctly formed 10-bit address.

  Precondition:
    None.

  Parameters:
    variable    - The variable to be initialized (by direct reference).

    address     - The 10-bit slave address, right-aligned.

    read        - One bit, indicating the desired Read/Write operation.

                  * I2C_READ    - if a Read operation is desired
                  * I2C_WRITE   - if a Write operation is desired

  Returns:
    None.

  Example:
    <code>
    I2C_10_BIT_ADDRESS slave10BitAddress;

    I2C_FORMAT_10_BIT_ADDRESS(slave10BitAddress, SLAVE_ADDRESS_10_BIT, I2C_READ);
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte( I2C1, GET_1ST_BYTE_OF_10_BIT_ADDRESS(slave10BitAddress) );
    }
    </code>

  Remarks:
    This macro directly references the variable by name, so the first parameter
    must resolve to a valid C language L-value.
  *****************************************************************************/

#define I2C_FORMAT_10_BIT_ADDRESS(v,a,r) ( (v).low_bits   = (a) & 0x00FF,                  \
                                           (v).const_bits = I2C_10_BIT_ADDRESS_CONST_BITS, \
                                           (v).high_bits  = ((a) & 0x0300) >> 8,           \
                                           (v).rw         = (r) )


/*******************************************************************************
  Macro:
    BYTE I2C_GET_1ST_BYTE_OF_10_BIT_ADDRESS( I2C_10_BIT_ADDRESS variable )

  Summary:
    This macro simplifies the process of accessing the first byte of a 10-bit
    I2C slave address.

  Description:
    This is a convenience macro that simplifies the process of accessing the
    first byte of a correctly formed 10-bit I2C slave address.

  Precondition:
    The I2C_10_BIT_ADDRESS variable passed by reference must have been properly
    initialized by the I2C_FORMAT_10_BIT_ADDRESS macro or equivalent.

  Parameters:
    variable    - The I2C_7_BIT_ADDRESS variable containing the desired address
                  byte value (accessed by direct reference).

  Returns:
    The first byte to be transmitted of the correctly formed 10-bit I2C slave
    address.

  Example:
    <code>
    I2C_10_BIT_ADDRESS slave10BitAddress;

    I2C_FORMAT_10_BIT_ADDRESS(slave10BitAddress, SLAVE_ADDRESS_10_BIT, I2C_READ);
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte( I2C1, I2C_GET_1ST_BYTE_OF_10_BIT_ADDRESS(slave10BitAddress) );
    }
    </code>

  Remarks:
    This macro directly references the variable by name, so the first parameter
    must resolve to a valid C language L-value.
  *****************************************************************************/

#define I2C_GET_1ST_BYTE_OF_10_BIT_ADDRESS(v) ( (v).first_byte )


/***************************************************************************************
  Summary:
    This macro simplifies the process of generating the second byte of a
    10-bit I2C slave address.

  Description:
    Macro: BYTE I2C_GET_2ND_BYTE_OF_10_BIT_ADDRESS( I2C_10_BIT_ADDRESS
    variable )

    This is a convenience macro that simplifies the process of accessing
    the second byte of a correctly formed 10-bit I2C slave address.

  Conditions:
    The I2C_10_BIT_ADDRESS variable passed by reference must have been
    properly initialized by the I2C_FORMAT_10_BIT_ADDRESS macro or
    equivalent.

  Input:
    variable -  The I2C_10_BIT_ADDRESS variable containing the desired
                address byte value (accessed by direct reference)
  Return:
    The second byte to be transmitted of the correctly formed 10-bit I2C
    slave address.

  Example:
    <code>
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte( I2C1, I2C_GET_2ND_BYTE_OF_10_BIT_ADDRESS(slave10BitAddress) );
    }
    </code>

  Remarks:
    This macro directly references the variable by name, so the first
    parameter must resolve to a valid C language L-value.
  ***************************************************************************************/

#define I2C_GET_2ND_BYTE_OF_10_BIT_ADDRESS(v) ( (v).second_byte )


// *****************************************************************************
// *****************************************************************************
// Section: I2C Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    void I2CEnable( I2C_MODULE id, BOOL enable )

  Summary:
    This is a routine to enable or disable the given I2C module.

  Description:
    This routine enables or disables the given I2C module.

  Precondition:
    The module should be appropriately configured (using I2CConfigure and
    I2CSetFrequency, and possibly I2CSetSlaveAddress) before being enabled.

  Parameters:
    id      - Identifies the desired I2C module.

    enable  - Determines if the module is to be enabled or disabled.
              * If TRUE, enables the I2C module
              * If FALSE, disables the I2C module

  Returns:
    None.

  Example:
    <code>
    I2CEnable(I2C1, TRUE);
    </code>

  Remarks:
    None.
  *****************************************************************************/

void I2CEnable( I2C_MODULE id, BOOL enable );


/*******************************************************************************
  Function:
    void I2CConfigure ( I2C_MODULE id, I2C_CONFIGURATION flags )

  Summary:
    This is a routine to configure the I2C module.

  Description:
    This routine allows the caller to configure various features of the I2C
    module for desired operation.

  Precondition:
    None.

  Parameters:
    id      - Identifies the desired I2C module.

    flags   - Bit-wise OR of the desired module configuration settings.

  Returns:
    None.

  Example:
    <code>
    I2CConfigure(I2C1, I2C_ENABLE_SLAVE_CLOCK_STRETCHING|I2C_ENABLE_HIGH_SPEED);
    </code>

  Remarks:
    Refer to the I2C_CONFIGURATION enumerated data type for details on each
    configuration flag.  Note that the bitmask resulting from the bit-wise OR
    of these values will result in a value that is not explicitly defined in
    the enumeration.
  *****************************************************************************/

void I2CConfigure ( I2C_MODULE id, I2C_CONFIGURATION flags );


/*******************************************************************************
  Function:
    UINT32 I2CSetFrequency ( I2C_MODULE id, UINT32 sourceClock, UINT32 i2cClock )

  Summary:
    This is a routine to set the I2C module's desired SCL clock frequency.

  Description:
    This routine allows the caller to set the desired clock frequency for the
    I2C module's SCL line.

  Precondition:
    The source clock's frequency must be operating at the frequency passed in
    "sourceClock" parameter.

  Parameters:
    id          - Identifies the desired I2C module.

    sourceClock - Frequency (Hz) of the source clock being provided to the
                  I2C module.

    i2cClock    - Desired frequency of the I2C SCL clock line.

  Returns:
    Actual frequency used.

  Example:
    <code>
    actualClock = I2CSetFrequency(I2C1, GetPeripheralClock(), I2C_CLOCK_FREQ);
    if ( abs(actualClock-I2C_CLOCK_FREQ) > I2C_CLOCK_FREQ/10 )
    {
        DBPRINTF("I2C1 clock frequency (%ld) error exceeds 10%%\n", actualClock);
    }
    </code>

  Remarks:
    Actual frequency selected may be slightly different than frequency
    requested due to truncation error.  Actual frequency observed on the SCL
    line may be lower due to clock stretching.
  *****************************************************************************/

UINT32 I2CSetFrequency ( I2C_MODULE id, UINT32 sourceClock, UINT32 i2cClock );


/*******************************************************************************
  Function:
    void I2CSetSlaveAddress ( I2C_MODULE id, UINT16 address, UINT16 mask,
                              I2C_ADDRESS_MODE flags )

  Summary:
    This is a routine to set the value and mode of the slave address(es) in
    Slave mode.

  Description:
    This routine sets the slave address and size (7-or-10 bits) to which the
    module will respond.  It also sets an optional "ignore" mask, allowing the
    module to ignore bits within the address and thus respond to multiple slave
    addresses as well as how reserved addresses are handled.

  Precondition:

  Parameters:
    id      - Identifies the desired I2C module

    address - The 7- or 10-bit slave address to which the module will respond.
              (The address should be right-aligned in the 16-bit parameter,
              without any read/write bit in the 0 position.)

    mask    - This parameter identifies bits in the address that are "don't-
              care" bits.  These bits will be ignored when attempting to match
              the address, effectively allowing the module to recognize
              multiple slave addresses.  (To match an address exactly, this
              parameter must be zero (0).)

    flags   - This parameter is a bit-wise OR of the values in the
              I2C_ADDRESS_MODE enumeration.  These enumeration flags can be
              used to select the addressing mode (7-or-10 bits) and define how
              reserved addresses are handled.

  Returns:
    None.

  Example:
    <code>
    I2CSetSlaveAddress(I2C1, MY_SLAVE_ADDRESS, 0, I2C_USE_10BIT_ADDRESS);
    </code>

  Remarks:
    Some modules may not support all addressing modes or the mask feature.  It
    is safe to pass a zero (0) value for these features if they are not needed.
    If they are not available, the value passed for these features will be
    ignored.
  *****************************************************************************/

void I2CSetSlaveAddress ( I2C_MODULE id, UINT16 address, UINT16 mask, I2C_ADDRESS_MODE flags );


/*******************************************************************************
  Function:
    BOOL I2CBusIsIdle( I2C_MODULE id )

  Summary:
    This is a routine to determine if the I2C bus is idle or busy.

  Description:
    This routine checks to see if the I2C bus is currently idle or if there is
    some activity currently taking place.

  Precondition:
    The module must have been configured appropriately and enabled.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the bus is idle or busy.
    * TRUE    - The bus is currently idle.  It is safe to start a master transfer.
    * FALSE   - The bus is currently busy.  Do not start a master transfer.

  Example:
    <code>
    if (I2CBusIsIdle(I2C1))
    {
        result = I2CStart(I2C1);
    }
    </code>

  Remarks:
    Just because this routine returns TRUE does not guarantee that a bus
    arbitration loss cannot occur.  Two or more masters can start a transfer
    within the minimum start signal hold time.  (Refer to the I2C specification
    for a definition of the minimum Start condition hold time.)
  *****************************************************************************/

BOOL I2CBusIsIdle( I2C_MODULE id );


/*******************************************************************************
  Function:
    I2C_RESULT I2CStart( I2C_MODULE id )

  Summary:
    This is a routine to start a transfer on the I2C bus.

  Description:
    This routine sends the "start" signal (a falling edge on SDA while SCL is
    high) to start a transfer on the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled and the I2C
    bus must currently be idle.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Result code identifiying if the operation was successful.
    * I2C_SUCCESS              - If the start condition occurred successfully
    * I2C_MASTER_BUS_COLLISION - If an arbitration lost occurred

  Example:
    <code>
    if (I2CBusIsIdle(I2C1))
    {
        result = I2CStart(I2C1);
    }
    </code>

  Remarks:
    Only an I2C master can start a transfer on the bus.  The bus is considered
    "busy" after a Start condition.
  *****************************************************************************/

I2C_RESULT I2CStart( I2C_MODULE id );


/*******************************************************************************
  Function:
    I2C_RESULT I2CRepeatStart ( I2C_MODULE id )

  Summary:
    This is a routine to send a repeated start condition during an ongoing
    transfer.

  Description:
    This routine supports sending a repeated Start condition to change slave
    targets or transfer direction to support certain I2C transfer formats.

  Precondition:
    The module must have been configured appropriately and enabled, and a
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Result code identifiying if the operation was successful.
    * I2C_SUCCESS              - If the Start condition occurred successfully
    * I2C_MASTER_BUS_COLLISION - If an arbitration lost occurred

  Example:
    <code>
    result = I2CRepeatStart (I2C1);
    </code>

  Remarks:
    Only an I2C master that has already started a transfer can send a
    repeated start condition.
  *****************************************************************************/

I2C_RESULT I2CRepeatStart ( I2C_MODULE id );


/*******************************************************************************
  Function:
    void I2CStop ( I2C_MODULE id )

  Summary:
    This is a routine to send an I2C Stop condition to terminate a transfer.

  Description:
    This routine sends the "stop" signal (a rising edge on SDA while SCL is
    high) on the I2C bus, to end a transfer on the I2C bus.

  Precondition:
    The module must have been configured appropriately, enabled, and a previously
    started transfer must be completed.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    None.

  Example:
    <code>
    I2CStop(I2C1);
    </code>

  Remarks:
    Only an I2C master that has already started a transfer can send a
    Stop condition.
  *****************************************************************************/

void I2CStop ( I2C_MODULE id );


/*******************************************************************************
  Function:
    BOOL I2CTransmitterIsReady ( I2C_MODULE id )

  Summary:
    This is a routine to detect if the transmitter is ready to accept data to
    transmit.

  Description:
    This routine determines if the transmitter is ready to accept more data to
    be transmitted on the I2C bus.

  Precondition:
    The module must have been configured appropriately, enabled, and a
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the transmitter is ready or is not ready.
    * TRUE    - If the transmitter is ready to accept more data
    * FALSE   - If the transmitter is not ready to accept more data

  Example:
    <code>
    if (I2CTransmitterIsReady(I2C1))
    {
        result = I2CSendByte(I2C1, data);
    }
    </code>

  Remarks:
    This routing should be used by both master and slave transmitters.
  *****************************************************************************/

BOOL I2CTransmitterIsReady ( I2C_MODULE id );


/*******************************************************************************
  Function:
    I2C_RESULT I2CSendByte ( I2C_MODULE id, BYTE data )

  Summary:
    This is a routine to send a byte of data on the I2C bus.

  Description:
    This routine allows the caller to send a byte of data on the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and the I2C module's transmitter must be
    ready to accept a byte of data to send.

  Parameters:
    id      - Identifies the desired I2C module.

    data    - Data byte to send on the I2C bus.

  Returns:
    Result code identifiying if the operation was successful.
    * I2C_SUCCESS               - The data has been buffered to be sent on the
                                  bus
    * I2C_MASTER_BUS_COLLISION  - A collision has occurred on the bus because
                                  arbitration was lost

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

I2C_RESULT I2CSendByte ( I2C_MODULE id, BYTE data );


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
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the transmission has completed.
    * TRUE    - If the transmitter has completed sending the data byte
    * FALSE   - If the transmitter is still busy sending the data byte

  Example:
    <code>
    if (I2CTransmissionHasCompleted(I2C1))
    {
        if (I2CByteWasAcknowledged(I2C1))
        {
            // transmission successful
        }
    }
    </code>

  Remarks:
    This routine should be used by both master and slave transmitters.
  *****************************************************************************/

BOOL I2CTransmissionHasCompleted ( I2C_MODULE id );


/*******************************************************************************
  Function:
    BOOL I2CByteWasAcknowledged ( I2C_MODULE id )

  Summary:
    Routine to determine if the most recently sent byte was acknowledged

  Description:
    This routine allows a transmitter to determine if the byte just sent was
    positively acknowledged (ACK'd) or negatively acknowledged (NAK'd) by the
    receiver.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, a byte of data must have been sent
    on the I2C bus, and the transmission must have completeed.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the byte was acknowledged or was not acknowledged.
    * TRUE    - If the receiver ACK'd the byte
    * FALSE   - If the receiver NAK'd the byte

  Example:
    <code>
    if (I2CTransmissionHasCompleted(I2C1))
    {
        if (I2CByteWasAcknowledged(I2C1))
        {
            // transmission successful
        }
    }
    </code>

  Remarks:
    This routine can be used by both master or slave transmitters.
  *****************************************************************************/

BOOL I2CByteWasAcknowledged ( I2C_MODULE id );


/*******************************************************************************
  Function:
    I2C_RESULT I2CReceiverEnable ( I2C_MODULE id, BOOL enable )

  Summary:
    This is a routine to enable the module to receive data from the I2C bus.

  Description:
    This routine enables the module to receive data from the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started (either by the I2C module or by an
    external master), and module must be the intended receiver of the next byte
    of data.

  Parameters:
    id      - Identifies the desired I2C module.

    enable  - Determines if the receiver is to be enabled or disabled.
              * If TRUE, enables the module to receive data on the I2C
              * If FALSE, disables the module from receiving data on the I2C

  Returns:
    Result code identifiying if the operation was successful.
    * I2C_SUCCESS           - The receiver has been enabled
    * I2C_RECEIVE_OVERFLOW  - A receiver overflow has occurred and must be
                              cleared

  Example:
    <code>
    I2CReceiverEnable(I2C1, TRUE);
    </code>

  Remarks:
    This routine should be used by both master and slave receivers.
  *****************************************************************************/

I2C_RESULT I2CReceiverEnable ( I2C_MODULE id, BOOL enable );


/*******************************************************************************
  Function:
    BOOL I2CReceivedDataIsAvailable ( I2C_MODULE id )

  Summary:
    Routine to detect if the receiver has data available

  Description:
    This routine determines if the receiver has data available to be read by
    software.

  Precondition:
    The I2C module must have been configured appropriately and enabled, and a
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if data is availble or is not available.
    * TRUE    - If the receiver has data available
    * FALSE   - If the receiver does not have data availble

  Example:
    <code>
    if (I2CReceivedDataIsAvailable(I2C1))
    {
        data = I2CGetByte(I2C1);
    }
    </code>

  Remarks:
    This routine should be used by both master and slave receivers.
  *****************************************************************************/

BOOL I2CReceivedDataIsAvailable ( I2C_MODULE id );


/*******************************************************************************
  Function:
    BOOL I2CReceivedByteIsAnAddress ( I2C_MODULE id )

  Summary:
    Routine to detect if the most recent byte received is data or an address

  Description:
    This routine identifies if the most recent byte received was an address
    byte or a data byte.

  Precondition:
    The module must have been configured appropriately and enabled, and a
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the byte received is data or an address byte.
    * TRUE    - If the byte received is an address byte
    * FALSE   - If the byte received is a data byte

  Example:
    <code>
    if (I2CReceivedDataIsAvailable(I2C1))
    {
        data = I2CGetByte(I2C1);
        if (I2CReceivedByteIsAnAddress(I2C1))
        {
            // Handle address byte
        }
        else
        {
            // Copy the byte to the slave buffer
        }
    }
    </code>

  Remarks:
    This routine should only be used by slave receivers.
  *****************************************************************************/

BOOL I2CReceivedByteIsAnAddress ( I2C_MODULE id );


/*******************************************************************************
  Function:
    BYTE I2CGetByte ( I2C_MODULE id )

  Summary:
    This is a routine to get a byte of data received from the I2C bus.

  Description:
    This routine allows the caller to read a byte of data received from the I2C
    bus.

  Precondition:
    The module must have been configured appropriately and enable, a transfer
    must have been previously started, and a byte of data must have been
    received from the I2C bus.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    A byte of data received from the I2C bus.

  Example:
    <code>
    if (I2CReceivedDataIsAvailable(I2C1))
    {
        I2CAcknowledgeByte(I2C1, TRUE);
        data = I2CGetByte(I2C1);
    }
    </code>

  Remarks:
    This routine should be used by both master and slave receivers.
  *****************************************************************************/

BYTE I2CGetByte ( I2C_MODULE id );


/*******************************************************************************
  Function:
    void I2CAcknowledgeByte ( I2C_MODULE id, BOOL ack )

  Summary:
    This is a routine to allow a receiver to acknowledge a received byte of data.

  Description:
    This routine allows a receiver to positively acknowledge (ACK) or negatively
    acknowledge (NAK) a byte of data that has been received from the I2C bus.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, and a byte of data must have been
    received from the I2C bus.

  Parameters:
    id      - Identifies the desired I2C module.

    ack     - Determines how the byte should be acknoweldged.
              * If TRUE, positively acknowledges (ACK) the byte of data received
              * If FALSE, negatively acknowledges (NAK) the byte of data received

  Returns:
    None.

  Example:
    <code>
    if (I2CReceivedDataIsAvailable(I2C1))
    {
        I2CAcknowledgeByte(I2C1, TRUE);
        data = I2CGetByte(I2C1);
    }
    </code>

  Remarks:
    This routine should be used by both master and slave receivers.
  *****************************************************************************/

void I2CAcknowledgeByte ( I2C_MODULE id, BOOL ack );


/*******************************************************************************
  Function:
    BOOL I2CAcknowledgeHasCompleted ( I2C_MODULE id )

  Summary:
    Routine to determine if the Acknowledge has completed

  Description:
    This routine allows the receiver to detemine if the acknowledgment sent
    has completed.

  Precondition:
    The module must have been configured appropriately and enabled, a transfer
    must have been previously started, a byte of data must have been received
    on the I2C bus, and the acknowledgement must have been started (by calling
    the "I2CAcknowledgeByte" routine).

  Parameters:
    id      - Identifies the desired I2C module

  Returns:
    Boolean identifying if the acknowledgement transmission has completed
    * TRUE    - If the acknowledgment has completed
    * FALSE   - If the acknowledgment has not completed

  Example:
    <code>
    I2CAcknowledgeByte(I2C1, TRUE);

    if(I2CAcknowledgeHasCompleted(I2C1))
    {
        // acknowledgment completed
    }
    </code>

  Remarks:
    This routine can be used by both master or slave receivers.
  *****************************************************************************/

BOOL I2CAcknowledgeHasCompleted ( I2C_MODULE id );


/*******************************************************************************
  Function:
    BOOL I2CSlaveDataReadRequested ( I2C_MODULE id )

  Summary:
    Routine to detect if the request from the master was a read or write

  Description:
    This routine identifies if a slave read (transmit) or a slave write
    (receive) was requested by the master that addressed the module.

  Precondition:
    The module must have been configured appropriately and enabled, and a
    transfer must have been previously started.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    Boolean identifying if the request was a slave read or write.
    * TRUE    - If an external master is requesting data (slave read/transmit)
    * FALSE   - If an external master is sending data (slave write/receive)

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
    None.
  *****************************************************************************/

BOOL I2CSlaveDataReadRequested ( I2C_MODULE id );


/*******************************************************************************
  Function:
    void I2CSlaveClockHold ( I2C_MODULE id )

  Summary:
    This is a routine to hold the SCL clock line low.

  Description:
    This routine allows an I2C slave to stretch the SCL clock line,
    holding it low to throttle data transfer from a master transmitter.

  Precondition:
    The module must have been configured appropriately and enabled, and a
    transfer must have been previously started by an exteral master.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    None.

  Example:
    <code>
    I2CSlaveClockHold(I2C1);
    </code>

  Remarks:
    This routine will cause the SCL line to be forced low, after the current
    byte has been fully received.
  *****************************************************************************/

void I2CSlaveClockHold ( I2C_MODULE id );


/*******************************************************************************
  Function:
    void I2CSlaveClockRelease ( I2C_MODULE id )

  Summary:
    This is a routine to release a previously held SCL clock line.

  Description:
    This routine allows a slave receiver to release a previously held SCL clock
    line, allowing it to go high and allowing data transfer to continue.

  Precondition:
    The module must have been configured appropriately and enabled, and a
    transfer must have been previously started by an external master, and the
    SCL clock line should have been previously held (forced low) by the I2C
    module.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    None.

  Example:
    <code>
    I2CSlaveClockRelease(I2C1);
    </code>

  Remarks:
    Calling this routine when the clock has not been held will not cause any
    problems.
  *****************************************************************************/

void I2CSlaveClockRelease ( I2C_MODULE id );


/*******************************************************************************
  Function:
    I2C_STATUS I2CGetStatus ( I2C_MODULE id )

  Summary:
    This is a routine to provide the current status of the I2C module.

  Description:
    This routine provides a bitmask of the current status flags for the I2C
    module.

  Precondition:
    None.

  Parameters:
    id      - Identifies the desired I2C module.

  Returns:
    The return value is a bitmask generated by a bit-wise OR of the I2C_STATUS
    flags that are currently set.

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
  *****************************************************************************/

I2C_STATUS I2CGetStatus ( I2C_MODULE id );


/*******************************************************************************
  Function:
    void I2CClearStatus ( I2C_MODULE id, I2C_STATUS status )

  Summary:
    This is a routine to clear the specified I2C module status conditions.

  Description:
    This routine clears (if possible) the specified status conditions in the
    I2C module.

  Precondition:
    The I2C module must be enabled.

  Parameters:
    id      - Identifies the desired I2C module.

    status  - A bit-wise OR of the I2C_STATUS flags to be cleared.

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

void I2CClearStatus ( I2C_MODULE id, I2C_STATUS status );


#endif // _I2C_h_

