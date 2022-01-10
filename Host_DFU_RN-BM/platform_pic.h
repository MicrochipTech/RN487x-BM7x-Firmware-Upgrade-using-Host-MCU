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
#ifndef _PLATFORM_H_
#define _PLATFORM_H_

/*
 * @brief Initialize platform layer
 *
 * @param
 *
 * @return 
*/
void platform_init(void);

/*
 * @brief Configure UART interface with BM7x
 *
 * @param 
 *
 * @return 
*/
void configure_usart(void);

/*
 * @brief Configure UART callback
 *
 * @param 
 *
 * @return 
*/
void configure_usart_callbacks(void);

/*
 * @brief UART receive interrupt callback function
 *
 * @param[in] usart_module UART module used to interface with BM7x
 *
 * @return 
*/
void usart_read_callback(/*struct usart_module *const usart_module*/);

/*
 * @brief UART write synchronously
 *
 * @param[in] data UART TX data
 * @param[in] length UART TX data length
 *
 * @return 
*/
void uart_write_sync(uint8_t *data, uint16_t length);

/*
 * @brief Read UART data
 *
 * @param[in] data UART RX data
 *
 * @return 
*/
void uart_read_data(uint16_t *data);

/*
 * @brief Start reading UART data asynchronously
 *
 * @param[in] data UART RX data
 *
 * @return 
*/
void read_data_async(void);

/*
 * @brief Send user data to remote device
 *
 * @param
 *
 * @return 
*/
void send_user_data(void);

void read_async_callback(uart_recv_async_cb_t recv_async_callback);

void *platform_create_timer(void (*timer_cb)(void *));
void platform_delete_timer(void *timer_handle);
void platform_start_timer(void *timer_handle, uint32_t ms);
void platform_stop_timer(void *timer_handle);
void platform_sleep(uint32_t ms);
void platform_gpio_set(gpio_pin_t pin, gpio_status_t status);
void platform_mode_set(uint8_t mode);
void platform_send_sync(uint8_t *data, uint32_t length);
void platform_recv_async(uart_recv_async_cb_t recv_async_callback);
void platform_ble_mode_select(uint8_t mode);
bool platform_wakeup_pin_status(void);
void platform_process_rxdata(uint8_t t_rx_data);

#endif //_PLATFORM_H_
