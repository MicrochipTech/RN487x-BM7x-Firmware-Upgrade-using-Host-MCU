/********************************************************************

    System Library Interface Definition

    Summary:
        This file contains the interface definition for the System
        peripheral library.

    Description:
        This library provides functions for configuring the peripheral
        clock, cache settings, and wait states.  For details on the
        register and bit settings used by these functions, refer to the
        PIC32 Family Reference Manual.


 ********************************************************************/
//DOM-IGNORE-BEGIN
/********************************************************************
 * FileName:        System.h
 * Dependencies:
 * Processor:       PIC32
 * Hardware:        N/A
 * Assembler:       N/A
 * Linker:          N/A
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement:
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * $Id: CoreTimer.h,v 1.2 2006/11/03 15:07:21 C12923 Exp $
 * $Name:  $
 ********************************************************************/
//DOM-IGNORE-END


#ifndef _SYSTEM_HEADER_FILE
#define _SYSTEM_HEADER_FILE

#include <xc.h>
#include <peripheral/int.h>
#include <peripheral/pcache.h>
#include <peripheral/osc.h>
#include <peripheral/dma.h>
#include <peripheral/bmx.h>
#include <peripheral/lock.h>
#ifdef __cplusplus
extern "C"
  {
#endif

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif



#define FLASH_SPEED_HZ          30000000 //Max Flash speed
#define PB_BUS_MAX_FREQ_HZ      80000000 //Max Peripheral bus speed

/*********************************************************************
 * SYSTEMConfig Flags
 *********************************************************************/
#define SYS_CFG_WAIT_STATES     0x00000001 //SYSTEMConfig wait states
#define SYS_CFG_PB_BUS          0x00000002 //SYSTEMConfig pb bus
#define SYS_CFG_PCACHE          0x00000004 //SYSTEMConfig cache
#define SYS_CFG_ALL             0xFFFFFFFF //SYSTEMConfig All

/*********************************************************************
 Function:
    unsigned int SYSTEMConfigPB(unsigned int sys_clock)

 Description:
    The function sets the PB divider to the optimum value.

 PreCondition:
    None

 Parameters:
    sys_clock - system clock in Hz

 Returns:
    the PB clock frequency in Hz

 Side Effects:
    The PB clock may be changed

 Overview:
    The function sets the PB divider to the optimum value.

 Remarks:
    The interrupts are disabled briefly, the DMA is suspended and the system is unlocked while performing the operation.
    Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.

 Example:
    <code>
    SYSTEMConfigPB(72000000);
    </code>
 ********************************************************************/
extern inline unsigned int __attribute__((always_inline)) SYSTEMConfigPB(unsigned int sys_clock)
{
    unsigned int pb_div;
    unsigned int pb_clock;

    pb_clock = sys_clock;

    if(sys_clock > PB_BUS_MAX_FREQ_HZ)
    {
        pb_div=OSC_PB_DIV_2;
        pb_clock >>= 1;
    }
    else
    {
        pb_div=OSC_PB_DIV_1;
    }

    OSCSetPBDIV(pb_div);

    return pb_clock;
}


/*********************************************************************
  Function:
    void SYSTEMConfigWaitStates(unsigned int sys_clock)

  Description:
    The function sets the Flash Wait states to the optimum value.

  PreCondition:
    None

  Parameters:
    sys_clock - system clock in Hz

  Returns:
    None

  Side Effects:
    The Wait States may be changed

  Remarks:
    The interrupts are disabled briefly, the DMA is suspended and the system is unlocked while performing the operation.
    Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.

  Example:
    <code>
    SYSTEMConfigWaitStates(72000000);
    </code>
 ********************************************************************/
extern inline void __attribute__((always_inline)) SYSTEMConfigWaitStates(unsigned int sys_clock)
{
#ifdef _PCACHE
    unsigned int wait_states;
    unsigned int int_status;
#endif

#ifdef _PCACHE
    wait_states = 0;

    while(sys_clock > FLASH_SPEED_HZ)
    {
        wait_states++;
        sys_clock -= FLASH_SPEED_HZ;
    }

    int_status=INTDisableInterrupts();
    mCheConfigure(wait_states);
    INTRestoreInterrupts(int_status);

#endif
}

/*********************************************************************
  Function:
        unsigned int SYSTEMConfigWaitStatesAndPB(unsigned int sys_clock)

  Description:
    The function sets the PB divider and the Flash Wait states to the optimum value.

  PreCondition:
    None

  Parameters:
    sys_clock - system clock in Hz

  Returns:
    the PB clock frequency in Hz

  Side Effects:
    The PB clock and wait states may be changed

  Remarks:
    The interrupts are disabled briefly, the DMA is suspended and the system is unlocked while performing the operation.
    Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.

  Example:
    <code>
    SYSTEMConfigWaitStatesAndPB(72000000);
    </code>
 ********************************************************************/
extern inline unsigned int __attribute__((always_inline)) SYSTEMConfigWaitStatesAndPB(unsigned int sys_clock)
{
#ifdef _PCACHE
    unsigned int wait_states;
#endif
    unsigned int pb_clock;
    unsigned int int_status;

    pb_clock = SYSTEMConfigPB(sys_clock);


    // set the flash wait states based on 1 wait state
    // for every 20 MHz
#ifdef _PCACHE
    wait_states = 0;

    while(sys_clock > FLASH_SPEED_HZ)
    {
        wait_states++;
        sys_clock -= FLASH_SPEED_HZ;
    }

    int_status=INTDisableInterrupts();
    mCheConfigure(wait_states);
    INTRestoreInterrupts(int_status);

#endif

    return pb_clock;
}
/*********************************************************************
  Function:
    unsigned int SYSTEMConfigPerformance(unsigned int sys_clock)

  Description:
    The function sets the PB divider, the Flash Wait states and the DRM wait states to the optimum value.
    It also enables the cacheability for the K0 segment.

  PreCondition:
    None

  Parameters:
    sys_clock - system clock in Hz

  Output:
    the PB clock frequency in Hz

  Side Effects:
    Sets the PB and Flash Wait states

  Remarks:
    The interrupts are disabled briefly, the DMA is suspended and the system is unlocked while performing the operation.
    Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.

  Example:
    <code>
    SYSTEMConfigPerformance(72000000);
    </code>
 ********************************************************************/
extern inline unsigned int __attribute__((always_inline)) SYSTEMConfigPerformance(unsigned int sys_clock)
{
    // set up the wait states
    unsigned int pb_clk;
#ifdef _PCACHE
    unsigned int cache_status;
#endif
    unsigned int int_status;

    pb_clk = SYSTEMConfigWaitStatesAndPB(sys_clock);

    int_status=INTDisableInterrupts();

    mBMXDisableDRMWaitState();

#ifdef _PCACHE
    cache_status = mCheGetCon();
    cache_status |= CHE_CONF_PF_ALL;
    mCheConfigure(cache_status);
    CheKseg0CacheOn();
#endif

    INTRestoreInterrupts(int_status);

    return pb_clk;

}
/*********************************************************************
  Function:
    unsigned int SYSTEMConfig(unsigned int sys_clock, unsigned int flags)

  Description:
    The function sets the PB divider, the Flash Wait states or the DRM wait states to the optimum value,
    based on the flags selected and on the frequency of the system clock.
    It also enables the cacheability for the K0 segment.

  PreCondition:
    None

  Parameters:
    sys_clock - system clock frequency in Hz
    flags -
        *    SYS_CFG_WAIT_STATES  - configure the flash wait states from the system clock
        *    SYS_CFG_PB_BUS       - configure the PB bus from the system clock
        *    SYS_CFG_PCACHE      - configure the pCache (if used)
        *    SYS_CFG_ALL          - configure all based on system clock

  Returns:
    the PB clock frequency in Hz

  Side Effects:
    Could change the wait state, pb clock and turn on the pre-fetch buffer and cache. Sets the RAM
    wait state to 0.


  Remarks:
    The interrupts are disabled shortly, the DMA is suspended and the system is unlocked while performing the operation.
    Upon return the previous status of the interrupts and the DMA are restored. The system is re-locked.

  Example:
    <code>
    SYSTEMConfig(72000000, SYS_CFG_ALL);
    </code>
 ********************************************************************/
extern inline unsigned int __attribute__((always_inline)) SYSTEMConfig(unsigned int sys_clock, unsigned int flags)
{
    unsigned int pb_clk;
    unsigned int int_status;
#ifdef _PCACHE
    unsigned int cache_status;
#endif

    int_status=INTDisableInterrupts();

    mBMXDisableDRMWaitState();

    if(flags & SYS_CFG_WAIT_STATES)
    {
        SYSTEMConfigWaitStates(sys_clock);
    }

    if(flags & SYS_CFG_PB_BUS)
    {
        SYSTEMConfigPB(sys_clock);
    }


#ifdef _PCACHE
    if(flags & SYS_CFG_PCACHE)
    {
        cache_status = mCheGetCon();
        cache_status |= CHE_CONF_PF_ALL;
        mCheConfigure(cache_status);
        CheKseg0CacheOn();
    }
#endif

    pb_clk = sys_clock;
    pb_clk >>= OSCCONbits.PBDIV;

    INTRestoreInterrupts(int_status);

    return pb_clk;

}
#ifdef __cplusplus
  }
#endif
#endif

