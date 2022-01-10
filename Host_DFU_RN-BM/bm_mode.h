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
#ifndef _BM_MODE_H
#define _BM_MODE_H

/** \file bm_mode.h
 * Defines BM mode APIs to switch between different
 * BM operation modes such as EEPROM Mode and Application Mode.
 * Defines BM operation mode enumerations.
 */

#include "stdint.h"
 
/*! \enum BM_MODE
 * Enumeration of the BM operation modes.
 */
typedef enum
{
    /*! Flash update mode. */
    BM_MODE_PROGRAM = 0,
    /*! Application mode. */
    BM_MODE_APPLICATION
}BM_MODE;

/*! \fn void BM_MODE_Init(void)
 *  \brief Initializes BM mode configuration library.
 *  \pre None.
 *  \return None.
 */
void BM_MODE_Init(void);

/*! \fn void BM_MODE_Set(BM_MODE mode)
 *  \brief Sets the BM operation mode.
 *  \param mode The BM operation mode to be set.
 *  \pre BM mode initalize function should be invoked prior.
 *  \return None.
 */
void BM_MODE_Set(BM_MODE mode);

/*! \fn void BM_MODE BM_MODE_Get(BM_MODE mode)
 *  \brief Gets the curent BM operation mode.
 *  \param mode Variable to load the current BM operation mode.
 *  \pre BM mode initalize function should be invoked prior.
 *  \return None.
 */
void BM_MODE_Get(BM_MODE mode);

/*! \fn uint16_t BM_ConfigurationLibraryVersion(void)
 *  \brief Gets the version of the BM configuration library.
 *  \pre None.
 *  \return BM Configuration Library version (0xMMmm).
 */
uint16_t BM_ConfigurationLibraryVersion(void);

/// @cond
#define BM_MODE_Init()                BM_MODULE_ControlInit();

#define BM_MODE_Get(mode)             {                                               \
                                            if(BM_MODULE_ProgramModeGet())             \
                                                mode = BM_MODE_PROGRAM;                \
                                            else if(BM_MODULE_ApplicationModeGet())             \
                                                mode = BM_MODE_APPLICATION;                \
                                        }                                               \

#define BM_MODE_Set(mode)             {                                           \
                                            if(mode == BM_MODE_PROGRAM)            \
                                                BM_MODULE_ProgramModeSet();        \
                                            if(mode == BM_MODE_APPLICATION)       \
                                                BM_MODULE_ApplicationModeSet();   \
                                        }                                           \

/// @endcond

#endif