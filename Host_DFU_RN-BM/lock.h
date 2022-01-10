/********************************************************************
 * FileName:        lock.h
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

#ifndef _LOCK_H_
#define _LOCK_H_

#include <xc.h>
#include <peripheral/dma.h>
#include <peripheral/int.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


/*********************************************************************
  Function:        void mSYSTEMUnlock(intStat, dmaSusp)

  PreCondition:    None

  Input:           None

  Output:          None

  Side Effects:    The system will be unlocked, the interrupts disabled and the DMA
            operation suspended.
            The previous interrupt and DMA status is saved in the passed parameters,
            supposed to be integers.

  Example:
    <code>
    unsigned int status1, status2;
    mSYSTEMUnlock(status1, status2);
    //change some system settings
    mSYSTEMLock(status1, status2);
    </code>
  Note:            The first write is "garbage" to ensure that the
                   unlocking is correctly preformed
 ********************************************************************/
#ifdef _DMAC
    #define mSYSTEMUnlock(intStat, dmaSusp) do{intStat=INTDisableInterrupts(); dmaSusp=DmaSuspend(); \
                        SYSKEY = 0, SYSKEY = 0xAA996655, SYSKEY = 0x556699AA;}while(0)
#else
    #define mSYSTEMUnlock(intStat, dmaSusp) do{intStat=INTDisableInterrupts(); \
                        SYSKEY = 0, SYSKEY = 0xAA996655, SYSKEY = 0x556699AA;}while(0)
#endif  // _DMAC


/*********************************************************************
  Function:        void mSYSTEMLock(intStat, dmaSusp)

  PreCondition:    None

  Input:           None

  Output:          None

   Example:
    <code>
    unsigned int status1, status2;
    mSYSTEMUnlock(status1, status2);
    //change some system settings
    mSYSTEMLock(status1, status2);
    </code>

  Side Effects:    The system will be locked and the status of the interrupts and the DMA restored
            from the integer parameters passed.
 ********************************************************************/
#ifdef _DMAC
    #define mSYSTEMLock(intStat, dmaSusp)   do{SYSKEY = 0x33333333; DmaResume(dmaSusp); INTRestoreInterrupts(intStat);}while(0)
#else
    #define mSYSTEMLock(intStat, dmaSusp)   do{SYSKEY = 0x33333333; INTRestoreInterrupts(intStat);}while(0)
#endif // _DMAC

/*********************************************************************
  Function:        void mSysUnlockOpLock(op)

  PreCondition:    None

  Input:           Operator to be performed between unlocking and locking the system.

  Output:          None


  Side Effects:    The system will be unlocked, the operation(s) passed as parameter will be executed
            and the system will be locked again.

  Note:            None
 ********************************************************************/
#ifdef _DMAC
    #define mSysUnlockOpLock(op)    do{int intStat, dmaSusp; intStat=INTDisableInterrupts(); dmaSusp=DmaSuspend(); \
                SYSKEY = 0, SYSKEY = 0xAA996655, SYSKEY = 0x556699AA; \
                (op); \
                SYSKEY = 0x33333333; \
                DmaResume(dmaSusp); INTRestoreInterrupts(intStat);}while(0)
#else
    #define mSysUnlockOpLock(op)    do{int intStat; intStat=INTDisableInterrupts(); \
                SYSKEY = 0, SYSKEY = 0xAA996655, SYSKEY = 0x556699AA; \
                (op); \
                SYSKEY = 0x33333333; \
                INTRestoreInterrupts(intStat);}while(0)
#endif  // _DMAC





#endif  // _LOCK_H_
