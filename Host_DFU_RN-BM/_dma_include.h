/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        _dma_include.h
 * Dependencies:    Dma.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32/PIC24F Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24F Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
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
 *
 * $Id:$
 * $Name$
 *
 ********************************************************************/

#ifndef _DMAINCLUDE_H_
#define _DMAINCLUDE_H_


#include <xc.h>
#include <peripheral/dma.h>


#ifdef _DMA_CHANNELS

#if  ( ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || \
      (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470) || \
       defined(__32MXGENERIC__) )
#   define _DMA_REV_5XX_
#   include "_dma_5xx_6xx_7xx_include.h"
#elif  ((__PIC32_FEATURE_SET__ >= 300) && (__PIC32_FEATURE_SET__ <= 499))
#   define _DMA_REV_3XX_
#   include "_dma_3xx_4xx_include.h"
#elif  ((__PIC32_FEATURE_SET__ >= 500) && (__PIC32_FEATURE_SET__ <= 799))
#   define _DMA_REV_5XX_
#   include "_dma_5xx_6xx_7xx_include.h"
#else
#   error "Device not supported by the DMA peripheral library"
#endif


extern volatile _DmaRegMap* const _DmaMapTbl;
// dma register map table


// common local inline functions
/*********************************************************************
 * Function:        unsigned int _VirtToPhys(const void* p)
 *
 * PreCondition:    None
 *
 * Input:           p   - pointer to be converted.
 *
 * Output:          a physical address corresponding to the virtual input pointer
 *
 * Side Effects:    None
 *
 * Overview:        Virtual to physical translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) _VirtToPhys(const void* p)
{
    return (int)p<0?((int)p&0x1fffffffL):(unsigned int)((unsigned char*)p+0x40000000L);
}

/*********************************************************************
 * Function:        void* _PhysToVirtK0(unsigned int a)
 *
 * PreCondition:    None
 *
 * Input:           a   - address to be converted.
 *
 * Output:          a virtual pointer corresponding to the physical input address
 *
 * Side Effects:    None
 *
 * Overview:        Physical to virtual translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void* __attribute__((always_inline)) _PhysToVirtK0(unsigned int a)
{
    return a<0x40000000L?(void*)(a|0x80000000L):(void*)(a-0x40000000L);
}

/*********************************************************************
 * Function:        void* _PhysToVirtK1(unsigned int a)
 *
 * PreCondition:    None
 *
 * Input:           a   - address to be converted.
 *
 * Output:          a virtual pointer corresponding to the physical input address
 *
 * Side Effects:    None
 *
 * Overview:        Physical to virtual translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void* __attribute__((always_inline)) _PhysToVirtK1(unsigned int a)
{
    return a<0x40000000L?(void*)(a|0xa0000000L):(void*)(a-0x40000000L);
}



/*********************************************************************
 * Function:        void _DmaChnInitOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Makes sure the DMA controller is on and running
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) _DmaChnInitOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);    // abort channel
        DMACONCLR=_DMACON_SUSPEND_MASK;     // unsuspend
        DMACONSET=_DMACON_ON_MASK;      // make sure it's on
    _DmaChnWaitAbort(pReg);         // wait operation abort

}

/*********************************************************************
 * Function:        void _DmaChnAbortOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Does not turn on the DMA controller, does not unsuspend
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) _DmaChnAbortOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);        // abort
        _DmaChnWaitAbort(pReg);             // wait abort
}

/*********************************************************************
 * Function:        void _DmaChnOpenOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Turns on the DMA controller but does not perform unsuspend
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) _DmaChnOpenOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);        // abort
        DMACONSET=_DMACON_ON_MASK;          // make sure it's on
    _DmaChnWaitAbort(pReg);             // wait abort
}




#endif  // _DMA_CHANNELS

#endif  // _DMAINCLUDE_H_

