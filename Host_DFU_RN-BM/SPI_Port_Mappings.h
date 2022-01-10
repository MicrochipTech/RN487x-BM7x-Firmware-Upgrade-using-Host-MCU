#if !defined(_SPI_PORT_MAPPINGS_H)
#   define   _SPI_PORT_MAPPINGS_H

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
#   if ( defined(__32MX310F032H__) || \
         defined(__32MX320F032H__) || \
         defined(__32MX320F064H__) || \
         defined(__32MX320F128H__) || \
         defined(__32MX340F128H__) || \
         defined(__32MX340F256H__) || \
         defined(__32MX340F512H__) || \
         defined(__32MX420F032H__) || \
         defined(__32MX440F128H__) || \
         defined(__32MX440F256H__) || \
         defined(__32MX440F512H__) || \
         defined(__32MX534F064H__) || \
         defined(__32MX564F064H__) || \
         defined(__32MX564F128H__) || \
         defined(__32MX575F256H__) || \
         defined(__32MX575F512H__) || \
         defined(__32MX664F064H__) || \
         defined(__32MX664F128H__) || \
         defined(__32MX675F256H__) || \
         defined(__32MX675F512H__) || \
         defined(__32MX695F512H__) || \
         defined(__32MX764F128H__) || \
         defined(__32MX775F256H__) || \
         defined(__32MX775F512H__) || \
         defined(__32MX795F512H__) )

/*      IO Mapping */
#       define _SPI1A_CLK_BIT                           BIT_1

/*      SPI1A IO Mapping                                   */
#       define _SPI1A_CLK_PORT                          IOPORT_D
#       define _SPI1A_SDI_BIT                           BIT_2
#       define _SPI1A_SDI_PORT                          IOPORT_D
#       define _SPI1A_SDO_BIT                           BIT_3
#       define _SPI1A_SDO_PORT                          IOPORT_D
#       define _SPI1A_SS_BIT                            BIT_9
#       define _SPI1A_SS_PORT                           IOPORT_D
#       define _SPI2A_CLK_BIT                           BIT_6

/*      SPI2A IO Mapping                                   */
#       define _SPI2A_CLK_PORT                          IOPORT_G
#       define _SPI2A_SDI_BIT                           BIT_7
#       define _SPI2A_SDI_PORT                          IOPORT_G
#       define _SPI2A_SDO_BIT                           BIT_8
#       define _SPI2A_SDO_PORT                          IOPORT_G
#       define _SPI2A_SS_BIT                            BIT_9
#       define _SPI2A_SS_PORT                           IOPORT_G
#       define _SPI2_CLK_BIT                            BIT_6

/*      SPI2 IO Mapping                                    */
#       define _SPI2_CLK_PORT                           IOPORT_G
#       define _SPI2_SDI_BIT                            BIT_7
#       define _SPI2_SDI_PORT                           IOPORT_G
#       define _SPI2_SDO_BIT                            BIT_8
#       define _SPI2_SDO_PORT                           IOPORT_G
#       define _SPI2_SS_BIT                             BIT_9
#       define _SPI2_SS_PORT                            IOPORT_G
#       define _SPI3A_CLK_BIT                           BIT_14

/*      SPI3A IO Mapping                                   */
#       define _SPI3A_CLK_PORT                          IOPORT_B
#       define _SPI3A_SDI_BIT                           BIT_4
#       define _SPI3A_SDI_PORT                          IOPORT_F
#       define _SPI3A_SDO_BIT                           BIT_5
#       define _SPI3A_SDO_PORT                          IOPORT_F
#       define _SPI3A_SS_BIT                            BIT_8
#       define _SPI3A_SS_PORT                           IOPORT_B
#       define _SPI3_CLK_BIT                            BIT_1

/*      SPI3 IO Mapping                                    */
#       define _SPI3_CLK_PORT                           IOPORT_D
#       define _SPI3_SDI_BIT                            BIT_2
#       define _SPI3_SDI_PORT                           IOPORT_D
#       define _SPI3_SDO_BIT                            BIT_3
#       define _SPI3_SDO_PORT                           IOPORT_D
#       define _SPI3_SS_BIT                             BIT_9
#       define _SPI3_SS_PORT                            IOPORT_D
#       define _SPI4_CLK_BIT                            BIT_14

/*      SPI4 IO Mapping                                    */
#       define _SPI4_CLK_PORT                           IOPORT_B
#       define _SPI4_SDI_BIT                            BIT_4
#       define _SPI4_SDI_PORT                           IOPORT_F
#       define _SPI4_SDO_BIT                            BIT_5
#       define _SPI4_SDO_PORT                           IOPORT_F
#       define _SPI4_SS_BIT                             BIT_8
#       define _SPI4_SS_PORT                            IOPORT_B

#   endif//H package

//  if "L" package
#   if ( defined(__32MX320F128L__) || \
         defined(__32MX340F128L__) || \
         defined(__32MX360F256L__) || \
         defined(__32MX360F512L__) || \
         defined(__32MX440F128L__) || \
         defined(__32MX460F256L__) || \
         defined(__32MX460F512L__) || \
         defined(__32MX534F064L__) || \
         defined(__32MX564F064L__) || \
         defined(__32MX564F128L__) || \
         defined(__32MX575F256L__) || \
         defined(__32MX575F512L__) || \
         defined(__32MX664F064L__) || \
         defined(__32MX664F128L__) || \
         defined(__32MX675F256L__) || \
         defined(__32MX675F512L__) || \
         defined(__32MX695F512L__) || \
         defined(__32MX764F128L__) || \
         defined(__32MX775F256L__) || \
         defined(__32MX775F512L__) || \
         defined(__32MX795F512L__) )

/*      IO Mapping */
#       define _SPI1A_CLK_BIT                           BIT_15

/*      SPI1A IO Mapping                                   */
#       define _SPI1A_CLK_PORT                          IOPORT_D
#       define _SPI1A_SDI_BIT                           BIT_2
#       define _SPI1A_SDI_PORT                          IOPORT_F
#       define _SPI1A_SDO_BIT                           BIT_8
#       define _SPI1A_SDO_PORT                          IOPORT_F
#       define _SPI1A_SS_BIT                            BIT_14
#       define _SPI1A_SS_PORT                           IOPORT_D
#       define _SPI1_CLK_BIT                            BIT_10

/*      SPI1 IO Mapping                                    */
#       define _SPI1_CLK_PORT                           IOPORT_D
#       define _SPI1_SDI_BIT                            BIT_4
#       define _SPI1_SDI_PORT                           IOPORT_C
#       define _SPI1_SDO_BIT                            BIT_0
#       define _SPI1_SDO_PORT                           IOPORT_D
#       define _SPI1_SS_BIT                             BIT_9
#       define _SPI1_SS_PORT                            IOPORT_D
#       define _SPI2A_CLK_BIT                           BIT_6

/*      SPI2A IO Mapping                                   */
#       define _SPI2A_CLK_PORT                          IOPORT_G
#       define _SPI2A_SDI_BIT                           BIT_7
#       define _SPI2A_SDI_PORT                          IOPORT_G
#       define _SPI2A_SDO_BIT                           BIT_8
#       define _SPI2A_SDO_PORT                          IOPORT_G
#       define _SPI2A_SS_BIT                            BIT_9
#       define _SPI2A_SS_PORT                           IOPORT_G
#       define _SPI2_CLK_BIT                            BIT_6

/*      SPI2 IO Mapping                                    */
#       define _SPI2_CLK_PORT                           IOPORT_G
#       define _SPI2_SDI_BIT                            BIT_7
#       define _SPI2_SDI_PORT                           IOPORT_G
#       define _SPI2_SDO_BIT                            BIT_8
#       define _SPI2_SDO_PORT                           IOPORT_G
#       define _SPI2_SS_BIT                             BIT_9
#       define _SPI2_SS_PORT                            IOPORT_G
#       define _SPI3A_CLK_BIT                           BIT_13

/*      SPI3A IO Mapping                                   */
#       define _SPI3A_CLK_PORT                          IOPORT_F
#       define _SPI3A_SDI_BIT                           BIT_4
#       define _SPI3A_SDI_PORT                          IOPORT_F
#       define _SPI3A_SDO_BIT                           BIT_5
#       define _SPI3A_SDO_PORT                          IOPORT_F
#       define _SPI3A_SS_BIT                            BIT_12
#       define _SPI3A_SS_PORT                           IOPORT_F
#       define _SPI3_CLK_BIT                            BIT_15

/*      SPI3 IO Mapping                                    */
#       define _SPI3_CLK_PORT                           IOPORT_D
#       define _SPI3_SDI_BIT                            BIT_2
#       define _SPI3_SDI_PORT                           IOPORT_F
#       define _SPI3_SDO_BIT                            BIT_8
#       define _SPI3_SDO_PORT                           IOPORT_F
#       define _SPI3_SS_BIT                             BIT_14
#       define _SPI3_SS_PORT                            IOPORT_D
#       define _SPI4_CLK_BIT                            BIT_13

/*      SPI4 IO Mapping                                    */
#       define _SPI4_CLK_PORT                           IOPORT_F
#       define _SPI4_SDI_BIT                            BIT_4
#       define _SPI4_SDI_PORT                           IOPORT_F
#       define _SPI4_SDO_BIT                            BIT_5
#       define _SPI4_SDO_PORT                           IOPORT_F
#       define _SPI4_SS_BIT                             BIT_12
#       define _SPI4_SS_PORT                            IOPORT_F

#   endif//L package

#endif//!defined(_SPI_PORT_MAPPINGS_H)
