#include "cpu.h"

#include <cstdint>
#include <iostream>

#include "cpu_instructions.h"
#include "memory_map.h"
#include "system_clock.h"

bool debug_mode = false;

uint16_t AF_register;
uint16_t BC_register;
uint16_t DE_register;
uint16_t HL_register;
uint16_t SP_register;
uint16_t PC_register;


bool cpu_init(bool debug)
{
    debug_mode = debug;
    return true;
}

bool cpu_execute()
{
    uint8_t opcode = read_next_instruction();
    cpu_instruction instruction = cpu_instructions[opcode];

    if (debug_mode)
    {
        std::cout << "OPCODE: " << std::hex << (uint16_t) opcode << " " << instruction.instruction_name << std::endl;
    }

    if (!instruction.function)
    {
        std::cout << "ERROR: Unimplemented opcode: " << std::hex << (uint16_t)opcode << std::endl;
        return false;
    }

    instruction.function();
    return true;
}

void nop()
{
    advance_system_clock(4);
    std::cout << "NOP" << std::endl;
}

void jp_imm16()
{
    advance_system_clock(4);
    uint8_t upper = read_next_instruction();

    advance_system_clock(4);
    uint8_t lower = read_next_instruction();

    // TODO: Where does the 4th M-cycle happen?
    advance_system_clock(4);
    advance_system_clock(4);
    uint16_t new_address = (upper << 8) | lower;
    PC_register = new_address;
    std::cout << "JP to " << std::hex << new_address << std::endl;
}
