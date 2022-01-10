/********************************************************************
 * FileName:        int_tbl_lipb.c
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
 * $Id:$
 * $Name:  $
 ********************************************************************/
#include <peripheral/int.h>

enum {
    SFR_REG,
    SFR_CLR,
    SFR_SET,
    SFR_INV
};

typedef volatile unsigned int VUINT;

typedef struct {
    VUINT *ipc;
    unsigned int sub_shift;
    unsigned int pri_shift;
} INT_VECTOR_TBL_ENTRY;

const INT_VECTOR_TBL_ENTRY __IntScrPriTbl[] = // In order of vector #
{
    { &IPC0, _IPC0_CTIS_POSITION, _IPC0_CTIP_POSITION}, // Core Timer Interrupt
    { &IPC0, _IPC0_CS0IS_POSITION, _IPC0_CS0IP_POSITION}, // Core Software Interrupt 0
    { &IPC0, _IPC0_CS1IS_POSITION, _IPC0_CS1IP_POSITION}, // Core Software Interrupt 1
    { &IPC0, _IPC0_INT0IS_POSITION, _IPC0_INT0IP_POSITION}, // External Interrupt 0

    { &IPC1, _IPC1_T1IS_POSITION, _IPC1_T1IP_POSITION}, // Timer 1
    { &IPC1, _IPC1_IC1IS_POSITION, _IPC1_IC1IP_POSITION}, // Input Capture 1
    { &IPC1, _IPC1_OC1IS_POSITION, _IPC1_OC1IP_POSITION}, // Output Compare 1
    { &IPC1, _IPC1_INT1IS_POSITION, _IPC1_INT1IP_POSITION}, // External Interrupt 1

    { &IPC2, _IPC2_T2IS_POSITION, _IPC2_T2IP_POSITION}, // Timer 2
    { &IPC2, _IPC2_IC2IS_POSITION, _IPC2_IC2IP_POSITION}, // Input Capture 2
    { &IPC2, _IPC2_OC2IS_POSITION, _IPC2_OC2IP_POSITION}, // Output Compare 2
    { &IPC2, _IPC2_INT2IS_POSITION, _IPC2_INT2IP_POSITION}, // External Interrupt 2

    { &IPC3, _IPC3_T3IS_POSITION, _IPC3_T3IP_POSITION}, // T1mer 3
    { &IPC3, _IPC3_IC3IS_POSITION, _IPC3_IC3IP_POSITION}, // Input Capture 3
    { &IPC3, _IPC3_OC3IS_POSITION, _IPC3_OC3IP_POSITION}, // Output Compare 3
    { &IPC3, _IPC3_INT3IS_POSITION, _IPC3_INT3IP_POSITION}, // External Interrupt 3

    { &IPC4, _IPC4_T4IS_POSITION, _IPC4_T4IP_POSITION}, // Timer 4
    { &IPC4, _IPC4_IC4IS_POSITION, _IPC4_IC4IP_POSITION}, // Input Capture 4
    { &IPC4, _IPC4_OC4IS_POSITION, _IPC4_OC4IP_POSITION}, // Output Compare 4
    { &IPC4, _IPC4_INT4IS_POSITION, _IPC4_INT4IP_POSITION}, // External Interrupt 4

    { &IPC5, _IPC5_T5IS_POSITION, _IPC5_T5IP_POSITION}, // Timer 5
    { &IPC5, _IPC5_IC5IS_POSITION, _IPC5_IC5IP_POSITION}, // Input Capture 5
    { &IPC5, _IPC5_OC5IS_POSITION, _IPC5_OC5IP_POSITION}, // Output Compare 5

    { &IPC5, _IPC5_AD1IS_POSITION, _IPC5_AD1IP_POSITION}, // ADC 1 Convert Done
    { &IPC6, _IPC6_FSCMIS_POSITION, _IPC6_FSCMIP_POSITION}, // Fail-safe Clock Monitor
    { &IPC6, _IPC6_RTCCIS_POSITION, _IPC6_RTCCIP_POSITION}, // Real Time Clock/Calendar
    { &IPC6, _IPC6_FCEIS_POSITION, _IPC6_FCEIP_POSITION}, // Flash Control Event

    { &IPC6, _IPC6_CMP1IS_POSITION, _IPC6_CMP1IP_POSITION}, // Comparator 1 Interrupt
    { &IPC7, _IPC7_CMP2IS_POSITION, _IPC7_CMP2IP_POSITION}, // Comparator 2 Interrupt
#ifdef _USB
    { &IPC7, _IPC7_USBIS_POSITION, _IPC7_USBIP_POSITION}, // USB
#else
    { (VUINT *) 0, 0, 0},
#endif

    { &IPC7, _IPC7_SPI1IS_POSITION, _IPC7_SPI1IP_POSITION}, // SPI 1
    { &IPC7, _IPC7_U1IS_POSITION, _IPC7_U1IP_POSITION}, // UART 1
    { &IPC8, _IPC8_I2C1IS_POSITION, _IPC8_I2C1IP_POSITION}, // I2C1

    { &IPC8, _IPC8_CNIS_POSITION, _IPC8_CNIP_POSITION}, // Change Notification
    { &IPC8, _IPC8_PMPIS_POSITION, _IPC8_PMPIP_POSITION}, // Parallel Master Port

    { &IPC8, _IPC8_SPI2IS_POSITION, _IPC8_SPI2IP_POSITION}, // SPI 2
    { &IPC9, _IPC9_U2IS_POSITION, _IPC9_U2IP_POSITION}, // UART 2
    { &IPC9, _IPC9_I2C2IS_POSITION, _IPC9_I2C2IP_POSITION}, // I2C2

    { &IPC9, _IPC9_U3IS_POSITION, _IPC9_U3IP_POSITION}, // UART 3
    { &IPC9, _IPC9_U4IS_POSITION, _IPC9_U4IP_POSITION}, // UART 4
#if defined( _UART5 )
    { &IPC10, _IPC10_U5IS_POSITION, _IPC10_U5IP_POSITION}, // UART 5
#else
    { (VUINT *) 0, 0, 0},
#endif

    { &IPC10, _IPC10_CTMUIS_POSITION, _IPC10_CTMUIP_POSITION}, // CTMU

    { &IPC10, _IPC10_DMA0IS_POSITION, _IPC10_DMA0IP_POSITION}, // DMA Channel 0
    { &IPC10, _IPC10_DMA1IS_POSITION, _IPC10_DMA1IP_POSITION}, // DMA Channel 1
    { &IPC11, _IPC11_DMA2IS_POSITION, _IPC11_DMA2IP_POSITION}, // DMA Channel 2
    { &IPC11, _IPC11_DMA3IS_POSITION, _IPC11_DMA3IP_POSITION}, // DMA Channel 3

    { &IPC11, _IPC11_CMP3IS_POSITION, _IPC11_CMP3IP_POSITION}, // Comparator 3 Interrupt

#ifdef _CAN1
    { &IPC11, _IPC11_CAN1IS_POSITION, _IPC11_CAN1IP_POSITION}, // CAN
#else
    { (VUINT *) 0, 0, 0},
#endif

    { &IPC12, _IPC12_SPI3IS_POSITION, _IPC12_SPI3IP_POSITION}, // SPI 3
#if defined( _SPI4 )
    { &IPC12, _IPC12_SPI4IS_POSITION, _IPC12_SPI4IP_POSITION}, // SPI 4
#else
    { (VUINT *) 0, 0, 0},
#endif
};

