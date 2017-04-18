/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/maple_mini/board.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board file.
 */

#include <board/board.h>

#include <libmaple/gpio.h>
#include <libmaple/timer.h>

/* Roger Clark. Added next to includes for changes to Serial */
#include <libmaple/usart.h>
#include <HardwareSerial.h>

#include <wirish_debug.h>
#include <wirish_types.h>

/* Since we want the Serial Wire/JTAG pins as GPIOs, disable both SW
 * and JTAG debug support, unless configured otherwise. */
void boardInit(void)
{
#ifndef CONFIG_MAPLE_MINI_NO_DISABLE_DEBUG
    disableDebugPorts();
#endif
}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {
    {&gpiob, &timer2, NULL, 10, 3, ADCx},    /* D0/PB10 */
    {&gpiob, NULL, NULL, 12, 0, ADCx},    /* D1/PB12 */
    {&gpiob, &timer4, NULL, 8, 3, ADCx},     /* D2/PB8 */
    {&gpiob, &timer4, NULL, 7, 2, ADCx},    /* D3/PB7 */
    {&gpiob, &timer4, NULL, 6, 1, ADCx},    /* D4/PB6 */
    {&gpiob, &timer2, NULL, 3, 2, ADCx},    /* D5/PB3 */
    {&gpiob, &timer3, NULL, 4, 1, ADCx},    /* D6/PB4 */
    {&gpiob, &timer3, NULL, 5, 2, ADCx},       /* D7/PB5 */
    {&gpioa, &timer1, NULL, 10, 3, ADCx},    /* D8/PA10 */
    {&gpioa, &timer1, NULL, 9, 2, ADCx},    /* D9/PA9 */
    {&gpiob, &timer3, &adc1, 0, 3, 8},    /* D10/PB0 */
    {&gpiob, &timer2, NULL, 11, 4, ADCx},    /* D11/PB11 */
    {&gpioa, &timer2, NULL, 15, 1, ADCx},    /* D12/PA15 */
    {&gpioc, NULL, NULL, 15, 0, ADCx},    /* D13/PC15 */
    {&gpiob, NULL, NULL, 14, 0, ADCx},    /* D14/PB14 */
    {&gpiob, NULL, NULL, 13, 0, ADCx},  /* D15/PB13 */
    {&gpiob, NULL, NULL, 15, 1, ADCx},  /* D16/PB15 */
    {&gpioa, NULL, &adc1, 1, 0, 1},     /* D17/PA1 */
    {&gpioa, NULL, &adc1, 2, 0, 2},     /* D18/PA2 */
    {&gpioa, NULL, &adc2, 5, 0, 5},     /* D19/PA5 */
    {&gpioa, &timer3, &adc2, 6, 1, 6},    /* D20/PA6 */
    {&gpioa, NULL, &adc2, 4, 0, 4},    /* D21/PA4 */
    {&gpiob, &timer4, NULL, 9, 4, ADCx},    /* D22/PB9 */
    {&gpioa, &timer3, &adc2, 7, 2, 7},    /* D23/PA7 */
    {&gpioa, NULL, &adc1, 3, 0, 3}, /* D24/PA3 */
    {&gpioc, NULL, NULL, 14, 0, ADCx}, /* D25/PC14 */
    {&gpioc, NULL, NULL, 13, 0, ADCx},  /* D26/PC13 */
    {&gpioa, NULL, NULL, 13, 0, ADCx},  /* D27/PA13 */
    {&gpioa, NULL, NULL, 14, 0, ADCx},    /* D28/PA14 */
    {&gpioa, NULL, NULL, 12, 0, ADCx},    /* D29/PA12 */
    {&gpioa, NULL, NULL, 11, 0, ADCx},    /* D30/PA11 */
};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    2, 3, 4, 10
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    17, 18
};

#define USB_DP 29
#define USB_DM 30

extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    USB_DP, USB_DM};

/* 
 * Roger Clark
 * 
 * 2015/05/28
 *
 * Moved definitions for Hardware Serial devices from HardwareSerial.cpp so that each board can define which Arduino "Serial" instance
 * Maps to which hardware serial port on the microprocessor
 *
 * Note. Maple mini always has SERIAL USB, so there is no need for the #fidef for this
 * As its a Medium Density device, it only has 3 hardware serial devices. 
 */

DEFINE_HWSERIAL(Serial1, 1);
DEFINE_HWSERIAL(Serial2, 2);

