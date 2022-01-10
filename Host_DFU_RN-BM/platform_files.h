#ifndef _PLATFORM_FILES_H_
#define _PLATFORM_FILES_H_

/* Platform list */
//#define HOST_MCU_SAML21		1
#define PIC_XX 1
/* Select any one platform */
//#define HOST_MCU_DEVICE		HOST_MCU_SAML21
#define HOST_MCU_DEVICE		PIC_XX


#if (HOST_MCU_DEVICE == HOST_MCU_SAML21)	
	#include "asf.h"
	#include "compiler.h"
	#include "profiles.h"
	#include "console_serial.h"
	#include "timer_hw.h"
	#include "conf_extint.h"
	#include "ble_utils.h"
	#include "conf_serialdrv.h"
	#include "conf_gpio.h"
	#include "config.h"
	#include "serial_drv.h"
#elif (HOST_MCU_DEVICE == PIC_XX)
	#define PACKED   __attribute__ ((packed))
	#include "stdint.h"
	#include "stdbool.h"
	#include "stdlib.h"
	#include "string.h"
	#include "config.h"
#else
	#error Select a Platform in platform_files.h
#endif //(HOST_MCU_DEVICE)	

#endif //_PLATFORM_FILES_H_
