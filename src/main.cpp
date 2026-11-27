#include <iostream>
#include <string>

#include "core.h"


int main(int argc, char* argv[])
{
    std::cout << "Hello Game Boy" << std::endl;

    if (argc == 1)
    {
        return 0;
    }

    std::string rom_name(argv[1]);
    load_rom(rom_name);

    return 0;
}