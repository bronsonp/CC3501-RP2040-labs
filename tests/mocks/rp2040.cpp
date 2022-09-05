#include <iostream>
#include "mocks/rp2040.h"
#include "mocks/ws2812.h"

#include <thread>
#include <chrono>

void stdio_init_all()
{

}

void sleep_ms(uint32_t ms)
{
    mock_ws2812_end_transaction();
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void gpio_init(unsigned int gpio)
{
    printf("Debug: initialised GPIO pin %u\n", gpio);
}

void gpio_set_dir(unsigned int gpio, bool out)
{
    // TODO: Could use the test harness here to check correct use of the API, e.g. that `gpio_init()` was previously called.
    printf("Debug: GPIO pin %u set to %s\n", gpio, out ? "output" : "input");
}

void gpio_put(unsigned int gpio, bool val)
{
    printf("Debug: GPIO pin %u set to %i\n", gpio, val);
}
