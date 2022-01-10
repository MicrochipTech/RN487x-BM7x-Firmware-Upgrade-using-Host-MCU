/*********************************************************************
 *
 *                  SPI API implementation file
 *
 *********************************************************************
 * FileName:        spi_change_chg_mode_lib.c
 * Dependencies:    Spi.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB Cxx
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
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
 *
 * $Id$
 * $Name$
 *
 ********************************************************************/

#include <peripheral/spi.h>
#include <peripheral/ports.h>
#include <peripheral/osc.h>
#include "_spi_got_new_spi_port_question.h"

#if defined( _GOT_NEW_SPI_PORT )
    //Do Nothing - _spi_io_tbl.h not needed.
    //It's probably not needed for other devices, but I'm not sure.
    //#include "_spi_io_tbl.h" const _SpiIoDcpt*   pDcpt=_SpiIoTbl+spiChn;
#else
    #include "_spi_io_tbl.h"
#endif

#include "_spi_map_tbl.h"


/********************
 * Channel functions.
 * Defined only if there's at least one valid SPI channel
 * *********************************/
#ifdef _SPI_DEF_CHN_


// internal function to wait a number of CPU cycles
static void __attribute__((nomips16, noinline)) _SpiWaitBusy(volatile __SPIxSTATbits_t* pSpiStat, int busyMask, int nClksWait);



/*********************************************************************
 * Function:        void SpiChnChangeMode(SpiChannel chn, int isMaster, int isFrmMaster, int waitBusy)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to set
 *                  isMaster    - master/slave mode
 *                  isFrmMaster - frame master/slave mode
 *                  waitBusy    - boolean to wait/no wait for the current transfer to finish
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function changes the SPI channel mode on the fly.
 *
 * Note:            - If waitBusy is TRUE, the function blocks until the current transfer, if any, is completed.
 *                    Due to a bug in the PIC32_3XX_4xx and PIC32_5XX_6xx_7xx SPI implementation, the BUSY/SRMT flag is set one spi_clk earlier.
 *                    What it means is that the data is not available in the SPIRxBUFF/SPIRxFIFO at the moment that BUSY is cleared.
 *                    The function will wait for the BUSY to be cleared.
 *                    For high SPIxBRG and PBDIV values note that the number of CPU clock cycles that have to be spent in this function could be significant.
 *                  - If waitBusy is FALSE, the function performs the mode switching immediately. It assumes that no transfer is currently on.
 *                    The caller must make sure that the current transfer, if any, is completed.
 *                  - isFrmMaster is relevant only if the SPI channel is operating in frame mode
 *                  - The SCK is properly configured as an digital I/O pin
 *                  - The SS is configured as a digital pin only if in frame mode or if the SSEN configuration bit is set.
 *
 * Example:         SpiChnChangeMode(SPI_CHANNEL2, TRUE, TRUE, TRUE);
 ********************************************************************/
void    SpiChnChangeMode(SpiChannel spiChn, int isMaster, int isFrmMaster, int waitBusy)
{
    register volatile _SpiRegMap* pReg = _SpiMapTbl[spiChn];
    int WasOn=0;
  #if defined( _GOT_NEW_SPI_PORT )
    //Do Nothing. SPI module responsible for port configuration.
  #else
    unsigned int    rdBuff;
    fConfPorts      fPorts;
    const _SpiIoDcpt*   pDcpt=_SpiIoTbl+spiChn;
  #endif

    if(pReg->con.ON)
    {
        if(waitBusy)
        {
        #if (((__PIC32_FEATURE_SET__ > 799) && !defined(__32MXGENERIC__)))
            while(pReg->stat.SPIBUSY);  // wait current txfer to finish
        #else
            // wait a number of CPU clock cycles corresponding to one spi_clk i.e.: sysClk/spiClk=(fpbDiv*pbClk)/(pbClk/2(brg+1))=fpbDiv*2*(brg+1)
            _SpiWaitBusy(&pReg->stat, __SPIxSTAT_MASK_(SPIBUSY_MASK), (pReg->brg+1) << (mOSCGetPBDIV()+1));     // since the fpbDiv is always pwr of 2: (1 << (mOSCGetPBDIV())
        #endif
        }

        pReg->conClr=__SPIxCON_MASK_(ON_MASK);  // turn off
        WasOn=1;
    }
  #if defined( _GOT_NEW_SPI_PORT )
    //Do Nothing. SPI module responsible for port configuration.
  #else //All this stuff may not be needed, since SPI module is supposedly responsible for port configuration.
    fPorts=isMaster?PORTSetPinsDigitalOut:PORTSetPinsDigitalIn;
    (*fPorts)(pDcpt->portSck, pDcpt->sckMask);      // configure the SCK

    if(pReg->con.FRMEN || pReg->con.SSEN)
    {
        if(pReg->con.FRMEN)
        {
            fPorts=isFrmMaster?PORTSetPinsDigitalOut:PORTSetPinsDigitalIn;
        }
        // else fPorts properly set by isMaster

        (*fPorts)(pDcpt->portSS, pDcpt->ssMask);        // configure the SS
    }

    // reconfigure the SPI channel
    if(isMaster)
    {
        pReg->conSet=__SPIxCON_MASK_(MSTEN_MASK);
    }
    else
    {
        pReg->conClr=__SPIxCON_MASK_(MSTEN_MASK);
    }

    if(isFrmMaster)
    {
        pReg->conClr=__SPIxCON_MASK_(FRMSYNC_MASK);
    }
    else
    {
        pReg->conSet=__SPIxCON_MASK_(FRMSYNC_MASK);
    }
  #endif//defined( _GOT_NEW_SPI_PORT )

    if(WasOn)
    {
        pReg->conSet=__SPIxCON_MASK_(ON_MASK);      // turn on
    }

}


// internal function to wait a number of CPU cycles
/*********************************************************************
 * Function:        void _SpiWaitBusy(volatile unsigned int* pSpiStat, int busyMask, int nClksWait)
 *
 * PreCondition:    None
 *
 * Input:           pSpiStat - address of a status register to poll
 *                  busyMask - mask to check for (poll while the (register & mask)!=0
 *                  nCLksWait - how many CPU clocks to wait
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This is a helper for waiting few CPU clocks.
 *                  Due to a bug in the SPI implementation, the BUSY/SRMT flag is set one spi_clk earlier.
 *                  What it means is that the data is not available in the SPIRxBUFF/SPIRxFIFO at the moment that BUSY is cleared.
 *
 *
 * Note:            - The function will wait for the specified number of CPU clocks only if it probes the BUSY bit to be asserted.
 *                  Otherwise the wait period is skipped.
 *                  There's no way to know, at this moment, when the BUSY bit was cleared so it makes no sense to wait.
 *                  Of course in some certain conditions this might fail.
 *                  - The general system settings (cache, prefetch, wait states) affect the actual execution time of this function.
 ********************************************************************/
static void __attribute__((nomips16, noinline)) _SpiWaitBusy(volatile __SPIxSTATbits_t* pSpiStat, int busyMask, int nClksWait)
{
    __asm__ __volatile__ (" #;                      \n\
                .set    noreorder           \n\
                    lw  $t0, 0($a0);            \n\
                or  $t1, $0, $a2;   # lds       \n\
                and $t0, $t0, $a1;          \n\
                beq $t0, $0, 3f;            \n\
                addiu   $t1, $t1, -4;   # nClksWait--;  \n\
                #; no wait if BUSY was not set      \n\
                1:                      \n\
                lw  $t0, 0($a0);            \n\
                or  $t1, $0, $a2;   # lds       \n\
                and $t0, $t0, $a1;          \n\
                bne $t0, $0, 1b;            \n\
                addiu   $t1, $t1, -4;   # nClksWait--;  \n\
                #; busy released            \n\
                blez    $t1, 3f;            \n\
                addiu   $t1, $t1, -2;   # nClksWait--;  \n\
            2:                      \n\
                bgtz    $t1, 2b;            \n\
                addiu   $t1, $t1, -2;   # nClksWait--;  \n\
            3:  #; finished");
}

#endif  // _SPI_DEF_CHN_

