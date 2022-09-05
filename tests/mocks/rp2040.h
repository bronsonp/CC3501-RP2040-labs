#pragma once
#include <stdint.h>

// Generic API
typedef unsigned int uint;
void stdio_init_all();
void sleep_ms(uint32_t ms);

// GPIO functionality
#define GPIO_OUT 1
#define GPIO_IN 0
void gpio_init(unsigned int gpio);
void gpio_set_dir(unsigned int gpio, bool out);
void gpio_put(unsigned int gpio, bool val);

