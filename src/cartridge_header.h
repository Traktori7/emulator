#pragma once
#include <map>
#include <string>

std::map<char, std::string> cartridge_types = {
    {0x00, "ROM_ONLY"},
    {0x01, "MBC1"},
    {0x02, "MBC1+RAM"},
    {0x03, "MBC1+RAM+BATTERY"},
    {0x05, "MBC2"},
    {0x06, "MBC2+BATTERY"},
    {0x08, "ROM+RAM"},
    {0x09, "ROM+RAM+BATTERY"},
    {0x0B, "MMM01"},
    {0x0C, "MMM01+RAM"},
    {0X0D, "MMM01+RAM+BATTERY"}
};

std::map<char, u_int16_t> ram_sizes = {
    {0x00, 0},
    {0x02, 8},
    {0x03, 32},
    {0x04, 128},
    {0x05, 64}
};
