/*********************************************************************
 *
 *                  CMP API definitions
 *
 *********************************************************************
 * FileName:        CMP.h
 * Dependencies:
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PIC Microcontroller is intended
 * and supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PIC Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id:$
 *
 ********************************************************************/

#ifndef CMP_H_
#define CMP_H_

#include <xc.h>
#include <peripheral/int.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#if !defined( _SUPPRESS_PLIB_WARNING )
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


/*********************************************************************
 * Function:        CMPxOpen()
 *
 * Description:     Configures Comparator 1, the common SIDL bit for both comparators is also written
 *
 * PreCondition:    None
 *
 * Inputs:          Desired configuration - see below
 *
 * Output:          None
 *
 * Example:         CMPxOpen()
 *
 ********************************************************************/
//#define CMP1Open(config)  (CM1CONCLR = CMP_ENABLE, CM1CON = (config) & 0x7FFF, CMSTATCLR = _CMSTAT_SIDL_POSITION, CMSTATSET = (config) >> 16, CM1CONSET = (config) & _CM1CON_ON_MASK)
//#define CMP2Open(config)  (CM2CONCLR = CMP_ENABLE, CM2CON = (config) & 0x7FFF, CMSTATCLR = _CMSTAT_SIDL_POSITION, CMSTATSET = (config) >> 16, CM2CONSET = (config) & _CM2CON_ON_MASK)


#define CMP1Open(config)  (CM1CON = (config)&0xFFFF, CMSTATCLR = _CMSTAT_SIDL_MASK, CMSTATSET = ((config)>>29))
#define CMP2Open(config)  (CM2CON = (config)&0xFFFF, CMSTATCLR = _CMSTAT_SIDL_MASK, CMSTATSET = ((config)>>29))

    /****************************************
     * Available options for config parameter - used by both CMP1Open and CM2Open except two exceptions highlighted below
     ****************************************/
        // CMP Operation in idle - values are mutually exclusive
        #define CMP_STOP_IN_IDLE        (1 << 29)           // Goes in CMSTAT register SIDL position
        #define CMP_RUN_IN_IDLE         (0)

        // CMP Enable/disable - values are mutually exclusive
        #define CMP_ENABLE              (1 << _CM1CON_ON_POSITION)
        #define CMP_DISABLE             (0)

        #define CMP_OUTPUT_ENABLE       (1 << _CM1CON_COE_POSITION)
        #define CMP_OUTPUT_DISABLE      (0)

        // CMP Output control - values are mutuallye exclusive
        #define CMP_OUTPUT_INVERT       (1 << _CM1CON_CPOL_POSITION)
        #define CMP_OUTPUT_NONINVERT    (0)

        // CMP Interrupt event select - values are mutually exclusive
        #define CMP_EVENT_NONE          (0)
        #define CMP_EVENT_LOW_TO_HIGH   (1 << _CM1CON_EVPOL0_POSITION)
        #define CMP_EVENT_HIGH_TO_LOW   (2 << _CM1CON_EVPOL0_POSITION)
        #define CMP_EVENT_CHANGE        (3 << _CM1CON_EVPOL0_POSITION)

        // For CM1Open only

        // CMP1  Positive input select - values are mutually exclusive - for CMP1Open Only.
        #define CMP_POS_INPUT_C1IN_POS  (0)
        #define CMP_POS_INPUT_CVREF     (1 << _CM1CON_CREF_POSITION)

        // CMP1 Negative input select - values are mutually exclusive - for CMP1Open Only
        #define CMP1_NEG_INPUT_C1IN_NEG (0 << _CM1CON_CCH_POSITION)
        #define CMP1_NEG_INPUT_C1IN_POS (1 << _CM1CON_CCH_POSITION)
        #define CMP1_NEG_INPUT_C2IN_POS (2 << _CM1CON_CCH_POSITION)
        #define CMP1_NEG_INPUT_IVREF    (3 << _CM1CON_CCH_POSITION)

        // For CM2Open only

        // CMP2 Positive input select - values are mutually exclusive - for CMP2Open only
        #define CMP_POS_INPUT_C2IN_POS  (0)
        // OR use CMP_POS_INPUT_CVREF as defined above

        // CMP2 Negative input select - values are mutually exclusive - for CMP2Open only
        #define CMP2_NEG_INPUT_C2IN_NEG (0 << _CM2CON_CCH_POSITION)
        #define CMP2_NEG_INPUT_C2IN_POS (1 << _CM2CON_CCH_POSITION)
        #define CMP2_NEG_INPUT_C1IN_POS (2 << _CM2CON_CCH_POSITION)
        #define CMP2_NEG_INPUT_IVREF    (3 << _CM2CON_CCH_POSITION)
    /****************************************
     * End config parameter values
     ****************************************/



/*********************************************************************
 * <combinewith CMP2Close>
 *
 * Function:        CMPxClose()
 *
 * Description:     Turns off the comparator and disables the interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          Desired configuration
 *
 * Output:          None
 *
 * Example:         CMP1Close()
 *
 ********************************************************************/
#define CMP1Close()  (CM1CONCLR = CMP_ENABLE, mCMP1IntEnable(0))
#define CMP2Close()  (CM2CONCLR = CMP_ENABLE, mCMP2IntEnable(0))


/*********************************************************************
 * <combinewith CMP2ConfigInt>
 *
 * Function:        CMPxConfigInt(config)
 *
 * Description:     Configures the interrupt priority and enables the interrupt, this affects the common int priority for both comparators
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CMPxConfigInt()
 *
 ********************************************************************/
#define CMP1ConfigInt(config)  ( mCMP1ClearIntFlag(), mCMP1SetIntPriority((config)&7), mCMP1SetIntSubPriority(((config) >> 4)&3), mCMP1IntEnable((config) >> 15) )
#define CMP2ConfigInt(config)  ( mCMP2ClearIntFlag(), mCMP2SetIntPriority((config)&7), mCMP2SetIntSubPriority(((config) >> 4)&3), mCMP2IntEnable((config) >> 15) )


    /****************************************
     * Available options for config parameter - used by both CMP1Open and CM2Open except two exceptions highlighted below
     ****************************************/
        // Priority values -  Values are mutually exclusive
        #define CMP_INT_PRIOR_7         (7)
        #define CMP_INT_PRIOR_6         (6)
        #define CMP_INT_PRIOR_5         (5)
        #define CMP_INT_PRIOR_4         (4)
        #define CMP_INT_PRIOR_3         (3)
        #define CMP_INT_PRIOR_2         (2)
        #define CMP_INT_PRIOR_1         (1)
        #define CMP_INT_PRIOR_0         (0)

        // Sub-Priority values -  Values are mutually exclusive
        #define CMP_INT_SUB_PRI_3       (3<<4)
        #define CMP_INT_SUB_PRI_2       (2<<4)
        #define CMP_INT_SUB_PRI_1       (1<<4)
        #define CMP_INT_SUB_PRI_0       (0<<4)

        // CMP Interrupt enable/disable - values are mutually exclusive
        #define CMP_INT_ENABLE          (1<<15)
        #define CMP_INT_DISABLE         (0)
    /****************************************
     * End config parameter values
     ****************************************/


/*********************************************************************
 * <combinewith CMP2Read>
 *
 * Function:        CMPxRead()
 *
 * Description:     Returns the status of the Comparator Output Status bit
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          1 or 0
 *
 * Example:         CMPxRead()
 *
 ********************************************************************/
#define CMP1Read()  (CM1CONbits.COUT)
#define CMP2Read()  (CM2CONbits.COUT)



#endif /*CMP_H_*/
