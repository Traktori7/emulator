#include "log.h"

#include <fstream>
#include <iostream>

log_level current_log_level = log_level::WARN;
std::string current_log_file = "";

void init_log(std::string log_file)
{
    if (!log_file.empty())
    {
        current_log_file = log_file;
        std::ofstream f;
        f.open(current_log_file, std::ofstream::out | std::ofstream::trunc);
        f << "Starting log" << std::endl;
        f.close();
    }
}

void set_log_level(log_level new_level)
{
    current_log_level = new_level;
}

void log_print(log_level level, std::string message)
{
    if (level > current_log_level)
    {
        return;
    }

    if (!current_log_file.empty())
    {
        std::ofstream f;
        f.open(current_log_file, std::ofstream::out | std::ofstream::app);
        
        switch (level)
        {
        case log_level::ERROR:
            f << "ERROR: ";
            break;
        case log_level::WARN:
            f << "WARN: ";
            break;
        case log_level::DEBUG:
            f << "DEBUG: ";
            break;
        
        default:
            break;
        }
        
        f << message << std::endl;
        f.close();
    }
    else
    {
        switch (level)
        {
        case log_level::ERROR:
            std::cout << "ERROR: ";
            break;
        case log_level::WARN:
            std::cout << "WARN: ";
            break;
        case log_level::DEBUG:
            std::cout << "DEBUG: ";
            break;
        
        default:
            break;
        }
        
        std::cout << message << std::endl;
    }
}
