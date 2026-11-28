#include "system_clock.h"

uint64_t system_clock_ticks = 0;

void init_system_clock(uint32_t master_clock_hz)
{
    
}

void advance_system_clock(uint8_t cycles)
{
    // TODO: Overflow?
    system_clock_ticks += cycles;
}
