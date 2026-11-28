#pragma once
#include <cstdint>

void init_system_clock(uint32_t master_clock_hz);
void advance_system_clock(uint8_t cycles);
