/*******************************************************************************
  UART Library Interface Definition

  Summary:
    This file contains the interface definition for the UART peripheral library.

  Description:
    This library provides a low-level abstraction of the UART (Universal
    Asynchronous Receiver/Transmtter) module on Microchip PIC32MX family
    microcontrollers with a convenient C language interface.  It can be used to
    simplify low-level access to the module without the necessity of interacting
    directly with the module's registers, thus hiding differences from one
    microcontroller variant to another.
*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
FileName:       uart.h
Dependencies:   See includes
Processor:      PIC32MX

Compiler:       Microchip MPLAB XC32 v1.00 or higher
Company:        Microchip Technology Inc.

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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Includes
// *****************************************************************************
// *****************************************************************************
#include <peripheral/uart.h>
#include <GenericTypeDefs.h>
#include <xc.h>


UART_REGS * const uartReg[] =
{
#if defined _UART1
    (UART_REGS *)_UART1_BASE_ADDRESS,
#endif
#if defined _UART2
    (UART_REGS *)_UART2_BASE_ADDRESS,
#endif
#ifdef _UART3
	(UART_REGS *)_UART3_BASE_ADDRESS,
#endif
#ifdef _UART4
    (UART_REGS *)_UART4_BASE_ADDRESS,
#endif
#ifdef _UART5
	(UART_REGS *)_UART5_BASE_ADDRESS,
#endif
#ifdef _UART6
	(UART_REGS *)_UART6_BASE_ADDRESS
#endif
};

/*******************************************************************************
  Function:
    void UARTEnable( UART_MODULE id, UART_ENABLE_MODE mode )

  Summary:
    Enables or disables the given UART module in the desired mode

  Description:
    This routine enables or disables the given UART module in the desired mode.

  Precondition:
    The module should be appropriatly configured before being enabled.

  Parameters:
    id    - Identifies the desired UART module

    mode  - Identifies the desired mode of UART operation

  Returns:
    None
  *****************************************************************************/
void UARTEnable( UART_MODULE id, UART_ENABLE_MODE mode )
{
    volatile UINT   *uart_mode;
    volatile UINT   *uart_sta;

    if(mode & UART_ENABLE)
    {
        uart_mode = (volatile UINT *)&uartReg[id]->mode.set;
        uart_sta = (volatile UINT *)&uartReg[id]->sta.set;
    }else
    {
        uart_mode = (volatile UINT *)&uartReg[id]->mode.clr;
        uart_sta = (volatile UINT *)&uartReg[id]->sta.clr;
    }


    if(mode & UART_RX)
        *uart_sta = _U1STA_URXEN_MASK;

    if(mode & UART_TX)
        *uart_sta = _U1STA_UTXEN_MASK;

    if(mode & UART_PERIPHERAL)
        *uart_mode = _U1MODE_ON_MASK;
}
/*******************************************************************************
  Function:
    UART_RESULT UARTConfigure ( UART_MODULE id, UART_CONFIGURATION flags )

  Summary:
    UART module configuration routine

  Description:
    This routine allows the caller to configure various features of the UART
    module for desired operation.

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module

    flags   - Bit-wise OR of the desired module configuration settings

  Returns:
    An UART operation result indicating if the operation succeeded or if an error
    occured.
  *****************************************************************************/
void UARTConfigure ( UART_MODULE id, UART_CONFIGURATION flags )
{
	UART_REGS *uart;

    uart = (UART_REGS *)uartReg[id];

    uart->mode.clr = UART_ENABLE_HIGH_SPEED | UART_INVERT_RECEIVE_POLARITY | UART_ENABLE_LOOPBACK |  UART_ENABLE_WAKE_ON_START | \
                         UART_ENABLE_PINS_BIT_CLOCK | UART_RTS_WHEN_TX_NOT_EMPTY | UART_ENABLE_IRDA | \
                         UART_SUPPORT_IEEE_485 | UART_ENABLE_STOP_ON_IDLE;

    uart->sta.clr = (UART_INVERT_TRANSMIT_POLARITY) >> 16;

    uart->mode.set = flags & 0x0000FFFF;

    uart->sta.set = (flags >> 16) & 0x0000FFFF;
}
/*******************************************************************************
  Function:
    void UARTSetFifoMode ( UART_MODULE id, UART_FIFO_MODE mode )

  Summary:
    Controls UART module Tx and Rx FIFO operation

  Description:
    This routine allows the caller to configure when interrupts occur relative
    to different "watermark" levels in the UART Tx and Rx FIFOs (i.e. how full
    or empty the FIFOs are).

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module

    mode    - Bit-wise OR of the desired FIFO mode values

  Returns:
    An UART operation result indicating if the operation succeeded or if an error
    occured.
  *****************************************************************************/
void UARTSetFifoMode ( UART_MODULE id, UART_FIFO_MODE mode )
{
	UART_REGS *uart;

    uart = (UART_REGS *)uartReg[id];

    uart->sta.clr = UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_TX_DONE | UART_INTERRUPT_ON_RX_FULL;

    uart->sta.set = mode;
}
/*******************************************************************************
  Function:
    void UARTSetDataRate ( UART_MODULE id, UINT32 sourceClock, UINT32 dataRate )

  Summary:
    Routine to set the UART module's desired data data rate.

  Description:
    This routine allows the caller to set the desired data rate for the UART.

  Precondition:
    The source clock's frequency must be operating at the frequency passed in
    "sourceClock" parameter.

  Parameters:
    id          - Identifies the desired UART module

    sourceClock - Frequency (Hz) of the source clock being provided to the
                  UART module

    bitRate     - Desired bit rate (bits per second)

  Returns:
    Actual bit rate selected
  *****************************************************************************/
UINT32 UARTSetDataRate ( UART_MODULE id, UINT32 sourceClock, UINT32 dataRate )
{
    UINT32      brg_value;
	UART_REGS   *uart;

    uart = (UART_REGS *)uartReg[id];

    if(uart->mode.reg & _U1MODE_BRGH_MASK)
    {
        sourceClock >>= 1;
    }else
    {
        sourceClock >>= 3;
    }

    brg_value = sourceClock / dataRate;
    brg_value++;
    brg_value >>= 1;
    brg_value--;

    uart->brg.reg = brg_value & 0x0000FFFF;

    dataRate = (sourceClock >> 1) / ( brg_value + 1 );

    return dataRate;
}
/*******************************************************************************
  Function:
    void UARTGetDataRate ( UART_MODULE id, UINT32 sourceClock )

  Summary:
    Routine to get the UART module's current data data rate.

  Description:
    This routine allows the caller to get the current data rate for the UART.

  Precondition:
    The source clock's frequency must be operating at the frequency passed in
    "sourceClock" parameter.

  Parameters:
    id          - Identifies the desired UART module

    sourceClock - Frequency (Hz) of the source clock being provided to the
                  UART module

  Returns:
    The UART's current rate
  *****************************************************************************/

UINT32 UARTGetDataRate( UART_MODULE id, UINT32 sourceClock )
{
    UINT32      dataRate;
	UART_REGS   *uart;

    uart = (UART_REGS *)uartReg[id];

    if(uart->mode.reg & _U1MODE_BRGH_MASK)
    {
        sourceClock >>= 2;
    }else
    {
        sourceClock >>= 4;
    }

    dataRate = sourceClock / ( uart->brg.reg + 1 );

    return dataRate;

}
/*******************************************************************************
  Function:
        void UARTSetLineControl ( UART_MODULE id, UART_LINE_CONTROL_MODE mode )

  Summary:
    Routine to set the UART module's desired line control parameters.

  Description:
    This routine allows the caller to select the desired size of the UART data
    frame, the generation of parity and framing parameters (collectively
    referred to as the "line control" mode

  Precondition:

  Parameters:
    id      - Identifies the desired UART module

    mode    - This is a bit-wise OR of the desired line control mode flags

  Returns:
    None
 *****************************************************************************/

void UARTSetLineControl ( UART_MODULE id, UART_LINE_CONTROL_MODE mode )
{
	UART_REGS *uart;

    uart = (UART_REGS *)uartReg[id];

    uart->mode.clr = UART_DATA_SIZE_9_BITS | UART_STOP_BITS_2;
    uart->mode.set = mode;
}
/*******************************************************************************
  Function:
    void UARTSetAddress ( UART_MODULE id, BYTE address )

  Summary:
    Routine to program the address for which the module may watch

  Description:
    This routine programs the 8-bit address for which the module may watch.

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module

    address - Address for which the module will watch

    watch   - Determines if the "address watch" mode will be enabled or
              disabled:
              TRUE = Enable address watch mode
              FALE = Disable address watch mode

  Returns:
    None
  *****************************************************************************/

void UARTSetAddress ( UART_MODULE id, BYTE address, BOOL watch )
{
	UART_REGS *uart;

    uart = (UART_REGS *)uartReg[id];


    uart->sta.clr = _U1STA_ADDR_MASK | _U1STA_ADM_EN_MASK;
    uart->sta.set = ((UINT32)address) << _U1STA_ADDR_POSITION;

    if(watch)
        uart->sta.set = _U1STA_ADM_EN_MASK;
}


/*******************************************************************************
  Function:
    void UARTWatchForAddress ( UART_MODULE id, BOOL watch )

  Summary:
    Routine to enable or disable recognition of the programmed address byte

  Description:
    This routine can enable or disable the "address watch" mode.  In this mode
    the module will ignore all data until it recognizes the programmed address.

  Precondition:

  Parameters:
    id      - Identifies the desired UART module

    watch   - Determines if the "address watch" mode will be enabled or
              disabled.
              TRUE = Enable address watch mode
              FALE = Disable address watch mode

  Returns:
    None

  *****************************************************************************/

void UARTWatchForAddress ( UART_MODULE id, BOOL watch )
{
	UART_REGS *uart;

    uart = (UART_REGS *)uartReg[id];

    if(watch)
        uart->sta.set = _U1STA_ADM_EN_MASK;
    else
        uart->sta.clr = _U1STA_ADM_EN_MASK;
}
