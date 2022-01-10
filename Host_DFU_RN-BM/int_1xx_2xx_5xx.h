/*******************************************************************************
    PIC32MX Interrupt

  Summary:
    This file contains Application Program Interface (API definitions for the
    Interrupt peripheral library.

  Description:
    This library provides a low-level abstraction of the interrupt controller
    module on Microchip PIC32MX family microcontrollers with a
    convenient C language interface.  It can be used to simplify low-level
    access to the module without the necessity of interacting directly with the
    module's registers, thus hiding differences from one microcontroller
    variant to another.
*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
FileName:       int_1xx_2xx_5xx.h
Processor:      PIC32MX
Compiler:       Microchip MPLAB XC32 v1.33 or higher

Copyright © 2014 released Microchip Technology Inc.  All rights
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

#ifndef _PIC32INT_1XX_2XX_5XX_HEADER_FILE
#define _PIC32INT_1XX_2XX_5XX_HEADER_FILE

// *****************************************************************************
// *****************************************************************************
// Section: Includes
// *****************************************************************************
// *****************************************************************************
#include <xc.h>
#include <sys/attribs.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Legacy Includes
// *****************************************************************************
// *****************************************************************************
#ifndef _PLIB_DISABLE_LEGACY
  #include <peripheral/legacy/int_1xx_2xx_5xx_legacy.h>
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Constants & Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Interrupt Source

  Summary:
    Interrupt source definitions (PIC32MX1xx/2xx/5xx family).

  Description:
    These definitions can be used to set or get the state of the interrupt source flag and
    interrupt enable.

    This enumeration is used by
      void INTClearFlag(INT_SOURCE source)
      void INTSetFlag(INT_SOURCE source)
      unsigned int INTGetFlag(INT_SOURCE source)
      void INTEnable(INT_SOURCE source, INT_EN_DIS enable)
      unsigned int INTGetEnable(INT_SOURCE source)
*/
typedef enum //IRQ's from Table 5-1
{
    INT_CT = 0,             // Core Timer Interrupt

    INT_CS0,                // Core Software Interrupt 0
    INT_CS1,                // Core Software Interrupt 1

    INT_INT0,               // External Interrupt 0
    INT_INT1,               // External Interrupt 1
    INT_INT2,               // External Interrrupt 2
    INT_INT3,               // External Interrupt 3
    INT_INT4,               // External Interupt 4

    INT_T1,                 // Timer1
    INT_T2,                 // Timer2
    INT_T3,                 // Timer3
    INT_T4,                 // Timer4
    INT_T5,                 // Timer5

    INT_IC1E,               // Input Capture Error 1
    INT_IC2E,               // Input Capture Error 2
    INT_IC3E,               // Input Capture Error 3
    INT_IC4E,               // Input Capture Error 4
    INT_IC5E,               // Input Capture Error 5

    INT_IC1,                // Input Capture 1
    INT_IC2,                // Input Capture 2
    INT_IC3,                // Input Capture 3
    INT_IC4,                // Input Capture 4
    INT_IC5,                // Input Capture 5

    INT_OC1,                // Output Compare 1
    INT_OC2,                // Output Compare 2
    INT_OC3,                // Output Compare 3
    INT_OC4,                // Output Compare 4
    INT_OC5,                // Output Compare 5

    INT_CNA,                // Change Notice, Port A
    INT_CNB,                // Change Notice, Port B
    INT_CNC,                // Change Notice, Port C
    INT_CND,                // Change Notice, Port D
    INT_CNE,                // Change Notice, Port E
    INT_CNF,                // Change Notice, Port F
    INT_CNG,                // Change Notice, Port G

    INT_SPI1,
    INT_SPI2,
    INT_SPI3,
    INT_SPI4,

    INT_SPI1E,              // SPI1 Fault
    INT_SPI2E,              // SPI2 Fault
    INT_SPI3E,              // SPI3 Fault
    INT_SPI4E,              // SPI4 Fault

    INT_SPI1TX,             // SPI1 Transfer Done
    INT_SPI2TX,             // SPI2 Transfer Done
    INT_SPI3TX,             // SPI3 Transfer Done
    INT_SPI4TX,             // SPI4 Transfer Done

    INT_SPI1RX,             // SPI1 Receive Done
    INT_SPI2RX,             // SPI2 Receive Done
    INT_SPI3RX,             // SPI3 Receive Done
    INT_SPI4RX,             // SPI4 Receive Done

    INT_I2C1,
    INT_I2C2,

    INT_I2C1B,              // I2C1 Bus Colision Event
    INT_I2C2B,              // I2C2 Bus Colision Event

    INT_I2C1S,              // I2C1 Slave Event
    INT_I2C2S,              // I2C2 Slave Event

    INT_I2C1M,              // I2C1 Master Event
    INT_I2C2M,              // I2C2 Master Event

    INT_U1,
    INT_U2,
    INT_U3_DONOTUSE,        // DO NOT USE - interrupt table entry empty, use individual entries below
    INT_U4,
    INT_U5,

    INT_U1E,                // UART1 Error Event
    INT_U2E,                // UART2 Error Event
    INT_U3E,                // UART2 Error Event
    INT_U4E,                // UART2 Error Event
    INT_U5E,                // UART2 Error Event

    INT_U1RX,               // UART1 RX Event
    INT_U2RX,               // UART2 RX Event
    INT_U3RX,               // UART2 RX Event
    INT_U4RX,               // UART2 RX Event
    INT_U5RX,               // UART2 RX Event

    INT_U1TX,               // UART1 TX Event
    INT_U2TX,               // UART2 TX Event
    INT_U3TX,               // UART2 TX Event
    INT_U4TX,               // UART2 TX Event
    INT_U5TX,               // UART2 TX Event

    INT_AD1,                // ADC1 Convert Done

    INT_PMP,                // Parallel Master Port
    INT_PMPE,               // Parallel Master Port Error

    INT_CMP1,               // Comparator 1 Interrupt
    INT_CMP2,               // Comparator 2 Interrupt
    INT_CMP3,               // Comparator 3 Interrupt

    INT_FSCM,               // Fail-safe Monitor

    INT_FCE,                // Flash Control Event

    INT_RTCC,               // Real Time Clock

    INT_CTMU,               // CTMU

    INT_DMA0,               // DMA Channel 0
    INT_DMA1,               // DMA Channel 1
    INT_DMA2,               // DMA Channel 2
    INT_DMA3,               // DMA Channel 3

    INT_USB,                // USB

    INT_CAN1,               // CAN1

    INT_NUM                 // Number of available interrupt soruces and vectors

}  INT_SOURCE;


// *****************************************************************************
/* Interrupt Muli-Channel Converter

  Summary:
    Interrupt muli-channel converter definitions.

  Description:
    These definitions can be used to convert a channel into the correct INT_SOURCE value.

    These macros can be used by
      void INTClearFlag(INT_SOURCE source)
      void INTSetFlag(INT_SOURCE source)
      unsigned int INTGetFlag(INT_SOURCE source)
      void INTEnable(INT_SOURCE source, INT_EN_DIS enable)
      unsigned int INTGetEnable(INT_SOURCE source)
*/
// Core Software Interrupt Channel.
#define INT_SOURCE_CORE_SW(chn)         /*DOM-IGNORE-BEGIN*/(INT_CS0 + (chn))           /*DOM-IGNORE-END*/
// External Interrupt Channel.
#define INT_SOURCE_EX_INT(chn)          /*DOM-IGNORE-BEGIN*/(INT_INT0 + (chn))          /*DOM-IGNORE-END*/
// Timer Interrupt Channel.
#define INT_SOURCE_TIMER(chn)           /*DOM-IGNORE-BEGIN*/(INT_T1 + (chn))            /*DOM-IGNORE-END*/
// Input Capture Interrupt Channel.
#define INT_SOURCE_INPUT_CAP(chn)       /*DOM-IGNORE-BEGIN*/(INT_IC1 + (chn))           /*DOM-IGNORE-END*/
// Output Compare Interrupt Channel.
#define INT_SOURCE_OUTPUT_COM(chn)      /*DOM-IGNORE-BEGIN*/(INT_OC1 + (chn))           /*DOM-IGNORE-END*/
// SPI Interrupt Channel.
#define INT_SOURCE_SPI(chn)             /*DOM-IGNORE-BEGIN*/((INT_SPI1 - 1) + (chn))    /*DOM-IGNORE-END*/
// SPI Error Interrupt Channel.
#define INT_SOURCE_SPI_ERROR(chn)       /*DOM-IGNORE-BEGIN*/((INT_SPI1E - 1) + (chn))   /*DOM-IGNORE-END*/
// SPI Transmit Interrupt Channel.
#define INT_SOURCE_SPI_TX(chn)          /*DOM-IGNORE-BEGIN*/((INT_SPI1TX - 1) + (chn))  /*DOM-IGNORE-END*/
// SPI Receive Interrupt Channel.
#define INT_SOURCE_SPI_RX(chn)          /*DOM-IGNORE-BEGIN*/((INT_SPI1RX - 1) + (chn))  /*DOM-IGNORE-END*/
// I2C Interrupt Channel.
#define INT_SOURCE_I2C(chn)             /*DOM-IGNORE-BEGIN*/(INT_I2C1 + (chn))          /*DOM-IGNORE-END*/
// I2C Bus Collision Interrupt Channel.
#define INT_SOURCE_I2C_ERROR(chn)       /*DOM-IGNORE-BEGIN*/(INT_I2C1B + (chn))         /*DOM-IGNORE-END*/
// I2C Slave Interrupt Channel.
#define INT_SOURCE_I2C_SLAVE(chn)       /*DOM-IGNORE-BEGIN*/(INT_I2C1S + (chn))         /*DOM-IGNORE-END*/
// I2C Master Interrupt Channel.
#define INT_SOURCE_I2C_MASTER(chn)      /*DOM-IGNORE-BEGIN*/(INT_I2C1M + (chn))         /*DOM-IGNORE-END*/
// UART Interrupt Channel.
#define INT_SOURCE_UART(chn)            /*DOM-IGNORE-BEGIN*/(INT_U1 + (chn))            /*DOM-IGNORE-END*/
// UART Error Interrupt Channel.
#define INT_SOURCE_UART_ERROR(chn)      /*DOM-IGNORE-BEGIN*/(INT_U1E + (chn))           /*DOM-IGNORE-END*/
// UART Receive Interrupt Channel.
#define INT_SOURCE_UART_RX(chn)         /*DOM-IGNORE-BEGIN*/(INT_U1RX + (chn))          /*DOM-IGNORE-END*/
// UART Transmit Interrupt Channel.
#define INT_SOURCE_UART_TX(chn)         /*DOM-IGNORE-BEGIN*/(INT_U1TX + (chn))          /*DOM-IGNORE-END*/
// DMA Interrupt Channel.
#define INT_SOURCE_DMA(chn)             /*DOM-IGNORE-BEGIN*/(INT_DMA0 + (chn))          /*DOM-IGNORE-END*/
// CAN Interrupt Channel.
#define INT_SOURCE_CAN(chn)             /*DOM-IGNORE-BEGIN*/(INT_CAN1 + (chn))          /*DOM-IGNORE-END*/


// *****************************************************************************
/* Interrupt Vector

  Summary:
    Interrupt vector definitions (PIC32MX1xx/2xx family).

  Description:
    These definitions can be used to set or get the state of the interrupt vector
    priority and sub-priority.

    This enumeration is used by:
      void INTSetVectorPriority(INT_VECTOR vector, INT_PRIORITY priority)
      INT_PRIORITY INTGetVectorPriority(INT_VECTOR vector)
      void INTSetVectorSubPriority(INT_VECTOR vector, INT_SUB_PRIORITY subPriority)
      INT_SUB_PRIORITY INTGetVectorSubPriority(INT_VECTOR vector)

  WARNING:
    Do not use with the __IPL(v,ipl) macro.

*/
typedef enum //Vector Number from Table 7-1
{
    INT_CORE_TIMER_VECTOR,            // Core Timer Interrupt

    INT_CORE_SOFTWARE_0_VECTOR,       // Core Software Interrupt 0
    INT_CORE_SOFTWARE_1_VECTOR,       // Core Software Interrupt 1

    INT_EXTERNAL_0_VECTOR,            // External Interrupt 0
    INT_EXTERNAL_1_VECTOR,            // External Interrupt 1
    INT_EXTERNAL_2_VECTOR,            // External Interrrupt 2
    INT_EXTERNAL_3_VECTOR,            // External Interrupt 3
    INT_EXTERNAL_4_VECTOR,            // External Interupt 4

    INT_TIMER_1_VECTOR,               // Timer1
    INT_TIMER_2_VECTOR,               // Timer2
    INT_TIMER_3_VECTOR,               // TImer3
    INT_TIMER_4_VECTOR,               // Timer4
    INT_TIMER_5_VECTOR,               // Timer5

    INT_INPUT_CAPTURE_1_VECTOR,       // Input Capture 1
    INT_INPUT_CAPTURE_2_VECTOR,       // Input Capture 2
    INT_INPUT_CAPTURE_3_VECTOR,       // Input Capture 3
    INT_INPUT_CAPTURE_4_VECTOR,       // Input Capture 4
    INT_INPUT_CAPTURE_5_VECTOR,       // Input Capture 5

    INT_OUTPUT_COMPARE_1_VECTOR,       // Output Compare 1
    INT_OUTPUT_COMPARE_2_VECTOR,       // Output Compare 2
    INT_OUTPUT_COMPARE_3_VECTOR,       // Output Compare 3
    INT_OUTPUT_COMPARE_4_VECTOR,       // Output Compare 4
    INT_OUTPUT_COMPARE_5_VECTOR,       // Output Compare 5

    INT_SPI_1_VECTOR,                 // SPI1 Vector
    INT_SPI_2_VECTOR,                 // SPI2 Vector
    INT_SPI_3_VECTOR,                 // SPI3 Vector
    INT_SPI_4_VECTOR,                 // SPI4 Vector

    INT_UART_1_VECTOR,                // UART1 Vector
    INT_UART_2_VECTOR,                // UART2 Vector
    INT_UART_3_VECTOR,                // UART3 Vector
    INT_UART_4_VECTOR,                // UART4 Vector
    INT_UART_5_VECTOR,                // UART5 Vector

    INT_I2C_1_VECTOR,                 // I2C1 Vector
    INT_I2C_2_VECTOR,                 // I2C2 Vector

    INT_CHANGE_NOTICE_VECTOR,         // Change Notice
    INT_ADC_VECTOR,                   // ADC1 Convert Done
    INT_PMP_VECTOR,                   // Parallel Master Port

    INT_COMPARATOR_1_VECTOR,          // Comparator 1 Interrupt
    INT_COMPARATOR_2_VECTOR,          // Comparator 2 Interrupt
    INT_COMPARATOR_3_VECTOR,          // Comparator 3 Interrupt

    INT_FAIL_SAFE_MONITOR_VECTOR,     // Fail-safe Monitor
    INT_RTCC_VECTOR,                  // Real-Time Clock

    INT_CTMU_VECTOR,                  // CTMU

    INT_DMA_0_VECTOR,                 // DMA Channel 0
    INT_DMA_1_VECTOR,                 // DMA Channel 1
    INT_DMA_2_VECTOR,                 // DMA Channel 2
    INT_DMA_3_VECTOR,                 // DMA Channel 3

    INT_FCE_VECTOR,                   // Flash Control Event

    INT_USB_1_VECTOR,                 // USB

    INT_CAN_1_VECTOR,                 // CAN

}INT_VECTOR;

// *****************************************************************************
/* Interrupt Muli-Channel Converter

  Summary:
    Interrupt muli-channel converter definitions.

  Description:
    These definitions can be used to convert a channel into the correct INT_VECTOR value.

    These macros can be used by:
      void INTSetVectorPriority(INT_VECTOR vector, INT_PRIORITY priority)
      INT_PRIORITY INTGetVectorPriority(INT_VECTOR vector)
      void INTSetVectorSubPriority(INT_VECTOR vector, INT_SUB_PRIORITY subPriority)
      INT_SUB_PRIORITY INTGetVectorSubPriority(INT_VECTOR vector)

  WARNING:
    Do not use with the __IPL(v,ipl) macro.

*/
// Core Software Interrupt Channel
#define INT_VECTOR_CORE_SW(chn)         /*DOM-IGNORE-BEGIN*/(INT_CORE_SOFTWARE_0_VECTOR + (chn))    /*DOM-IGNORE-END*/
// External Interrupt Channel
#define INT_VECTOR_EX_INT(chn)          /*DOM-IGNORE-BEGIN*/(INT_EXTERNAL_0_VECTOR + (chn))         /*DOM-IGNORE-END*/
// Timer Interrupt Channel
#define INT_VECTOR_TIMER(chn)           /*DOM-IGNORE-BEGIN*/(INT_TIMER_1_VECTOR + (chn))            /*DOM-IGNORE-END*/
// Input Capture Interrupt Channel
#define INT_VECTOR_INPUT_CAP(chn)       /*DOM-IGNORE-BEGIN*/(INT_INPUT_CAPTURE_1_VECTOR + (chn))    /*DOM-IGNORE-END*/
// Output Compare Interrupt Channel
#define INT_VECTOR_OUTPUT_COM(chn)      /*DOM-IGNORE-BEGIN*/(INT_OUTPUT_COMPARE_1_VECTOR + (chn))   /*DOM-IGNORE-END*/
// SPI Interrupt Channel
#define INT_VECTOR_SPI(chn)             /*DOM-IGNORE-BEGIN*/((INT_SPI_1_VECTOR - 1) + (chn))        /*DOM-IGNORE-END*/
// I2C Interrupt Channel
#define INT_VECTOR_I2C(chn)             /*DOM-IGNORE-BEGIN*/(INT_I2C_1_VECTOR + (chn))              /*DOM-IGNORE-END*/
// UART Interrupt Channel
#define INT_VECTOR_UART(chn)            /*DOM-IGNORE-BEGIN*/(INT_UART_1_VECTOR + (chn))             /*DOM-IGNORE-END*/
// DMA Interrupt Channel
#define INT_VECTOR_DMA(chn)             /*DOM-IGNORE-BEGIN*/(INT_DMA_0_VECTOR + (chn))              /*DOM-IGNORE-END*/
// CAN Interrupt Channel
#define INT_VECTOR_CAN(chn)             /*DOM-IGNORE-BEGIN*/(INT_CAN_1_VECTOR + (chn))              /*DOM-IGNORE-END*/

#endif//_PIC32INT_1XX_2XX_5XX_HEADER_FILE

