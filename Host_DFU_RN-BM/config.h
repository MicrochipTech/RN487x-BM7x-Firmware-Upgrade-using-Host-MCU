/*
********************************************************************************

Software License Agreement

Copyright © 2018 Microchip Technology Inc. and its licensors.  All
rights reserved.

Microchip licenses to you the right to: (1) install Software on a single
computer and use the Software with Microchip microcontrollers and
digital signal controllers ("Microchip Product"); and (2) at your
own discretion and risk, use, modify, copy and distribute the device
driver files of the Software that are provided to you in Source Code;
provided that such Device Drivers are only used with Microchip Products
and that no open source or free software is incorporated into the Device
Drivers without Microchip's prior written consent in each instance.

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE
LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY,
CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY
DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR
LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

********************************************************************************
*/
#include "plib.h"


#define SYS_FREQ                    (80000000L)
#define	GetPeripheralClock()		(SYS_FREQ/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(SYS_FREQ)

#define GetUARTBaudrate()           (115200)

#define UART1M                      UART2
#define UART2M                      UART1
#define UART1_MODULE_ID             ((unsigned short)UART1M)
#define UART2_MODULE_ID             ((unsigned short)UART2M)

#define BUFFER_LEN_MAX              128

#define DBG_LOG_CONT                  printf

#define DBG_LOG_DEV							//
//#define DBG_LOG(...)                  {DBG_PRINT(__VA_ARGS__); UART_Write(UART1_MODULE_ID, (char*) "\r\n", 2);}
//#define DBG_LOG_2(...)                {DBG_PRINT(__VA_ARGS__);}

#define DBG_LOG(x)                  {UART_Write(UART1_MODULE_ID, (char*) x, strlen(x)); UART_Write(UART1_MODULE_ID, (char*) "\r\n", 2);}
#define DBG_LOG_2(x)                {UART_Write(UART1_MODULE_ID, (char*) x, strlen(x));}

#define BM_RST_DIR                  TRISGbits.TRISG1
#define BM_P20_DIR                  TRISBbits.TRISB1

#define BM_RST                      LATGbits.LATG1
#define BM_P20                      LATBbits.LATB1

#define BM_DIO                      {DDPCONbits.JTAGEN = 0; AD1PCFG = 0xFFFF;} 


#define BM_CTRL_INIT()              { BM_DIO; BM_RST_DIR = 0; BM_P20_DIR = 1; BM_RST = 0; }

#define BM_MODULE_ControlInit()     BM_CTRL_INIT()

#define BM_PROGRAM_MODE()    ({     uint32_t delay_cnt;                                         \
                                    BM_RST_DIR = 0;                                             \
                                    BM_RST = 0;                                                 \
                                    delay_cnt = 1800U;                                          \
                                    do                                                          \
                                    {                                                           \
                                        delay_cnt--;                                            \
                                    }while(delay_cnt);                                          \
                                    BM_P20_DIR = 0;                                             \
                                    BM_P20 = 0;                                                 \
                                    delay_cnt = 1800U;                                          \
                                    do                                                          \
                                    {                                                           \
                                        delay_cnt--;                                            \
                                    }while(delay_cnt);                                          \
                                    BM_RST_DIR = 1;                                             \
                                    delay_cnt = 1000000u;                                       \
                                    do                                                          \
                                    {                                                           \
                                        delay_cnt--;                                            \
                                    }while(delay_cnt);})                                          


#define BM_MODULE_ProgramModeSet()  BM_PROGRAM_MODE()

#define BM_MODULE_ProgramModeGet()  ((BM_P20_DIR == 0) ? 1 : 0)


#define BM_APPLICATION_MODE() ({    uint16_t delay_cnt;                                         \
                                    BM_RST_DIR = 0;                                             \
                                    BM_RST = 0;                                                 \
                                    delay_cnt = 1800U;                                          \
                                    do                                                          \
                                    {                                                           \
                                        delay_cnt--;                                            \
                                    }while(delay_cnt);                                          \
                                    BM_P20_DIR = 1;                                             \
                                    delay_cnt = 1800U;                                          \
                                    do                                                          \
                                    {                                                           \
                                        delay_cnt--;                                            \
                                    }while(delay_cnt);                                          \
                                    BM_RST_DIR = 1; })                                           
                                    

#define BM_MODULE_ApplicationModeSet()     BM_APPLICATION_MODE()

#define BM_MODULE_ApplicationModeGet() (((BM_P20_DIR) == 0) ? 0 : 1)

#define BM_RESET()            ({    BM_RST_DIR = 0;  											\
									BM_RST = 0;                                                 \
                                    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();     \
                                    BM_RST_DIR = 1;  })                                          



