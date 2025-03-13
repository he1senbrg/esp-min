#include "../include/common.h"
#include "watchdog.h"

void disable_watchdog(void) {
    // Disable watchdog protection
    *(REG(RTC_CNTL_WDTWPROTECT_REG)) = 0x50d83aa1;

    // Feed watchdog
    *(REG(RTC_CNTL_WDTFEED_REG)) |= BIT(31);

    // Disable watchdog
    *(REG(RTC_CNTL_WDTCONFIG0_REG)) = 0;

    // Disable timer watchdog
    *(REG(TIMG0_WDTCONFIG0_REG)) = 0;
    *(REG(TIMG1_WDTCONFIG0_REG)) = 0;
}