#include "cpu.h"

#include <cstdint>
#include <format>
#include <iostream>

#include "cpu_instructions.h"
#include "log.h"
#include "memory_map.h"
#include "system_clock.h"


bool debug_mode = false;
cpu_registers regs;


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
        log_print(log_level::DEBUG, std::format("OPCODE: {:#04x} {}", (uint16_t)opcode, instruction.instruction_name));
    }

    if (!instruction.function)
    {
        log_print(log_level::ERROR, std::format("Unimplemented opcode: {:#04x}", (uint16_t)opcode));
        return false;
    }

    instruction.function();
    return true;
}

/**
 * Reads next 2 bytes and combines them in little endien order.
 * Advances the clock by 3 M-cycles.
 */
uint16_t read_imm16()
{
    advance_system_clock(4);
    uint8_t lower = read_next_instruction();

    advance_system_clock(4);
    uint8_t upper = read_next_instruction();

    advance_system_clock(4);
    return (upper << 8) | lower;
}

void nop()
{
    advance_system_clock(4);
    log_print(log_level::DEBUG, "NOP");
}

void ld_r16_imm16(uint16_t& register_value)
{
    register_value = read_imm16();
    advance_system_clock(4);
}

void ld_bc_imm16()
{
    ld_r16_imm16(regs.BC);
    log_print(log_level::DEBUG, std::format("LD {:#06x} to BC", regs.BC));
}

void ld_de_imm16()
{
    ld_r16_imm16(regs.DE);
    log_print(log_level::DEBUG, std::format("LD {:#06x} to DE", regs.DE));
}

void ld_hl_imm16()
{
    ld_r16_imm16(regs.HL);
    log_print(log_level::DEBUG, std::format("LD {:#06x} to HL", regs.HL));
}

void ld_sp_imm16()
{
    ld_r16_imm16(regs.SP);
    log_print(log_level::DEBUG, std::format("LD {:#06x} to SP", regs.SP));
}

void jp_imm16()
{
    // TODO: Where does the 4th M-cycle happen?
    advance_system_clock(4);
    uint16_t new_address = read_imm16();
    regs.PC = new_address;
    advance_system_clock(4);
    log_print(log_level::DEBUG, std::format("JP to {:#06x}", new_address));
}
