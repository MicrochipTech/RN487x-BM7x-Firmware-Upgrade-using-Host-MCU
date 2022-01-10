/********************************************************************
 * FileName:		int_tbl_lipb.c
 * Dependencies:
 * Processor:		PIC32
 * Hardware:		N/A
 * Assembler:		N/A
 * Linker:		    N/A
 * Company:		    Microchip Technology Inc.
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


enum
{
	SFR_REG,
	SFR_CLR,
	SFR_SET,
	SFR_INV
};

typedef volatile unsigned int   VUINT;

typedef struct
{
    VUINT           *ipc;
    unsigned int    sub_shift;
    unsigned int    pri_shift;
}INT_VECTOR_TBL_ENTRY;

const INT_VECTOR_TBL_ENTRY __IntScrPriTbl[] =
{
    {   &IPC0,  _IPC0_CTIS_POSITION,    _IPC0_CTIP_POSITION     },  // Core Timer Interrupt

    {   &IPC0,  _IPC0_CS0IS_POSITION,   _IPC0_CS0IP_POSITION    },  // Core Software Interrupt 0
    {   &IPC0,  _IPC0_CS1IS_POSITION,   _IPC0_CS1IP_POSITION    },  // Core Software Interrupt 1

    {   &IPC0, _IPC0_INT0IS_POSITION,  _IPC0_INT0IP_POSITION   },  // External Interrupt 0
    {   &IPC1, _IPC1_INT1IS_POSITION,  _IPC1_INT1IP_POSITION   },  // External Interrupt 1
    {   &IPC2, _IPC2_INT2IS_POSITION,  _IPC2_INT2IP_POSITION   },  // External Interrrupt 2
    {   &IPC3, _IPC3_INT3IS_POSITION,  _IPC3_INT3IP_POSITION   },  // External Interrupt 3
    {   &IPC4, _IPC4_INT4IS_POSITION,  _IPC4_INT4IP_POSITION   },  // External Interupt 4

    {   &IPC1, _IPC1_T1IS_POSITION,    _IPC1_T1IP_POSITION     },  // Timer 1
    {   &IPC2, _IPC2_T2IS_POSITION,    _IPC2_T2IP_POSITION     },  // Timer 2
    {   &IPC3, _IPC3_T3IS_POSITION,    _IPC3_T3IP_POSITION     },  // TImer 3
    {   &IPC4, _IPC4_T4IS_POSITION,    _IPC4_T4IP_POSITION     },  // Timer 4
    {   &IPC5, _IPC5_T5IS_POSITION,    _IPC5_T5IP_POSITION     },  // Timer 5

    {   &IPC1,  _IPC1_IC1IS_POSITION,   _IPC1_IC1IP_POSITION    },  // Input Capture 1
    {   &IPC2,  _IPC2_IC2IS_POSITION,   _IPC2_IC2IP_POSITION    },  // Input Capture 2
    {   &IPC3,  _IPC3_IC3IS_POSITION,   _IPC3_IC3IP_POSITION    },  // Input Capture 3
    {   &IPC4,  _IPC4_IC4IS_POSITION,   _IPC4_IC4IP_POSITION    },  // Input Capture 4
    {   &IPC5,  _IPC5_IC5IS_POSITION,   _IPC5_IC5IP_POSITION    },  // Input Capture 5

    {   &IPC1,  _IPC1_IC1IS_POSITION,   _IPC1_IC1IP_POSITION    },  // Input Capture 1
    {   &IPC2,  _IPC2_IC2IS_POSITION,   _IPC2_IC2IP_POSITION    },  // Input Capture 2
    {   &IPC3,  _IPC3_IC3IS_POSITION,   _IPC3_IC3IP_POSITION    },  // Input Capture 3
    {   &IPC4,  _IPC4_IC4IS_POSITION,   _IPC4_IC4IP_POSITION    },  // Input Capture 4
    {   &IPC5,  _IPC5_IC5IS_POSITION,   _IPC5_IC5IP_POSITION    },  // Input Capture 5

    {   &IPC1, _IPC1_OC1IS_POSITION,   _IPC1_OC1IP_POSITION    },  // Output Capture 1
    {   &IPC2, _IPC2_OC2IS_POSITION,   _IPC2_OC2IP_POSITION    },  // Output Capture 2
    {   &IPC3, _IPC3_OC3IS_POSITION,   _IPC3_OC3IP_POSITION    },  // Output Capture 3
    {   &IPC4, _IPC4_OC4IS_POSITION,   _IPC4_OC4IP_POSITION    },  // Output Capture 4
    {   &IPC5, _IPC5_OC5IS_POSITION,   _IPC5_OC5IP_POSITION    },  // Output Capture 5


    {   &IPC6,  _IPC6_CNIS_POSITION,    _IPC6_CNIP_POSITION     },  // Input Change

/**********************************************************
 * SPI channel definitions
 ***********************************************************/
#ifdef _SPI1
    {   &IPC5,  _IPC5_SPI1IS_POSITION,      _IPC5_SPI1IP_POSITION       },  // SPI 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI2A)
    {   &IPC7,  _IPC7_SPI2AIS_POSITION,      _IPC7_SPI2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI1A)
    {   &IPC6,  _IPC6_SPI1AIS_POSITION,      _IPC6_SPI1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI3A)
    {   &IPC8,  _IPC8_SPI3AIS_POSITION,      _IPC8_SPI3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

/**********************************************************
 * SPI channel definitions Fault
 ***********************************************************/
#ifdef _SPI1
    {   &IPC5,  _IPC5_SPI1IS_POSITION,      _IPC5_SPI1IP_POSITION       },  // SPI 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI2A)
    {   &IPC7,  _IPC7_SPI2AIS_POSITION,      _IPC7_SPI2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI1A)
    {   &IPC6,  _IPC6_SPI1AIS_POSITION,      _IPC6_SPI1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI3A)
    {   &IPC8,  _IPC8_SPI3AIS_POSITION,      _IPC8_SPI3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

/**********************************************************
 * SPI channel definitions Tx
 ***********************************************************/
#ifdef _SPI1
    {   &IPC5,  _IPC5_SPI1IS_POSITION,      _IPC5_SPI1IP_POSITION       },  // SPI 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI2A)
    {   &IPC7,  _IPC7_SPI2AIS_POSITION,      _IPC7_SPI2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI1A)
    {   &IPC6,  _IPC6_SPI1AIS_POSITION,      _IPC6_SPI1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI3A)
    {   &IPC8,  _IPC8_SPI3AIS_POSITION,      _IPC8_SPI3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

/**********************************************************
 * SPI channel definitions Rx
 ***********************************************************/
#ifdef _SPI1
    {   &IPC5,  _IPC5_SPI1IS_POSITION,      _IPC5_SPI1IP_POSITION       },  // SPI 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI2A)
    {   &IPC7,  _IPC7_SPI2AIS_POSITION,      _IPC7_SPI2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI1A)
    {   &IPC6,  _IPC6_SPI1AIS_POSITION,      _IPC6_SPI1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_SPI3A)
    {   &IPC8,  _IPC8_SPI3AIS_POSITION,      _IPC8_SPI3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

/**********************************************************
 * I2C channel definitions 
 ***********************************************************/
#ifdef _I2C1
    {   &IPC6,  _IPC6_I2C1IS_POSITION,     _IPC6_I2C1IP_POSITION      },  // I2C1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _I2C2
    {   &IPC8,  _IPC8_I2C2IS_POSITION,      _IPC8_I2C2IP_POSITION      },  // I2C2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C1A)
    {   &IPC6,  _IPC6_I2C1AIS_POSITION,      _IPC6_I2C1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C2A)
    {   &IPC7,  _IPC7_I2C2AIS_POSITION,      _IPC7_I2C2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

#if defined(_I2C3A)
    {   &IPC8,  _IPC8_I2C3AIS_POSITION,      _IPC8_I2C3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * I2C channel definitions - Bus Colision 
 ***********************************************************/
#ifdef _I2C1
    {   &IPC6,  _IPC6_I2C1IS_POSITION,     _IPC6_I2C1IP_POSITION      },  // I2C1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _I2C2
    {   &IPC8,  _IPC8_I2C2IS_POSITION,      _IPC8_I2C2IP_POSITION      },  // I2C2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C1A)
    {   &IPC6,  _IPC6_I2C1AIS_POSITION,      _IPC6_I2C1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C2A)
    {   &IPC7,  _IPC7_I2C2AIS_POSITION,      _IPC7_I2C2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

#if defined(_I2C3A)
    {   &IPC8,  _IPC8_I2C3AIS_POSITION,      _IPC8_I2C3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * I2C channel definitions - Slave 
 ***********************************************************/
#ifdef _I2C1
    {   &IPC6,  _IPC6_I2C1IS_POSITION,     _IPC6_I2C1IP_POSITION      },  // I2C1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _I2C2
    {   &IPC8,  _IPC8_I2C2IS_POSITION,      _IPC8_I2C2IP_POSITION      },  // I2C2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C1A)
    {   &IPC6,  _IPC6_I2C1AIS_POSITION,      _IPC6_I2C1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C2A)
    {   &IPC7,  _IPC7_I2C2AIS_POSITION,      _IPC7_I2C2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

#if defined(_I2C3A)
    {   &IPC8,  _IPC8_I2C3AIS_POSITION,      _IPC8_I2C3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * I2C channel definitions - Master 
 ***********************************************************/
#ifdef _I2C1
    {   &IPC6,  _IPC6_I2C1IS_POSITION,     _IPC6_I2C1IP_POSITION      },  // I2C1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _I2C2
    {   &IPC8,  _IPC8_I2C2IS_POSITION,      _IPC8_I2C2IP_POSITION      },  // I2C2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C1A)
    {   &IPC6,  _IPC6_I2C1AIS_POSITION,      _IPC6_I2C1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_I2C2A)
    {   &IPC7,  _IPC7_I2C2AIS_POSITION,      _IPC7_I2C2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif

#if defined(_I2C3A)
    {   &IPC8,  _IPC8_I2C3AIS_POSITION,      _IPC8_I2C3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * UART channel definitions 
 ***********************************************************/
#if defined(_UART1A)
    {   &IPC6,  _IPC6_U1AIS_POSITION,      _IPC6_U1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART3A)
    {   &IPC8,  _IPC8_U3AIS_POSITION,      _IPC8_U3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART1B
    {   &IPC12,  _IPC12_U1BIS_POSITION,      _IPC12_U1BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART2A)
    {   &IPC7,  _IPC7_U2AIS_POSITION,      _IPC7_U2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART2B
    {   &IPC12,  _IPC12_U2BIS_POSITION,      _IPC12_U2BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART3B
    {   &IPC12,  _IPC12_U3BIS_POSITION,      _IPC12_U3BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * UART channel definitions - Error 
 ***********************************************************/
#if defined(_UART1A)
    {   &IPC6,  _IPC6_U1AIS_POSITION,      _IPC6_U1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART3A)
    {   &IPC8,  _IPC8_U3AIS_POSITION,      _IPC8_U3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART1B
    {   &IPC12,  _IPC12_U1BIS_POSITION,      _IPC12_U1BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART2A)
    {   &IPC7,  _IPC7_U2AIS_POSITION,      _IPC7_U2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART2B
    {   &IPC12,  _IPC12_U2BIS_POSITION,      _IPC12_U2BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART3B
    {   &IPC12,  _IPC12_U3BIS_POSITION,      _IPC12_U3BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * UART channel definitions - Rx 
 ***********************************************************/
#if defined(_UART1A)
    {   &IPC6,  _IPC6_U1AIS_POSITION,      _IPC6_U1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART3A)
    {   &IPC8,  _IPC8_U3AIS_POSITION,      _IPC8_U3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART1B
    {   &IPC12,  _IPC12_U1BIS_POSITION,      _IPC12_U1BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART2A)
    {   &IPC7,  _IPC7_U2AIS_POSITION,      _IPC7_U2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART2B
    {   &IPC12,  _IPC12_U2BIS_POSITION,      _IPC12_U2BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART3B
    {   &IPC12,  _IPC12_U3BIS_POSITION,      _IPC12_U3BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
/**********************************************************
 * UART channel definitions - Tx 
 ***********************************************************/
#if defined(_UART1A)
    {   &IPC6,  _IPC6_U1AIS_POSITION,      _IPC6_U1AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART3A)
    {   &IPC8,  _IPC8_U3AIS_POSITION,      _IPC8_U3AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART1B
    {   &IPC12,  _IPC12_U1BIS_POSITION,      _IPC12_U1BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#if defined(_UART2A)
    {   &IPC7,  _IPC7_U2AIS_POSITION,      _IPC7_U2AIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART2B
    {   &IPC12,  _IPC12_U2BIS_POSITION,      _IPC12_U2BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _UART3B
    {   &IPC12,  _IPC12_U3BIS_POSITION,      _IPC12_U3BIP_POSITION      },  
#else
    {   (VUINT *)0,  0,  0      },
#endif


    {   &IPC6,  _IPC6_AD1IS_POSITION,   _IPC6_AD1IP_POSITION    },  // ADC 1 Convert Done
    {   &IPC7,  _IPC7_PMPIS_POSITION,   _IPC7_PMPIP_POSITION    },  // Parallel Master Port
    {   &IPC7,  _IPC7_PMPIS_POSITION,   _IPC7_PMPIP_POSITION    },  // Parallel Master Port
    {   &IPC7,  _IPC7_CMP1IS_POSITION,  _IPC7_CMP1IP_POSITION   },  // Comparator 1 Interrupt
    {   &IPC7,  _IPC7_CMP2IS_POSITION,  _IPC7_CMP2IP_POSITION   },  // Comparator 2 Interrupt
    {   &IPC8,  _IPC8_FSCMIS_POSITION,  _IPC8_FSCMIP_POSITION   },  // Fail-safe Monitor
    {   &IPC11,  _IPC11_FCEIS_POSITION,  _IPC11_FCEIP_POSITION   },  // Flash Control Event
    {   &IPC8,  _IPC8_RTCCIS_POSITION,  _IPC8_RTCCIP_POSITION   },  // Real Time Clock


#ifdef _DMAC0
    {   &IPC9,  _IPC9_DMA0IS_POSITION,  _IPC9_DMA0IP_POSITION   },  // DMA Channel 0
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC1
    {   &IPC9,  _IPC9_DMA1IS_POSITION,  _IPC9_DMA1IP_POSITION   },  // DMA Channel 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC2
    {   &IPC9,  _IPC9_DMA2IS_POSITION,  _IPC9_DMA2IP_POSITION   },  // DMA Channel 2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC3
    {   &IPC9,  _IPC9_DMA3IS_POSITION,  _IPC9_DMA3IP_POSITION   },  // DMA Channel 3
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC4
    {   &IPC10, _IPC10_DMA4IS_POSITION, _IPC10_DMA4IP_POSITION  },  // DMA Channel 4
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC5
    {   &IPC10, _IPC10_DMA5IS_POSITION, _IPC10_DMA5IP_POSITION  },  // DMA Channel 5
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC6
    {   &IPC10, _IPC10_DMA6IS_POSITION, _IPC10_DMA6IP_POSITION  },  // DMA Channel 6
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _DMAC7
    {   &IPC10, _IPC10_DMA7IS_POSITION, _IPC10_DMA7IP_POSITION  },  // DMA Channel 7
#else
    {   (VUINT *)0,  0,  0      },
#endif

#ifdef _USB
    {   &IPC11, _IPC11_USBIS_POSITION,  _IPC11_USBIP_POSITION   },   // USB
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _CAN1
    {   &IPC11, _IPC11_CAN1IS_POSITION,  _IPC11_CAN1IP_POSITION   },  // CAN 1
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _CAN2
    {   &IPC11, _IPC11_CAN2IS_POSITION,  _IPC11_CAN2IP_POSITION   },   // CAN 2
#else
    {   (VUINT *)0,  0,  0      },
#endif
#ifdef _ETH
    {   &IPC12, _IPC12_ETHIS_POSITION,  _IPC12_ETHIP_POSITION   }   // Ethernat
#else
    {   (VUINT *)0,  0,  0      }
#endif
    // driver info
};


