cmake_minimum_required(VERSION 4.2.3)
project(emulator)

add_executable(emulator)

target_sources(emulator
    PRIVATE
        main.cpp
)