/******************************************************************************
 *
 *                  IO PORT Library definitions
 *
 ******************************************************************************
 * FileName:        ports.h
 * Dependencies:
 * Processor:       PIC32 family
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc..
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
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
 * $Id: ports.h,v 1.3 2006/11/10 16:22:47 C11842 Exp $
 *
 * $Name:  $
 *
 *****************************************************************************/

#ifndef _PORTS_H_
#define _PORTS_H_

#include <xc.h>
#include <peripheral/int.h>
#include <peripheral/SPI_Port_Mappings.h>
#include <peripheral/Ethernet_Port_Mappings.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


/******************************************************************************
 * Parameter values to be used with ConfigINTx() & SetPriorityINTx()
 *****************************************************************************/
// Interrupt enable/disable values
#define EXT_INT_ENABLE          (1 << 15)
#define EXT_INT_DISABLE         (0)         /* Default */

// Interrupt edge modes - must be any one value only
#define RISING_EDGE_INT         (1 << 3)
#define FALLING_EDGE_INT        (0)         /* Default */

// Priority values - must be any one value only
#define EXT_INT_PRI_7         (7) //Priority 7
#define EXT_INT_PRI_6         (6) //Priority 6
#define EXT_INT_PRI_5         (5) //Priority 5
#define EXT_INT_PRI_4         (4) //Priority 4
#define EXT_INT_PRI_3         (3) //Priority 3
#define EXT_INT_PRI_2         (2) //Priority 2
#define EXT_INT_PRI_1         (1) //Priority 1
#define EXT_INT_PRI_0         (0) //Priority Default

/******************************************************************************
 * <combinewith ConfigINT1, ConfigINT2, ConfigINT3, ConfigINT4>
 *
 * External INTx Control Function
 *
 * Function:        void ConfigINTx(unsigned int config)
 *
 * Description:     This macro configures an external interrupt as follows:
 *                  1. clears the INTx interrupt flag
 *                  2. sets the INTx priority
 *                  3. sets the INTx edge selection (rising or falling)
 *                  4. enables the INTx interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigINT0(EXT_INT_PRI_1 | RISING_EDGE_INT | EXT_INT_ENABLE)
 *
 *****************************************************************************/
#define ConfigINT0(config)  (mINT0ClearIntFlag(), mINT0SetIntPriority((config) & 7),\
        mINT0SetEdgeMode(((config) >> 3) & 1), mINT0IntEnable((config) >> 15))

#define ConfigINT1(config)  (mINT1ClearIntFlag(), mINT1SetIntPriority((config) & 7),\
        mINT1SetEdgeMode(((config) >> 3) & 1), mINT1IntEnable((config) >> 15))

#define ConfigINT2(config)  (mINT2ClearIntFlag(), mINT2SetIntPriority((config) & 7),\
        mINT2SetEdgeMode(((config) >> 3) & 1), mINT2IntEnable((config) >> 15))

#define ConfigINT3(config)  (mINT3ClearIntFlag(), mINT3SetIntPriority((config) & 7),\
        mINT3SetEdgeMode(((config) >> 3) & 1), mINT3IntEnable((config) >> 15))

#define ConfigINT4(config)  (mINT4ClearIntFlag(), mINT4SetIntPriority((config) & 7),\
        mINT4SetEdgeMode(((config) >> 3) & 1), mINT4IntEnable((config) >> 15))


/******************************************************************************
 * <combinewith SetPriorityInt1, SetPriorityInt2, SetPriorityInt3, SetPriorityInt4,
 * SetPriorityINT0, SetPriorityINT1, SetPriorityINT2, SetPriorityINT3, SetPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetPriorityINTx(unsigned int priority)
 *
 * Description:     This macro sets the priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: A Priority value
 *
 * Output:          None
 *
 * Example:         SetPriorityInt0(EXT_INT_PRI_5)
 *
 *****************************************************************************/
#define SetPriorityInt0             SetPriorityINT0
#define SetPriorityInt1             SetPriorityINT1
#define SetPriorityInt2             SetPriorityINT2
#define SetPriorityInt3             SetPriorityINT3
#define SetPriorityInt4             SetPriorityINT4

#define SetPriorityINT0(priority)   (mINT0SetIntPriority(priority))
#define SetPriorityINT1(priority)   (mINT1SetIntPriority(priority))
#define SetPriorityINT2(priority)   (mINT2SetIntPriority(priority))
#define SetPriorityINT3(priority)   (mINT3SetIntPriority(priority))
#define SetPriorityINT4(priority)   (mINT4SetIntPriority(priority))


/******************************************************************************
 * Sub-priority values to be used with SetSubPriorityIntx
 *****************************************************************************/
#define EXT_INT_SUB_PRI_3           (3 << 4) //sub priority 3
#define EXT_INT_SUB_PRI_2           (2 << 4) //sub priority 2
#define EXT_INT_SUB_PRI_1           (1 << 4) //sub priority 1
#define EXT_INT_SUB_PRI_0           (0 << 4) //sub priority default

/******************************************************************************
 * <combinewith SetSubPriorityINT1, SetSubPriorityINT2, SetSubPriorityINT3, SetSubPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetSubPriorityINTx(unsigned int subPriority)
 *
 * Description:     This macro sets the sub-priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          A Sub-priority value
 *
 * Output:          None
 *
 * Example:         SetSubPriorityInt0(EXT_INT_SUB_PRI_2)
 *
 *****************************************************************************/
#define SetSubPriorityINT0(subpriority) (mINT0SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT1(subpriority) (mINT1SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT2(subpriority) (mINT2SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT3(subpriority) (mINT3SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT4(subpriority) (mINT4SetIntSubPriority((subpriority) >> 4))


/******************************************************************************
 * <combinewith CloseINT1, CloseINT2, CloseINT3, CloseINT4>
 *
 * External INTx Control Function
 *
 * Function:        void CloseINTx(void)
 *
 * Description:     This macro disables the external interrupt and clears corresponding flag.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseINT0()
 *
 *****************************************************************************/
#define CloseINT0()    (mINT0IntEnable(0), mINT0ClearIntFlag())
#define CloseINT1()    (mINT1IntEnable(0), mINT1ClearIntFlag())
#define CloseINT2()    (mINT2IntEnable(0), mINT2ClearIntFlag())
#define CloseINT3()    (mINT3IntEnable(0), mINT3ClearIntFlag())
#define CloseINT4()    (mINT4IntEnable(0), mINT4ClearIntFlag())

/******************************************************************************
 * <combinewith EnableINT1, EnableINT2, EnableINT3, EnableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void EnableINTx(void)
 *
 * Description:     This macro enables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableINT4()
 *
 *****************************************************************************/
#define EnableINT0    (mINT0IntEnable(1))
#define EnableINT1    (mINT1IntEnable(1))
#define EnableINT2    (mINT2IntEnable(1))
#define EnableINT3    (mINT3IntEnable(1))
#define EnableINT4    (mINT4IntEnable(1))

/******************************************************************************
 * <combinewith DisableINT1, DisableINT2, DisableINT3, DisableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void DisableINTx(void)
 *
 * Description:     This macro disables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableINT0()
 *
 *****************************************************************************/
#define DisableINT0             (mINT0IntEnable(0))
#define DisableINT1             (mINT1IntEnable(0))
#define DisableINT2             (mINT2IntEnable(0))
#define DisableINT3             (mINT3IntEnable(0))
#define DisableINT4             (mINT4IntEnable(0))


/******************************************************************************
 * Parameter values to be used with ConfigINTCN()
 *****************************************************************************/
// Change Interrupt ON/OFF values.
#define CHANGE_INT_ON               (1 << 23)
#define CHANGE_INT_OFF              (0)             /* Default */

// Change Interrupt Priority Values
#define CHANGE_INT_PRI_7            (7) //Priority 7
#define CHANGE_INT_PRI_6            (6) //Priority 6
#define CHANGE_INT_PRI_5            (5) //Priority 5
#define CHANGE_INT_PRI_4            (4) //Priority 4
#define CHANGE_INT_PRI_3            (3) //Priority 3
#define CHANGE_INT_PRI_2            (2) //Priority 2
#define CHANGE_INT_PRI_1            (1) //Priority 1
#define CHANGE_INT_PRI_0            (0) //Priority default


/******************************************************************************
 * Change Notice Interrupt Control Function
 *
 * Function:        void ConfigIntCN(unsigned int config)
 *
 * Description:     This macro configures Change Notice interrupts as follows
 *                  1. clears CN interrupt flag
 *                  2. sets CN interrupt priority
 *                  3. enables CN interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CHANGE_INT_PRIx and
 *                  CHANGE_INT_XXX sets
 *
 * Output:          None
 *
 * Example:         ConfigIntCN(CHANGE_INT_PRI_3 |
 *                                CHANGE_INT_ON)
 *
 *****************************************************************************/
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
  #define ConfigIntCNA(config) (mCNAClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNAIntEnable(((config) >> 23)))
  #define ConfigIntCNB(config) (mCNBClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNBIntEnable(((config) >> 23)))
  #define ConfigIntCNC(config) (mCNCClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNCIntEnable(((config) >> 23)))
  #define ConfigIntCND(config) (mCNDClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNDIntEnable(((config) >> 23)))
  #define ConfigIntCNE(config) (mCNEClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNEIntEnable(((config) >> 23)))
  #define ConfigIntCNF(config) (mCNFClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNFIntEnable(((config) >> 23)))
  #define ConfigIntCNG(config) (mCNGClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNGIntEnable(((config) >> 23)))

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define ConfigIntCNA(config) (mCNAClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNAIntEnable(((config) >> 23)))
  #define ConfigIntCNB(config) (mCNBClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNBIntEnable(((config) >> 23)))
  #define ConfigIntCNC(config) (mCNCClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNCIntEnable(((config) >> 23)))

#elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
  #define ConfigIntCNA(config) (mCNAClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNAIntEnable(((config) >> 23)))
  #define ConfigIntCNB(config) (mCNBClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNBIntEnable(((config) >> 23)))
  #define ConfigIntCNC(config) (mCNCClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNCIntEnable(((config) >> 23)))
  #define ConfigIntCND(config) (mCNDClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNDIntEnable(((config) >> 23)))
  #define ConfigIntCNE(config) (mCNEClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNEIntEnable(((config) >> 23)))
  #define ConfigIntCNF(config) (mCNFClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNFIntEnable(((config) >> 23)))
  #define ConfigIntCNG(config) (mCNGClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNGIntEnable(((config) >> 23)))

#else
  #define ConfigIntCN(config)  (mCNClearIntFlag(),  mCNSetIntPriority(((config) & 7)), mCNIntEnable(((config) >> 23)))
#endif

/******************************************************************************
 * <combinewith CN0_PULLUP_ENABLE, CN1_PULLUP_ENABLE, CN2_PULLUP_ENABLE, CN3_PULLUP_ENABLE,
 *  CN4_PULLUP_ENABLE, CN5_PULLUP_ENABLE, CN6_PULLUP_ENABLE, CN7_PULLUP_ENABLE, CN8_PULLUP_ENABLE,
 *  CN9_PULLUP_ENABLE, CN10_PULLUP_ENABLE, CN11_PULLUP_ENABLE, CN12_PULLUP_ENABLE, CN13_PULLUP_ENABLE,
 *  CN14_PULLUP_ENABLE, CN15_PULLUP_ENABLE, CN16_PULLUP_ENABLE, CN17_PULLUP_ENABLE, CN18_PULLUP_ENABLE,
 *  CN19_PULLUP_ENABLE, CN20_PULLUP_ENABLE, CN_PULLUP_DISABLE_ALL>
 *
 * Parameter values to be used with ConfigCNPullups()
 *****************************************************************************/
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

   #ifdef _PORTA
      #define CNA15_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA15_POSITION)
      #define CNA14_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA14_POSITION)
      #define CNA10_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA10_POSITION)
      #define CNA9_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA9_POSITION)
      #define CNA7_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA7_POSITION)
      #define CNA6_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA6_POSITION)
      #define CNA5_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA5_POSITION)
      #define CNA4_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA4_POSITION)
      #define CNA3_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA3_POSITION)
      #define CNA2_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA2_POSITION)
      #define CNA1_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA1_POSITION)
      #define CNA0_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA0_POSITION)
      #define CNA_PULLUP_DISABLE_ALL              (0)             /* Default */
  #endif

  #define CNB15_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB15_POSITION)
  #define CNB14_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB14_POSITION)
  #define CNB13_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB13_POSITION)
  #define CNB12_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB12_POSITION)
  #define CNB11_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB11_POSITION)
  #define CNB10_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB10_POSITION)
  #define CNB9_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB9_POSITION)
  #define CNB8_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB8_POSITION)
  #define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
  #define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
  #define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
  #define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
  #define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
  #define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
  #define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
  #define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNC15_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC15_POSITION)
  #define CNC14_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC14_POSITION)
  #define CNC13_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC13_POSITION)
  #define CNC12_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC12_POSITION)
  #define CNC4_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC4_POSITION)
  #define CNC3_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC3_POSITION)
  #define CNC2_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC2_POSITION)
  #define CNC1_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC1_POSITION)
  #define CNC_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CND15_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD15_POSITION)
  #define CND14_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD14_POSITION)
  #define CND13_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD13_POSITION)
  #define CND12_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD12_POSITION)
  #define CND11_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD11_POSITION)
  #define CND10_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD10_POSITION)
  #define CND9_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD9_POSITION)
  #define CND8_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD8_POSITION)
  #define CND7_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD7_POSITION)
  #define CND6_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD6_POSITION)
  #define CND5_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD5_POSITION)
  #define CND4_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD4_POSITION)
  #define CND3_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD3_POSITION)
  #define CND2_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD2_POSITION)
  #define CND1_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD1_POSITION)
  #define CND0_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD0_POSITION)
  #define CND_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNE9_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE9_POSITION)
  #define CNE8_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE8_POSITION)
  #define CNE7_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE7_POSITION)
  #define CNE6_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE6_POSITION)
  #define CNE5_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE5_POSITION)
  #define CNE4_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE4_POSITION)
  #define CNE3_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE3_POSITION)
  #define CNE2_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE2_POSITION)
  #define CNE1_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE1_POSITION)
  #define CNE0_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE0_POSITION)
  #define CNE_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNF13_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF13_POSITION)
  #define CNF12_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF12_POSITION)
  #define CNF8_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF8_POSITION)
  #define CNF7_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF7_POSITION)
  #define CNF6_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF6_POSITION)
  #define CNF5_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF5_POSITION)
  #define CNF4_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF4_POSITION)
  #define CNF3_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF3_POSITION)
  #define CNF2_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF2_POSITION)
  #define CNF1_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF1_POSITION)
  #define CNF0_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF0_POSITION)
  #define CNF_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNG15_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG15_POSITION)
  #define CNG14_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG15_POSITION)
  #define CNG13_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG15_POSITION)
  #define CNG12_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG15_POSITION)
  #define CNG9_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG9_POSITION)
  #define CNG8_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG8_POSITION)
  #define CNG7_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG7_POSITION)
  #define CNG6_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG6_POSITION)
  #define CNG3_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG3_POSITION)
  #define CNG2_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG2_POSITION)
  #define CNG1_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG1_POSITION)
  #define CNG0_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG0_POSITION)
  #define CNG_PULLUP_DISABLE_ALL              (0)             /* Default */

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define CNA10_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA10_POSITION)
  #define CNA9_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA9_POSITION)
  #define CNA8_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA8_POSITION)
  #define CNA7_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA7_POSITION)
  #define CNA4_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA4_POSITION)
  #define CNA3_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA3_POSITION)
  #define CNA2_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA2_POSITION)
  #define CNA1_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA1_POSITION)
  #define CNA0_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA0_POSITION)
  #define CNA_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNB15_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB15_POSITION)
  #define CNB14_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB14_POSITION)
  #define CNB13_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB13_POSITION)
  #define CNB12_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB12_POSITION)
  #define CNB11_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB11_POSITION)
  #define CNB10_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB10_POSITION)
  #define CNB9_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB9_POSITION)
  #define CNB8_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB8_POSITION)
  #define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
  #define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
  #define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
  #define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
  #define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
  #define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
  #define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
  #define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNC9_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC9_POSITION)
  #define CNC8_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC8_POSITION)
  #define CNC7_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC7_POSITION)
  #define CNC6_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC6_POSITION)
  #define CNC5_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC5_POSITION)
  #define CNC4_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC4_POSITION)
  #define CNC3_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC3_POSITION)
  #define CNC2_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC2_POSITION)
  #define CNC1_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC1_POSITION)
  #define CNC0_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC0_POSITION)
  #define CNC_PULLUP_DISABLE_ALL              (0)             /* Default */

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define CNA15_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA15_POSITION)
  #define CNA14_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA14_POSITION)
  #define CNA10_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA10_POSITION)
  #define CNA9_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA9_POSITION)
  #define CNA7_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA7_POSITION)
  #define CNA6_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA6_POSITION)
  #define CNA5_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA5_POSITION)
  #define CNA4_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA4_POSITION)
  #define CNA3_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA3_POSITION)
  #define CNA2_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA2_POSITION)
  #define CNA1_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA1_POSITION)
  #define CNA0_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA0_POSITION)
  #define CNA_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNB15_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB15_POSITION)
  #define CNB14_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB14_POSITION)
  #define CNB13_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB13_POSITION)
  #define CNB12_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB12_POSITION)
  #define CNB11_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB11_POSITION)
  #define CNB10_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB10_POSITION)
  #define CNB9_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB9_POSITION)
  #define CNB8_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB8_POSITION)
  #define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
  #define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
  #define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
  #define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
  #define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
  #define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
  #define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
  #define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNC15_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC15_POSITION)
  #define CNC14_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC14_POSITION)
  #define CNC13_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC13_POSITION)
  #define CNC12_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC12_POSITION)
  #define CNC_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CND15_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD15_POSITION)
  #define CND14_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD14_POSITION)
  #define CND13_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD13_POSITION)
  #define CND12_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD12_POSITION)
  #define CND11_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD11_POSITION)
  #define CND10_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD10_POSITION)
  #define CND9_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD9_POSITION)
  #define CND8_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD8_POSITION)
  #define CND7_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD7_POSITION)
  #define CND6_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD6_POSITION)
  #define CND5_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD5_POSITION)
  #define CND4_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD4_POSITION)
  #define CND3_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD3_POSITION)
  #define CND2_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD2_POSITION)
  #define CND1_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD1_POSITION)
  #define CND0_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD0_POSITION)
  #define CND_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNE9_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE9_POSITION)
  #define CNE8_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE8_POSITION)
  #define CNE7_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE7_POSITION)
  #define CNE6_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE6_POSITION)
  #define CNE5_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE5_POSITION)
  #define CNE4_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE4_POSITION)
  #define CNE3_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE3_POSITION)
  #define CNE2_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE2_POSITION)
  #define CNE1_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE1_POSITION)
  #define CNE0_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE0_POSITION)
  #define CNE_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNF13_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF13_POSITION)
  #define CNF12_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF12_POSITION)
  #define CNF8_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF8_POSITION)
  #define CNF7_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF7_POSITION)
  #define CNF6_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF6_POSITION)
  #define CNF5_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF5_POSITION)
  #define CNF4_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF4_POSITION)
  #define CNF3_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF3_POSITION)
  #define CNF2_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF2_POSITION)
  #define CNF1_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF1_POSITION)
  #define CNF0_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF0_POSITION)
  #define CNF_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNG9_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG9_POSITION)
  #define CNG8_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG8_POSITION)
  #define CNG7_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG7_POSITION)
  #define CNG6_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG6_POSITION)
  #define CNG3_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG3_POSITION)
  #define CNG2_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG2_POSITION)
  #define CNG1_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG1_POSITION)
  #define CNG0_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG0_POSITION)
  #define CNG_PULLUP_DISABLE_ALL              (0)             /* Default */

#else
  #define CN21_PULLUP_ENABLE          (1 << _CNPUE_CNPUE21_POSITION)
  #define CN20_PULLUP_ENABLE          (1 << _CNPUE_CNPUE20_POSITION)
  #define CN19_PULLUP_ENABLE          (1 << _CNPUE_CNPUE19_POSITION)
  #define CN18_PULLUP_ENABLE          (1 << _CNPUE_CNPUE18_POSITION)
  #define CN17_PULLUP_ENABLE          (1 << _CNPUE_CNPUE17_POSITION)
  #define CN16_PULLUP_ENABLE          (1 << _CNPUE_CNPUE16_POSITION)
  #define CN15_PULLUP_ENABLE          (1 << _CNPUE_CNPUE15_POSITION)
  #define CN14_PULLUP_ENABLE          (1 << _CNPUE_CNPUE14_POSITION)
  #define CN13_PULLUP_ENABLE          (1 << _CNPUE_CNPUE13_POSITION)
  #define CN12_PULLUP_ENABLE          (1 << _CNPUE_CNPUE12_POSITION)
  #define CN11_PULLUP_ENABLE          (1 << _CNPUE_CNPUE11_POSITION)
  #define CN10_PULLUP_ENABLE          (1 << _CNPUE_CNPUE10_POSITION)
  #define CN9_PULLUP_ENABLE           (1 << _CNPUE_CNPUE9_POSITION)
  #define CN8_PULLUP_ENABLE           (1 << _CNPUE_CNPUE8_POSITION)
  #define CN7_PULLUP_ENABLE           (1 << _CNPUE_CNPUE7_POSITION)
  #define CN6_PULLUP_ENABLE           (1 << _CNPUE_CNPUE6_POSITION)
  #define CN5_PULLUP_ENABLE           (1 << _CNPUE_CNPUE5_POSITION)
  #define CN4_PULLUP_ENABLE           (1 << _CNPUE_CNPUE4_POSITION)
  #define CN3_PULLUP_ENABLE           (1 << _CNPUE_CNPUE3_POSITION)
  #define CN2_PULLUP_ENABLE           (1 << _CNPUE_CNPUE2_POSITION)
  #define CN1_PULLUP_ENABLE           (1 << _CNPUE_CNPUE1_POSITION)
  #define CN0_PULLUP_ENABLE           (1 << _CNPUE_CNPUE0_POSITION)
  #define CN_PULLUP_DISABLE_ALL       (0)             /* Default */

#endif


/******************************************************************************
 * Change Notice Pullup Enable Control Function
 *
 * Function:        void ConfigCNPullups(unsigned int config)
 *
 * Description:     Configures Change Notice pull-ups
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_PULLUP_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         To enable CN0 & CN1 pullups and disable all others
 *                  ConfigCNPullups(CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 *****************************************************************************/
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
  #define ConfigCNAPullups(config)     CNPUA = config
  #define ConfigCNBPullups(config)     CNPUB = config
  #define ConfigCNCPullups(config)     CNPUC = config
  #define ConfigCNDPullups(config)     CNPUD = config
  #define ConfigCNEPullups(config)     CNPUE = config
  #define ConfigCNFPullups(config)     CNPUF = config
  #define ConfigCNGPullups(config)     CNPUG = config

#elif   ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__)
  #define ConfigCNAPullups(config)     CNPUA = config
  #define ConfigCNBPullups(config)     CNPUB = config
  #define ConfigCNCPullups(config)     CNPUC = config

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define ConfigCNAPullups(config)     CNPUA = config
  #define ConfigCNBPullups(config)     CNPUB = config
  #define ConfigCNCPullups(config)     CNPUC = config
  #define ConfigCNDPullups(config)     CNPUD = config
  #define ConfigCNEPullups(config)     CNPUE = config
  #define ConfigCNFPullups(config)     CNPUF = config
  #define ConfigCNGPullups(config)     CNPUG = config

#else
  #define ConfigCNPullups(config)     CNPUE = config

#endif

/******************************************************************************
 * Parameter values to be used with mCNOpen()
 *****************************************************************************/
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

  #define CNA_ON                           (1 << _CNCONA_ON_POSITION)     /* CN ON */
  #define CNA_OFF                          (0)  /* CN OFF */

  #define CNA_FRZ_ON                       (1 << _CNCONA_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNA_FRZ_OFF                      (0) //Freeze off

  #define CNA_IDLE_CON                     (1 << _CNCONA_SIDL_POSITION)     /* operate during idle */
  #define CNA_IDLE_STOP                    (0) // stop during idle

  #define CNB_ON                           (1 << _CNCONB_ON_POSITION)     /* CN ON */
  #define CNB_OFF                          (0)  /* CN OFF */

  #define CNB_FRZ_ON                       (1 << _CNCONB_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNB_FRZ_OFF                      (0) //Freeze off

  #define CNB_IDLE_CON                     (1 << _CNCONB_SIDL_POSITION)     /* operate during idle */
  #define CNB_IDLE_STOP                    (0) // stop during idle

  #define CNC_ON                           (1 << _CNCONC_ON_POSITION)     /* CN ON */
  #define CNC_OFF                          (0)  /* CN OFF */

  #define CNC_FRZ_ON                       (1 << _CNCONC_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNC_FRZ_OFF                      (0) //Freeze off

  #define CNC_IDLE_CON                     (1 << _CNCONC_SIDL_POSITION)     /* operate during idle */
  #define CNC_IDLE_STOP                    (0) // stop during idle

  #define CND_ON                           (1 << _CNCOND_ON_POSITION)     /* CN ON */
  #define CND_OFF                          (0)  /* CN OFF */

  #define CND_IDLE_CON                     (1 << _CNCOND_SIDL_POSITION)     /* operate during idle */
  #define CND_IDLE_STOP                    (0) // stop during idle

  #define CNE_ON                           (1 << _CNCONE_ON_POSITION)     /* CN ON */
  #define CNE_OFF                          (0)  /* CN OFF */

  #define CNE_IDLE_CON                     (1 << _CNCONE_SIDL_POSITION)     /* operate during idle */
  #define CNE_IDLE_STOP                    (0) // stop during idle

  #define CNF_ON                           (1 << _CNCONF_ON_POSITION)     /* CN ON */
  #define CNF_OFF                          (0)  /* CN OFF */

  #define CNF_IDLE_CON                     (1 << _CNCONF_SIDL_POSITION)     /* operate during idle */
  #define CNF_IDLE_STOP                    (0) // stop during idle

  #define CNG_ON                           (1 << _CNCONG_ON_POSITION)     /* CN ON */
  #define CNG_OFF                          (0)  /* CN OFF */

  #define CNG_IDLE_CON                     (1 << _CNCONG_SIDL_POSITION)     /* operate during idle */
  #define CNG_IDLE_STOP                    (0) // stop during idle

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define CNA_ON                           (1 << _CNCONA_ON_POSITION)     /* CN ON */
  #define CNA_OFF                          (0)  /* CN OFF */

  #define CNA_FRZ_ON                       (1 << _CNCONA_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNA_FRZ_OFF                      (0) //Freeze off

  #define CNA_IDLE_CON                     (1 << _CNCONA_SIDL_POSITION)     /* operate during idle */
  #define CNA_IDLE_STOP                    (0) // stop during idle

  #define CNB_ON                           (1 << _CNCONB_ON_POSITION)     /* CN ON */
  #define CNB_OFF                          (0)  /* CN OFF */

  #define CNB_FRZ_ON                       (1 << _CNCONB_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNB_FRZ_OFF                      (0) //Freeze off

  #define CNB_IDLE_CON                     (1 << _CNCONB_SIDL_POSITION)     /* operate during idle */
  #define CNB_IDLE_STOP                    (0) // stop during idle

  #define CNC_ON                           (1 << _CNCONC_ON_POSITION)     /* CN ON */
  #define CNC_OFF                          (0)  /* CN OFF */

  #define CNC_FRZ_ON                       (1 << _CNCONC_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNC_FRZ_OFF                      (0) //Freeze off

  #define CNC_IDLE_CON                     (1 << _CNCONC_SIDL_POSITION)     /* operate during idle */
  #define CNC_IDLE_STOP                    (0) // stop during idle

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define CNA_ON                           (1 << _CNCONA_ON_POSITION)     /* CN ON */
  #define CNA_OFF                          (0)  /* CN OFF */

  #define CNA_FRZ_ON                       (1 << _CNCONA_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNA_FRZ_OFF                      (0) //Freeze off

  #define CNA_IDLE_CON                     (1 << _CNCONA_SIDL_POSITION)     /* operate during idle */
  #define CNA_IDLE_STOP                    (0) // stop during idle

  #define CNB_ON                           (1 << _CNCONB_ON_POSITION)     /* CN ON */
  #define CNB_OFF                          (0)  /* CN OFF */

  #define CNB_FRZ_ON                       (1 << _CNCONB_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNB_FRZ_OFF                      (0) //Freeze off

  #define CNB_IDLE_CON                     (1 << _CNCONB_SIDL_POSITION)     /* operate during idle */
  #define CNB_IDLE_STOP                    (0) // stop during idle

  #define CNC_ON                           (1 << _CNCONC_ON_POSITION)     /* CN ON */
  #define CNC_OFF                          (0)  /* CN OFF */

  #define CNC_FRZ_ON                       (1 << _CNCONC_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CNC_FRZ_OFF                      (0) //Freeze off

  #define CNC_IDLE_CON                     (1 << _CNCONC_SIDL_POSITION)     /* operate during idle */
  #define CNC_IDLE_STOP                    (0) // stop during idle

  #define CND_ON                           (1 << _CNCOND_ON_POSITION)     /* CN ON */
  #define CND_OFF                          (0)  /* CN OFF */

  #define CND_IDLE_CON                     (1 << _CNCOND_SIDL_POSITION)     /* operate during idle */
  #define CND_IDLE_STOP                    (0) // stop during idle

  #define CNE_ON                           (1 << _CNCONE_ON_POSITION)     /* CN ON */
  #define CNE_OFF                          (0)  /* CN OFF */

  #define CNE_IDLE_CON                     (1 << _CNCONE_SIDL_POSITION)     /* operate during idle */
  #define CNE_IDLE_STOP                    (0) // stop during idle

  #define CNF_ON                           (1 << _CNCONF_ON_POSITION)     /* CN ON */
  #define CNF_OFF                          (0)  /* CN OFF */

  #define CNF_IDLE_CON                     (1 << _CNCONF_SIDL_POSITION)     /* operate during idle */
  #define CNF_IDLE_STOP                    (0) // stop during idle

  #define CNG_ON                           (1 << _CNCONG_ON_POSITION)     /* CN ON */
  #define CNG_OFF                          (0)  /* CN OFF */

  #define CNG_IDLE_CON                     (1 << _CNCONG_SIDL_POSITION)     /* operate during idle */
  #define CNG_IDLE_STOP                    (0) // stop during idle

#else
  #define CN_ON                           (1 << _CNCON_ON_POSITION)     /* CN ON */
  #define CN_OFF                          (0)  /* CN OFF */

  #define CN_FRZ_ON                       (1 << _CNCON_FRZ_POSITION)    /* Freeze timer on debug halt */
  #define CN_FRZ_OFF                      (0) //Freeze off

  #define CN_IDLE_CON                     (1 << _CNCON_SIDL_POSITION)     /* operate during idle */
  #define CN_IDLE_STOP                    (0) // stop during idle

#endif

/******************************************************************
 * <combinewith CN0_ENABLE, CN1_ENABLE, CN2_ENABLE, CN3_ENABLE,
 * CN4_ENABLE, CN5_ENABLE, CN6_ENABLE, CN7_ENABLE, CN8_ENABLE,
 * CN9_ENABLE, CN10_ENABLE, CN11_ENABLE, CN12_ENABLE, CN13_ENABLE,
 * CN14_ENABLE, CN15_ENABLE, CN16_ENABLE, CN17_ENABLE, CN18_ENABLE,
 * CN19_ENABLE, CN20_ENABLE, CN_DISABLE_ALL>
 *
 * Change notice enable flags
 *******************************************************************/
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

   #ifdef _PORTA
      #define CNA15_ENABLE                 (1 << _CNENA_CNIEA15_POSITION)
      #define CNA14_ENABLE                 (1 << _CNENA_CNIEA14_POSITION)
      #define CNA10_ENABLE                 (1 << _CNENA_CNIEA10_POSITION)
      #define CNA9_ENABLE                  (1 << _CNENA_CNIEA9_POSITION)
      #define CNA7_ENABLE                  (1 << _CNENA_CNIEA7_POSITION)
      #define CNA6_ENABLE                  (1 << _CNENA_CNIEA6_POSITION)
      #define CNA5_ENABLE                  (1 << _CNENA_CNIEA5_POSITION)
      #define CNA4_ENABLE                  (1 << _CNENA_CNIEA4_POSITION)
      #define CNA3_ENABLE                  (1 << _CNENA_CNIEA3_POSITION)
      #define CNA2_ENABLE                  (1 << _CNENA_CNIEA2_POSITION)
      #define CNA1_ENABLE                  (1 << _CNENA_CNIEA1_POSITION)
      #define CNA0_ENABLE                  (1 << _CNENA_CNIEA0_POSITION)
      #define CNA_PULLUP_DISABLE_ALL              (0)             /* Default */
  #endif

  #define CNB15_ENABLE                 (1 << _CNENB_CNIEB15_POSITION)
  #define CNB14_ENABLE                 (1 << _CNENB_CNIEB14_POSITION)
  #define CNB13_ENABLE                 (1 << _CNENB_CNIEB13_POSITION)
  #define CNB12_ENABLE                 (1 << _CNENB_CNIEB12_POSITION)
  #define CNB11_ENABLE                 (1 << _CNENB_CNIEB11_POSITION)
  #define CNB10_ENABLE                 (1 << _CNENB_CNIEB10_POSITION)
  #define CNB9_ENABLE                  (1 << _CNENB_CNIEB9_POSITION)
  #define CNB8_ENABLE                  (1 << _CNENB_CNIEB8_POSITION)
  #define CNB7_ENABLE                  (1 << _CNENB_CNIEB7_POSITION)
  #define CNB6_ENABLE                  (1 << _CNENB_CNIEB6_POSITION)
  #define CNB5_ENABLE                  (1 << _CNENB_CNIEB5_POSITION)
  #define CNB4_ENABLE                  (1 << _CNENB_CNIEB4_POSITION)
  #define CNB3_ENABLE                  (1 << _CNENB_CNIEB3_POSITION)
  #define CNB2_ENABLE                  (1 << _CNENB_CNIEB2_POSITION)
  #define CNB1_ENABLE                  (1 << _CNENB_CNIEB1_POSITION)
  #define CNB0_ENABLE                  (1 << _CNENB_CNIEB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNC15_ENABLE                 (1 << _CNENC_CNIEC15_POSITION)
  #define CNC14_ENABLE                 (1 << _CNENC_CNIEC14_POSITION)
  #define CNC13_ENABLE                 (1 << _CNENC_CNIEC13_POSITION)
  #define CNC12_ENABLE                 (1 << _CNENC_CNIEC12_POSITION)
  #define CNC4_ENABLE                  (1 << _CNENC_CNIEC4_POSITION)
  #define CNC3_ENABLE                  (1 << _CNENC_CNIEC3_POSITION)
  #define CNC2_ENABLE                  (1 << _CNENC_CNIEC2_POSITION)
  #define CNC1_ENABLE                  (1 << _CNENC_CNIEC1_POSITION)
  #define CNC_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CND15_ENABLE                 (1 << _CNEND_CNIED15_POSITION)
  #define CND14_ENABLE                 (1 << _CNEND_CNIED14_POSITION)
  #define CND13_ENABLE                 (1 << _CNEND_CNIED13_POSITION)
  #define CND12_ENABLE                 (1 << _CNEND_CNIED12_POSITION)
  #define CND11_ENABLE                 (1 << _CNEND_CNIED11_POSITION)
  #define CND10_ENABLE                 (1 << _CNEND_CNIED10_POSITION)
  #define CND9_ENABLE                  (1 << _CNEND_CNIED9_POSITION)
  #define CND8_ENABLE                  (1 << _CNEND_CNIED8_POSITION)
  #define CND7_ENABLE                  (1 << _CNEND_CNIED7_POSITION)
  #define CND6_ENABLE                  (1 << _CNEND_CNIED6_POSITION)
  #define CND5_ENABLE                  (1 << _CNEND_CNIED5_POSITION)
  #define CND4_ENABLE                  (1 << _CNEND_CNIED4_POSITION)
  #define CND3_ENABLE                  (1 << _CNEND_CNIED3_POSITION)
  #define CND2_ENABLE                  (1 << _CNEND_CNIED2_POSITION)
  #define CND1_ENABLE                  (1 << _CNEND_CNIED1_POSITION)
  #define CND0_ENABLE                  (1 << _CNEND_CNIED0_POSITION)
  #define CND_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNE9_ENABLE                  (1 << _CNENE_CNIEE9_POSITION)
  #define CNE8_ENABLE                  (1 << _CNENE_CNIEE8_POSITION)
  #define CNE7_ENABLE                  (1 << _CNENE_CNIEE7_POSITION)
  #define CNE6_ENABLE                  (1 << _CNENE_CNIEE6_POSITION)
  #define CNE5_ENABLE                  (1 << _CNENE_CNIEE5_POSITION)
  #define CNE4_ENABLE                  (1 << _CNENE_CNIEE4_POSITION)
  #define CNE3_ENABLE                  (1 << _CNENE_CNIEE3_POSITION)
  #define CNE2_ENABLE                  (1 << _CNENE_CNIEE2_POSITION)
  #define CNE1_ENABLE                  (1 << _CNENE_CNIEE1_POSITION)
  #define CNE0_ENABLE                  (1 << _CNENE_CNIEE0_POSITION)
  #define CNE_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNF13_ENABLE                 (1 << _CNENF_CNIEF13_POSITION)
  #define CNF12_ENABLE                 (1 << _CNENF_CNIEF12_POSITION)
  #define CNF8_ENABLE                  (1 << _CNENF_CNIEF8_POSITION)
  #define CNF7_ENABLE                  (1 << _CNENF_CNIEF7_POSITION)
  #define CNF6_ENABLE                  (1 << _CNENF_CNIEF6_POSITION)
  #define CNF5_ENABLE                  (1 << _CNENF_CNIEF5_POSITION)
  #define CNF4_ENABLE                  (1 << _CNENF_CNIEF4_POSITION)
  #define CNF3_ENABLE                  (1 << _CNENF_CNIEF3_POSITION)
  #define CNF2_ENABLE                  (1 << _CNENF_CNIEF2_POSITION)
  #define CNF1_ENABLE                  (1 << _CNENF_CNIEF1_POSITION)
  #define CNF0_ENABLE                  (1 << _CNENF_CNIEF0_POSITION)
  #define CNF_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNG15_ENABLE                 (1 << _CNENG_CNIEG15_POSITION)
  #define CNG14_ENABLE                 (1 << _CNENG_CNIEG15_POSITION)
  #define CNG13_ENABLE                 (1 << _CNENG_CNIEG15_POSITION)
  #define CNG12_ENABLE                 (1 << _CNENG_CNIEG15_POSITION)
  #define CNG9_ENABLE                  (1 << _CNENG_CNIEG9_POSITION)
  #define CNG8_ENABLE                  (1 << _CNENG_CNIEG8_POSITION)
  #define CNG7_ENABLE                  (1 << _CNENG_CNIEG7_POSITION)
  #define CNG6_ENABLE                  (1 << _CNENG_CNIEG6_POSITION)
  #define CNG3_ENABLE                  (1 << _CNENG_CNIEG3_POSITION)
  #define CNG2_ENABLE                  (1 << _CNENG_CNIEG2_POSITION)
  #define CNG1_ENABLE                  (1 << _CNENG_CNIEG1_POSITION)
  #define CNG0_ENABLE                  (1 << _CNENG_CNIEG0_POSITION)
  #define CNG_PULLUP_DISABLE_ALL              (0)             /* Default */

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define CNA10_ENABLE                 (1 << _CNENA_CNIEA10_POSITION)
  #define CNA9_ENABLE                  (1 << _CNENA_CNIEA9_POSITION)
  #define CNA8_ENABLE                  (1 << _CNENA_CNIEA8_POSITION)
  #define CNA7_ENABLE                  (1 << _CNENA_CNIEA7_POSITION)
  #define CNA4_ENABLE                  (1 << _CNENA_CNIEA4_POSITION)
  #define CNA3_ENABLE                  (1 << _CNENA_CNIEA3_POSITION)
  #define CNA2_ENABLE                  (1 << _CNENA_CNIEA2_POSITION)
  #define CNA1_ENABLE                  (1 << _CNENA_CNIEA1_POSITION)
  #define CNA0_ENABLE                  (1 << _CNENA_CNIEA0_POSITION)
  #define CNA_DISABLE_ALL              (0)             /* Default */

  #define CNB15_ENABLE                 (1 << _CNENB_CNIEB15_POSITION)
  #define CNB14_ENABLE                 (1 << _CNENB_CNIEB14_POSITION)
  #define CNB13_ENABLE                 (1 << _CNENB_CNIEB13_POSITION)
  #define CNB12_ENABLE                 (1 << _CNENB_CNIEB12_POSITION)
  #define CNB11_ENABLE                 (1 << _CNENB_CNIEB11_POSITION)
  #define CNB10_ENABLE                 (1 << _CNENB_CNIEB10_POSITION)
  #define CNB9_ENABLE                  (1 << _CNENB_CNIEB9_POSITION)
  #define CNB8_ENABLE                  (1 << _CNENB_CNIEB8_POSITION)
  #define CNB7_ENABLE                  (1 << _CNENB_CNIEB7_POSITION)
  #define CNB6_ENABLE                  (1 << _CNENB_CNIEB6_POSITION)
  #define CNB5_ENABLE                  (1 << _CNENB_CNIEB5_POSITION)
  #define CNB4_ENABLE                  (1 << _CNENB_CNIEB4_POSITION)
  #define CNB3_ENABLE                  (1 << _CNENB_CNIEB3_POSITION)
  #define CNB2_ENABLE                  (1 << _CNENB_CNIEB2_POSITION)
  #define CNB1_ENABLE                  (1 << _CNENB_CNIEB1_POSITION)
  #define CNB0_ENABLE                  (1 << _CNENB_CNIEB0_POSITION)
  #define CNB_DISABLE_ALL              (0)             /* Default */

  #define CNC9_ENABLE                  (1 << _CNENC_CNIEC9_POSITION)
  #define CNC8_ENABLE                  (1 << _CNENC_CNIEC8_POSITION)
  #define CNC7_ENABLE                  (1 << _CNENC_CNIEC7_POSITION)
  #define CNC6_ENABLE                  (1 << _CNENC_CNIEC6_POSITION)
  #define CNC5_ENABLE                  (1 << _CNENC_CNIEC5_POSITION)
  #define CNC4_ENABLE                  (1 << _CNENC_CNIEC4_POSITION)
  #define CNC3_ENABLE                  (1 << _CNENC_CNIEC3_POSITION)
  #define CNC2_ENABLE                  (1 << _CNENC_CNIEC2_POSITION)
  #define CNC1_ENABLE                  (1 << _CNENC_CNIEC1_POSITION)
  #define CNC0_ENABLE                  (1 << _CNENC_CNIEC0_POSITION)
  #define CNC_DISABLE_ALL              (0)             /* Default */

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define CNA15_ENABLE                 (1 << _CNENA_CNIEA15_POSITION)
  #define CNA14_ENABLE                 (1 << _CNENA_CNIEA14_POSITION)
  #define CNA10_ENABLE                 (1 << _CNENA_CNIEA10_POSITION)
  #define CNA9_ENABLE                  (1 << _CNENA_CNIEA9_POSITION)
  #define CNA7_ENABLE                  (1 << _CNENA_CNIEA7_POSITION)
  #define CNA6_ENABLE                  (1 << _CNENA_CNIEA6_POSITION)
  #define CNA5_ENABLE                  (1 << _CNENA_CNIEA5_POSITION)
  #define CNA4_ENABLE                  (1 << _CNENA_CNIEA4_POSITION)
  #define CNA3_ENABLE                  (1 << _CNENA_CNIEA3_POSITION)
  #define CNA2_ENABLE                  (1 << _CNENA_CNIEA2_POSITION)
  #define CNA1_ENABLE                  (1 << _CNENA_CNIEA1_POSITION)
  #define CNA0_ENABLE                  (1 << _CNENA_CNIEA0_POSITION)
  #define CNA_DISABLE_ALL              (0)             /* Default */

  #define CNB15_ENABLE                 (1 << _CNENB_CNIEB15_POSITION)
  #define CNB14_ENABLE                 (1 << _CNENB_CNIEB14_POSITION)
  #define CNB13_ENABLE                 (1 << _CNENB_CNIEB13_POSITION)
  #define CNB12_ENABLE                 (1 << _CNENB_CNIEB12_POSITION)
  #define CNB11_ENABLE                 (1 << _CNENB_CNIEB11_POSITION)
  #define CNB10_ENABLE                 (1 << _CNENB_CNIEB10_POSITION)
  #define CNB9_ENABLE                  (1 << _CNENB_CNIEB9_POSITION)
  #define CNB8_ENABLE                  (1 << _CNENB_CNIEB8_POSITION)
  #define CNB7_ENABLE                  (1 << _CNENB_CNIEB7_POSITION)
  #define CNB6_ENABLE                  (1 << _CNENB_CNIEB6_POSITION)
  #define CNB5_ENABLE                  (1 << _CNENB_CNIEB5_POSITION)
  #define CNB4_ENABLE                  (1 << _CNENB_CNIEB4_POSITION)
  #define CNB3_ENABLE                  (1 << _CNENB_CNIEB3_POSITION)
  #define CNB2_ENABLE                  (1 << _CNENB_CNIEB2_POSITION)
  #define CNB1_ENABLE                  (1 << _CNENB_CNIEB1_POSITION)
  #define CNB0_ENABLE                  (1 << _CNENB_CNIEB0_POSITION)
  #define CNB_DISABLE_ALL              (0)             /* Default */

  #define CNC15_ENABLE                 (1 << _CNENC_CNIEC15_POSITION)
  #define CNC14_ENABLE                 (1 << _CNENC_CNIEC14_POSITION)
  #define CNC13_ENABLE                 (1 << _CNENC_CNIEC13_POSITION)
  #define CNC12_ENABLE                 (1 << _CNENC_CNIEC12_POSITION)
  #define CNC4_ENABLE                  (1 << _CNENC_CNIEC4_POSITION)
  #define CNC3_ENABLE                  (1 << _CNENC_CNIEC3_POSITION)
  #define CNC2_ENABLE                  (1 << _CNENC_CNIEC2_POSITION)
  #define CNC1_ENABLE                  (1 << _CNENC_CNIEC1_POSITION)
  #define CNC_DISABLE_ALL              (0)             /* Default */

  #define CND15_ENABLE                 (1 << _CNEND_CNIED15_POSITION)
  #define CND14_ENABLE                 (1 << _CNEND_CNIED14_POSITION)
  #define CND13_ENABLE                 (1 << _CNEND_CNIED13_POSITION)
  #define CND12_ENABLE                 (1 << _CNEND_CNIED12_POSITION)
  #define CND11_ENABLE                 (1 << _CNEND_CNIED11_POSITION)
  #define CND10_ENABLE                 (1 << _CNEND_CNIED10_POSITION)
  #define CND9_ENABLE                  (1 << _CNEND_CNIED9_POSITION)
  #define CND8_ENABLE                  (1 << _CNEND_CNIED8_POSITION)
  #define CND7_ENABLE                  (1 << _CNEND_CNIED7_POSITION)
  #define CND6_ENABLE                  (1 << _CNEND_CNIED6_POSITION)
  #define CND5_ENABLE                  (1 << _CNEND_CNIED5_POSITION)
  #define CND4_ENABLE                  (1 << _CNEND_CNIED4_POSITION)
  #define CND3_ENABLE                  (1 << _CNEND_CNIED3_POSITION)
  #define CND2_ENABLE                  (1 << _CNEND_CNIED2_POSITION)
  #define CND1_ENABLE                  (1 << _CNEND_CNIED1_POSITION)
  #define CND0_ENABLE                  (1 << _CNEND_CNIED0_POSITION)
  #define CND_DISABLE_ALL              (0)             /* Default */

  #define CNE9_ENABLE                  (1 << _CNENE_CNIEE9_POSITION)
  #define CNE8_ENABLE                  (1 << _CNENE_CNIEE8_POSITION)
  #define CNE7_ENABLE                  (1 << _CNENE_CNIEE7_POSITION)
  #define CNE6_ENABLE                  (1 << _CNENE_CNIEE6_POSITION)
  #define CNE5_ENABLE                  (1 << _CNENE_CNIEE5_POSITION)
  #define CNE4_ENABLE                  (1 << _CNENE_CNIEE4_POSITION)
  #define CNE3_ENABLE                  (1 << _CNENE_CNIEE3_POSITION)
  #define CNE2_ENABLE                  (1 << _CNENE_CNIEE2_POSITION)
  #define CNE1_ENABLE                  (1 << _CNENE_CNIEE1_POSITION)
  #define CNE0_ENABLE                  (1 << _CNENE_CNIEE0_POSITION)
  #define CNE_DISABLE_ALL              (0)             /* Default */

  #define CNF13_ENABLE                 (1 << _CNENF_CNIEF13_POSITION)
  #define CNF12_ENABLE                 (1 << _CNENF_CNIEF12_POSITION)
  #define CNF8_ENABLE                  (1 << _CNENF_CNIEF8_POSITION)
  #define CNF7_ENABLE                  (1 << _CNENF_CNIEF7_POSITION)
  #define CNF6_ENABLE                  (1 << _CNENF_CNIEF6_POSITION)
  #define CNF5_ENABLE                  (1 << _CNENF_CNIEF5_POSITION)
  #define CNF4_ENABLE                  (1 << _CNENF_CNIEF4_POSITION)
  #define CNF3_ENABLE                  (1 << _CNENF_CNIEF3_POSITION)
  #define CNF2_ENABLE                  (1 << _CNENF_CNIEF2_POSITION)
  #define CNF1_ENABLE                  (1 << _CNENF_CNIEF1_POSITION)
  #define CNF0_ENABLE                  (1 << _CNENF_CNIEF0_POSITION)
  #define CNF_DISABLE_ALL              (0)             /* Default */

  #define CNG9_ENABLE                  (1 << _CNENG_CNIEG9_POSITION)
  #define CNG8_ENABLE                  (1 << _CNENG_CNIEG8_POSITION)
  #define CNG7_ENABLE                  (1 << _CNENG_CNIEG7_POSITION)
  #define CNG6_ENABLE                  (1 << _CNENG_CNIEG6_POSITION)
  #define CNG3_ENABLE                  (1 << _CNENG_CNIEG3_POSITION)
  #define CNG2_ENABLE                  (1 << _CNENG_CNIEG2_POSITION)
  #define CNG1_ENABLE                  (1 << _CNENG_CNIEG1_POSITION)
  #define CNG0_ENABLE                  (1 << _CNENG_CNIEG0_POSITION)
  #define CNG_DISABLE_ALL              (0)             /* Default */

#else
  #define CN21_ENABLE                 (1 << _CNEN_CNEN21_POSITION)
  #define CN20_ENABLE                 (1 << _CNEN_CNEN20_POSITION)
  #define CN19_ENABLE                 (1 << _CNEN_CNEN19_POSITION)
  #define CN18_ENABLE                 (1 << _CNEN_CNEN18_POSITION)
  #define CN17_ENABLE                 (1 << _CNEN_CNEN17_POSITION)
  #define CN16_ENABLE                 (1 << _CNEN_CNEN16_POSITION)
  #define CN15_ENABLE                 (1 << _CNEN_CNEN15_POSITION)
  #define CN14_ENABLE                 (1 << _CNEN_CNEN14_POSITION)
  #define CN13_ENABLE                 (1 << _CNEN_CNEN13_POSITION)
  #define CN12_ENABLE                 (1 << _CNEN_CNEN12_POSITION)
  #define CN11_ENABLE                 (1 << _CNEN_CNEN11_POSITION)
  #define CN10_ENABLE                 (1 << _CNEN_CNEN10_POSITION)
  #define CN9_ENABLE                  (1 << _CNEN_CNEN9_POSITION)
  #define CN8_ENABLE                  (1 << _CNEN_CNEN8_POSITION)
  #define CN7_ENABLE                  (1 << _CNEN_CNEN7_POSITION)
  #define CN6_ENABLE                  (1 << _CNEN_CNEN6_POSITION)
  #define CN5_ENABLE                  (1 << _CNEN_CNEN5_POSITION)
  #define CN4_ENABLE                  (1 << _CNEN_CNEN4_POSITION)
  #define CN3_ENABLE                  (1 << _CNEN_CNEN3_POSITION)
  #define CN2_ENABLE                  (1 << _CNEN_CNEN2_POSITION)
  #define CN1_ENABLE                  (1 << _CNEN_CNEN1_POSITION)
  #define CN0_ENABLE                  (1 << _CNEN_CNEN0_POSITION)
  #define CN_DISABLE_ALL              (0)             /* Default */

#endif

/******************************************************************************
 * Change Notice Open Control Function
 *
 * Function:        void mCNOpen(unsigned int control, unsigned int pins, unsigned int pullup)
 *
 * Description:     Configures Change Notice interrupt, enables specified
 *                  change notice inputs and pullups and configures the CNCON register.
 *                  Attention: This function does not enable the CN interrupt nor its priorities.
 *                  The user should use macro ConfigIntCN to enable the CN interrupt and set the
 *                  desired priorities only after reading the corresponding ports.
 *                  See Notes below.
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
* Example:          Enable the change notice module, select pins CN0 & CN1 and enable
 *                  corresponding weak pull-ups.
 *                  mCNOpen(CN_ON | CN_IDLE_CON, CN0_ENABLE | CN1_ENABLE,
 *                  CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 * Notes:           It is recommended to disable vector interrupts prior to configuring
 *                  the change notice module and to use the following sequence to
 *                  prevent spurious change notice interrupts during configuration:
 *
 *                  1. setup the change notice module, pins and optional pullups
 *                  mCNOpen(control, pins, pullups).
 *
 *                  2. read every port that has a corresponding enabled change notice pins
 *                  var = mPORTARead;
 *                  var = PORTBRead;
 *                  ...
 *
 *                  3. setup the change notice interrupts
 *                  ConfigIntCN(interrupt).
 *
 *****************************************************************************/
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
  #define mCNAOpen(configA, pinsA, pullupsA)\
          (CNCONACLR = 0xFFFF, CNCONASET = ((configA) | CNA_ON), CNENA = (pinsA), CNPUA = (pullupsA))
  #define mCNBOpen(configB, pinsB, pullupsB)\
          (CNCONBCLR = 0xFFFF, CNCONBSET = ((configB) | CNB_ON), CNENB = (pinsB), CNPUB = (pullupsB))
  #define mCNCOpen(configC, pinsC, pullupsC)\
          (CNCONCCLR = 0xFFFF, CNCONCSET = ((configC) | CNC_ON), CNENC = (pinsC), CNPUC = (pullupsC))
  #define mCNDOpen(configD, pinsD, pullupsD)\
          (CNCONDCLR = 0xFFFF, CNCONDSET = ((configD) | CND_ON), CNEND = (pinsD), CNPUD = (pullupsD))
  #define mCNEOpen(configE, pinsE, pullupsE)\
          (CNCONECLR = 0xFFFF, CNCONESET = ((configE) | CNE_ON), CNENE = (pinsE), CNPUE = (pullupsE))
  #define mCNFOpen(configF, pinsF, pullupsF)\
          (CNCONFCLR = 0xFFFF, CNCONFSET = ((configF) | CNF_ON), CNENF = (pinsF), CNPUF = (pullupsF))
  #define mCNGOpen(configG, pinsG, pullupsG)\
          (CNCONGCLR = 0xFFFF, CNCONGSET = ((configG) | CNG_ON), CNENG = (pinsG), CNPUG = (pullupsG))

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define mCNAOpen(configA, pinsA, pullupsA)\
          (CNCONACLR = 0xFFFF, CNCONASET = ((configA) | CNA_ON), CNENA = (pinsA), CNPUA = (pullupsA))
  #define mCNBOpen(configB, pinsB, pullupsB)\
          (CNCONBCLR = 0xFFFF, CNCONBSET = ((configB) | CNB_ON), CNENB = (pinsB), CNPUB = (pullupsB))
  #define mCNCOpen(configC, pinsC, pullupsC)\
          (CNCONCCLR = 0xFFFF, CNCONCSET = ((configC) | CNC_ON), CNENC = (pinsC), CNPUC = (pullupsC))

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define mCNAOpen(configA, pinsA, pullupsA)\
          (CNCONACLR = 0xFFFF, CNCONASET = ((configA) | CNA_ON), CNENA = (pinsA), CNPUA = (pullupsA))
  #define mCNBOpen(configB, pinsB, pullupsB)\
          (CNCONBCLR = 0xFFFF, CNCONBSET = ((configB) | CNB_ON), CNENB = (pinsB), CNPUB = (pullupsB))
  #define mCNCOpen(configC, pinsC, pullupsC)\
          (CNCONCCLR = 0xFFFF, CNCONCSET = ((configC) | CNC_ON), CNENC = (pinsC), CNPUC = (pullupsC))
  #define mCNDOpen(configD, pinsD, pullupsD)\
          (CNCONDCLR = 0xFFFF, CNCONDSET = ((configD) | CND_ON), CNEND = (pinsD), CNPUD = (pullupsD))
  #define mCNEOpen(configE, pinsE, pullupsE)\
          (CNCONECLR = 0xFFFF, CNCONESET = ((configE) | CNE_ON), CNENE = (pinsE), CNPUE = (pullupsE))
  #define mCNFOpen(configF, pinsF, pullupsF)\
          (CNCONFCLR = 0xFFFF, CNCONFSET = ((configF) | CNF_ON), CNENF = (pinsF), CNPUF = (pullupsF))
  #define mCNGOpen(configG, pinsG, pullupsG)\
          (CNCONGCLR = 0xFFFF, CNCONGSET = ((configG) | CNG_ON), CNENG = (pinsG), CNPUG = (pullupsG))

#else
  #define mCNOpen(config, pins, pullups)\
          (CNCONCLR = 0xFFFF, CNCONSET = ((config) | CN_ON), CNEN = (pins), CNPUE = (pullups))
#endif


/******************************************************************************
 * Change Notice Close Control Function
 *
 * Function:        void mCNClose(void)
 *
 * Description:     Disables Change Notice interrupt, disables all
 *                  change notice inputs and pullups
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         mCNClose();
 *
 *****************************************************************************/
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
  #define mCNAClose() (mCNAClearIntFlag(), mCNAIntEnable(0), CNCONACLR = (1 << 15), CNENA = 0, CNPUA = 0)
  #define mCNBClose() (mCNBClearIntFlag(), mCNBIntEnable(0), CNCONBCLR = (1 << 15), CNENB = 0, CNPUB = 0)
  #define mCNCClose() (mCNCClearIntFlag(), mCNCIntEnable(0), CNCONCCLR = (1 << 15), CNENC = 0, CNPUC = 0)
  #define mCNDClose() (mCNDClearIntFlag(), mCNDIntEnable(0), CNCONDCLR = (1 << 15), CNEND = 0, CNPUD = 0)
  #define mCNEClose() (mCNEClearIntFlag(), mCNEIntEnable(0), CNCONECLR = (1 << 15), CNENE = 0, CNPUE = 0)
  #define mCNFClose() (mCNFClearIntFlag(), mCNFIntEnable(0), CNCONFCLR = (1 << 15), CNENF = 0, CNPUF = 0)
  #define mCNGClose() (mCNGClearIntFlag(), mCNGIntEnable(0), CNCONGCLR = (1 << 15), CNENG = 0, CNPUG = 0)

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define mCNAClose() (mCNAClearIntFlag(), mCNAIntEnable(0), CNCONACLR = (1 << 15), CNENA = 0, CNPUA = 0)
  #define mCNBClose() (mCNBClearIntFlag(), mCNBIntEnable(0), CNCONBCLR = (1 << 15), CNENB = 0, CNPUB = 0)
  #define mCNCClose() (mCNCClearIntFlag(), mCNCIntEnable(0), CNCONCCLR = (1 << 15), CNENC = 0, CNPUC = 0)

#elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
  #define mCNAClose() (mCNAClearIntFlag(), mCNAIntEnable(0), CNCONACLR = (1 << 15), CNENA = 0, CNPUA = 0)
  #define mCNBClose() (mCNBClearIntFlag(), mCNBIntEnable(0), CNCONBCLR = (1 << 15), CNENB = 0, CNPUB = 0)
  #define mCNCClose() (mCNCClearIntFlag(), mCNCIntEnable(0), CNCONCCLR = (1 << 15), CNENC = 0, CNPUC = 0)
  #define mCNDClose() (mCNDClearIntFlag(), mCNDIntEnable(0), CNCONDCLR = (1 << 15), CNEND = 0, CNPUD = 0)
  #define mCNEClose() (mCNEClearIntFlag(), mCNEIntEnable(0), CNCONECLR = (1 << 15), CNENE = 0, CNPUE = 0)
  #define mCNFClose() (mCNFClearIntFlag(), mCNFIntEnable(0), CNCONFCLR = (1 << 15), CNENF = 0, CNPUF = 0)
  #define mCNGClose() (mCNGClearIntFlag(), mCNGIntEnable(0), CNCONGCLR = (1 << 15), CNENG = 0, CNPUG = 0)

#else
  #define mCNClose() (mCNClearIntFlag(), mCNIntEnable(0), CNCONCLR = (1 << 15), CNEN = 0, CNPUE = 0)
#endif


/******************************************************************************
 * Change Notice Enable Interrupt Control Function
 *
 * Function:        void mCNEnable(void)
 *
 * Description:     Enables/Disables Change Notice Interrupt
 *
 * PreCondition:    Assumes Change Notice interrupt priorities have already been
 *                  set as well as the individual CN inputs
 *
 * Inputs:          CHANGE_INT_ON, CHANGE_INT_OFF
 *
 * Output:          None
 *
 * Example:         mCNEnable(CHANGE_INT_ON);
 *
 *****************************************************************************/
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
  #define mCNAEnable(config) (mCNAIntEnable((config) >> 23))
  #define mCNBEnable(config) (mCNBIntEnable((config) >> 23))
  #define mCNCEnable(config) (mCNCIntEnable((config) >> 23))
  #define mCNDEnable(config) (mCNDIntEnable((config) >> 23))
  #define mCNEEnable(config) (mCNEIntEnable((config) >> 23))
  #define mCNFEnable(config) (mCNFIntEnable((config) >> 23))
  #define mCNGEnable(config) (mCNGIntEnable((config) >> 23))

#elif   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define mCNAEnable(config) (mCNAIntEnable((config) >> 23))
  #define mCNBEnable(config) (mCNBIntEnable((config) >> 23))
  #define mCNCEnable(config) (mCNCIntEnable((config) >> 23))

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define mCNAEnable(config) (mCNAIntEnable((config) >> 23))
  #define mCNBEnable(config) (mCNBIntEnable((config) >> 23))
  #define mCNCEnable(config) (mCNCIntEnable((config) >> 23))
  #define mCNDEnable(config) (mCNDIntEnable((config) >> 23))
  #define mCNEEnable(config) (mCNEIntEnable((config) >> 23))
  #define mCNFEnable(config) (mCNFIntEnable((config) >> 23))
  #define mCNGEnable(config) (mCNGIntEnable((config) >> 23))

#else
  #define mCNEnable(config) (mCNIntEnable((config) >> 23))

#endif


/******************************************************************************
 * <combinewith EnableCN0, EnableCN1, EnableCN2, EnableCN3, EnableCN4, EnableCN5,
 * EnableCN6, EnableCN7, EnableCN8, EnableCN9, EnableCN10, EnableCN11, EnableCN12, EnableCN13,
 * EnableCN14, EnableCN15, EnableCN16, EnableCN17, EnableCN18, EnableCN19, EnableCN20>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void EnableCNx(void)
 *
 * Description:     Enables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableCN0()
 *
 *****************************************************************************/
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

  #ifdef _PORTA
      #define EnableCNA15                (CNENASET =  CNA15_ENABLE)
      #define EnableCNA14                (CNENASET =  CNA14_ENABLE)
      #define EnableCNA10                (CNENASET =  CNA10_ENABLE)
      #define EnableCNA9                 (CNENASET =   CNA9_ENABLE)
      #define EnableCNA7                 (CNENASET =   CNA7_ENABLE)
      #define EnableCNA6                 (CNENASET =   CNA6_ENABLE)
      #define EnableCNA5                 (CNENASET =   CNA5_ENABLE)
      #define EnableCNA4                 (CNENASET =   CNA4_ENABLE)
      #define EnableCNA3                 (CNENASET =   CNA3_ENABLE)
      #define EnableCNA2                 (CNENASET =   CNA2_ENABLE)
      #define EnableCNA1                 (CNENASET =   CNA1_ENABLE)
      #define EnableCNA0                 (CNENASET =   CNA0_ENABLE)
  #endif

  #define EnableCNB15                (CNENBSET =  CNB15_ENABLE)
  #define EnableCNB14                (CNENBSET =  CNB14_ENABLE)
  #define EnableCNB13                (CNENBSET =  CNB13_ENABLE)
  #define EnableCNB12                (CNENBSET =  CNB12_ENABLE)
  #define EnableCNB11                (CNENBSET =  CNB11_ENABLE)
  #define EnableCNB10                (CNENBSET =  CNB10_ENABLE)
  #define EnableCNB9                 (CNENBSET =   CNB9_ENABLE)
  #define EnableCNB8                 (CNENBSET =   CNB8_ENABLE)
  #define EnableCNB7                 (CNENBSET =   CNB7_ENABLE)
  #define EnableCNB6                 (CNENBSET =   CNB6_ENABLE)
  #define EnableCNB5                 (CNENBSET =   CNB5_ENABLE)
  #define EnableCNB4                 (CNENBSET =   CNB4_ENABLE)
  #define EnableCNB3                 (CNENBSET =   CNB3_ENABLE)
  #define EnableCNB2                 (CNENBSET =   CNB2_ENABLE)
  #define EnableCNB1                 (CNENBSET =   CNB1_ENABLE)
  #define EnableCNB0                 (CNENBSET =   CNB0_ENABLE)

  #define EnableCNC15                (CNENCSET =  CNC15_ENABLE)
  #define EnableCNC14                (CNENCSET =  CNC14_ENABLE)
  #define EnableCNC13                (CNENCSET =  CNC13_ENABLE)
  #define EnableCNC12                (CNENCSET =  CNC12_ENABLE)
  #define EnableCNC4                 (CNENCSET =   CNC4_ENABLE)
  #define EnableCNC3                 (CNENCSET =   CNC3_ENABLE)
  #define EnableCNC2                 (CNENCSET =   CNC2_ENABLE)
  #define EnableCNC1                 (CNENCSET =   CNC1_ENABLE)

  #define EnableCND15                (CNENDSET =  CND15_ENABLE)
  #define EnableCND14                (CNENDSET =  CND14_ENABLE)
  #define EnableCND13                (CNENDSET =  CND13_ENABLE)
  #define EnableCND12                (CNENDSET =  CND12_ENABLE)
  #define EnableCND11                (CNENDSET =  CND11_ENABLE)
  #define EnableCND10                (CNENDSET =  CND10_ENABLE)
  #define EnableCND9                 (CNENDSET =   CND9_ENABLE)
  #define EnableCND8                 (CNENDSET =   CND8_ENABLE)
  #define EnableCND7                 (CNENDSET =   CND7_ENABLE)
  #define EnableCND6                 (CNENDSET =   CND6_ENABLE)
  #define EnableCND5                 (CNENDSET =   CND5_ENABLE)
  #define EnableCND4                 (CNENDSET =   CND4_ENABLE)
  #define EnableCND3                 (CNENDSET =   CND3_ENABLE)
  #define EnableCND2                 (CNENDSET =   CND2_ENABLE)
  #define EnableCND1                 (CNENDSET =   CND1_ENABLE)
  #define EnableCND0                 (CNENDSET =   CND0_ENABLE)

  #define EnableCNE9                 (CNENESET =   CNE9_ENABLE)
  #define EnableCNE8                 (CNENESET =   CNE8_ENABLE)
  #define EnableCNE7                 (CNENESET =   CNE7_ENABLE)
  #define EnableCNE6                 (CNENESET =   CNE6_ENABLE)
  #define EnableCNE5                 (CNENESET =   CNE5_ENABLE)
  #define EnableCNE4                 (CNENESET =   CNE4_ENABLE)
  #define EnableCNE3                 (CNENESET =   CNE3_ENABLE)
  #define EnableCNE2                 (CNENESET =   CNE2_ENABLE)
  #define EnableCNE1                 (CNENESET =   CNE1_ENABLE)
  #define EnableCNE0                 (CNENESET =   CNE0_ENABLE)

  #define EnableCNF13                (CNENFSET =  CNF13_ENABLE)
  #define EnableCNF12                (CNENFSET =  CNF12_ENABLE)
  #define EnableCNF8                 (CNENFSET =   CNF8_ENABLE)
  #define EnableCNF7                 (CNENFSET =   CNF7_ENABLE)
  #define EnableCNF6                 (CNENFSET =   CNF6_ENABLE)
  #define EnableCNF5                 (CNENFSET =   CNF5_ENABLE)
  #define EnableCNF4                 (CNENFSET =   CNF4_ENABLE)
  #define EnableCNF3                 (CNENFSET =   CNF3_ENABLE)
  #define EnableCNF2                 (CNENFSET =   CNF2_ENABLE)
  #define EnableCNF1                 (CNENFSET =   CNF1_ENABLE)
  #define EnableCNF0                 (CNENFSET =   CNF0_ENABLE)

  #define EnableCNG15                (CNENGSET =  CNG15_ENABLE)
  #define EnableCNG14                (CNENGSET =  CNG14_ENABLE)
  #define EnableCNG13                (CNENGSET =  CNG13_ENABLE)
  #define EnableCNG12                (CNENGSET =  CNG12_ENABLE)
  #define EnableCNG9                 (CNENGSET =   CNG9_ENABLE)
  #define EnableCNG8                 (CNENGSET =   CNG8_ENABLE)
  #define EnableCNG7                 (CNENGSET =   CNG7_ENABLE)
  #define EnableCNG6                 (CNENGSET =   CNG6_ENABLE)
  #define EnableCNG3                 (CNENGSET =   CNG3_ENABLE)
  #define EnableCNG2                 (CNENGSET =   CNG2_ENABLE)
  #define EnableCNG1                 (CNENGSET =   CNG1_ENABLE)
  #define EnableCNG0                 (CNENGSET =   CNG0_ENABLE)

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define EnableCNA10                (CNENASET = CNA10_ENABLE)
  #define EnableCNA9                 (CNENASET = CNA9_ENABLE)
  #define EnableCNA8                 (CNENASET = CNA8_ENABLE)
  #define EnableCNA7                 (CNENASET = CNA7_ENABLE)
  #define EnableCNA4                 (CNENASET = CNA4_ENABLE)
  #define EnableCNA3                 (CNENASET = CNA3_ENABLE)
  #define EnableCNA2                 (CNENASET = CNA2_ENABLE)
  #define EnableCNA1                 (CNENASET = CNA1_ENABLE)
  #define EnableCNA0                 (CNENASET = CNA0_ENABLE)

  #define EnableCNB15                (CNENBSET = CNB15_ENABLE)
  #define EnableCNB14                (CNENBSET = CNB14_ENABLE)
  #define EnableCNB13                (CNENBSET = CNB13_ENABLE)
  #define EnableCNB12                (CNENBSET = CNB12_ENABLE)
  #define EnableCNB11                (CNENBSET = CNB11_ENABLE)
  #define EnableCNB10                (CNENBSET = CNB10_ENABLE)
  #define EnableCNB9                 (CNENBSET =  CNB9_ENABLE)
  #define EnableCNB8                 (CNENBSET =  CNB8_ENABLE)
  #define EnableCNB7                 (CNENBSET =  CNB7_ENABLE)
  #define EnableCNB6                 (CNENBSET =  CNB6_ENABLE)
  #define EnableCNB5                 (CNENBSET =  CNB5_ENABLE)
  #define EnableCNB4                 (CNENBSET =  CNB4_ENABLE)
  #define EnableCNB3                 (CNENBSET =  CNB3_ENABLE)
  #define EnableCNB2                 (CNENBSET =  CNB2_ENABLE)
  #define EnableCNB1                 (CNENBSET =  CNB1_ENABLE)
  #define EnableCNB0                 (CNENBSET =  CNB0_ENABLE)

  #define EnableCNC9                 (CNENCSET =  CNC9_ENABLE)
  #define EnableCNC8                 (CNENCSET =  CNC8_ENABLE)
  #define EnableCNC7                 (CNENCSET =  CNC7_ENABLE)
  #define EnableCNC6                 (CNENCSET =  CNC6_ENABLE)
  #define EnableCNC5                 (CNENCSET =  CNC5_ENABLE)
  #define EnableCNC4                 (CNENCSET =  CNC4_ENABLE)
  #define EnableCNC3                 (CNENCSET =  CNC3_ENABLE)
  #define EnableCNC2                 (CNENCSET =  CNC2_ENABLE)
  #define EnableCNC1                 (CNENCSET =  CNC1_ENABLE)
  #define EnableCNC0                 (CNENCSET =  CNC0_ENABLE)

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define EnableCNA15                (CNENASET =  CNA15_ENABLE)
  #define EnableCNA14                (CNENASET =  CNA14_ENABLE)
  #define EnableCNA10                (CNENASET =  CNA10_ENABLE)
  #define EnableCNA9                 (CNENASET =   CNA9_ENABLE)
  #define EnableCNA7                 (CNENASET =   CNA7_ENABLE)
  #define EnableCNA6                 (CNENASET =   CNA6_ENABLE)
  #define EnableCNA5                 (CNENASET =   CNA5_ENABLE)
  #define EnableCNA4                 (CNENASET =   CNA4_ENABLE)
  #define EnableCNA3                 (CNENASET =   CNA3_ENABLE)
  #define EnableCNA2                 (CNENASET =   CNA2_ENABLE)
  #define EnableCNA1                 (CNENASET =   CNA1_ENABLE)
  #define EnableCNA0                 (CNENASET =   CNA0_ENABLE)

  #define EnableCNB15                (CNENBSET =  CNB15_ENABLE)
  #define EnableCNB14                (CNENBSET =  CNB14_ENABLE)
  #define EnableCNB13                (CNENBSET =  CNB13_ENABLE)
  #define EnableCNB12                (CNENBSET =  CNB12_ENABLE)
  #define EnableCNB11                (CNENBSET =  CNB11_ENABLE)
  #define EnableCNB10                (CNENBSET =  CNB10_ENABLE)
  #define EnableCNB9                 (CNENBSET =   CNB9_ENABLE)
  #define EnableCNB8                 (CNENBSET =   CNB8_ENABLE)
  #define EnableCNB7                 (CNENBSET =   CNB7_ENABLE)
  #define EnableCNB6                 (CNENBSET =   CNB6_ENABLE)
  #define EnableCNB5                 (CNENBSET =   CNB5_ENABLE)
  #define EnableCNB4                 (CNENBSET =   CNB4_ENABLE)
  #define EnableCNB3                 (CNENBSET =   CNB3_ENABLE)
  #define EnableCNB2                 (CNENBSET =   CNB2_ENABLE)
  #define EnableCNB1                 (CNENBSET =   CNB1_ENABLE)
  #define EnableCNB0                 (CNENBSET =   CNB0_ENABLE)

  #define EnableCNC15                (CNENCSET =  CNC15_ENABLE)
  #define EnableCNC14                (CNENCSET =  CNC14_ENABLE)
  #define EnableCNC13                (CNENCSET =  CNC13_ENABLE)
  #define EnableCNC12                (CNENCSET =  CNC12_ENABLE)
  #define EnableCNC4                 (CNENCSET =   CNC4_ENABLE)
  #define EnableCNC3                 (CNENCSET =   CNC3_ENABLE)
  #define EnableCNC2                 (CNENCSET =   CNC2_ENABLE)
  #define EnableCNC1                 (CNENCSET =   CNC1_ENABLE)

  #define EnableCND15                (CNENDSET =  CND15_ENABLE)
  #define EnableCND14                (CNENDSET =  CND14_ENABLE)
  #define EnableCND13                (CNENDSET =  CND13_ENABLE)
  #define EnableCND12                (CNENDSET =  CND12_ENABLE)
  #define EnableCND11                (CNENDSET =  CND11_ENABLE)
  #define EnableCND10                (CNENDSET =  CND10_ENABLE)
  #define EnableCND9                 (CNENDSET =   CND9_ENABLE)
  #define EnableCND8                 (CNENDSET =   CND8_ENABLE)
  #define EnableCND7                 (CNENDSET =   CND7_ENABLE)
  #define EnableCND6                 (CNENDSET =   CND6_ENABLE)
  #define EnableCND5                 (CNENDSET =   CND5_ENABLE)
  #define EnableCND4                 (CNENDSET =   CND4_ENABLE)
  #define EnableCND3                 (CNENDSET =   CND3_ENABLE)
  #define EnableCND2                 (CNENDSET =   CND2_ENABLE)
  #define EnableCND1                 (CNENDSET =   CND1_ENABLE)
  #define EnableCND0                 (CNENDSET =   CND0_ENABLE)

  #define EnableCNE9                 (CNENESET =   CNE9_ENABLE)
  #define EnableCNE8                 (CNENESET =   CNE8_ENABLE)
  #define EnableCNE7                 (CNENESET =   CNE7_ENABLE)
  #define EnableCNE6                 (CNENESET =   CNE6_ENABLE)
  #define EnableCNE5                 (CNENESET =   CNE5_ENABLE)
  #define EnableCNE4                 (CNENESET =   CNE4_ENABLE)
  #define EnableCNE3                 (CNENESET =   CNE3_ENABLE)
  #define EnableCNE2                 (CNENESET =   CNE2_ENABLE)
  #define EnableCNE1                 (CNENESET =   CNE1_ENABLE)
  #define EnableCNE0                 (CNENESET =   CNE0_ENABLE)

  #define EnableCNF13                (CNENFSET =  CNF13_ENABLE)
  #define EnableCNF12                (CNENFSET =  CNF12_ENABLE)
  #define EnableCNF8                 (CNENFSET =   CNF8_ENABLE)
  #define EnableCNF7                 (CNENFSET =   CNF7_ENABLE)
  #define EnableCNF6                 (CNENFSET =   CNF6_ENABLE)
  #define EnableCNF5                 (CNENFSET =   CNF5_ENABLE)
  #define EnableCNF4                 (CNENFSET =   CNF4_ENABLE)
  #define EnableCNF3                 (CNENFSET =   CNF3_ENABLE)
  #define EnableCNF2                 (CNENFSET =   CNF2_ENABLE)
  #define EnableCNF1                 (CNENFSET =   CNF1_ENABLE)
  #define EnableCNF0                 (CNENFSET =   CNF0_ENABLE)

  #define EnableCNG9                 (CNENGSET =   CNG9_ENABLE)
  #define EnableCNG8                 (CNENGSET =   CNG8_ENABLE)
  #define EnableCNG7                 (CNENGSET =   CNG7_ENABLE)
  #define EnableCNG6                 (CNENGSET =   CNG6_ENABLE)
  #define EnableCNG3                 (CNENGSET =   CNG3_ENABLE)
  #define EnableCNG2                 (CNENGSET =   CNG2_ENABLE)
  #define EnableCNG1                 (CNENGSET =   CNG1_ENABLE)
  #define EnableCNG0                 (CNENGSET =   CNG0_ENABLE)

#else
  #define EnableCN21                  (CNENSET = CN21_ENABLE)
  #define EnableCN20                  (CNENSET = CN20_ENABLE)
  #define EnableCN19                  (CNENSET = CN19_ENABLE)
  #define EnableCN18                  (CNENSET = CN18_ENABLE)
  #define EnableCN17                  (CNENSET = CN17_ENABLE)
  #define EnableCN16                  (CNENSET = CN16_ENABLE)
  #define EnableCN15                  (CNENSET = CN15_ENABLE)
  #define EnableCN14                  (CNENSET = CN14_ENABLE)
  #define EnableCN13                  (CNENSET = CN13_ENABLE)
  #define EnableCN12                  (CNENSET = CN12_ENABLE)
  #define EnableCN11                  (CNENSET = CN11_ENABLE)
  #define EnableCN10                  (CNENSET = CN10_ENABLE)
  #define EnableCN9                   (CNENSET =  CN9_ENABLE)
  #define EnableCN8                   (CNENSET =  CN8_ENABLE)
  #define EnableCN7                   (CNENSET =  CN7_ENABLE)
  #define EnableCN6                   (CNENSET =  CN6_ENABLE)
  #define EnableCN5                   (CNENSET =  CN5_ENABLE)
  #define EnableCN4                   (CNENSET =  CN4_ENABLE)
  #define EnableCN3                   (CNENSET =  CN3_ENABLE)
  #define EnableCN2                   (CNENSET =  CN2_ENABLE)
  #define EnableCN1                   (CNENSET =  CN1_ENABLE)
  #define EnableCN0                   (CNENSET =  CN0_ENABLE)

#endif

/******************************************************************************
 * <combinewith DisableCN0, DisableCN1, DisableCN2, DisableCN3, DisableCN4, DisableCN5,
 * DisableCN6, DisableCN7, DisableCN8, DisableCN9, DisableCN10, DisableCN11, DisableCN12,
 * DisableCN13, DisableCN14, DisableCN15, DisableCN16, DisableCN17, DisableCN18, DisableCN19,
 * DisableCN20, DisableCN_ALL>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void DisableCNx(void)
 *
 * Description:     Disables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableCN0()
 *
 *****************************************************************************/
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

   #ifdef _PORTA
     #define DisableCNA15                (CNENACLR =  CNA15_ENABLE)
     #define DisableCNA14                (CNENACLR =  CNA14_ENABLE)
     #define DisableCNA10                (CNENACLR =  CNA10_ENABLE)
     #define DisableCNA9                 (CNENACLR =   CNA9_ENABLE)
     #define DisableCNA7                 (CNENACLR =   CNA7_ENABLE)
     #define DisableCNA6                 (CNENACLR =   CNA6_ENABLE)
     #define DisableCNA5                 (CNENACLR =   CNA5_ENABLE)
     #define DisableCNA4                 (CNENACLR =   CNA4_ENABLE)
     #define DisableCNA3                 (CNENACLR =   CNA3_ENABLE)
     #define DisableCNA2                 (CNENACLR =   CNA2_ENABLE)
     #define DisableCNA1                 (CNENACLR =   CNA1_ENABLE)
     #define DisableCNA0                 (CNENACLR =   CNA0_ENABLE)
     #define DisableCNA_ALL              (CNENACLR = (0xFFFF))
   #endif

   #define DisableCNB15                (CNENBCLR =  CNB15_ENABLE)
   #define DisableCNB14                (CNENBCLR =  CNB14_ENABLE)
   #define DisableCNB13                (CNENBCLR =  CNB13_ENABLE)
   #define DisableCNB12                (CNENBCLR =  CNB12_ENABLE)
   #define DisableCNB11                (CNENBCLR =  CNB11_ENABLE)
   #define DisableCNB10                (CNENBCLR =  CNB10_ENABLE)
   #define DisableCNB9                 (CNENBCLR =   CNB9_ENABLE)
   #define DisableCNB8                 (CNENBCLR =   CNB8_ENABLE)
   #define DisableCNB7                 (CNENBCLR =   CNB7_ENABLE)
   #define DisableCNB6                 (CNENBCLR =   CNB6_ENABLE)
   #define DisableCNB5                 (CNENBCLR =   CNB5_ENABLE)
   #define DisableCNB4                 (CNENBCLR =   CNB4_ENABLE)
   #define DisableCNB3                 (CNENBCLR =   CNB3_ENABLE)
   #define DisableCNB2                 (CNENBCLR =   CNB2_ENABLE)
   #define DisableCNB1                 (CNENBCLR =   CNB1_ENABLE)
   #define DisableCNB0                 (CNENBCLR =   CNB0_ENABLE)
   #define DisableCNB_ALL              (CNENBCLR = (0xFFFF))

   #define DisableCNC15                (CNENCCLR =  CNC15_ENABLE)
   #define DisableCNC14                (CNENCCLR =  CNC14_ENABLE)
   #define DisableCNC13                (CNENCCLR =  CNC13_ENABLE)
   #define DisableCNC12                (CNENCCLR =  CNC12_ENABLE)
   #define DisableCNC4                 (CNENCCLR =   CNC4_ENABLE)
   #define DisableCNC3                 (CNENCCLR =   CNC3_ENABLE)
   #define DisableCNC2                 (CNENCCLR =   CNC2_ENABLE)
   #define DisableCNC1                 (CNENCCLR =   CNC1_ENABLE)
   #define DisableCNC_ALL              (CNENCCLR = (0xFFFF))

   #define DisableCND15                (CNENDCLR =  CND15_ENABLE)
   #define DisableCND14                (CNENDCLR =  CND14_ENABLE)
   #define DisableCND13                (CNENDCLR =  CND13_ENABLE)
   #define DisableCND12                (CNENDCLR =  CND12_ENABLE)
   #define DisableCND11                (CNENDCLR =  CND11_ENABLE)
   #define DisableCND10                (CNENDCLR =  CND10_ENABLE)
   #define DisableCND9                 (CNENDCLR =   CND9_ENABLE)
   #define DisableCND8                 (CNENDCLR =   CND8_ENABLE)
   #define DisableCND7                 (CNENDCLR =   CND7_ENABLE)
   #define DisableCND6                 (CNENDCLR =   CND6_ENABLE)
   #define DisableCND5                 (CNENDCLR =   CND5_ENABLE)
   #define DisableCND4                 (CNENDCLR =   CND4_ENABLE)
   #define DisableCND3                 (CNENDCLR =   CND3_ENABLE)
   #define DisableCND2                 (CNENDCLR =   CND2_ENABLE)
   #define DisableCND1                 (CNENDCLR =   CND1_ENABLE)
   #define DisableCND0                 (CNENDCLR =   CND0_ENABLE)
   #define DisableCND_ALL              (CNENDCLR = (0xFFFF))

   #define DisableCNE9                 (CNENECLR =   CNE9_ENABLE)
   #define DisableCNE8                 (CNENECLR =   CNE8_ENABLE)
   #define DisableCNE7                 (CNENECLR =   CNE7_ENABLE)
   #define DisableCNE6                 (CNENECLR =   CNE6_ENABLE)
   #define DisableCNE5                 (CNENECLR =   CNE5_ENABLE)
   #define DisableCNE4                 (CNENECLR =   CNE4_ENABLE)
   #define DisableCNE3                 (CNENECLR =   CNE3_ENABLE)
   #define DisableCNE2                 (CNENECLR =   CNE2_ENABLE)
   #define DisableCNE1                 (CNENECLR =   CNE1_ENABLE)
   #define DisableCNE0                 (CNENECLR =   CNE0_ENABLE)
   #define DisableCNE_ALL              (CNENECLR = (0xFFFF))

   #define DisableCNF13                (CNENFCLR =  CNF13_ENABLE)
   #define DisableCNF12                (CNENFCLR =  CNF12_ENABLE)
   #define DisableCNF8                 (CNENFCLR =   CNF8_ENABLE)
   #define DisableCNF7                 (CNENFCLR =   CNF7_ENABLE)
   #define DisableCNF6                 (CNENFCLR =   CNF6_ENABLE)
   #define DisableCNF5                 (CNENFCLR =   CNF5_ENABLE)
   #define DisableCNF4                 (CNENFCLR =   CNF4_ENABLE)
   #define DisableCNF3                 (CNENFCLR =   CNF3_ENABLE)
   #define DisableCNF2                 (CNENFCLR =   CNF2_ENABLE)
   #define DisableCNF1                 (CNENFCLR =   CNF1_ENABLE)
   #define DisableCNF0                 (CNENFCLR =   CNF0_ENABLE)
   #define DisableCNF_ALL              (CNENFCLR = (0xFFFF))

   #define DisableCNG15                (CNENGCLR =   CNG15_ENABLE)
   #define DisableCNG14                (CNENGCLR =   CNG14_ENABLE)
   #define DisableCNG13                (CNENGCLR =   CNG13_ENABLE)
   #define DisableCNG12                (CNENGCLR =   CNG12_ENABLE)
   #define DisableCNG9                 (CNENGCLR =   CNG9_ENABLE)
   #define DisableCNG8                 (CNENGCLR =   CNG8_ENABLE)
   #define DisableCNG7                 (CNENGCLR =   CNG7_ENABLE)
   #define DisableCNG6                 (CNENGCLR =   CNG6_ENABLE)
   #define DisableCNG3                 (CNENGCLR =   CNG3_ENABLE)
   #define DisableCNG2                 (CNENGCLR =   CNG2_ENABLE)
   #define DisableCNG1                 (CNENGCLR =   CNG1_ENABLE)
   #define DisableCNG0                 (CNENGCLR =   CNG0_ENABLE)
   #define DisableCNG_ALL              (CNENGCLR = (0xFFFF))

#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
  #define DisableCNA10                (CNENACLR = (1 << _CNENA_CNIEA10_POSITION))
  #define DisableCNA9                 (CNENACLR = (1 << _CNENA_CNIEA9_POSITION))
  #define DisableCNA8                 (CNENACLR = (1 << _CNENA_CNIEA8_POSITION))
  #define DisableCNA7                 (CNENACLR = (1 << _CNENA_CNIEA7_POSITION))
  #define DisableCNA4                 (CNENACLR = (1 << _CNENA_CNIEA4_POSITION))
  #define DisableCNA3                 (CNENACLR = (1 << _CNENA_CNIEA3_POSITION))
  #define DisableCNA2                 (CNENACLR = (1 << _CNENA_CNIEA2_POSITION))
  #define DisableCNA1                 (CNENACLR = (1 << _CNENA_CNIEA1_POSITION))
  #define DisableCNA0                 (CNENACLR = (1 << _CNENA_CNIEA0_POSITION))
  #define DisableCNA_ALL              (CNENACLR = (0xFFFF))

  #define DisableCNB15                (CNENBCLR = (1 << _CNENB_CNIEB15_POSITION))
  #define DisableCNB14                (CNENBCLR = (1 << _CNENB_CNIEB14_POSITION))
  #define DisableCNB13                (CNENBCLR = (1 << _CNENB_CNIEB13_POSITION))
  #define DisableCNB12                (CNENBCLR = (1 << _CNENB_CNIEB12_POSITION))
  #define DisableCNB11                (CNENBCLR = (1 << _CNENB_CNIEB11_POSITION))
  #define DisableCNB10                (CNENBCLR = (1 << _CNENB_CNIEB10_POSITION))
  #define DisableCNB9                 (CNENBCLR = (1 << _CNENB_CNIEB9_POSITION))
  #define DisableCNB8                 (CNENBCLR = (1 << _CNENB_CNIEB8_POSITION))
  #define DisableCNB7                 (CNENBCLR = (1 << _CNENB_CNIEB7_POSITION))
  #define DisableCNB6                 (CNENBCLR = (1 << _CNENB_CNIEB6_POSITION))
  #define DisableCNB5                 (CNENBCLR = (1 << _CNENB_CNIEB5_POSITION))
  #define DisableCNB4                 (CNENBCLR = (1 << _CNENB_CNIEB4_POSITION))
  #define DisableCNB3                 (CNENBCLR = (1 << _CNENB_CNIEB3_POSITION))
  #define DisableCNB2                 (CNENBCLR = (1 << _CNENB_CNIEB2_POSITION))
  #define DisableCNB1                 (CNENBCLR = (1 << _CNENB_CNIEB1_POSITION))
  #define DisableCNB0                 (CNENBCLR = (1 << _CNENB_CNIEB0_POSITION))
  #define DisableCNB_ALL              (CNENBCLR = (0xFFFF))

  #define DisableCNC9                 (CNENCCLR = (1 << _CNENC_CNIEC9_POSITION))
  #define DisableCNC8                 (CNENCCLR = (1 << _CNENC_CNIEC8_POSITION))
  #define DisableCNC7                 (CNENCCLR = (1 << _CNENC_CNIEC7_POSITION))
  #define DisableCNC6                 (CNENCCLR = (1 << _CNENC_CNIEC6_POSITION))
  #define DisableCNC5                 (CNENCCLR = (1 << _CNENC_CNIEC5_POSITION))
  #define DisableCNC4                 (CNENCCLR = (1 << _CNENC_CNIEC4_POSITION))
  #define DisableCNC3                 (CNENCCLR = (1 << _CNENC_CNIEC3_POSITION))
  #define DisableCNC2                 (CNENCCLR = (1 << _CNENC_CNIEC2_POSITION))
  #define DisableCNC1                 (CNENCCLR = (1 << _CNENC_CNIEC1_POSITION))
  #define DisableCNC0                 (CNENCCLR = (1 << _CNENC_CNIEC0_POSITION))
  #define DisableCNC_ALL              (CNENCCLR = (0xFFFF))

#elif ((__PIC32_FEATURE_SET__ == 330) || \
       (__PIC32_FEATURE_SET__ == 350) || \
       (__PIC32_FEATURE_SET__ == 370) || \
       (__PIC32_FEATURE_SET__ == 430) || \
       (__PIC32_FEATURE_SET__ == 450) || \
       (__PIC32_FEATURE_SET__ == 470))
  #define DisableCNA15                (CNENACLR = (1 << _CNENA_CNIEA15_POSITION))
  #define DisableCNA14                (CNENACLR = (1 << _CNENA_CNIEA14_POSITION))
  #define DisableCNA10                (CNENACLR = (1 << _CNENA_CNIEA10_POSITION))
  #define DisableCNA9                 (CNENACLR = (1 << _CNENA_CNIEA9_POSITION))
  #define DisableCNA7                 (CNENACLR = (1 << _CNENA_CNIEA7_POSITION))
  #define DisableCNA6                 (CNENACLR = (1 << _CNENA_CNIEA6_POSITION))
  #define DisableCNA5                 (CNENACLR = (1 << _CNENA_CNIEA5_POSITION))
  #define DisableCNA4                 (CNENACLR = (1 << _CNENA_CNIEA4_POSITION))
  #define DisableCNA3                 (CNENACLR = (1 << _CNENA_CNIEA3_POSITION))
  #define DisableCNA2                 (CNENACLR = (1 << _CNENA_CNIEA2_POSITION))
  #define DisableCNA1                 (CNENACLR = (1 << _CNENA_CNIEA1_POSITION))
  #define DisableCNA0                 (CNENACLR = (1 << _CNENA_CNIEA0_POSITION))
  #define DisableCNA_ALL              (CNENACLR = (0xFFFF))

  #define DisableCNB15                (CNENBCLR = (1 << _CNENB_CNIEB15_POSITION))
  #define DisableCNB14                (CNENBCLR = (1 << _CNENB_CNIEB14_POSITION))
  #define DisableCNB13                (CNENBCLR = (1 << _CNENB_CNIEB13_POSITION))
  #define DisableCNB12                (CNENBCLR = (1 << _CNENB_CNIEB12_POSITION))
  #define DisableCNB11                (CNENBCLR = (1 << _CNENB_CNIEB11_POSITION))
  #define DisableCNB10                (CNENBCLR = (1 << _CNENB_CNIEB10_POSITION))
  #define DisableCNB9                 (CNENBCLR = (1 << _CNENB_CNIEB9_POSITION))
  #define DisableCNB8                 (CNENBCLR = (1 << _CNENB_CNIEB8_POSITION))
  #define DisableCNB7                 (CNENBCLR = (1 << _CNENB_CNIEB7_POSITION))
  #define DisableCNB6                 (CNENBCLR = (1 << _CNENB_CNIEB6_POSITION))
  #define DisableCNB5                 (CNENBCLR = (1 << _CNENB_CNIEB5_POSITION))
  #define DisableCNB4                 (CNENBCLR = (1 << _CNENB_CNIEB4_POSITION))
  #define DisableCNB3                 (CNENBCLR = (1 << _CNENB_CNIEB3_POSITION))
  #define DisableCNB2                 (CNENBCLR = (1 << _CNENB_CNIEB2_POSITION))
  #define DisableCNB1                 (CNENBCLR = (1 << _CNENB_CNIEB1_POSITION))
  #define DisableCNB0                 (CNENBCLR = (1 << _CNENB_CNIEB0_POSITION))
  #define DisableCNB_ALL              (CNENBCLR = (0xFFFF))

  #define DisableCNC15                (CNENCCLR = (1 << _CNENC_CNIEC15_POSITION))
  #define DisableCNC14                (CNENCCLR = (1 << _CNENC_CNIEC14_POSITION))
  #define DisableCNC13                (CNENCCLR = (1 << _CNENC_CNIEC13_POSITION))
  #define DisableCNC12                (CNENCCLR = (1 << _CNENC_CNIEC12_POSITION))
  #define DisableCNC4                 (CNENCCLR = (1 << _CNENC_CNIEC4_POSITION))
  #define DisableCNC3                 (CNENCCLR = (1 << _CNENC_CNIEC3_POSITION))
  #define DisableCNC2                 (CNENCCLR = (1 << _CNENC_CNIEC2_POSITION))
  #define DisableCNC1                 (CNENCCLR = (1 << _CNENC_CNIEC1_POSITION))
  #define DisableCNC_ALL              (CNENCCLR = (0xFFFF))

  #define DisableCND15                (CNENDCLR = (1 << _CNEND_CNIED15_POSITION))
  #define DisableCND14                (CNENDCLR = (1 << _CNEND_CNIED14_POSITION))
  #define DisableCND13                (CNENDCLR = (1 << _CNEND_CNIED13_POSITION))
  #define DisableCND12                (CNENDCLR = (1 << _CNEND_CNIED12_POSITION))
  #define DisableCND11                (CNENDCLR = (1 << _CNEND_CNIED11_POSITION))
  #define DisableCND10                (CNENDCLR = (1 << _CNEND_CNIED10_POSITION))
  #define DisableCND9                 (CNENDCLR = (1 << _CNEND_CNIED9_POSITION))
  #define DisableCND8                 (CNENDCLR = (1 << _CNEND_CNIED8_POSITION))
  #define DisableCND7                 (CNENDCLR = (1 << _CNEND_CNIED7_POSITION))
  #define DisableCND6                 (CNENDCLR = (1 << _CNEND_CNIED6_POSITION))
  #define DisableCND5                 (CNENDCLR = (1 << _CNEND_CNIED5_POSITION))
  #define DisableCND4                 (CNENDCLR = (1 << _CNEND_CNIED4_POSITION))
  #define DisableCND3                 (CNENDCLR = (1 << _CNEND_CNIED3_POSITION))
  #define DisableCND2                 (CNENDCLR = (1 << _CNEND_CNIED2_POSITION))
  #define DisableCND1                 (CNENDCLR = (1 << _CNEND_CNIED1_POSITION))
  #define DisableCND0                 (CNENDCLR = (1 << _CNEND_CNIED0_POSITION))
  #define DisableCND_ALL              (CNENDCLR = (0xFFFF))

  #define DisableCNE9                 (CNENECLR = (1 << _CNENE_CNIEE9_POSITION))
  #define DisableCNE8                 (CNENECLR = (1 << _CNENE_CNIEE8_POSITION))
  #define DisableCNE7                 (CNENECLR = (1 << _CNENE_CNIEE7_POSITION))
  #define DisableCNE6                 (CNENECLR = (1 << _CNENE_CNIEE6_POSITION))
  #define DisableCNE5                 (CNENECLR = (1 << _CNENE_CNIEE5_POSITION))
  #define DisableCNE4                 (CNENECLR = (1 << _CNENE_CNIEE4_POSITION))
  #define DisableCNE3                 (CNENECLR = (1 << _CNENE_CNIEE3_POSITION))
  #define DisableCNE2                 (CNENECLR = (1 << _CNENE_CNIEE2_POSITION))
  #define DisableCNE1                 (CNENECLR = (1 << _CNENE_CNIEE1_POSITION))
  #define DisableCNE0                 (CNENECLR = (1 << _CNENE_CNIEE0_POSITION))
  #define DisableCNE_ALL              (CNENECLR = (0xFFFF))

  #define DisableCNF13                (CNENFCLR = (1 << _CNENF_CNIEF13_POSITION))
  #define DisableCNF12                (CNENFCLR = (1 << _CNENF_CNIEF12_POSITION))
  #define DisableCNF8                 (CNENFCLR = (1 << _CNENF_CNIEF8_POSITION))
  #define DisableCNF7                 (CNENFCLR = (1 << _CNENF_CNIEF7_POSITION))
  #define DisableCNF6                 (CNENFCLR = (1 << _CNENF_CNIEF6_POSITION))
  #define DisableCNF5                 (CNENFCLR = (1 << _CNENF_CNIEF5_POSITION))
  #define DisableCNF4                 (CNENFCLR = (1 << _CNENF_CNIEF4_POSITION))
  #define DisableCNF3                 (CNENFCLR = (1 << _CNENF_CNIEF3_POSITION))
  #define DisableCNF2                 (CNENFCLR = (1 << _CNENF_CNIEF2_POSITION))
  #define DisableCNF1                 (CNENFCLR = (1 << _CNENF_CNIEF1_POSITION))
  #define DisableCNF0                 (CNENFCLR = (1 << _CNENF_CNIEF0_POSITION))
  #define DisableCNF_ALL              (CNENFCLR = (0xFFFF))

  #define DisableCNG9                 (CNENGCLR = (1 << _CNENG_CNIEG9_POSITION))
  #define DisableCNG8                 (CNENGCLR = (1 << _CNENG_CNIEG8_POSITION))
  #define DisableCNG7                 (CNENGCLR = (1 << _CNENG_CNIEG7_POSITION))
  #define DisableCNG6                 (CNENGCLR = (1 << _CNENG_CNIEG6_POSITION))
  #define DisableCNG3                 (CNENGCLR = (1 << _CNENG_CNIEG3_POSITION))
  #define DisableCNG2                 (CNENGCLR = (1 << _CNENG_CNIEG2_POSITION))
  #define DisableCNG1                 (CNENGCLR = (1 << _CNENG_CNIEG1_POSITION))
  #define DisableCNG0                 (CNENGCLR = (1 << _CNENG_CNIEG0_POSITION))
  #define DisableCNG_ALL              (CNENGCLR = (0xFFFF))

#else
  #define DisableCN21                 (CNENCLR = (1 << _CNEN_CNEN21_POSITION))
  #define DisableCN20                 (CNENCLR = (1 << _CNEN_CNEN20_POSITION))
  #define DisableCN19                 (CNENCLR = (1 << _CNEN_CNEN19_POSITION))
  #define DisableCN18                 (CNENCLR = (1 << _CNEN_CNEN18_POSITION))
  #define DisableCN17                 (CNENCLR = (1 << _CNEN_CNEN17_POSITION))
  #define DisableCN16                 (CNENCLR = (1 << _CNEN_CNEN16_POSITION))
  #define DisableCN15                 (CNENCLR = (1 << _CNEN_CNEN15_POSITION))
  #define DisableCN14                 (CNENCLR = (1 << _CNEN_CNEN14_POSITION))
  #define DisableCN13                 (CNENCLR = (1 << _CNEN_CNEN13_POSITION))
  #define DisableCN12                 (CNENCLR = (1 << _CNEN_CNEN12_POSITION))
  #define DisableCN11                 (CNENCLR = (1 << _CNEN_CNEN11_POSITION))
  #define DisableCN10                 (CNENCLR = (1 << _CNEN_CNEN10_POSITION))
  #define DisableCN9                  (CNENCLR = (1 << _CNEN_CNEN9_POSITION))
  #define DisableCN8                  (CNENCLR = (1 << _CNEN_CNEN8_POSITION))
  #define DisableCN7                  (CNENCLR = (1 << _CNEN_CNEN7_POSITION))
  #define DisableCN6                  (CNENCLR = (1 << _CNEN_CNEN6_POSITION))
  #define DisableCN5                  (CNENCLR = (1 << _CNEN_CNEN5_POSITION))
  #define DisableCN4                  (CNENCLR = (1 << _CNEN_CNEN4_POSITION))
  #define DisableCN3                  (CNENCLR = (1 << _CNEN_CNEN3_POSITION))
  #define DisableCN2                  (CNENCLR = (1 << _CNEN_CNEN2_POSITION))
  #define DisableCN1                  (CNENCLR = (1 << _CNEN_CNEN1_POSITION))
  #define DisableCN0                  (CNENCLR = (1 << _CNEN_CNEN0_POSITION))
  #define DisableCN_ALL               (CNENCLR = (0x3FFFFF))

#endif

/******************************************************************************
 * PORT Parameter values to be used with mPORTxxx macros
 *****************************************************************************/

 #define BIT_31                       (1 << 31)
 #define BIT_30                       (1 << 30)
 #define BIT_29                       (1 << 29)
 #define BIT_28                       (1 << 28)
 #define BIT_27                       (1 << 27)
 #define BIT_26                       (1 << 26)
 #define BIT_25                       (1 << 25)
 #define BIT_24                       (1 << 24)
 #define BIT_23                       (1 << 23)
 #define BIT_22                       (1 << 22)
 #define BIT_21                       (1 << 21)
 #define BIT_20                       (1 << 20)
 #define BIT_19                       (1 << 19)
 #define BIT_18                       (1 << 18)
 #define BIT_17                       (1 << 17)
 #define BIT_16                       (1 << 16)
 #define BIT_15                       (1 << 15)
 #define BIT_14                       (1 << 14)
 #define BIT_13                       (1 << 13)
 #define BIT_12                       (1 << 12)
 #define BIT_11                       (1 << 11)
 #define BIT_10                       (1 << 10)
 #define BIT_9                        (1 << 9)
 #define BIT_8                        (1 << 8)
 #define BIT_7                        (1 << 7)
 #define BIT_6                        (1 << 6)
 #define BIT_5                        (1 << 5)
 #define BIT_4                        (1 << 4)
 #define BIT_3                        (1 << 3)
 #define BIT_2                        (1 << 2)
 #define BIT_1                        (1 << 1)
 #define BIT_0                        (1 << 0)


typedef enum {
#ifdef _PORTA
        IOPORT_A,
#endif
#ifdef _PORTB
        IOPORT_B,
#endif
#ifdef _PORTC
        IOPORT_C,
#endif
#ifdef _PORTD
        IOPORT_D,
#endif
#ifdef _PORTE
        IOPORT_E,
#endif
#ifdef _PORTF
        IOPORT_F,
#endif
#ifdef _PORTG
        IOPORT_G,
#endif
    IOPORT_NUM
} IoPortId;

/******************************************************************************
 * Set Pins as Digital Input
 *
 * Function:        PORTSetPinsDigitalIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as digital inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetPinsDigitalIn(IoPortId portId, unsigned int inputs);

/******************************************************************************
 * Set Pins as Digital Output
 *
 * Function:        PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as digital outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
void    PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs);

/******************************************************************************
 * Set Pins as Analog Input
 *
 * Function:        PORTSetPinsAnalogIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as Analog inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetPinsAnalogIn(IoPortId portId, unsigned int inputs);

/******************************************************************************
 * Set Pins as Analog Output
 *
 * Function:        PORTSetPinsAnalogOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as analog outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
void    PORTSetPinsAnalogOut(IoPortId portId, unsigned int outputs);

/******************************************************************************
 * Reset PORT pins
 *
 * Function:        PORTResetPins(IoPortId portId, unsigned int pins)
 *
 * Description:     Resets IOPORT pins to their POR state
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  pins: Bit-wise ORed of port pin bits.
 *
 *
 * Output:          None
 *
 * Example:         PORTResetPins(IOPORT_D, IOPORT_PIN_15);// Set Port D, bit 15 to input, latch at zero
 *
 *****************************************************************************/
void    PORTResetPins(IoPortId portId, unsigned int pins);

/******************************************************************************
 * Reads digital port
 *
 * Function:        unsigned int    PORTRead(IoPortId portId);
 *
 * Description:     Reads from a selected port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTRead(IOPORT_B);
 *
 *****************************************************************************/
unsigned int    PORTRead(IoPortId portId);

/******************************************************************************
 * Reads digital port bits
 *
 * Function:        unsigned int    PORTReadBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Reads selected pins from port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be read
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTReadBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
unsigned int    PORTReadBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Writes to a digital port
 *
 * Function:        void    PORTWrite(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes to PORT register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          None
 *
 * Example:         PORTWrite(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTWrite(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Sets digital port bits
 *
 * Function:        void    PORTSetBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTSET register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTSetBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Clears digital port bits
 *
 * Function:        void    PORTClearBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTCLR register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTClearBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTClearBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Toggle digital port bits
 *
 * Function:        void    PORTToggleBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTINV register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTToggleBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTToggleBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * <combinewith mPORTAGetDirection, mPORTAReadDirectionBits, mPORTARead ,mPORTAReadBits, mPORTAReadLatch,
 * mPORTAReadLatchBits, mPORTAWrite, mPORTASetBits, mPORTAClearBits, mPORTAToggleBits, mPORTAOpenDrainOpen,
 * mPORTAOpenDrainClose, mPORTACloseAll, mPORTACloseBits, mPORTASetPinsDigitalIn, mPORTASetPinsDigitalOut,
 * mPORTBDirection, mPORTBGetDirection, mPORTBReadDirectionBits, mPORTBRead ,mPORTBReadBits, mPORTBReadLatch,
 * mPORTBReadLatchBits, mPORTBWrite, mPORTBSetBits, mPORTBClearBits, mPORTBToggleBits, mPORTBOpenDrainOpen,
 * mPORTBOpenDrainClose, mPORTBCloseAll, mPORTBCloseBits, mPORTBSetPinsDigitalIn, mPORTBSetPinsDigitalOut,
 * mPORTBSetPinsAnalogOut, mPORTBSetPinsAnalogIn,
 * mPORTCDirection, mPORTCGetDirection, mPORTCReadDirectionBits, mPORTCRead ,mPORTCReadBits, mPORTCReadLatch,
 * mPORTCReadLatchBits, mPORTCWrite, mPORTCSetBits, mPORTCClearBits, mPORTCToggleBits, mPORTCOpenDrainOpen,
 * mPORTCOpenDrainClose, mPORTCCloseAll, mPORTCCloseBits, mPORTCSetPinsDigitalIn, mPORTCSetPinsDigitalOut,
 * mPORTDDirection, mPORTDGetDirection, mPORTDReadDirectionBits, mPORTDRead ,mPORTDReadBits, mPORTDReadLatch,
 * mPORTDReadLatchBits, mPORTDWrite, mPORTDSetBits, mPORTDClearBits, mPORTDToggleBits, mPORTDOpenDrainOpen,
 * mPORTDOpenDrainClose, mPORTDCloseAll, mPORTDCloseBits, mPORTDSetPinsDigitalIn, mPORTDSetPinsDigitalOut,
 * mPORTBEirection, mPORTEGetDirection, mPORTEReadDirectionBits, mPORTERead ,mPORTEReadBits, mPORTEReadLatch,
 * mPORTEReadLatchBits, mPORTEWrite, mPORTESetBits, mPORTEClearBits, mPORTEToggleBits, mPORTEOpenDrainOpen,
 * mPORTEOpenDrainClose, mPORTECloseAll, mPORTECloseBits, mPORTESetPinsDigitalIn, mPORTESetPinsDigitalOut,
 * mPORTFDirection, mPORTFGetDirection, mPORTFReadDirectionBits, mPORTFRead ,mPORTFReadBits, mPORTFReadLatch,
 * mPORTFReadLatchBits, mPORTFWrite, mPORTFSetBits, mPORTFClearBits, mPORTFToggleBits, mPORTFOpenDrainOpen,
 * mPORTFOpenDrainClose, mPORTFCloseAll, mPORTFCloseBits, mPORTFSetPinsDigitalIn, mPORTFSetPinsDigitalOut,
 * mPORTGDirection, mPORTGGetDirection, mPORTGReadDirectionBits, mPORTGRead ,mPORTGReadBits, mPORTGReadLatch,
 * mPORTGReadLatchBits, mPORTGWrite, mPORTGSetBits, mPORTGClearBits, mPORTGToggleBits, mPORTGOpenDrainOpen,
 * mPORTGOpenDrainClose, mPORTGCloseAll, mPORTGCloseBits, mPORTGSetPinsDigitalIn, mPORTGSetPinsDigitalOut>
 *
 * GPIO Control Macros
 *
 * Description:
 *          To set I/O pin directions for a PORTx
 *                  void mPORTxConfig(unsigned int _direction)
 *                  unsigned int mPORTxGetConfig(void)
 *                  unsigned int mPORTxReadConfigBit(unsigned int _bits)
 *
 *          To read an input pin
 *                  unsigned int mPORTxRead(void)
 *                  unsigned int mPORTxReadBit(unsigned int _bits)
 *
 *          To write to an output pin
 *                  void mPORTxWrite(unsigned int _value)
 *                  unsigned int mPORTxReadLatch(void)
 *                  unsigned int mPORTxReadLatchBit(unsigned int _bits)
 *
 *          To configure select pins in a PORT without affecting other pins
 *                  void mPORTxSetPinsDigitalInput(unsigned int _inputs)
 *                  void mPORTxSetPinsDigitalOutput(unsigned int _outputs)
 *                  void mPORTxSetPinsAnalogInput(unsigned int _inputs)
 *                  void mPORTxSetPinsAnalogOutput(unsigned int _outputs)
 *                  void mPORTxOutputConfig(unsigned int _outputs)
 *                  void mPORTxInputConfig(unsigned int _inputs)
 *
 *          To manipulate select pins in a PORT without affecting other pins
 *                  void mPORTxSetbits(unsigned int _bits)
 *                  void mPORTxClearBits(unsigned int _bits)
 *                  void mPORTxToggleBits(unsigned int _bits)
 *
 *          To make a PORT all input and clear latch values.
 *                  void mPORTxCloseAll(void)
 *                  void mPORTxCloseBits(unsigned int _bits)
 *
 *          To configure open drain I/Os in a PORT.
 *                  void mPORTxOpenDrainOpen(unsigned int _bits)
 *                  void mPORTxOpenDrainClose(unsigned int _bits)
 *
 *
 * Example:         mPORTCSetPinsDigitalOutput(IO_PORT_BIT_4 | IO_PORT_BIT_3)
 *
 *****************************************************************************/

#if defined _PORTA
  #define mPORTADirection(_tris)              (TRISA = (unsigned int)(_tris))
  #define mPORTAGetDirection()                (TRISA)
  #define mPORTAReadDirectionBits(_bits)      (TRISA & (unsigned int)(_bits))

  #define mPORTARead()                        (PORTA)
  #define mPORTAReadBits(_bits)               (PORTA & (unsigned int)(_bits))
  #define mPORTAReadLatch()                   (LATA)
  #define mPORTAReadLatchBits(_bits)          (LATA & (unsigned int)(_bits))

  #define mPORTAWrite(_lat)                   (LATA = (unsigned int)(_lat))
  #define mPORTASetBits(_bits)                (LATASET = (unsigned int)(_bits))
  #define mPORTAClearBits(_bits)              (LATACLR = (unsigned int)(_bits))
  #define mPORTAToggleBits(_bits)             (LATAINV = (unsigned int)(_bits))

  #define mPORTAOpenDrainOpen(_bits)          (ODCASET = (unsigned int)(_bits), TRISACLR = (unsigned int)(_bits))
  #define mPORTAOpenDrainClose(_bits)         (ODCACLR = (unsigned int)(_bits), TRISASET = (unsigned int)(_bits))

  #define mPORTACloseAll()                    (TRISASET = 0xFFFFFFFF, LATACLR = 0xFFFFFFFF)
  #define mPORTACloseBits(_bits)              (TRISASET = (unsigned int)(_bits), LATACLR = (unsigned int)(_bits))

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
    #define mPORTASetPinsAnalogOut(_outputs)    (TRISACLR = (unsigned int)(_outputs), ANSELASET = (unsigned int)(_outputs))
    #define mPORTASetPinsAnalogIn(_inputs)      (TRISASET = (unsigned int)(_inputs),  ANSELASET = (unsigned int)(_inputs) )
    #define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs), ANSELACLR = (unsigned int)(_outputs))
    #define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs),  ANSELACLR = (unsigned int)(_inputs) )

  #elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
    #define mPORTASetPinsAnalogOut(_outputs)    (TRISACLR = (unsigned int)(_outputs), ANSELASET = (unsigned int)(_outputs))
    #define mPORTASetPinsAnalogIn(_inputs)      (TRISASET = (unsigned int)(_inputs),  ANSELASET = (unsigned int)(_inputs) )
    #define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs), ANSELACLR = (unsigned int)(_outputs))
    #define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs),  ANSELACLR = (unsigned int)(_inputs) )

  #elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
    #define mPORTASetPinsAnalogOut(_outputs)    (TRISACLR = (unsigned int)(_outputs), ANSELASET = (unsigned int)(_outputs))
    #define mPORTASetPinsAnalogIn(_inputs)      (TRISASET = (unsigned int)(_inputs),  ANSELASET = (unsigned int)(_inputs) )
    #define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs), ANSELACLR = (unsigned int)(_outputs))
    #define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs),  ANSELACLR = (unsigned int)(_inputs) )

 #else
    #define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs))
    #define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs))

  #endif

#endif  //end PORTA


#if defined _PORTB
/******************************************************************************
 * PORTB macros
 *****************************************************************************/
  #define mPORTBDirection(_tris)              (TRISB = (unsigned int)(_tris))
  #define mPORTBGetDirection()                (TRISB)
  #define mPORTBReadDirectionBits(_bits)      (TRISB & (unsigned int)(_bits))

  #define mPORTBRead()                        (PORTB)
  #define mPORTBReadBits(_bits)               (PORTB & (unsigned int)(_bits))
  #define mPORTBReadLatch()                   (LATB)
  #define mPORTBReadLatchBits(_bits)          (LATB & (unsigned int)(_bits))

  #define mPORTBWrite(_lat)                   (LATB = (unsigned int)(_lat))
  #define mPORTBSetBits(_bits)                (LATBSET = (unsigned int)(_bits))
  #define mPORTBClearBits(_bits)              (LATBCLR = (unsigned int)(_bits))
  #define mPORTBToggleBits(_bits)             (LATBINV = (unsigned int)(_bits))

  #define mPORTBOpenDrainOpen(_bits)          (ODCBSET = (unsigned int)(_bits), TRISBCLR = (unsigned int)(_bits))
  #define mPORTBOpenDrainClose(_bits)         (ODCBCLR = (unsigned int)(_bits), TRISBSET = (unsigned int)(_bits))

  #define mPORTBCloseAll()                    (TRISBSET = 0xFFFFFFFF, LATBCLR = 0xFFFFFFFF)
  #define mPORTBCloseBits(_bits)              (TRISBSET = (unsigned int)(_bits), LATBCLR = (unsigned int)(_bits))

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
    #define mPORTBSetPinsAnalogOut(_outputs)    (TRISBCLR = (unsigned int)(_outputs), ANSELBSET = (unsigned int)(_outputs))
    #define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),  ANSELBSET = (unsigned int)(_inputs) )
    #define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs), ANSELBCLR = (unsigned int)(_outputs))
    #define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),  ANSELBCLR = (unsigned int)(_inputs) )

  #elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
    #define mPORTBSetPinsAnalogOut(_outputs)    (TRISBCLR = (unsigned int)(_outputs), ANSELBSET = (unsigned int)(_outputs))
    #define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),  ANSELBSET = (unsigned int)(_inputs) )
    #define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs), ANSELBCLR = (unsigned int)(_outputs))
    #define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),  ANSELBCLR = (unsigned int)(_inputs) )

  #elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
    #define mPORTBSetPinsAnalogOut(_outputs)    (TRISBCLR = (unsigned int)(_outputs), ANSELBSET = (unsigned int)(_outputs))
    #define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),  ANSELBSET = (unsigned int)(_inputs) )
    #define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs), ANSELBCLR = (unsigned int)(_outputs))
    #define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),  ANSELBCLR = (unsigned int)(_inputs) )

  #else
    #define mPORTBSetPinsAnalogOut(_outputs)    (TRISBCLR = (unsigned int)(_outputs), AD1PCFGCLR = (unsigned int)(_outputs))
    #define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),  AD1PCFGCLR = (unsigned int)(_inputs) )
    #define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs), AD1PCFGSET = (unsigned int)(_outputs))
    #define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),  AD1PCFGSET = (unsigned int)(_inputs) )

  #endif

#endif  //end PORTB


#if defined _PORTC
/******************************************************************************
 * PORTC macros
 *****************************************************************************/
  #define mPORTCDirection(_tris)              (TRISC = (unsigned int)(_tris))
  #define mPORTCGetDirection()                (TRISC)
  #define mPORTCReadDirectionBits(_bits)      (TRISC & (unsigned int)(_bits))

  #define mPORTCRead()                        (PORTC)
  #define mPORTCReadBits(_bits)               (PORTC & (unsigned int)(_bits))
  #define mPORTCReadLatch()                   (LATC)
  #define mPORTCReadLatchBits(_bits)          (LATC & (unsigned int)(_bits))

  #define mPORTCWrite(_lat)                   (LATC = (unsigned int)(_lat))
  #define mPORTCSetBits(_bits)                (LATCSET = (unsigned int)(_bits))
  #define mPORTCClearBits(_bits)              (LATCCLR = (unsigned int)(_bits))
  #define mPORTCToggleBits(_bits)             (LATCINV = (unsigned int)(_bits))

  #define mPORTCOpenDrainOpen(_bits)          (ODCCSET = (unsigned int)(_bits), TRISCCLR = (unsigned int)(_bits))
  #define mPORTCOpenDrainClose(_bits)         (ODCCCLR = (unsigned int)(_bits), TRISCSET = (unsigned int)(_bits))

  #define mPORTCCloseAll()                    (TRISCSET = 0xFFFFFFFF, LATCCLR = 0xFFFFFFFF)
  #define mPORTCCloseBits(_bits)              (TRISCSET = (unsigned int)(_bits), LATCCLR = (unsigned int)(_bits))

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
    #define mPORTCSetPinsAnalogOut(_outputs)    (TRISCCLR = (unsigned int)(_outputs), ANSELCSET = (unsigned int)(_outputs))
    #define mPORTCSetPinsAnalogIn(_inputs)      (TRISCSET = (unsigned int)(_inputs),  ANSELCSET = (unsigned int)(_inputs) )
    #define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs), ANSELCCLR = (unsigned int)(_outputs))
    #define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs),  ANSELCCLR = (unsigned int)(_inputs) )

  #elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
    #define mPORTCSetPinsAnalogOut(_outputs)    (TRISCCLR = (unsigned int)(_outputs), ANSELCSET = (unsigned int)(_outputs))
    #define mPORTCSetPinsAnalogIn(_inputs)      (TRISCSET = (unsigned int)(_inputs),  ANSELCSET = (unsigned int)(_inputs) )
    #define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs), ANSELCCLR = (unsigned int)(_outputs))
    #define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs),  ANSELCCLR = (unsigned int)(_inputs) )

  #elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
    #define mPORTCSetPinsAnalogOut(_outputs)    (TRISCCLR = (unsigned int)(_outputs), ANSELCSET = (unsigned int)(_outputs))
    #define mPORTCSetPinsAnalogIn(_inputs)      (TRISCSET = (unsigned int)(_inputs),  ANSELCSET = (unsigned int)(_inputs) )
    #define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs), ANSELCCLR = (unsigned int)(_outputs))
    #define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs),  ANSELCCLR = (unsigned int)(_inputs) )

  #else
    #define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs))
    #define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs))

  #endif

#endif  // end PORTC


#if defined _PORTD
/******************************************************************************
 * PORTD macros
 *****************************************************************************/
  #define mPORTDDirection(_tris)              (TRISD = (unsigned int)(_tris))
  #define mPORTDGetDirection()                (TRISD)
  #define mPORTDReadDirectionBits(_bits)      (TRISD & (unsigned int)(_bits))

  #define mPORTDRead()                        (PORTD)
  #define mPORTDReadBits(_bits)               (PORTD & (unsigned int)(_bits))
  #define mPORTDReadLatch()                   (LATD)
  #define mPORTDReadLatchBits(_bits)          (LATD & (unsigned int)(_bits))

  #define mPORTDWrite(_lat)                   (LATD = (unsigned int)(_lat))
  #define mPORTDSetBits(_bits)                (LATDSET = (unsigned int)(_bits))
  #define mPORTDClearBits(_bits)              (LATDCLR = (unsigned int)(_bits))
  #define mPORTDToggleBits(_bits)             (LATDINV = (unsigned int)(_bits))

  #define mPORTDOpenDrainOpen(_bits)          (TRISDCLR = (unsigned int)(_bits), ODCDSET = (unsigned int)(_bits))
  #define mPORTDOpenDrainClose(_bits)         (TRISDSET = (unsigned int)(_bits), ODCDCLR = (unsigned int)(_bits))

  #define mPORTDCloseAll()                    (TRISDSET = 0xFFFFFFFF, LATDCLR = 0xFFFFFFFF)
  #define mPORTDCloseBits(_bits)              (TRISDSET = (unsigned int)(_bits), LATDCLR = (unsigned int)(_bits))

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
    #define mPORTDSetPinsAnalogOut(_outputs)    (TRISDCLR = (unsigned int)(_outputs), ANSELDSET = (unsigned int)(_outputs))
    #define mPORTDSetPinsAnalogIn(_inputs)      (TRISDSET = (unsigned int)(_inputs),  ANSELDSET = (unsigned int)(_inputs) )
    #define mPORTDSetPinsDigitalOut(_outputs)   (TRISDCLR = (unsigned int)(_outputs), ANSELDCLR = (unsigned int)(_outputs))
    #define mPORTDSetPinsDigitalIn(_inputs)     (TRISDSET = (unsigned int)(_inputs),  ANSELDCLR = (unsigned int)(_inputs) )

   #elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
    #define mPORTDSetPinsAnalogOut(_outputs)    (TRISDCLR = (unsigned int)(_outputs), ANSELDSET = (unsigned int)(_outputs))
    #define mPORTDSetPinsAnalogIn(_inputs)      (TRISDSET = (unsigned int)(_inputs),  ANSELDSET = (unsigned int)(_inputs) )
    #define mPORTDSetPinsDigitalOut(_outputs)   (TRISDCLR = (unsigned int)(_outputs), ANSELDCLR = (unsigned int)(_outputs))
    #define mPORTDSetPinsDigitalIn(_inputs)     (TRISDSET = (unsigned int)(_inputs),  ANSELDCLR = (unsigned int)(_inputs) )

  #else
    #define mPORTDSetPinsDigitalIn(_inputs)     (TRISDSET = (unsigned int)(_inputs))
    #define mPORTDSetPinsDigitalOut(_outputs)   (TRISDCLR = (unsigned int)(_outputs))

  #endif

#endif  // end PORTD


#if defined _PORTE
/******************************************************************************
 * PORTE macros
 *****************************************************************************/
  #define mPORTEDirection(_tris)              (TRISE = (unsigned int)(_tris))
  #define mPORTEGetDirection()                (TRISE)
  #define mPORTEReadDirectionBits(_bits)      (TRISE & (unsigned int)(_bits))

  #define mPORTERead()                        (PORTE)
  #define mPORTEReadBits(_bits)               (PORTE & (unsigned int)(_bits))
  #define mPORTEReadLatch()                   (LATE)
  #define mPORTEReadLatchBits(_bits)          (LATE & (unsigned int)(_bits))

  #define mPORTEWrite(_lat)                   (LATE = (unsigned int)(_lat))
  #define mPORTESetBits(_bits)                (LATESET = (unsigned int)(_bits))
  #define mPORTEClearBits(_bits)              (LATECLR = (unsigned int)(_bits))
  #define mPORTEToggleBits(_bits)             (LATEINV = (unsigned int)(_bits))

  #define mPORTEOpenDrainOpen(_bits)          (ODCESET = (unsigned int)(_bits), TRISECLR = (unsigned int)(_bits))
  #define mPORTEOpenDrainClose(_bits)         (ODCECLR = (unsigned int)(_bits), TRISESET = (unsigned int)(_bits))

  #define mPORTECloseAll()                    (TRISESET = 0xFFFFFFFF, LATECLR = 0xFFFFFFFF)
  #define mPORTECloseBits(_bits)              (TRISESET = (unsigned int)(_bits), LATECLR = (unsigned int)(_bits))

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
    #define mPORTESetPinsAnalogOut(_outputs)    (TRISECLR = (unsigned int)(_outputs), ANSELESET = (unsigned int)(_outputs))
    #define mPORTESetPinsAnalogIn(_inputs)      (TRISESET = (unsigned int)(_inputs),  ANSELESET = (unsigned int)(_inputs) )
    #define mPORTESetPinsDigitalOut(_outputs)   (TRISECLR = (unsigned int)(_outputs), ANSELECLR = (unsigned int)(_outputs))
    #define mPORTESetPinsDigitalIn(_inputs)     (TRISESET = (unsigned int)(_inputs),  ANSELECLR = (unsigned int)(_inputs) )

  #elif ((__PIC32_FEATURE_SET__ == 330) || (__PIC32_FEATURE_SET__ == 350) || (__PIC32_FEATURE_SET__ == 370) || (__PIC32_FEATURE_SET__ == 430) || (__PIC32_FEATURE_SET__ == 450) || (__PIC32_FEATURE_SET__ == 470))
    #define mPORTESetPinsAnalogOut(_outputs)    (TRISECLR = (unsigned int)(_outputs), ANSELESET = (unsigned int)(_outputs))
    #define mPORTESetPinsAnalogIn(_inputs)      (TRISESET = (unsigned int)(_inputs),  ANSELESET = (unsigned int)(_inputs) )
    #define mPORTESetPinsDigitalOut(_outputs)   (TRISECLR = (unsigned int)(_outputs), ANSELECLR = (unsigned int)(_outputs))
    #define mPORTESetPinsDigitalIn(_inputs)     (TRISESET = (unsigned int)(_inputs),  ANSELECLR = (unsigned int)(_inputs) )

  #else
    #define mPORTESetPinsDigitalIn(_inputs)     (TRISESET = (unsigned int)(_inputs))
    #define mPORTESetPinsDigitalOut(_outputs)   (TRISECLR = (unsigned int)(_outputs))

  #endif

#endif  // end PORTE


#if defined _PORTF
/******************************************************************************
 * PORTF macros
 *****************************************************************************/
  #define mPORTFDirection(_tris)              (TRISF = (unsigned int)(_tris))
  #define mPORTFGetDirection()                (TRISF)
  #define mPORTFReadDirectionBits(_bits)      (TRISF & (unsigned int)(_bits))

  #define mPORTFRead()                        (PORTF)
  #define mPORTFReadBits(_bits)               (PORTF & (unsigned int)(_bits))
  #define mPORTFReadLatch()                   (LATF)
  #define mPORTFReadLatchBits(_bits)          (LATF & (unsigned int)(_bits))

  #define mPORTFWrite(_lat)                   (LATF = (unsigned int)(_lat))
  #define mPORTFSetBits(_bits)                (LATFSET = (unsigned int)(_bits))
  #define mPORTFClearBits(_bits)              (LATFCLR = (unsigned int)(_bits))
  #define mPORTFToggleBits(_bits)             (LATFINV = (unsigned int)(_bits))

  #define mPORTFOpenDrainOpen(_bits)          (ODCFSET = (unsigned int)(_bits), TRISFCLR = (unsigned int)(_bits))
  #define mPORTFOpenDrainClose(_bits)         (ODCFCLR = (unsigned int)(_bits), TRISFSET = (unsigned int)(_bits))

  #define mPORTFCloseAll()                    (TRISFSET = 0xFFFFFFFF, LATFCLR = 0xFFFFFFFF)
  #define mPORTFCloseBits(_bits)              (TRISFSET = (unsigned int)(_bits), LATFCLR = (unsigned int)(_bits))

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
    #define mPORTFSetPinsAnalogOut(_outputs)    (TRISFCLR = (unsigned int)(_outputs), ANSELFSET = (unsigned int)(_outputs))
    #define mPORTFSetPinsAnalogIn(_inputs)      (TRISFSET = (unsigned int)(_inputs),  ANSELFSET = (unsigned int)(_inputs) )
    #define mPORTFSetPinsDigitalOut(_outputs)   (TRISFCLR = (unsigned int)(_outputs), ANSELFCLR = (unsigned int)(_outputs))
    #define mPORTFSetPinsDigitalIn(_inputs)     (TRISFSET = (unsigned int)(_inputs),  ANSELFCLR = (unsigned int)(_inputs) )

   #elif ((__PIC32_FEATURE_SET__ == 330) || \
          (__PIC32_FEATURE_SET__ == 350) || \
          (__PIC32_FEATURE_SET__ == 370) || \
          (__PIC32_FEATURE_SET__ == 430) || \
          (__PIC32_FEATURE_SET__ == 450) || \
          (__PIC32_FEATURE_SET__ == 470))
    #define mPORTFSetPinsAnalogOut(_outputs)    (TRISFCLR = (unsigned int)(_outputs), ANSELFSET = (unsigned int)(_outputs))
    #define mPORTFSetPinsAnalogIn(_inputs)      (TRISFSET = (unsigned int)(_inputs),  ANSELFSET = (unsigned int)(_inputs) )
    #define mPORTFSetPinsDigitalOut(_outputs)   (TRISFCLR = (unsigned int)(_outputs), ANSELFCLR = (unsigned int)(_outputs))
    #define mPORTFSetPinsDigitalIn(_inputs)     (TRISFSET = (unsigned int)(_inputs),  ANSELFCLR = (unsigned int)(_inputs) )

  #else

    #define mPORTFSetPinsDigitalIn(_inputs)     (TRISFSET = (unsigned int)(_inputs))
    #define mPORTFSetPinsDigitalOut(_outputs)   (TRISFCLR = (unsigned int)(_outputs))

  #endif

#endif  // end PORTF


#if defined _PORTG
/******************************************************************************
 * PORTG macros
 *****************************************************************************/
  #define mPORTGDirection(_tris)              (TRISG = (unsigned int)(_tris))
  #define mPORTGGetDirection()                (TRISG)
  #define mPORTGReadDirectionBits(_bits)      (TRISG & (unsigned int)(_bits))

  #define mPORTGRead()                        (PORTG)
  #define mPORTGReadBits(_bits)               (PORTG & (unsigned int)(_bits))
  #define mPORTGReadLatch()                   (LATG)
  #define mPORTGReadLatchBits(_bits)          (LATG & (unsigned int)(_bits))

  #define mPORTGWrite(_lat)                   (LATG = (unsigned int)(_lat))
  #define mPORTGSetBits(_bits)                (LATGSET = (unsigned int)(_bits))
  #define mPORTGClearBits(_bits)              (LATGCLR = (unsigned int)(_bits))
  #define mPORTGToggleBits(_bits)             (LATGINV = (unsigned int)(_bits))

  #define mPORTGOpenDrainOpen(_bits)          (ODCGSET = (unsigned int)(_bits), TRISGCLR = (unsigned int)(_bits))
  #define mPORTGOpenDrainClose(_bits)         (ODCGCLR = (unsigned int)(_bits), TRISGSET = (unsigned int)(_bits))

  #define mPORTGCloseAll()                    (TRISGSET = 0xFFFFFFFF, LATGCLR = 0xFFFFFFFF)
  #define mPORTGCloseBits(_bits)              (TRISGSET = (unsigned int)(_bits), LATGCLR = (unsigned int)(_bits))

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
    #define mPORTGSetPinsAnalogOut(_outputs)    (TRISGCLR = (unsigned int)(_outputs), ANSELGSET = (unsigned int)(_outputs))
    #define mPORTGSetPinsAnalogIn(_inputs)      (TRISGSET = (unsigned int)(_inputs),  ANSELGSET = (unsigned int)(_inputs) )
    #define mPORTGSetPinsDigitalOut(_outputs)   (TRISGCLR = (unsigned int)(_outputs), ANSELGCLR = (unsigned int)(_outputs))
    #define mPORTGSetPinsDigitalIn(_inputs)     (TRISGSET = (unsigned int)(_inputs),  ANSELGCLR = (unsigned int)(_inputs) )

  #elif ((__PIC32_FEATURE_SET__ == 330) || \
         (__PIC32_FEATURE_SET__ == 350) || \
         (__PIC32_FEATURE_SET__ == 370) || \
         (__PIC32_FEATURE_SET__ == 430) || \
         (__PIC32_FEATURE_SET__ == 450) || \
         (__PIC32_FEATURE_SET__ == 470))
    #define mPORTGSetPinsAnalogOut(_outputs)    (TRISGCLR = (unsigned int)(_outputs), ANSELGSET = (unsigned int)(_outputs))
    #define mPORTGSetPinsAnalogIn(_inputs)      (TRISGSET = (unsigned int)(_inputs),  ANSELGSET = (unsigned int)(_inputs) )
    #define mPORTGSetPinsDigitalOut(_outputs)   (TRISGCLR = (unsigned int)(_outputs), ANSELGCLR = (unsigned int)(_outputs))
    #define mPORTGSetPinsDigitalIn(_inputs)     (TRISGSET = (unsigned int)(_inputs),  ANSELGCLR = (unsigned int)(_inputs) )

  #else

    #define mPORTGSetPinsDigitalIn(_inputs)     (TRISGSET = (unsigned int)(_inputs))
    #define mPORTGSetPinsDigitalOut(_outputs)   (TRISGCLR = (unsigned int)(_outputs))

  #endif

#endif  // end PORTG


/******************************************************************************
 * Parameter values to be used with mJTAGPortEnable()
 *****************************************************************************/
#define DEBUG_JTAGPORT_ON                       (1)
#define DEBUG_JTAGPORT_OFF                      (0) // Debug JTAG Off

/******************************************************************************
 * JTAG macro       void mJTAGPortEnable(unsigned int enable)
 *
 * Function:
 *                  To enable/disable JTAG module
 *                  mJTAGEnable(unsigned int _enable)
 *
 * Description:     Enables or disables JTAG port.
 *
 * PreCondition:    None
 *
 * Inputs:          0 = disable, 1 = enable
 *
 * Output:          None
 *
 * Example:         mJTAGPortEnable(1)
 *
 *****************************************************************************/
#define mJTAGPortEnable(_enable) (DDPCONbits.JTAGEN = (_enable))

#endif  // _PORTS_H_
