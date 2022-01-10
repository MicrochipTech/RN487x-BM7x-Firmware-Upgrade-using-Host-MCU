/*********************************************************************
 *
 *                  OSC API definitions
 *
 *********************************************************************
 * FileName:        OSC.h
 * Dependencies:
 * Processor:       PIC32
 *
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC Microcontroller products.
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
 * $Id: OSC.h,v 1.6 2006/10/13 21:24:31 C12532 Exp $
 * $Name:  $
 ********************************************************************/

#ifndef OSC_H_
#define OSC_H_

#include <xc.h>
#include <peripheral/lock.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


#define _OSC_

/*********************************************************************
 * Function:        OSCConfig(unsigned long int source, unsigned long int mult, unsigned long int post, unsigned long int div)
 *
 * Description:     Sets Osc options and clock source
 *
 * PreCondition:    Interrupts must be disabled and DMA suspended or disabled
 *
 * Inputs:          Clock source, PLL multiplier, PLL postscaler, FRC divisor - see below
 *
 * Output:          None
 *
 * Example:         OSCConfig( OSC_POSC, OSC_PLL_MULT_24, OSC_PLL_POST_256, OSC_FRC_POST_64 )
 *
 * Note:            Forces cpu clock source to FRC(no divisor, no PLL), configures new clock
 *                  source and then switches to the new clock source
 *
 *                  Unused parameters are set to zero/default values.
 ********************************************************************/
void OSCConfig(unsigned long int source, unsigned long int mult, unsigned long int post, unsigned long int div);

    /******************************************************************************
     * Available options for source parameter
     *****************************************************************************/
        // CPU Oscillator modes - values are mutually exclusive
        #define OSC_FRC_DIV     (7 << _OSCCON_NOSC_POSITION)
        #define OSC_FRC_DIV16   (6 << _OSCCON_NOSC_POSITION)
        #define OSC_LPRC        (5 << _OSCCON_NOSC_POSITION)
        #define OSC_SOSC        (4 << _OSCCON_NOSC_POSITION)
        #define OSC_POSC_PLL    (3 << _OSCCON_NOSC_POSITION)
        #define OSC_POSC        (2 << _OSCCON_NOSC_POSITION)
        #define OSC_FRC_PLL     (1 << _OSCCON_NOSC_POSITION)
        #define OSC_FRC         (0 << _OSCCON_NOSC_POSITION)

    /******************************************************************************
     * Available options for mult parameter
     *****************************************************************************/
        // CPU PLL multiplier values - values are mutually exclusive
        #define OSC_PLL_MULT_24 (7 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_21 (6 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_20 (5 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_19 (4 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_18 (3 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_17 (2 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_16 (1 << _OSCCON_PLLMULT_POSITION)
        #define OSC_PLL_MULT_15 (0 << _OSCCON_PLLMULT_POSITION)

    /******************************************************************************
     * Available options for post parameter
     *****************************************************************************/
        // CPU PLL output divisor values - values are mutuallye exclusive
        #define OSC_PLL_POST_256 (7 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_64  (6 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_32  (5 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_16  (4 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_8   (3 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_4   (2 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_2   (1 << _OSCCON_PLLODIV_POSITION)
        #define OSC_PLL_POST_1   (0 << _OSCCON_PLLODIV_POSITION)

    /******************************************************************************
     * Available options for div parameter
     *****************************************************************************/
        // CPU FRC output divisor values - values are mutually exclusive
        #define OSC_FRC_POST_256 (7 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_64  (6 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_32  (5 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_16  (4 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_8   (3 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_4   (2 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_2   (1 << _OSCCON_FRCDIV_POSITION)
        #define OSC_FRC_POST_1   (0 << _OSCCON_FRCDIV_POSITION)
    /***********************************
     * End parameter values
     ************************************/

#if defined(__32MX120F064H__) || \
    defined(__32MX130F128H__) || \
    defined(__32MX130F128L__) || \
    defined(__32MX150F256H__) || \
    defined(__32MX150F256L__) || \
    defined(__32MX170F512H__) || \
    defined(__32MX170F512L__) || \
    defined(__32MX230F128H__) || \
    defined(__32MX230F128L__) || \
    defined(__32MX250F256H__) || \
    defined(__32MX250F256L__) || \
    defined(__32MX270F512H__) || \
    defined(__32MX270F512L__) || \
    defined(__32MX530F128H__) || \
    defined(__32MX530F128L__) || \
    defined(__32MX550F256H__) || \
    defined(__32MX550F256L__) || \
    defined(__32MX570F512H__) || \
    defined(__32MX570F512L__)
  #define NEED_OSCREFCONFIG_FLAGS
#elif (__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)
  #define NEED_OSCREFCONFIG_FLAGS
#elif (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470)
  #define NEED_OSCREFCONFIG_FLAGS
#else
  #undef  NEED_OSCREFCONFIG_FLAGS
#endif

#if defined( NEED_OSCREFCONFIG_FLAGS )
    // Reference Oscillator Source Select bits - values are mutually exclusive
    #define OSC_REFOCON_REFCLKI     (7 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_SYSPLL      (7 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_USBPLL      (6 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_SOSC        (5 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_LPRC        (4 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_FRC         (3 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_POSC        (2 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_PBCLK       (1 << _REFOCON_ROSEL_POSITION )
    #define OSC_REFOCON_SYSCLK      (0 << _REFOCON_ROSEL_POSITION )

    typedef enum
    {
            OSC_REFOCON_RLSPEN      =(1 << _REFOCON_RSLP_POSITION ) ,
            OSC_REFOCON_OE          =(1 << _REFOCON_OE_POSITION ),
            OSC_REFOCON_SIDLEN      =(1 << _REFOCON_SIDL_POSITION ),
            OSC_REFOCON_ON          =(1 << _REFOCON_ON_POSITION )
    } OSCREFConfigFlags;

    void OSCREFConfig(unsigned long int source, OSCREFConfigFlags config, unsigned long int div);


    #define mOSCREFOTRIMSet(trim)       (REFOTRIM = (trim << _REFOTRIM_ROTRIM_POSITION))

#endif//defined( NEED_OSCREFCONFIG_FLAGS )

#undef  NEED_OSCREFCONFIG_FLAGS


/*********************************************************************
 * Function:    OSCSetPBDIV(unsigned int oscPbDiv)
 *
 * Description: Configures peripheral bus divisor
 *
 * PreCondition: oscPbDiv one of the OSC_PB_DIV_X valid values
 *
 * Inputs:    oscPbDiv - desired PB divider
 *
 * Output:      None
 *
 * Example:   OSCSetPBDIV(  OSC_PB_DIV_8 )
 *
 ********************************************************************/
extern inline void __attribute__((always_inline)) OSCSetPBDIV(unsigned int oscPbDiv)
{
    unsigned int dma_status;
    unsigned int int_status;
    __OSCCONbits_t oscBits;

    mSYSTEMUnlock(int_status, dma_status);

    oscBits.w=OSCCON;       // read to be in sync. flush any pending write
    oscBits.PBDIV=0;
    oscBits.w|=oscPbDiv;
    OSCCON=oscBits.w;       // write back
    oscBits.w=OSCCON;       // make sure the write occurred before returning from this function

    mSYSTEMLock(int_status, dma_status);
}

#define     mOSCSetPBDIV        OSCSetPBDIV     // backward compatibility



    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // CPU Peripheral Bus divisor values - values are mutually exclusive
        #define OSC_PB_DIV_8    (3 << _OSCCON_PBDIV_POSITION)
        #define OSC_PB_DIV_4    (2 << _OSCCON_PBDIV_POSITION)
        #define OSC_PB_DIV_2    (1 << _OSCCON_PBDIV_POSITION)
        #define OSC_PB_DIV_1    (0 << _OSCCON_PBDIV_POSITION)
    /***********************************
     * End config parameter values
     ************************************/


/*********************************************************************
 * Function:    mOSCGetPBDIV()
 *
 * Description: Reads peripheral bus divisor
 *
 * PreCondition:None
 *
 * Inputs:      None
 *
 * Output:      None
 *
 * Example:     mOSCGetPBDIV()
 *
 ********************************************************************/
#define mOSCGetPBDIV() (OSCCONbits.PBDIV)


/*********************************************************************
 * Function:    mOSCClockFailStatus()
 *
 * Description: Returns Clock Fail status. 1 = clock fail, 0 = no clock fail
 *
 * PreCondition: None
 *
 * Inputs:      None
 *
 * Output:      None
 *
 * Example:     mOSCClockFailStatus()
 *
 ********************************************************************/
#define mOSCClockFailStatus (OSCCONbits.CF)


/*********************************************************************
 * Function:        mOSCEnableSOSC()
 *
 * Description:     Enables the LPRC
 *
 * PreCondition:    Interrupts must be disabled and DMA suspended or disabled
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         mOSCEnableSOSC()
 *
 ********************************************************************/
#define mOSCEnableSOSC() mSysUnlockOpLock(OSCCONSET = _OSCCON_SOSCEN_MASK)


/*********************************************************************
 * Function:        mOSCDisableSOSC(config)
 *
 * Description:     Disables SOSC
 *
 * PreCondition:    Interrupts must be disabled and DMA suspended or disabled
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         mOSCDisableSOSC()
 *
 ********************************************************************/
#define mOSCDisableSOSC() mSysUnlockOpLock(OSCCONCLR = _OSCCON_SOSCEN_MASK)



#endif
