/********************************************************************
 * FileName:        int_tbl_lipb.c
 * Dependencies:
 * Processor:       PIC32
 * Hardware:        N/A
 * Assembler:       N/A
 * Linker:          N/A
 * Company:         Microchip Technology Inc..
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
    unsigned int    mask;
}INT_SCR_TBL_ENTRY;

const INT_SCR_TBL_ENTRY __IntSrcTbl[] =
{
    {   &IFS0,  &IEC0,  _IFS0_CTIF_MASK        },  // Core Timer Interrupt
	
    {   &IFS0,  &IEC0,  _IFS0_CS0IF_MASK       },  // Core Software Interrupt 0
    {   &IFS0,  &IEC0,  _IFS0_CS1IF_MASK       },  // Core Software Interrupt 1

    {   &IFS0,  &IEC0,  _IFS0_INT0IF_MASK      },  // External Interrupt 0
    {   &IFS0,  &IEC0,  _IFS0_INT1IF_MASK      },  // External Interrupt 1
    {   &IFS0,  &IEC0,  _IFS0_INT2IF_MASK      },  // External Interrrupt 2
    {   &IFS0,  &IEC0,  _IFS0_INT3IF_MASK      },  // External Interrupt 3
    {   &IFS0,  &IEC0,  _IFS0_INT4IF_MASK      },  // External Interupt 4

    {   &IFS0,  &IEC0,  _IFS0_T1IF_MASK        },  // Timer 1
    {   &IFS0,  &IEC0,  _IFS0_T2IF_MASK        },  // Timer 2
    {   &IFS0,  &IEC0,  _IFS0_T3IF_MASK        },  // TImer 3
    {   &IFS0,  &IEC0,  _IFS0_T4IF_MASK        },  // Timer 4
    {   &IFS0,  &IEC0,  _IFS0_T5IF_MASK        },  // Timer 5

    {   &IFS0,  &IEC0,  _IFS0_IC1EIF_MASK      },  // Input Capture Error 1
    {   &IFS0,  &IEC0,  _IFS0_IC2EIF_MASK      },  // Input Capture Error 2
    {   &IFS0,  &IEC0,  _IFS0_IC3EIF_MASK      },  // Input Capture Error 3
    {   &IFS0,  &IEC0,  _IFS0_IC4EIF_MASK      },  // Input Capture Error 4
    {   &IFS0,  &IEC0,  _IFS0_IC5EIF_MASK      },  // Input Capture Error 5

    {   &IFS0,  &IEC0,  _IFS0_IC1IF_MASK       },  // Input Capture 1
    {   &IFS0,  &IEC0,  _IFS0_IC2IF_MASK       },  // Input Capture 2
    {   &IFS0,  &IEC0,  _IFS0_IC3IF_MASK       },  // Input Capture 3
    {   &IFS0,  &IEC0,  _IFS0_IC4IF_MASK       },  // Input Capture 4
    {   &IFS0,  &IEC0,  _IFS0_IC5IF_MASK       },  // Input Capture 5

    {   &IFS0,  &IEC0,  _IFS0_OC1IF_MASK       },  // Output Capture 1
    {   &IFS0,  &IEC0,  _IFS0_OC2IF_MASK       },  // Output Capture 2
    {   &IFS0,  &IEC0,  _IFS0_OC3IF_MASK       },  // Output Capture 3
    {   &IFS0,  &IEC0,  _IFS0_OC4IF_MASK       },  // Output Capture 4
    {   &IFS0,  &IEC0,  _IFS0_OC5IF_MASK       },  // Output Capture 5

	{   &IFS1,  &IEC1,  _IFS1_CNAIF_MASK       },  // Input Change,Port A
    {   &IFS1,  &IEC1,  _IFS1_CNBIF_MASK       },  // Input Change,Port B
    {   &IFS1,  &IEC1,  _IFS1_CNCIF_MASK       },  // Input Change,Port C
	
    {   &IFS1,  &IEC1,  (_IFS1_SPI1EIF_MASK | _IFS1_SPI1TXIF_MASK | _IFS1_SPI1RXIF_MASK)       }, //SPI1
	{   &IFS1,  &IEC1,  (_IFS1_SPI2EIF_MASK | _IFS1_SPI2TXIF_MASK | _IFS1_SPI2RXIF_MASK)       }, //SPI2
	
	{   &IFS1,  &IEC1,  _IFS1_SPI1EIF_MASK     },  // SPI 1 Error
	{   &IFS1,  &IEC1,  _IFS1_SPI2EIF_MASK     },  // SPI 2 Error
    
    {   &IFS1,  &IEC1,  _IFS1_SPI1TXIF_MASK    },  // SPI 1 Transmit Done	
	{   &IFS1,  &IEC1,  _IFS1_SPI2TXIF_MASK    },  // SPI 2 Transmit Done

	{   &IFS1,  &IEC1,  _IFS1_SPI1RXIF_MASK    },  // SPI 1 Receive  Done
    {   &IFS1,  &IEC1,  _IFS1_SPI2RXIF_MASK    },  // SPI 2 Receive  Done
   
    {   &IFS1,  &IEC1,  (_IFS1_I2C1BIF_MASK | _IFS1_I2C1SIF_MASK | _IFS1_I2C1MIF_MASK)      }, //I2C1
	{   &IFS1,  &IEC1,  (_IFS1_I2C2BIF_MASK | _IFS1_I2C2SIF_MASK | _IFS1_I2C2MIF_MASK)      }, //I2C2

    {   &IFS1,  &IEC1,  _IFS1_I2C1BIF_MASK     },  // I2C 1 Bus Colision Event
	{   &IFS1,  &IEC1,  _IFS1_I2C2BIF_MASK     },  // I2C 2 Bus Colision Event
	
    {   &IFS1,  &IEC1,  _IFS1_I2C1SIF_MASK     },  // I2C 1 Slave Event
	{   &IFS1,  &IEC1,  _IFS1_I2C2SIF_MASK     },  // I2C 2 Slave Event
	
    {   &IFS1,  &IEC1,  _IFS1_I2C1MIF_MASK     },  // I2C 1 Master Event  
	{   &IFS1,  &IEC1,  _IFS1_I2C2MIF_MASK     },  // I2C 2 Master Event
	
    {   &IFS1,  &IEC1,  (_IFS1_U1EIF_MASK | _IFS1_U1RXIF_MASK | _IFS1_U1TXIF_MASK)}, //UART1
	{   &IFS1,  &IEC1,  (_IFS1_U2EIF_MASK | _IFS1_U2RXIF_MASK | _IFS1_U2TXIF_MASK)}, //UART2
	
    {   &IFS1,  &IEC1,  _IFS1_U1EIF_MASK       },  // UART 1 Error
	{   &IFS1,  &IEC1,  _IFS1_U2EIF_MASK       },  // UART 2 Error
	
    {   &IFS1,  &IEC1,  _IFS1_U1RXIF_MASK      },  // UART 1 Receive
	{   &IFS1,  &IEC1,  _IFS1_U2RXIF_MASK      },  // UART 2 Receive
	
    {   &IFS1,  &IEC1,  _IFS1_U1TXIF_MASK      },  // UART 1 Transmit
    {   &IFS1,  &IEC1,  _IFS1_U2TXIF_MASK      },  // UART 2 Transmit
	
	{   &IFS0,  &IEC0,  _IFS0_AD1IF_MASK       },  // ADC 1 Convert Done

    {   &IFS1,  &IEC1,  _IFS1_PMPIF_MASK       },  // Parallel Master Port
    {   &IFS1,  &IEC1,  _IFS1_PMPEIF_MASK      },  // Parallel Master Port Error
	
    {   &IFS1,  &IEC1,  _IFS1_CMP1IF_MASK      },  // Comparator 1 Interrupt
    {   &IFS1,  &IEC1,  _IFS1_CMP2IF_MASK      },  // Comparator 2 Interrupt
    {   &IFS1,  &IEC1,  _IFS1_CMP3IF_MASK      },  // Comparator 3 Interrupt
	
	{   &IFS0,  &IEC0,  _IFS0_FSCMIF_MASK      },  // Fail-safe Monitor
	
	{   &IFS0,  &IEC0,  _IFS0_FCEIF_MASK       },  // Flash Control Event
	
    {   &IFS0,  &IEC0,  _IFS0_RTCCIF_MASK      },  // Real Time Clock
    
    {   &IFS1,  &IEC1,  _IFS1_CTMUIF_MASK      },  // CTMU
	
    {   &IFS1,  &IEC1,  _IFS1_DMA0IF_MASK      },  // DMA Channel 0
    {   &IFS1,  &IEC1,  _IFS1_DMA1IF_MASK      },  // DMA Channel 1
    {   &IFS1,  &IEC1,  _IFS1_DMA2IF_MASK      },  // DMA Channel 2
    {   &IFS1,  &IEC1,  _IFS1_DMA3IF_MASK      },  // DMA Channel 3

#   ifdef _USB
    {   &IFS1,  &IEC1,  _IFS1_USBIF_MASK       },  // USB
#   else
    {   (VUINT *)0, (VUINT *)0,   0      },
#   endif

    // driver info
};

typedef struct
{
    VUINT           *ipc;
    unsigned int    sub_shift;
    unsigned int    pri_shift;
}INT_VECTOR_TBL_ENTRY;

const INT_VECTOR_TBL_ENTRY __IntVectorTbl[] =
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
	{   &IPC3, _IPC3_T3IS_POSITION,    _IPC3_T3IP_POSITION     },  // T1mer 3
	{   &IPC4, _IPC4_T4IS_POSITION,    _IPC4_T4IP_POSITION     },  // Timer 4
	{   &IPC5, _IPC5_T5IS_POSITION,    _IPC5_T5IP_POSITION     },  // Timer 5
	
    {   &IPC1, _IPC1_IC1IS_POSITION,   _IPC1_IC1IP_POSITION    },  // Input Capture 1
	{   &IPC2, _IPC2_IC2IS_POSITION,   _IPC2_IC2IP_POSITION    },  // Input Capture 2
	{   &IPC3, _IPC3_IC3IS_POSITION,   _IPC3_IC3IP_POSITION    },  // Input Capture 3
	{   &IPC4, _IPC4_IC4IS_POSITION,   _IPC4_IC4IP_POSITION    },  // Input Capture 4
	{   &IPC5, _IPC5_IC5IS_POSITION,   _IPC5_IC5IP_POSITION    },  // Input Capture 5
	
    {   &IPC1, _IPC1_OC1IS_POSITION,   _IPC1_OC1IP_POSITION    },  // Output Capture 1
    {   &IPC2, _IPC2_OC2IS_POSITION,   _IPC2_OC2IP_POSITION    },  // Output Capture 2
    {   &IPC3, _IPC3_OC3IS_POSITION,   _IPC3_OC3IP_POSITION    },  // Output Capture 3
    {   &IPC4, _IPC4_OC4IS_POSITION,   _IPC4_OC4IP_POSITION    },  // Output Capture 4
    {   &IPC5, _IPC5_OC5IS_POSITION,   _IPC5_OC5IP_POSITION    },  // Output Capture 5

	{   &IPC7,  _IPC7_SPI1IS_POSITION, _IPC7_SPI1IP_POSITION   },  // SPI 1
	{   &IPC9,  _IPC9_SPI2IS_POSITION, _IPC9_SPI2IP_POSITION   },  // SPI 2

	{   &IPC8,  _IPC8_U1IS_POSITION,   _IPC8_U1IP_POSITION     },  // UART 1	
	{   &IPC9,  _IPC9_U2IS_POSITION,   _IPC9_U2IP_POSITION     },  // UART 2
	
	{   &IPC8,  _IPC8_I2C1IS_POSITION, _IPC8_I2C1IP_POSITION   },  // I2C1
	{   &IPC9,  _IPC9_I2C2IS_POSITION, _IPC9_I2C2IP_POSITION   },  // I2C2
	
	{   &IPC8,  _IPC8_CNIS_POSITION,   _IPC8_CNIP_POSITION     },  // Input Change
    {   &IPC5,  _IPC5_AD1IS_POSITION,  _IPC5_AD1IP_POSITION    },  // ADC 1 Convert Done
	{   &IPC8,  _IPC8_PMPIS_POSITION,  _IPC8_PMPIP_POSITION    },  // Parallel Master Port

	{   &IPC6, _IPC6_CMP1IS_POSITION,  _IPC6_CMP1IP_POSITION   },  // Comparator 1 Interrupt
    {   &IPC7, _IPC7_CMP2IS_POSITION,  _IPC7_CMP2IP_POSITION   },  // Comparator 2 Interrupt
    {   &IPC7, _IPC7_CMP3IS_POSITION,  _IPC7_CMP3IP_POSITION   },  // Comparator 3 Interrupt
	
    {   &IPC6, _IPC6_FSCMIS_POSITION,  _IPC6_FSCMIP_POSITION   },  // Fail-safe Monitor
    {   &IPC6, _IPC6_RTCCIS_POSITION,  _IPC6_RTCCIP_POSITION   },  // Real Time Clock
	
	{   &IPC9,  _IPC9_CTMUIS_POSITION, _IPC9_CTMUIP_POSITION   },  // Parallel Master Port

    {   &IPC10, _IPC10_DMA0IS_POSITION,_IPC10_DMA0IP_POSITION  },  // DMA Channel 0
    {   &IPC10, _IPC10_DMA1IS_POSITION,_IPC10_DMA1IP_POSITION  },  // DMA Channel 1
    {   &IPC10, _IPC10_DMA2IS_POSITION,_IPC10_DMA2IP_POSITION  },  // DMA Channel 2
    {   &IPC10, _IPC10_DMA3IS_POSITION,_IPC10_DMA3IP_POSITION  },  // DMA Channel 
	
    {   &IPC6, _IPC6_FCEIS_POSITION,   _IPC6_FCEIP_POSITION    },  // Flash Control Event

#   ifdef _USB
    {   &IPC7, _IPC7_USBIS_POSITION,   _IPC7_USBIP_POSITION    },  // USB
#   else
    {   (VUINT *)0,  0,  0      },
#   endif
};
