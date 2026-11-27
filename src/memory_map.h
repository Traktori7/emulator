#pragma once
#include <cstdint>
#include <string>


void load_rom_to_memory(std::string& rom_name);
void print_header();
uint8_t read_next_instruction();
uint8_t read_next_instruction(uint16_t address);
