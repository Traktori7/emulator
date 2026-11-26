find_package(SDL3 REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS})

target_link_libraries(emulator PRIVATE SDL3::SDL3)

target_sources(emulator
    PRIVATE
        graphics.cpp
)
