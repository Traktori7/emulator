#include "core.h"

#include <iostream>

#include "cpu.h"
#include "log.h"
#include "memory_map.h"


bool core_init(std::string& rom_name, bool debug)
{
    cpu_init(debug);
    load_rom_to_memory(rom_name);
    print_header();
    return true;
}

bool core_run()
{
    while (cpu_execute())
    {
        continue;
    }

    return false;
}
