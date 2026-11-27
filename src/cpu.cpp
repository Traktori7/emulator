#include "cpu.h"

#include <cstdint>
#include <iostream>

uint16_t AF_register;
uint16_t BC_register;
uint16_t DE_register;
uint16_t HL_register;
uint16_t SP_register;
uint16_t PC_register;

/**
 * Some instruction take up to 2 bytes of extra data.
 * Since the instructions are read byte-by-byte, we need to keep track of
 * up to 3 bytes per instruction.
 * The bytes will be reset once the instruction function returns DONE.
 * */
uint8_t current_instruction = 0x00;
uint8_t following_byte_0 = 0x00;
uint8_t following_byte_1 = 0x00;
uint8_t following_bytes = 0;

std::map<uint8_t, std::function<uint16_t()>> instructions = {
    {0x00, nop},
    {0xC3, jp_imm16}
};

uint16_t parse_instruction(uint8_t opcode)
{
    std::cout << "Instruction: " << std::hex << (uint16_t)opcode << std::endl;
    
    if (current_instruction == 0x00)
    {
        current_instruction = opcode;
    }
    else if (following_bytes == 0)
    {
        following_byte_0 = opcode;
        following_bytes++;
    }
    else if (following_bytes == 1)
    {
        following_byte_1 = opcode;
        following_bytes++;
    }

    if (!instructions.contains(current_instruction))
    {
        std::cout << "ERROR: Unimplemented instruction: " << std::hex << (uint16_t)current_instruction << std::endl;
        return DONE;
        
    }

    uint16_t ret = instructions[current_instruction]();
    if (ret == DONE)
    {
        current_instruction = 0x00;
        following_byte_0 = 0x00;
        following_byte_1 = 0x00;
        following_bytes = 0;
    }

    return ret;
}

uint16_t nop()
{
    std::cout << "NOP" << std::endl;
    return DONE;
}

uint16_t jp_imm16()
{
    if (following_bytes != 2)
    {
        return MORE;
    }
    uint16_t new_address = (following_byte_0 << 8) | following_byte_1;
    std::cout << "JP to " << std::hex << new_address << std::endl;
    return DONE;
}
