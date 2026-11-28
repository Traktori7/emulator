#pragma once
#include <string>

enum log_level {
    ERROR,
    WARN,
    DEBUG
};

void init_log(std::string log_file = "");
void set_log_level(log_level new_level);
void log_print(log_level level, std::string message);
