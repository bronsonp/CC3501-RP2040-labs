#include "hardware/pio.h"

PIO pio0;

unsigned int pio_add_program(PIO &pio, const pio_program_t* program)
{
    pio.programs.push_back(*program);
    return 0;
}

void pio_sm_put_blocking(PIO &pio, unsigned int sm, uint32_t data)
{
    for (auto program : pio.programs) {
        program(data);
    }
}
