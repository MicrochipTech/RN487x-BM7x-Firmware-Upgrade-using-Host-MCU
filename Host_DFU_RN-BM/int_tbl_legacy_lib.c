/********************************************************************
 * FileName:        int_tbl_legacy_lipb.c
 * Dependencies:
 * Processor:       PIC32
 * Hardware:        N/A
 * Assembler:       N/A
 * Linker:          N/A
 * Company:         Microchip Technology Inc.
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
#if defined(__32MX120F064H__) || \
    defined(__32MX130F128H__) || \
    defined(__32MX130F128L__) || \
    defined(__32MX150F256H__) || \
    defined(__32MX150F256L__) || \
    defined(__32MX170F512H__) || \
    defined(__32MX170F512L__) || \
    defined(__32MX230F128H__) || \
    defined(__32MX230F128L__) || \
    defined(__32MX250F256H__) || \
    defined(__32MX250F256L__) || \
    defined(__32MX270F512H__) || \
    defined(__32MX270F512L__) || \
    defined(__32MX530F128H__) || \
    defined(__32MX530F128L__) || \
    defined(__32MX550F256H__) || \
    defined(__32MX550F256L__) || \
    defined(__32MX570F512H__) || \
    defined(__32MX570F512L__)
#   include "int_tbl_1xx_2xx_5xx_legacy_lib.c"
#elif (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#   include "int_tbl_1xx_2xx_legacy_lib.c"
#elif  ((__PIC32_FEATURE_SET__ >= 300) && (__PIC32_FEATURE_SET__ <= 499))
#   include "int_tbl_3xx_4xx_legacy_lib.c"
#elif (((__PIC32_FEATURE_SET__ >= 500) && (__PIC32_FEATURE_SET__ <= 799)) || defined (__32MXPOCONO__))
#   include "int_tbl_5xx_6xx_7xx_legacy_lib.c"
#else
#   error "Device not supported by the interrupt peripheral library"
#endif


void INTSetPriority(INT_SOURCE source, INT_PRIORITY priority)
{
    INT_VECTOR_TBL_ENTRY   *tbl;

    tbl                 = (INT_VECTOR_TBL_ENTRY *)__IntScrPriTbl + source;

    tbl->ipc[SFR_CLR]   = (7 << tbl->pri_shift);
    priority            <<= tbl->pri_shift;
    tbl->ipc[SFR_SET]   = priority;

}
INT_PRIORITY INTGetPriority(INT_SOURCE source)
{
    INT_VECTOR_TBL_ENTRY   *tbl;

    tbl                 = (INT_VECTOR_TBL_ENTRY *)__IntScrPriTbl + source;
    return ((*tbl->ipc >>  tbl->pri_shift) & 7);
}
void INTSetSubPriority(INT_SOURCE source, INT_SUB_PRIORITY subPriority)
{
    INT_VECTOR_TBL_ENTRY   *tbl;

    tbl                 = (INT_VECTOR_TBL_ENTRY *)__IntScrPriTbl + source;
    tbl->ipc[SFR_CLR]   = (3 << tbl->sub_shift);
    subPriority         <<= tbl->sub_shift;
    tbl->ipc[SFR_SET]   = subPriority;

}
INT_SUB_PRIORITY INTGetSubPriority(INT_SOURCE source)
{
    INT_VECTOR_TBL_ENTRY   *tbl;

    tbl                 = (INT_VECTOR_TBL_ENTRY *)__IntScrPriTbl + source;
    return ((*tbl->ipc >>  tbl->sub_shift) & 3);
}

void INTSetPriorityAndSubPriority(INT_SOURCE source, INT_PRIORITY priority, INT_SUB_PRIORITY subPriority)
{
    INT_VECTOR_TBL_ENTRY   *tbl;

    tbl                 = (INT_VECTOR_TBL_ENTRY *)__IntScrPriTbl + source;

    tbl->ipc[SFR_CLR]   = (7 << tbl->pri_shift);
    priority            <<= tbl->pri_shift;
    tbl->ipc[SFR_SET]   = priority;

    tbl->ipc[SFR_CLR]   = (3 << tbl->sub_shift);
    subPriority         <<= tbl->sub_shift;
    tbl->ipc[SFR_SET]   = subPriority;

}
