#ifndef WATCHDOG_H
#define WATCHDOG_H

// Watchdog registers
#define RTC_CNTL_WDTWPROTECT_REG 0x3FF480A4
#define RTC_CNTL_WDTFEED_REG     0x3FF480A0
#define RTC_CNTL_WDTCONFIG0_REG  0x3FF4808C

// Timer watchdog registers
#define TIMG0_WDTCONFIG0_REG     0x3FF5F048
#define TIMG1_WDTCONFIG0_REG     0x3FF60048

void disable_watchdog(void);

#endif