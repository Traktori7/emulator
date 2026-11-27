#pragma once

#include <cstdint>
#include <functional>
#include <map>

#define DONE 0
#define MORE 1

// The map can't be defined in the header unlike cartridge_header maps for some reason?
extern std::map<uint8_t, std::function<uint16_t()>> instructions;

uint16_t parse_instruction(uint8_t opcode);

uint16_t nop();
uint16_t jp_imm16();
