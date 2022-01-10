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

#include "stdio.h"
#include "flash_drv.h"
#include "plib.h"
/** FUNCTIONS ******************************************************/


#define EMULATED_FLASH_SIZE 0x4000


static volatile unsigned char emulated_flash_space[32] __attribute__((section(".ota_flash_header_section"), space(prog)))  = { 
															0x00, 0x00, 0x4E, 0x00,	 /*Total flash size*/
															0x03, 0x00, 0x00, 0x00,	 /*Num of section*/
															
															0x00, 0x00, 0x04, 0x00,	 /*image size*/												
															0x01, 0x00, 0x00, 0x00,   /*Image count*/

															0x00, 0x00, 0x00, 0x00,	/*image size*/												
															0x00, 0x00, 0x00, 0x00,	/*Image count*/

															0x00, 0x00, 0x00, 0x00,	/*image size*/													
															0x00, 0x00, 0x00, 0x00,	/*Image count*/														
                                                         };





static volatile const unsigned char emulated_flash_metadata1_3C000[0x50] __attribute__((section(".ota_metadata1_section"), space(prog))) = { 
				0x4E, 0x00, 
				0x01,
				0x01, 0x10,
				0x13, 0x00,
				0x01,
				0x01, 0x00, 0x00, 0x00, 
				0x02, 0x00, 
				0x01, /*hardware revision*/
				0x01, /*security level*/
				0x11, 0xF1, 0xFF, 0xFF, /*section_image_id 0xFFFFF111*/
				0x00, 0x00, 0x04, 0x00, /*total_image_size*/
				0x01, 0x00, 0x00, 0x04, 0x00, 0xB0, 0x02, 0xBD, /*patch_section info*/
				0x02, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, /*app_header_section info*/
				0x03, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, /*app_section info*/
				0x6E, 0xB8, 0xEF, 0xDE, /*total_image_crc*/
				0x8C, 0xD7, 0x07, 0x4C, /*patch_crc*/
				0x66, 0x0F, 0x15, 0xCC, /*app_header_crc*/
				0xB4, 0x50, 0x05, 0x8C, /*app_crc*/
				0x01, 0x00, 0x00, 0x04, /*patch_downloaded_info*/
				0x02, 0x48, 0x00, 0x00, /*app_hdr_downloaded_info*/
				0x03, 0x70, 0xFF, 0x00, /*app_downloaded_info*/
				0x30, 0x3A, 0xB3, 0x5E	/*header crc*/													
                                                         };


static volatile const unsigned char emulated_flash_metadata1_3C100[0x50] __attribute__((section(".ota_metadata2_section"), space(prog))) = {  
				0x4E, 0x00, 
				0x01,
				0x01, 0x10,
				0x13, 0x00,
				0x01,
				0x01, 0x00, 0x00, 0x00, 
				0x02, 0x00, 
				0x01, /*hardware revision*/
				0x01, /*security level*/
				0x11, 0xF1, 0xFF, 0xFF, /*section_image_id 0xFFFFF111*/
				0x00, 0x00, 0x04, 0x00, /*total_image_size*/
				0x01, 0x00, 0x00, 0x04, 0x00, 0xB0, 0x02, 0xBD, /*patch_section info*/
				0x02, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, /*app_header_section info*/
				0x03, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, /*app_section info*/
				0x6E, 0xB8, 0xEF, 0xDE, /*total_image_crc*/
				0x8C, 0xD7, 0x07, 0x4C, /*patch_crc*/
				0x66, 0x0F, 0x15, 0xCC, /*app_header_crc*/
				0xB4, 0x50, 0x05, 0x8C, /*app_crc*/
				0x01, 0x00, 0x00, 0x04, /*patch_downloaded_info*/
				0x02, 0x48, 0x00, 0x00, /*app_hdr_downloaded_info*/
				0x03, 0x70, 0xFF, 0x00, /*app_downloaded_info*/
				0x30, 0x3A, 0xB3, 0x5E	/*header crc 0x5EB33A30*/												
                                                         };


uint8_t spi_flash_read(unsigned char *read_buf, unsigned long flash_addr, unsigned int size)
{
	unsigned int i;
    unsigned char *flashPtr = (unsigned char *)flash_addr;
	unsigned char *readbuf_local = read_buf;

    for(i = 0; i < size; i++)
	{
		*readbuf_local++ = *flashPtr++;
	}

    return 0;
}

uint8_t spi_flash_write(unsigned char *write_buf, unsigned long flash_addr, unsigned int size)
{
    unsigned int i;
    unsigned int wr_bytes = (size >> 2);
    unsigned int *dataPtr = (unsigned int *)write_buf;
    unsigned int *flashPtr = (unsigned int *)flash_addr;
    unsigned int flashDataWord = 0xFFFFFFFF;
	unsigned int tempDataWord = 0xFFFFFFFF;
      
    if(size & 0x03)
    {
        flashDataWord = flashDataWord & (dataPtr[wr_bytes]);
    }
	
    for(i = 0; i < wr_bytes; i++)
    {
    	memcpy((void *)&tempDataWord, write_buf, 4);
        NVMWriteWord((void*)flashPtr++, tempDataWord);
		write_buf = write_buf + 4;
    }
    if(flashDataWord != 0xFFFFFFFF)
        NVMWriteWord((void*)flashPtr++, flashDataWord);

	return 0;

}

uint8_t spi_flash_erase(unsigned int start_offset, unsigned int size)
{
    uint32_t status;

    while(size > 0)
    {
        status = NVMErasePage((void *)start_offset);
        if(status)
        {            
            continue;
        }
        if(size > 0x1000)
        {
            start_offset += 0x1000;
            size -= 0x1000;
        }
        else
        {
            size = 0;
        }        
    }
    return 0;
}

