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

#define     TIME_C
#include    "time.h"
#include    "xc.h"
#include    "config.h"

////////////////////////////////////////////////////////////////////////////////

static volatile uint16_t time1ms, time10ms, time100ms;
static volatile uint16_t div10ms, div100ms;
static volatile uint32_t timeCycles;


//typedef 
void (*TimeCallback)(void *);

////////////////////////////////////////////////////////////////////////////////
void* TimeInit ( void (*timer_cb)(void *) )
{
    TimeCallback = timer_cb;
    time1ms = 0;
    time10ms = 0;
    time100ms = 0;
    div10ms = 0;
    div100ms = 0;


    TMR1 = 0;
    T1CON = 00;

    PR1 = GetPeripheralClock () / 1000;
    
    INTSetVectorPriority ( INT_TIMER_1_VECTOR, INT_PRIORITY_LEVEL_7);
    INTSetVectorSubPriority ( INT_TIMER_1_VECTOR, INT_SUB_PRIORITY_LEVEL_0 );
    INTEnable ( INT_T1, INT_ENABLED );

    return ((void*)&T1CON);
}

void TimeStart ( void )
{
    T1CONbits.TON = 1;
}

void TimeStop ( void )
{
    T1CONbits.TON = 0;
}
////////////////////////////////////////////////////////////////////////////////
void TimeUpdate ( uint16_t time )
{
    
    time1ms += time;

    div10ms += time;
    while ( div10ms >= 10)
    {
        time10ms ++;
        div10ms -= 10;
        TimeCallback((void*)&T1CON);
    }
            
    div100ms += time;
    while ( div100ms >= 100 )
    {
        
        time100ms ++;
        div100ms -= 100;
    }
}
////////////////////////////////////////////////////////////////////////////////
void TimeDelay10us ( uint16_t delay )
{

    timeCycles = delay;
    timeCycles *= ( GetInstructionClock () + 3905 ) / 3906;
    timeCycles /= 128;
    if ( timeCycles >= 5 )
    {
        timeCycles -= 5;
        while ( timeCycles -- );
    }
}
////////////////////////////////////////////////////////////////////////////////
void TimeDelay1ms ( uint16_t delay )
{
    delay += time1ms + 1;

    while ( delay - time1ms < 0x8000u )
    {

        Nop();
        Nop();
        Nop();
    }
}
////////////////////////////////////////////////////////////////////////////////
uint16_t TimeGet1ms ( void )
{
    return ( time1ms );
}
////////////////////////////////////////////////////////////////////////////////
uint16_t TimeGet100ms ( void )
{
    return ( time100ms );
}
////////////////////////////////////////////////////////////////////////////////
bool TimeElapsed1ms ( uint16_t timeMark )
{
    timeMark -= time1ms;
    return ( timeMark >= 0x8000 );
}
////////////////////////////////////////////////////////////////////////////////
bool TimeElapsed100ms ( uint16_t timeMark )
{
    timeMark -= time100ms;
    return ( timeMark >= 0x8000 );
}
////////////////////////////////////////////////////////////////////////////////


void __ISR ( _TIMER_1_VECTOR, IPL7SOFT ) _T1Interrupt ( void )
{
    // Reset interrupt flag.
    IFS0CLR = _IFS0_T1IF_MASK;
    // Our timer interrupt is configured to fire every millisecond.
    TimeUpdate ( 1 );


}
