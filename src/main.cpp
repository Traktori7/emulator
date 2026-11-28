#include <iostream>
#include <string>

#include "core.h"

struct args {
    bool debug = false;
    std::string rom_name = "";
};

bool parse_args(int argc, char* argv[], args& arguments)
{
    int parsed_args = 1;

    while (parsed_args < argc)
    {
        std::string next_argument = argv[parsed_args];
        if (next_argument == "--debug")
        {
            arguments.debug = true;
            parsed_args++;
        }
        else if (next_argument == "-f" && parsed_args + 1 < argc)
        {
            arguments.rom_name = argv[parsed_args + 1];
            parsed_args += 2;
        }
        else
        {
            std::cout << "ERROR: Invalid argument: " << next_argument << std::endl;
            return false;
        }
    }
    
    return true;
}

int main(int argc, char* argv[])
{
    std::cout << "Hello Game Boy" << std::endl;

    args arguments;
    if (!parse_args(argc, argv, arguments))
    {
        return 0;
    }

    if (arguments.rom_name != "")
    {
        load_rom(arguments.rom_name);
    }

    return 0;
}