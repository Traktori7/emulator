#include "memory_map.h"

#include <cstring> //memcpy
#include <fstream>
#include <iostream>


#define ROM_BANK_00_SIZE 0x4000

char rom_bank_00[ROM_BANK_00_SIZE];

void load_rom_to_memory(std::string& rom_name)
{
    std::cout << "Loading ROM: " << rom_name << std::endl;
    std::ifstream rom_file(rom_name, std::ios::in | std::ios::binary);
    if (rom_file.is_open())
    {
        rom_file.read(rom_bank_00, ROM_BANK_00_SIZE);
        rom_file.close();
    }
}

void print_header()
{
    char title[16];
    memcpy(title, rom_bank_00 + 0x0134, 16);
    std::cout << "ROM title: " << title << std::endl;

    std::cout << "ROM size: " << 32 * (1 << rom_bank_00[0x0148]) << std::endl;

    char ram_size = rom_bank_00[0x0149];
    if (ram_size == 0x00)
    {
        ram_size = 0;
    }
    else if (ram_size == 0x01)
    {
        ram_size = 2;
        std::cout << "ERROR: Unexpected RAM size of 0x01" << std::endl;
    }
    else if (ram_size == 0x02)
    {
        ram_size = 8;
    }
    else if (ram_size == 0x03)
    {
        ram_size = 32;
    }
    else if (ram_size == 0x04)
    {
        ram_size = 128;
    }
    else if (ram_size == 0x05)
    {
        ram_size = 64;
    }
    else
    {
        std::cout << "ERROR: Invalid RAM size " << std::hex << ram_size << std::endl;
    }

    std::cout << "RAM size: " << (u_int16_t)ram_size << std::endl;
    
}
