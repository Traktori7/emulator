#include "memory_map.h"

#include <cstring> //memcpy
#include <fstream>
#include <iostream>

#include "cartridge_header.h"


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

    std::cout << "Cartridge type: " << cartridge_types[rom_bank_00[0x0147]] << std::endl;
    std::cout << "ROM size: " << 32 * (1 << rom_bank_00[0x0148]) << std::endl;
    std::cout << "RAM size: " << ram_sizes[rom_bank_00[0x0149]] << std::endl;
    
}
