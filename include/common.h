#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define ESP32_TIMERGROUP0 0x3ff5F000
#define ESP32_TIMERGROUP1 0x3ff60000

#define ESP32_UART0 0x3ff40000

#define BIT(x) ((uint32_t) 1U << (x))
#define REG(x) ((volatile uint32_t *) (x))

#endif