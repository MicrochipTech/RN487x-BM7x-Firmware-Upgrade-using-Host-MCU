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
    VUINT           *ifs;
    VUINT           *iec;
    VUINT           *ipc;
    unsigned int    mask;
    unsigned int    sub_shift;
    unsigned int    pri_shift;
}INT_TBL_ENTRY;

const INT_TBL_ENTRY __IntTbl[] =
{
    {   &IFS0,  &IEC0,  &IPC0,  _IFS0_CTIF_MASK,        _IPC0_CTIS_POSITION,    _IPC0_CTIP_POSITION     },  // Core Timer Interrupt
    {   &IFS0,  &IEC0,  &IPC0,  _IFS0_CS0IF_MASK,       _IPC0_CS0IS_POSITION,   _IPC0_CS0IP_POSITION    },  // Core Software Interrupt 0
    {   &IFS0,  &IEC0,  &IPC0,  _IFS0_CS1IF_MASK,       _IPC0_CS1IS_POSITION,   _IPC0_CS1IP_POSITION    },  // Core Software Interrupt 1

    {   &IFS0,  &IEC0,  &IPC0,  _IFS0_INT0IF_MASK,      _IPC0_INT0IS_POSITION,  _IPC0_INT0IP_POSITION   },  // External Interrupt 0
    {   &IFS0,  &IEC0,  &IPC1,  _IFS0_INT1IF_MASK,      _IPC1_INT1IS_POSITION,  _IPC1_INT1IP_POSITION   },  // External Interrupt 1
    {   &IFS0,  &IEC0,  &IPC2,  _IFS0_INT2IF_MASK,      _IPC2_INT2IS_POSITION,  _IPC2_INT2IP_POSITION   },  // External Interrrupt 2
    {   &IFS0,  &IEC0,  &IPC3,  _IFS0_INT3IF_MASK,      _IPC3_INT3IS_POSITION,  _IPC3_INT3IP_POSITION   },  // External Interrupt 3
    {   &IFS0,  &IEC0,  &IPC4,  _IFS0_INT4IF_MASK,      _IPC4_INT4IS_POSITION,  _IPC4_INT4IP_POSITION   },  // External Interupt 4

    {   &IFS0,  &IEC0,  &IPC1,  _IFS0_T1IF_MASK,        _IPC1_T1IS_POSITION,    _IPC1_T1IP_POSITION     },  // Timer 1
    {   &IFS0,  &IEC0,  &IPC2,  _IFS0_T2IF_MASK,        _IPC2_T2IS_POSITION,    _IPC2_T2IP_POSITION     },  // Timer 2
    {   &IFS0,  &IEC0,  &IPC3,  _IFS0_T3IF_MASK,        _IPC3_T3IS_POSITION,    _IPC3_T3IP_POSITION     },  // TImer 3
    {   &IFS0,  &IEC0,  &IPC4,  _IFS0_T4IF_MASK,        _IPC4_T4IS_POSITION,    _IPC4_T4IP_POSITION     },  // Timer 4
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_T5IF_MASK,        _IPC5_T5IS_POSITION,    _IPC5_T5IP_POSITION     },  // Timer 5

    {   &IFS0,  &IEC0,  &IPC1,  _IFS0_IC1IF_MASK,       _IPC1_IC1IS_POSITION,   _IPC1_IC1IP_POSITION    },  // Input Capture 1
    {   &IFS0,  &IEC0,  &IPC2,  _IFS0_IC2IF_MASK,       _IPC2_IC2IS_POSITION,   _IPC2_IC2IP_POSITION    },  // Input Capture 2
    {   &IFS0,  &IEC0,  &IPC3,  _IFS0_IC3IF_MASK,       _IPC3_IC3IS_POSITION,   _IPC3_IC3IP_POSITION    },  // Input Capture 3
    {   &IFS0,  &IEC0,  &IPC4,  _IFS0_IC4IF_MASK,       _IPC4_IC4IS_POSITION,   _IPC4_IC4IP_POSITION    },  // Input Capture 4
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_IC5IF_MASK,       _IPC5_IC5IS_POSITION,   _IPC5_IC5IP_POSITION    },  // Input Capture 5

    {   &IFS0,  &IEC0,  &IPC1,  _IFS0_OC1IF_MASK,       _IPC1_OC1IS_POSITION,   _IPC1_OC1IP_POSITION    },  // Output Capture 1
    {   &IFS0,  &IEC0,  &IPC2,  _IFS0_OC2IF_MASK,       _IPC2_OC2IS_POSITION,   _IPC2_OC2IP_POSITION    },  // Output Capture 2
    {   &IFS0,  &IEC0,  &IPC3,  _IFS0_OC3IF_MASK,       _IPC3_OC3IS_POSITION,   _IPC3_OC3IP_POSITION    },  // Output Capture 3
    {   &IFS0,  &IEC0,  &IPC4,  _IFS0_OC4IF_MASK,       _IPC4_OC4IS_POSITION,   _IPC4_OC4IP_POSITION    },  // Output Capture 4
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_OC5IF_MASK,       _IPC5_OC5IS_POSITION,   _IPC5_OC5IP_POSITION    },  // Output Capture 5

    {   &IFS1,  &IEC1,  &IPC6,  _IFS1_CNIF_MASK,        _IPC6_CNIS_POSITION,    _IPC6_CNIP_POSITION     },  // Input Change

#ifdef _SPI1
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_SPI1EIF_MASK,     _IPC5_SPI1IS_POSITION,  _IPC5_SPI1IP_POSITION   },  // SPI 1 Fault
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI2
    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_SPI2EIF_MASK,     _IPC7_SPI2IS_POSITION,  _IPC7_SPI2IP_POSITION   },  // SPI 2 Fault
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI1
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_SPI1TXIF_MASK,    _IPC5_SPI1IS_POSITION,  _IPC5_SPI1IP_POSITION   },  // SPI 1 Transfer Done
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI2
    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_SPI2TXIF_MASK,    _IPC7_SPI2IS_POSITION,  _IPC7_SPI2IP_POSITION   },  // SPI 2 Transfer Done
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI1
    {   &IFS0,  &IEC0,  &IPC5,  _IFS0_SPI1RXIF_MASK,    _IPC5_SPI1IS_POSITION,  _IPC5_SPI1IP_POSITION   },  // SPI 1 Receive Done
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI2
    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_SPI2RXIF_MASK,    _IPC7_SPI2IS_POSITION,  _IPC7_SPI2IP_POSITION   },  // SPI 2 Receive Done
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI1
    {   &IFS0,  &IEC0,  &IPC5,  (_IFS0_SPI1EIF_MASK | _IFS0_SPI1TXIF_MASK | _IFS0_SPI1RXIF_MASK), _IPC5_SPI1IS_POSITION,      _IPC5_SPI1IP_POSITION       },  // SPI 1
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _SPI2
    {   &IFS1,  &IEC1,  &IPC7,  (_IFS1_SPI2EIF_MASK | _IFS1_SPI2TXIF_MASK | _IFS1_SPI2RXIF_MASK), _IPC7_SPI2IS_POSITION,     _IPC7_SPI2IP_POSITION      },  // SPI 2
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif

    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_U1EIF_MASK,       _IPC6_U1IS_POSITION,    _IPC6_U1IP_POSITION     },  // UART 1 Error
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_U2EIF_MASK,       _IPC8_U2IS_POSITION,    _IPC8_U2IP_POSITION     },  // UART 2 Error
    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_U1RXIF_MASK,      _IPC6_U1IS_POSITION,    _IPC6_U1IP_POSITION     },  // UART 1 Receiver
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_U2RXIF_MASK,      _IPC8_U2IS_POSITION,    _IPC8_U2IP_POSITION     },  // UART 2 Receiver
    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_U1TXIF_MASK,      _IPC6_U1IS_POSITION,    _IPC6_U1IP_POSITION     },  // UART 1 Transmitter
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_U2TXIF_MASK,      _IPC8_U2IS_POSITION,    _IPC8_U2IP_POSITION     },  // UART 2 Transmitter
    {   &IFS0,  &IEC0,  &IPC6,  (_IFS0_U1EIF_MASK | _IFS0_U1RXIF_MASK | _IFS0_U1TXIF_MASK), _IPC6_U1IS_POSITION,      _IPC6_U1IP_POSITION      },  // UART 1
    {   &IFS1,  &IEC1,  &IPC8,  (_IFS1_U2EIF_MASK | _IFS1_U2RXIF_MASK | _IFS1_U2TXIF_MASK), _IPC8_U2IS_POSITION,      _IPC8_U2IP_POSITION       },  // UART 2

#ifdef _I2C1
    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_I2C1BIF_MASK,     _IPC6_I2C1IS_POSITION,  _IPC6_I2C1IP_POSITION   },  // I2C 1 Bus Colision Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C2
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_I2C2BIF_MASK,     _IPC8_I2C2IS_POSITION,  _IPC8_I2C2IP_POSITION   },  // I2C 2 Bus Colision Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C1
    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_I2C1SIF_MASK,     _IPC6_I2C1IS_POSITION,  _IPC6_I2C1IP_POSITION   },  // I2C 1 Slave Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C2
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_I2C2SIF_MASK,     _IPC8_I2C2IS_POSITION,  _IPC8_I2C2IP_POSITION   },  // I2C 2 Slave Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C1
    {   &IFS0,  &IEC0,  &IPC6,  _IFS0_I2C1MIF_MASK,     _IPC6_I2C1IS_POSITION,  _IPC6_I2C1IP_POSITION   },  // I2C 1 Master Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C2
    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_I2C2MIF_MASK,     _IPC8_I2C2IS_POSITION,  _IPC8_I2C2IP_POSITION   },  // I2C 2 Master Event
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C1
    {   &IFS0,  &IEC0,  &IPC6,  (_IFS0_I2C1BIF_MASK | _IFS0_I2C1SIF_MASK | _IFS0_I2C1MIF_MASK), _IPC6_I2C1IS_POSITION,     _IPC6_I2C1IP_POSITION      },  // I2C1
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _I2C2
    {   &IFS1,  &IEC1,  &IPC8,  (_IFS1_I2C2BIF_MASK | _IFS1_I2C2SIF_MASK | _IFS1_I2C2MIF_MASK), _IPC8_I2C2IS_POSITION,      _IPC8_I2C2IP_POSITION      },  // I2C2
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif

    {   &IFS1,  &IEC1,  &IPC6,  _IFS1_AD1IF_MASK,       _IPC6_AD1IS_POSITION,   _IPC6_AD1IP_POSITION    },  // ADC 1 Convert Done

    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_PMPIF_MASK,       _IPC7_PMPIS_POSITION,   _IPC7_PMPIP_POSITION    },  // Parallel Master Port

    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_CMP1IF_MASK,      _IPC7_CMP1IS_POSITION,  _IPC7_CMP1IP_POSITION   },  // Comparator 1 Interrupt
    {   &IFS1,  &IEC1,  &IPC7,  _IFS1_CMP2IF_MASK,      _IPC7_CMP2IS_POSITION,  _IPC7_CMP2IP_POSITION   },  // Comparator 2 Interrupt

    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_FSCMIF_MASK,      _IPC8_FSCMIS_POSITION,  _IPC8_FSCMIP_POSITION   },  // Fail-safe Monitor

    {   &IFS1,  &IEC1,  &IPC11,  _IFS1_FCEIF_MASK,      _IPC11_FCEIS_POSITION,  _IPC11_FCEIP_POSITION   },  // Flash Control Event

    {   &IFS1,  &IEC1,  &IPC8,  _IFS1_RTCCIF_MASK,      _IPC8_RTCCIS_POSITION,  _IPC8_RTCCIP_POSITION   },  // Real Time Clock

#ifdef _DMAC0
    {   &IFS1,  &IEC1,  &IPC9,  _IFS1_DMA0IF_MASK,      _IPC9_DMA0IS_POSITION,  _IPC9_DMA0IP_POSITION   },  // DMA Channel 0
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC1
    {   &IFS1,  &IEC1,  &IPC9,  _IFS1_DMA1IF_MASK,      _IPC9_DMA1IS_POSITION,  _IPC9_DMA1IP_POSITION   },  // DMA Channel 1
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC2
    {   &IFS1,  &IEC1,  &IPC9,  _IFS1_DMA2IF_MASK,      _IPC9_DMA2IS_POSITION,  _IPC9_DMA2IP_POSITION   },  // DMA Channel 2
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC3
    {   &IFS1,  &IEC1,  &IPC9,  _IFS1_DMA3IF_MASK,      _IPC9_DMA3IS_POSITION,  _IPC9_DMA3IP_POSITION   },  // DMA Channel 3
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC4
    {   &IFS1,  &IEC1,  &IPC10, _IFS1_DMA4IF_MASK,      _IPC10_DMA4IS_POSITION, _IPC10_DMA4IP_POSITION  },  // DMA Channel 4
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC5
    {   &IFS1,  &IEC1,  &IPC10, _IFS1_DMA5IF_MASK,      _IPC10_DMA5IS_POSITION, _IPC10_DMA5IP_POSITION  },  // DMA Channel 5
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC6
    {   &IFS1,  &IEC1,  &IPC10, _IFS1_DMA6IF_MASK,      _IPC10_DMA6IS_POSITION, _IPC10_DMA6IP_POSITION  },  // DMA Channel 6
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _DMAC7
    {   &IFS1,  &IEC1,  &IPC10, _IFS1_DMA7IF_MASK,      _IPC10_DMA7IS_POSITION, _IPC10_DMA7IP_POSITION  },  // DMA Channel 7
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      },
#endif
#ifdef _USB
    {   &IFS1,  &IEC1,  &IPC11, _IFS1_USBIF_MASK,       _IPC11_USBIS_POSITION,  _IPC11_USBIP_POSITION   }   // USB
#else
    {   (VUINT *)0, (VUINT *)0, (VUINT *)0,  0, 0,  0      }
#endif
    // driver info
};


void INTClearFlag(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    tbl->ifs[SFR_CLR] 	= tbl->mask;
}
void INTSetFlag(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    tbl->ifs[SFR_SET] 	= tbl->mask;

}
unsigned int INTGetFlag(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    return (*tbl->ifs &  tbl->mask);
}

void INTEnable(INT_SOURCE source, unsigned int enable)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;

    if(enable)
        tbl->iec[SFR_SET] 	= tbl->mask;
    else
        tbl->iec[SFR_CLR] 	= tbl->mask;
}
unsigned int INTGetEnable(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    return (*tbl->iec &  tbl->mask);
}
void INTSetPriority(INT_SOURCE source, unsigned int priority)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;

    tbl->ipc[SFR_CLR]   = (7 << tbl->pri_shift);
    priority            <<= tbl->pri_shift;
    tbl->ipc[SFR_SET]   = priority;

}
unsigned int INTGetPriority(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    return (*tbl->ipc >>  tbl->pri_shift);
}
void INTSetSubPriority(INT_SOURCE source, unsigned int subPriority)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    tbl->ipc[SFR_CLR]   = (2 << tbl->sub_shift);
    subPriority         <<= tbl->sub_shift;
    tbl->ipc[SFR_SET]   = subPriority;

}
unsigned int INTGetSubPriority(INT_SOURCE source)
{
    INT_TBL_ENTRY   *tbl;

    tbl        			= (INT_TBL_ENTRY *)__IntTbl + source;
    return (*tbl->ipc >>  tbl->sub_shift);
}
