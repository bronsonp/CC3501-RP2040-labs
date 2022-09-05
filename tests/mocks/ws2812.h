#pragma once
#include <stdint.h>

// Types defined just so that we can replicate the real API
struct PIO { };
extern PIO pio0;
struct pio_program_t { };
extern pio_program_t ws2812_program;

// Functions defined to replicate the real API
unsigned int pio_add_program(PIO pio, const pio_program_t* program);
void ws2812_program_init(PIO pio, unsigned int sm, unsigned int offset, unsigned int pin, float freq, bool rgbw);
void pio_sm_put_blocking(PIO pio, unsigned int sm, uint32_t data);

/// Must be called at the end of a data load transaction (e.g. during `sleep_ms()`). This prints out the 
/// previously saved LED colours, much like how the real hardware latches the colours after the communication
/// channel goes idle.
void mock_ws2812_end_transaction();
