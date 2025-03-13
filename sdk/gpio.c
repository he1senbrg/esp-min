#include "gpio.h"

static inline void gpio_output_enable(int pin, bool enable) {
    if (pin > 31) {
        pin -= 31;
        if (enable) {
            REG(GPIO_ENABLE1_REG)[0] |= BIT(pin);
        } else {
            REG(GPIO_ENABLE1_REG)[0] &= ~BIT(pin);
        }
    } else  {
        if (enable) {
            REG(GPIO_ENABLE_REG)[0] |= BIT(pin);
        } else {
            REG(GPIO_ENABLE_REG)[0] &= ~BIT(pin);
        }
    }
}

inline void gpio_output(int pin) {
    REG(GPIO_FUNC_OUT_SEL_CFG_REG)[pin] = 256;
    gpio_output_enable(pin, 1);
}

inline void gpio_write(int pin, bool value) {
    if (pin > 31) {
        pin -= 31;
        REG(GPIO_OUT1_REG)[0] &= ~BIT(pin);
        REG(GPIO_OUT1_REG)[0] |= (value ? 1U : 0U) << pin;
    } else {
        REG(GPIO_OUT_REG)[0] &= ~BIT(pin);
        REG(GPIO_OUT_REG)[0] |= (value ? 1U : 0U) << pin;
    }
}

inline void gpio_input(int pin) {
    unsigned char map[40] = {
        17, 34, 16, 33, 18, 27, 24, 25, 26, 21,
        22, 23, 13, 14, 12, 15, 19, 20, 28, 29,
        30, 31, 32, 35, 36, 9,  10, 11, 0,  0,
        0,  0,  7,  8,  5,  6,  1,  2,  3,  4
    };

    if (pin < 0 || pin > 40) {
        return;
    }

    gpio_output_enable(pin, 0);

    REG(IO_MUX_PIN_CTRL)[map[pin]] |= BIT(9);
}

inline bool gpio_read(int pin) {
    if (pin > 31) {
        pin -= 31;
        return (REG(GPIO_IN1_REG)[0] & BIT(pin)) >> pin;
    } else {
        return (REG(GPIO_IN_REG)[0] & BIT(pin)) >> pin;
    }
}