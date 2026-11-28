#pragma once
#include <cstdint>
#include <string>


void load_rom_to_memory(std::string& rom_name);
void print_header();

uint8_t read_memory(uint16_t address);
void write_memory(uint16_t address, uint8_t value);
