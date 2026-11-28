#pragma once
#include <cstdint>
#include <functional>
#include <string>


struct cpu_instruction {
    std::string instruction_name;
    uint8_t operand_length;
    std::function<void()> function;
};

extern const cpu_instruction cpu_instructions[256];
