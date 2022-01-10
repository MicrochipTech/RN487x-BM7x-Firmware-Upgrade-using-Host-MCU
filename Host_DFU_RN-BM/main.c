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
#include "platform_files.h"
#include "bm_application_mode.h"
#include "event_mem.h"
#include "ble_api.h"
#include "dfu_api.h"
#include "platform_pic.h"
#include "ble_manager.h"
#include "dfu_manager.h"
#include "main.h"

// SYSCLK = 80 MHz (8MHz Crystal / FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 80 MHz (SYSCLK / FPBDIV)
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_2

const uint8_t dfu_image[] = {
  #include "rn487x.txt"  
};

int main(void)
{
    uint16_t i=0;
    uint16_t cntr = 0;
    bool     rsdu = false;
    uint8_t str[32];
    
    // System configure and enable multi vectored interrupts
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    INTEnableSystemMultiVectoredInt();
	
	platform_init();
	
    DBG_LOG("---------------------------");
    DBG_LOG("DFU Demo");
    DBG_LOG("---------------------------");
	DBG_LOG("Initializing BLE Application");
	    
    if (dfu_mgr_init() != DFU_SUCCESS)
    {
        DBG_LOG("DFU failed");
        while(1); //Proof-of-concept DFU demo only. 
    }
        
    
    if (FLASH_TOTAL_SIZE%FLASH_CHUNK_SIZE == 0)
    {
        cntr = (FLASH_TOTAL_SIZE/FLASH_CHUNK_SIZE) - 1;
        rsdu = false;
    }
    else
    {
        cntr = FLASH_TOTAL_SIZE/FLASH_CHUNK_SIZE;
        rsdu = true;
    }
    
    dfu_mgr_update_start(0x00000000, (uint8_t*)dfu_image, FLASH_CHUNK_SIZE, FLASH_TOTAL_SIZE);
    dfu_mgr_update_verify(0x00000000, (uint8_t*)dfu_image, FLASH_CHUNK_SIZE);
    format_hex(str, i);
    DBG_LOG(str);
    for (i=1; i<cntr; i++)
    {   
        dfu_mgr_update_continue(((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_CHUNK_SIZE);
        dfu_mgr_update_verify((FLASH_CHUNK_SIZE*i), ((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_CHUNK_SIZE);
        format_hex(str, i);
        DBG_LOG(str);
    }
    if (rsdu)
    {
        dfu_mgr_update_stop(((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_TOTAL_SIZE - (FLASH_CHUNK_SIZE*i));
        dfu_mgr_update_verify((FLASH_CHUNK_SIZE*i), ((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_CHUNK_SIZE - (FLASH_CHUNK_SIZE*i));
    }
    else
    {
        dfu_mgr_update_stop(((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_CHUNK_SIZE);
        dfu_mgr_update_verify((FLASH_CHUNK_SIZE*i), ((uint8_t*)dfu_image)+(FLASH_CHUNK_SIZE*i), FLASH_CHUNK_SIZE);
    }
    format_hex(str, i);
    DBG_LOG(str);
    
    dfu_mgr_deinit();
    
    while(1);
}

