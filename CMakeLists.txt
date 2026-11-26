cmake_minimum_required(VERSION 4.2.3)
project(emulator)

add_executable(emulator)

add_subdirectory(src)

target_sources(emulator
    PRIVATE
        main.cpp
)
