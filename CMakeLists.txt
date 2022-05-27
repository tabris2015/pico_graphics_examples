cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME pico_graph) # <-- Name your project/executable here!

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
        src/main.cpp # <-- Add source files here!
        game_controller/game_controller.h game_controller/object.h)

# Include required libraries
# This assumes `pimoroni-pico` is stored alongside your project
 include(libraries/bitmap_fonts/bitmap_fonts)
# include(libraries/pico_explorer/pico_explorer)
# include(libraries/pico_display/pico_display)
#include(libraries/pico_display/pico_display)
include(lilygo_tdisplay/lilygo_tdisplay.cmake)
#include(drivers/st7789/st7789)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
        pico_stdlib
        hardware_spi
        hardware_pwm
        hardware_dma
#        st7789
#        pico_display
        bitmap_fonts
        lilygo_tdisplay
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
        ${CMAKE_CURRENT_LIST_DIR}/README.md
        DESTINATION .
        )

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)