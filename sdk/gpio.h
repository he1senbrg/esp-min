#ifndef GPIO_H
#define GPIO_H

#include "../include/common.h"
#include <stdbool.h>

#define GPIO_FUNC_OUT_SEL_CFG_REG   0X3ff44530  // Pins 0-39
#define GPIO_FUNC_IN_SEL_CFG_REG    0X3ff44130  // Pins 0-39

#define GPIO_OUT_REG                0X3ff44004  // Pins 0-31
#define GPIO_IN_REG                 0x3FF4403C  // Pins 0-31
#define GPIO_ENABLE_REG             0X3ff44020  // Pins 0-31

#define GPIO_OUT1_REG               0X3ff44010  // Pins 32-39
#define GPIO_IN1_REG                0X3ff44040  // Pins 32-39
#define GPIO_ENABLE1_REG            0X3ff4402c  // Pins 32-39

#define IO_MUX_PIN_CTRL             0x3FF49000

void gpio_output(int pin);
void gpio_write(int pin, bool value);

void gpio_input(int pin);
bool gpio_read(int pin);

#endif