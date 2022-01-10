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

//#include "platform_files.h"
#include "bm_utils.h"
#include "bm_lib_version.h"

uint16_t BM_ConfigurationLibraryVersion(void)
{
		return(BM_CONFIGURATION_LIBRARY_VERSION);
}

uint8_t set_to_upper(uint8_t lower)
{
	if((lower >= 'a') && (lower <= 'z'))
        	return ('A'+lower-'a');
    	else
        	return lower;
}


uint8_t get_hex_byte(uint8_t * str, uint8_t * val)
{
	uint8_t x,y,z;
	z=0;

	for (x=0;x<2;x++)
	{
		y = set_to_upper(str[x]);
		z = z << 4;
		if ( (y >= '0') && (y <= '9') )
			z+= y -48;
		else
			if ( (y >= 'A') && (y <= 'F') )
				z+= y -55;
			else
				return 0;
        }

	*val=z;
	return 1;

}

uint8_t get_hex(uint8_t * str, uint16_t * val)
{
	uint8_t x,y;
	uint16_t z=0;

	for (x=0;x<3;x+=2)
	{
		if ( ! get_hex_byte(&str[x],&y)  )
			return 0;
		z= (z << 8) + y;
	}

	*val=z;
	return 1;

}

uint8_t get_hex_24bit(uint8_t * str, uint32_t * val)
{
	uint8_t x,y;
	uint32_t z=0;

	for (x=0;x<5;x+=2)
	{
		if ( ! get_hex_byte(&str[x],&y)  )
			return 0;
		z= (z << 8) + y;
	}

	*val=z;
	return 1;

}

uint8_t get_hex_bdaddrs(uint8_t * str, uint64_t * val)
{
	uint8_t x,y;
	uint64_t z=0;
	for (x=0;x<11;x+=2)
	{
		if ( ! get_hex_byte(&str[x],&y)  )
			return 0;
		z= (z << 8) + y;
	}

	*val=z;
	return 1;

}

uint8_t get_hex_long(uint8_t * str, uint64_t * val)
{
	uint8_t x,y;
	uint64_t z=0;

	for (x=0;x<16;x+=2)
	{
		if ( ! get_hex_byte(&str[x],&y)  )
			return 0;
		z= (z << 8) + y;
	}

	*val=z;
	return 1;

}


uint8_t get_hex_dword(uint8_t * str, uint32_t * val)
{
	uint8_t x,y;
	uint32_t z=0;

	for (x=0;x<7;x+=2)
	{
		if ( ! get_hex_byte(&str[x],&y)  )
			return 0;
		z= (z << 8) + y;
	}

	*val=z;
	return 1;

}

void format_hex_byte(uint8_t * str, uint8_t val)
{
    uint8_t x,y;

    for (x=0;x<2;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[1-x] = y + 55;
        else
            str[1-x] = y + 48;

        val = val >> 4;
    }
    str[2]=0;
}

void format_hex_byte2(uint8_t * str, uint8_t val)
{
    uint8_t x,y;

    for (x=0;x<2;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[1-x] = y + 55;
        else
            str[1-x] = y + 48;

        val = val >> 4;
    }
}

void format_hex(uint8_t * str, uint16_t val)
{
    uint8_t x,y;

    for (x=0;x<4;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[3-x] =y +55;
        else
            str[3-x] =y +48;

        val = val >> 4;
    }
    str[4]=0;
}

void format_hex_24bit(uint8_t * str, uint32_t val)
{
    uint8_t x,y;

    for (x=0;x<6;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[5-x] =y +55;
        else
            str[5-x] =y +48;

        val = val >> 4;
    }
    str[6]=0;
}

void format_hex_bdaddrs(uint8_t * str, uint64_t val)
{
    uint8_t x,y;
    for (x=0;x<12;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[15-x] =y +55;
        else
            str[15-x] =y +48;

        val = val >> 4;
    }
    str[16]=0;
}


void format_hex_bdaddrs2(uint8_t * str, uint8_t* val)
{
    uint8_t x,y,byte;
    uint8_t* temp = val;
    for (x=0;x<12;x+=2)
    {
        byte = temp[x/2];
        
        y = byte & 0xf;
        if ( y > 9 )
            str[11-x] =y +55;
        else
            str[11-x] =y +48;

        byte = byte >> 4;
        
        y = byte & 0xf;
        if ( y > 9 )
            str[11-x-1] =y +55;
        else
            str[11-x-1] =y +48;
        
    }
    str[12]=0;
}

void format_hex_long(uint8_t * str, uint64_t val)
{
    uint8_t x,y;
    for (x=0;x<16;x++)
    {
        y = val & 0xf;
        if ( y > 9 )
            str[15-x] =y +55;
        else
            str[15-x] =y +48;

        val = val >> 4;
    }
}

void memcpy_ascii_reorder(uint8_t* a, uint8_t* b, int len)
{
    int i=0;
    for(i=0; i<len; i++)
        format_hex_byte(a+(2*i), *(b+len-1-i));
}

void memcpy_ascii_order(uint8_t* a, uint8_t* b, int len)
{
    int i=0;
    for(i=0; i<len; i++)
        format_hex_byte(a+(2*i), *(b+i));
}

uint8_t* memcpy_inplace_reorder(uint8_t* data, uint16_t len)
{
      uint8_t *a, *b;

      if (!data) return data;
      for (a = data, b = (data + len - 1); b > a; ++a, --b)
      {
            *a ^= *b;
            *b ^= *a;
            *a ^= *b;
      }
      return data;
}


uint8_t* memcpy_nibble_inplace_reorder(uint8_t* data, uint16_t len)
{
      uint8_t *a, *b;

      if (!data) return data;
      for (a = data, b = (data + len - 1); b > a; ++a, --b)
      {
            *a ^= *b;
            *b ^= *a;
            *a ^= *b;
            *a = (*a >> 4) | (*a << 4);
            *b = (*b >> 4) | (*b << 4);
      }
      return data;
}

void memcpy_nibble_reorder(uint8_t* a, uint8_t* b, int len)
{
    int i=0;
    uint8_t c;
    for(i=0; i<len; i++)
    {
        c = *(b+len-1-i);
        *(a+i) = (c >> 4) | (c << 4);
    }
}

void memcpy_reorder(uint8_t* a, uint8_t* b, int len)
{
    int i=0;
    for(i=0; i<len; i++)
        *(a+i) = *(b+len-1-i);
}

uint8_t calc_chksum_8bit(uint8_t* data, uint16_t length)
{
    uint32_t chksum = 0;
    uint8_t* payload = data;
    uint16_t i;
    for(i=0; i<length; i++)
        chksum += *payload++;
    chksum = ~chksum;
    chksum += 1;
    return (uint8_t)chksum;
}