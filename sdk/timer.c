#include <stdint.h>
#include "../include/common.h"
#include "timer.h"

static inline void nop(volatile unsigned long count) {
    while (count--) asm volatile("nop");
}

static inline uint64_t systick(void) {
    REG(ESP32_TIMERGROUP0)[3] = 1;
    nop(1);
    return ((uint64_t) REG(ESP32_TIMERGROUP0)[2] << 32) | REG(ESP32_TIMERGROUP0)[1];
}

static inline uint64_t uptime_us(void) {
    return systick() >> 5;
}

inline void delay_us(unsigned long us) {
    uint64_t until = uptime_us() + us;
    while (uptime_us() < until) nop(1);
}

inline void delay_ms(unsigned long ms) {
    delay_us(ms * 1000);
}