#pragma once

#include <cstdint>
#include <functional>
#include <map>


struct cpu_registers {
    union
    {
        uint16_t AF;
        struct
        {
            uint8_t A;
            uint8_t F;
        };
        
    };
    union
    {
        uint16_t BC;
        struct
        {
            uint8_t B;
            uint8_t C;
        };
        
    };
    union
    {
        uint16_t DE;
        struct
        {
            uint8_t D;
            uint8_t E;
        };
        
    };
    union
    {
        uint16_t HL;
        struct
        {
            uint8_t H;
            uint8_t L;
        };
        
    };
    uint16_t SP;
    uint16_t PC;
};

bool cpu_init(bool debug = false);
bool cpu_execute();

void ld_r16_imm16(uint16_t& register_value);

// CPU functions, block 0
void nop();
void ld_bc_imm16();
void ld_de_imm16();
void ld_hl_imm16();
void ld_sp_imm16();

// CPU functions, block 1


// CPU functions, block 2


// CPU functions, block 3
void jp_imm16();
