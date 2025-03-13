#include "sdk/gpio.h"
#include "sdk/timer.h"

static int led_pin = 2;

int main(void) {
    gpio_output(led_pin);

    while (1) {
      gpio_write(led_pin, 1);
      delay_ms(500);

      gpio_write(led_pin, 0);
      delay_ms(500);
    }

    return 0;
}

