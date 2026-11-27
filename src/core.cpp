#include "core.h"

#include <iostream>

#include "memory_map.h"


void load_rom(std::string& rom_name)
{
    load_rom_to_memory(rom_name);
    print_header();
}
