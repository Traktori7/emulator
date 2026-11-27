#include "core.h"

#include <iostream>

#include "cpu.h"
#include "memory_map.h"


void load_rom(std::string& rom_name)
{
    load_rom_to_memory(rom_name);
    print_header();

    for (size_t i = 0; i < 10; i++)
    {
        uint8_t instruction = read_next_instruction();
        parse_instruction(instruction);
    }
    
}
