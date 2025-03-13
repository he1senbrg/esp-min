#include "watchdog.h"
#include "../include/common.h"

extern int main(void);
extern char _sbss, _ebss, _end, _eram;

static char *s_heap_start, *s_heap_end, *s_brk;

void init(void) {
    disable_watchdog();
    *(REG(ESP32_TIMERGROUP0)) |= BIT(31);
}

void _main(void) {
    s_heap_start = &_end;
    s_brk = &_end;
    s_heap_end = &_eram;
    
    for (char *p = &_sbss; p < &_ebss;) *p++ = '\0';
    init();
    main();
    while( 1 ) {}
}