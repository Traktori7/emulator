#pragma once

#include <cstdint>
#include <functional>
#include <map>


bool cpu_init(bool debug = false);
bool cpu_execute();

// CPU functions
void nop();
void jp_imm16();
