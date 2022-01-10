/*
********************************************************************************

Software License Agreement

Copyright © 2018 Microchip Technology Inc. and its licensors.  All
rights reserved.

Microchip licenses to you the right to: (1) install Software on a single
computer and use the Software with Microchip microcontrollers and
digital signal controllers ("Microchip Product"); and (2) at your
own discretion and risk, use, modify, copy and distribute the device
driver files of the Software that are provided to you in Source Code;
provided that such Device Drivers are only used with Microchip Products
and that no open source or free software is incorporated into the Device
Drivers without Microchip's prior written consent in each instance.

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE
LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY,
CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY
DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR
LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

********************************************************************************
*/

#ifndef TIME_H
#define TIME_H

#include    "stdint.h"
#include    "stdbool.h"
#if defined(__PIC32MX__) || defined(__C32__)
#include    "plib.h"
#endif

/****************************************************************************
  Function:
    void TimeInit ( void )

  Description:
    Initialization of internal variables.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    None
  ***************************************************************************/

void* TimeInit ( void (*timer_cb)(void *) );
void TimeStart ( void );
void TimeStop ( void );

/****************************************************************************
  Function:
    void TimeUpdate ( uint16_t time )

  Description:
    Time counting function.

  Precondition:
    None

  Parameters:
    uint16_t time     - time in ms passed since last execution

  Returns:
    None

  Remarks:
    Although this function can run in asyncronous mode with wide range of
    intermittent delays, synchronous mode with lowest possible resolution (1 ms)
    is recommended to keep timing as precise as possible. In either case,
    cycle-to-cycle rounding shouldn't result in accumulating error. Best practice
    is using 1-ms timer interrupt.
  ***************************************************************************/

void TimeUpdate ( uint16_t time );

/****************************************************************************
  Function:
    void TimeDelay10us ( uint16_t delay )

  Description:
    Generates delay defined in 10 us steps.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    This function uses hard-coded loop with known execution time to generate
    delays. It works independently from ms-range timekeeping, and uses
    SysGetInstructionClock () function / macro to calculate loop count. System
    clock can affect precision, particularly, running PIC24 below 4 MIPS
    or PIC32 below 2 MIPS results in rising minimal possible delay above 10 us.
    Maximum value is 65535 units as per uint16_t definition, what results
    in maximum delay of 655.35 ms.
  ***************************************************************************/

void TimeDelay10us( uint16_t delay );

/****************************************************************************
  Function:
    void TimeDelay1ms ( uint16_t delay )

  Description:
    Generates delay defined in 1 ms steps.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    This function uses ms-range timekeeping to generate delays, so it's
    precision will depend on TimeUpdate () calling profile. Maximum value
    is 65535 units as per uint16_t definition, what results in maximum delay
    of 65.535 s.
    PIC24 implementation uses Idle () inside the loop to reduce power
    consumption.
  ***************************************************************************/

void TimeDelay1ms ( uint16_t delay );

/****************************************************************************
  Function:
    uint16_t TimeGet1ms ( void )

  Description:
    Returns system time in 1 ms units.

  Precondition:
    None

  Parameters:
    None

  Returns:
    uint16_t          - system time in 1 ms units

  Remarks:
    The library uses free-running 16 bit timer, so application should account
    for possible rollover (65.536 s period ).
  ***************************************************************************/

uint16_t TimeGet1ms ( void );

/****************************************************************************
  Function:
    uint16_t TimeGet100ms ( void )

  Description:
    Returns system time in 100 ms units.

  Precondition:
    None

  Parameters:
    None

  Returns:
    uint16_t          - system time in 100 ms units

  Remarks:
    The library uses free-running 16 bit timer counting in 100 ms, so application should account
    for possible rollover ( 6553.6 s period ).
  ***************************************************************************/

uint16_t TimeGet100ms ( void );

/****************************************************************************
  Function:
    BOOL TimeElapsed1ms ( uint16_t time )

  Description:
    Safely checks if 1 ms timer reached given value.

  Precondition:
    None

  Parameters:
    uint16_t time     - time mark in 1 ms units to check against

  Returns:
    BOOL            - TRUE if timer passed the mark

  Remarks:
    This function accounts to possible timer rollover, thus making checking
    safe and simple. Common usage profile:
    <code>
        timemark = TimeGet1ms () + TIMEOUT_MS;
        while ( TimeElapsed1ms ( timemark ) != TRUE )
        {
            ...
        }
    </code>
  ***************************************************************************/

bool TimeElapsed1ms ( uint16_t time );

/****************************************************************************
  Function:
    BOOL TimeElapsed100ms ( uint16_t time )

  Description:
    Safely checks if 100 ms timer reached given value.

  Precondition:
    None

  Parameters:
    uint16_t time     - time mark in 100 ms units to check against

  Returns:
    BOOL            - TRUE if timer passed the mark

  Remarks:
    This function accounts to possible timer rollover, thus making checking
    safe and simple. Common usage profile:
    <code>
        timemark = TimeGet100ms () + TIMEOUT_100MS;
        while ( TimeElapsed100ms ( timemark ) != TRUE )
        {
            ...
        }
    </code>
  ***************************************************************************/

bool TimeElapsed100ms ( uint16_t time );

////////////////////////////////////////////////////////////////////////////////
#endif
