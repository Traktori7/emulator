cmake_minimum_required(VERSION 4.2.3)
project(emulator)

add_executable(emulator)

set_property(TARGET emulator PROPERTY CXX_STANDARD 20)

add_subdirectory(src)
