#if !defined(_ETHERNET_PORT_MAPPINGS_H)
#   define   _ETHERNET_PORT_MAPPINGS_H

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/
#ifndef _SUPPRESS_PLIB_WARNING
  #warning The PLIB functions and macros in this file will be removed from the MPLAB XC32 C/C++ Compiler in future releases
#endif


//  if "H" package
#   if ( defined(__32MX664F064H__) || \
         defined(__32MX664F128H__) || \
         defined(__32MX675F256H__) || \
         defined(__32MX675F512H__) || \
         defined(__32MX695F512H__) || \
         defined(__32MX764F128H__) || \
         defined(__32MX775F256H__) || \
         defined(__32MX775F512H__) || \
         defined(__32MX795F512H__) )

/*  IO Mapping */
#       define _ETH_ALT_COL_BIT                         BIT_10
#       define _ETH_ALT_COL_PORT                        IOPORT_D
#       define _ETH_ALT_CRS_BIT                         BIT_11
#       define _ETH_ALT_CRS_PORT                        IOPORT_D

/*  Alternate Ethernet IO configuration                */
#       define _ETH_ALT_MDC_BIT                         BIT_15
#       define _ETH_ALT_MDC_PORT                        IOPORT_B
#       define _ETH_ALT_MDIO_BIT                        BIT_1
#       define _ETH_ALT_MDIO_PORT                       IOPORT_D
#       define _ETH_ALT_RXCLK_BIT                       BIT_11
#       define _ETH_ALT_RXCLK_PORT                      IOPORT_D
#       define _ETH_ALT_RXD0_BIT                        BIT_9
#       define _ETH_ALT_RXD0_PORT                       IOPORT_D
#       define _ETH_ALT_RXD1_BIT                        BIT_8
#       define _ETH_ALT_RXD1_PORT                       IOPORT_D
#       define _ETH_ALT_RXD2_BIT                        BIT_1
#       define _ETH_ALT_RXD2_PORT                       IOPORT_F
#       define _ETH_ALT_RXD3_BIT                        BIT_0
#       define _ETH_ALT_RXD3_PORT                       IOPORT_F
#       define _ETH_ALT_RXDV_BIT                        BIT_10
#       define _ETH_ALT_RXDV_PORT                       IOPORT_D
#       define _ETH_ALT_RXERR_BIT                       BIT_7
#       define _ETH_ALT_RXERR_PORT                      IOPORT_D
#       define _ETH_ALT_TXCLK_BIT                       BIT_7
#       define _ETH_ALT_TXCLK_PORT                      IOPORT_D
#       define _ETH_ALT_TXD0_BIT                        BIT_1
#       define _ETH_ALT_TXD0_PORT                       IOPORT_F
#       define _ETH_ALT_TXD1_BIT                        BIT_0
#       define _ETH_ALT_TXD1_PORT                       IOPORT_F
#       define _ETH_ALT_TXD2_BIT                        BIT_9
#       define _ETH_ALT_TXD2_PORT                       IOPORT_D
#       define _ETH_ALT_TXD3_BIT                        BIT_8
#       define _ETH_ALT_TXD3_PORT                       IOPORT_D
#       define _ETH_ALT_TXEN_BIT                        BIT_6
#       define _ETH_ALT_TXEN_PORT                       IOPORT_D
#       define _ETH_ALT_TXERR_BIT                       BIT_6
#       define _ETH_ALT_TXERR_PORT                      IOPORT_D
#       define _ETH_COL_BIT                             BIT_10
#       define _ETH_COL_PORT                            IOPORT_D
#       define _ETH_CRS_BIT                             BIT_11
#       define _ETH_CRS_PORT                            IOPORT_D

/*  Ethernet IO Mapping                                */
#       define _ETH_MDC_BIT                             BIT_15
#       define _ETH_MDC_PORT                            IOPORT_B
#       define _ETH_MDIO_BIT                            BIT_1
#       define _ETH_MDIO_PORT                           IOPORT_D
#       define _ETH_RXCLK_BIT                           BIT_3
#       define _ETH_RXCLK_PORT                          IOPORT_E
#       define _ETH_RXD0_BIT                            BIT_1
#       define _ETH_RXD0_PORT                           IOPORT_E
#       define _ETH_RXD1_BIT                            BIT_0
#       define _ETH_RXD1_PORT                           IOPORT_E
#       define _ETH_RXD2_BIT                            BIT_1
#       define _ETH_RXD2_PORT                           IOPORT_F
#       define _ETH_RXD3_BIT                            BIT_0
#       define _ETH_RXD3_PORT                           IOPORT_F
#       define _ETH_RXDV_BIT                            BIT_2
#       define _ETH_RXDV_PORT                           IOPORT_E
#       define _ETH_RXERR_BIT                           BIT_4
#       define _ETH_RXERR_PORT                          IOPORT_E
#       define _ETH_TXCLK_BIT                           BIT_7
#       define _ETH_TXCLK_PORT                          IOPORT_D
#       define _ETH_TXD0_BIT                            BIT_6
#       define _ETH_TXD0_PORT                           IOPORT_E
#       define _ETH_TXD1_BIT                            BIT_7
#       define _ETH_TXD1_PORT                           IOPORT_E
#       define _ETH_TXD2_BIT                            BIT_9
#       define _ETH_TXD2_PORT                           IOPORT_D
#       define _ETH_TXD3_BIT                            BIT_8
#       define _ETH_TXD3_PORT                           IOPORT_D
#       define _ETH_TXEN_BIT                            BIT_5
#       define _ETH_TXEN_PORT                           IOPORT_E
#       define _ETH_TXERR_BIT                           BIT_6
#       define _ETH_TXERR_PORT                          IOPORT_D
#       define _SPI1A_CLK_BIT                           BIT_1

#   endif//H package

//  if "L" package
#   if ( defined(__32MX664F064L__) || \
         defined(__32MX664F128L__) || \
         defined(__32MX675F256L__) || \
         defined(__32MX675F512L__) || \
         defined(__32MX695F512L__) || \
         defined(__32MX764F128L__) || \
         defined(__32MX775F256L__) || \
         defined(__32MX775F512L__) || \
         defined(__32MX795F512L__) )

/*      IO Mapping */
#       define _ETH_ALT_COL_BIT                         BIT_13
#       define _ETH_ALT_COL_PORT                        IOPORT_B
#       define _ETH_ALT_CRS_BIT                         BIT_12
#       define _ETH_ALT_CRS_PORT                        IOPORT_B

/*      Alternate Ethernet IO configuration                */
#       define _ETH_ALT_MDC_BIT                         BIT_11
#       define _ETH_ALT_MDC_PORT                        IOPORT_D
#       define _ETH_ALT_MDIO_BIT                        BIT_8
#       define _ETH_ALT_MDIO_PORT                       IOPORT_D
#       define _ETH_ALT_RXCLK_BIT                       BIT_9
#       define _ETH_ALT_RXCLK_PORT                      IOPORT_G
#       define _ETH_ALT_RXD0_BIT                        BIT_8
#       define _ETH_ALT_RXD0_PORT                       IOPORT_E
#       define _ETH_ALT_RXD1_BIT                        BIT_9
#       define _ETH_ALT_RXD1_PORT                       IOPORT_E
#       define _ETH_ALT_RXD2_BIT                        BIT_9
#       define _ETH_ALT_RXD2_PORT                       IOPORT_A
#       define _ETH_ALT_RXD3_BIT                        BIT_10
#       define _ETH_ALT_RXD3_PORT                       IOPORT_A
#       define _ETH_ALT_RXDV_BIT                        BIT_8
#       define _ETH_ALT_RXDV_PORT                       IOPORT_G
#       define _ETH_ALT_RXERR_BIT                       BIT_15
#       define _ETH_ALT_RXERR_PORT                      IOPORT_G
#       define _ETH_ALT_TXCLK_BIT                       BIT_14
#       define _ETH_ALT_TXCLK_PORT                      IOPORT_A
#       define _ETH_ALT_TXD0_BIT                        BIT_14
#       define _ETH_ALT_TXD0_PORT                       IOPORT_D
#       define _ETH_ALT_TXD1_BIT                        BIT_15
#       define _ETH_ALT_TXD1_PORT                       IOPORT_D
#       define _ETH_ALT_TXD2_BIT                        BIT_15
#       define _ETH_ALT_TXD2_PORT                       IOPORT_B
#       define _ETH_ALT_TXD3_BIT                        BIT_14
#       define _ETH_ALT_TXD3_PORT                       IOPORT_B
#       define _ETH_ALT_TXEN_BIT                        BIT_15
#       define _ETH_ALT_TXEN_PORT                       IOPORT_A
#       define _ETH_ALT_TXERR_BIT                       BIT_11
#       define _ETH_ALT_TXERR_PORT                      IOPORT_B
#       define _ETH_COL_BIT                             BIT_6
#       define _ETH_COL_PORT                            IOPORT_G
#       define _ETH_CRS_BIT                             BIT_7
#       define _ETH_CRS_PORT                            IOPORT_G

/*      Ethernet IO Mapping                                */
#       define _ETH_MDC_BIT                             BIT_11
#       define _ETH_MDC_PORT                            IOPORT_D
#       define _ETH_MDIO_BIT                            BIT_8
#       define _ETH_MDIO_PORT                           IOPORT_D
#       define _ETH_RXCLK_BIT                           BIT_9
#       define _ETH_RXCLK_PORT                          IOPORT_G
#       define _ETH_RXD0_BIT                            BIT_12
#       define _ETH_RXD0_PORT                           IOPORT_B
#       define _ETH_RXD1_BIT                            BIT_13
#       define _ETH_RXD1_PORT                           IOPORT_B
#       define _ETH_RXD2_BIT                            BIT_14
#       define _ETH_RXD2_PORT                           IOPORT_B
#       define _ETH_RXD3_BIT                            BIT_15
#       define _ETH_RXD3_PORT                           IOPORT_B
#       define _ETH_RXDV_BIT                            BIT_8
#       define _ETH_RXDV_PORT                           IOPORT_G
#       define _ETH_RXERR_BIT                           BIT_11
#       define _ETH_RXERR_PORT                          IOPORT_B
#       define _ETH_TXCLK_BIT                           BIT_7
#       define _ETH_TXCLK_PORT                          IOPORT_D
#       define _ETH_TXD0_BIT                            BIT_1
#       define _ETH_TXD0_PORT                           IOPORT_F
#       define _ETH_TXD1_BIT                            BIT_0
#       define _ETH_TXD1_PORT                           IOPORT_F
#       define _ETH_TXD2_BIT                            BIT_12
#       define _ETH_TXD2_PORT                           IOPORT_D
#       define _ETH_TXD3_BIT                            BIT_13
#       define _ETH_TXD3_PORT                           IOPORT_D
#       define _ETH_TXEN_BIT                            BIT_6
#       define _ETH_TXEN_PORT                           IOPORT_D
#       define _ETH_TXERR_BIT                           BIT_1
#       define _ETH_TXERR_PORT                          IOPORT_G

#   endif//L package

#endif//!defined(_ETHERNET_PORT_MAPPINGS_H)
