#include "mocks/ws2812.h"
#include <vector>
#include <iostream>

pio_program_t ws2812_program;
PIO pio0;

// Array in which to receive the LED data during each call to pio_sm_put_blocking
std::vector<uint32_t> mock_ws2812_leds;

unsigned int pio_add_program(PIO pio, const pio_program_t* program)
{
    return 0;
}

void ws2812_program_init(PIO pio, unsigned int sm, unsigned int offset, unsigned int pin, float freq, bool rgbw)
{
    // TODO: could sanity check the details here
}

void pio_sm_put_blocking(PIO pio, unsigned int sm, uint32_t data)
{
    mock_ws2812_leds.push_back(data);
}

void mock_ws2812_end_transaction()
{
    if (mock_ws2812_leds.size() > 0 ) {
        printf("Debug: LEDs (R,G,B) = ");

        for (uint32_t v : mock_ws2812_leds) {
            uint8_t r = (0xFF000000 & v) >> 24;
            uint8_t g = (0xFF0000 & v) >> 16;
            uint8_t b = (0xFF00 & v) >> 8;
            printf("(%03u,%03u,%03u),", r, g, b);
        }
        printf("\n");

        mock_ws2812_leds.clear();
    }
}
