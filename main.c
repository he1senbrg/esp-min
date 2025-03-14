#include "sdk/gpio.h"
#include "sdk/timer.h"
#include <stdio.h>

static int led_pin = 2;
static int in_pin = 15;

int main(void) {
    gpio_output(led_pin);
    gpio_input(in_pin);

    while (1) {
      printf("IN: %d\n",gpio_read(in_pin));

      gpio_write(led_pin, 1);
      delay_ms(500);

      gpio_write(led_pin, 0);
      delay_ms(500);
    }

    return 0;
}

