include(../pimoroni-pico/drivers/st7789/st7789.cmake)
include(../pimoroni-pico/libraries/pico_graphics/pico_graphics.cmake)

add_library(lilygo_tdisplay INTERFACE)

target_sources(lilygo_tdisplay INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/lilygo_tdisplay.cpp
        )

target_include_directories(lilygo_tdisplay INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Pull in pico libraries that we need
target_link_libraries(lilygo_tdisplay INTERFACE pico_stdlib hardware_spi hardware_pwm hardware_dma st7789 pico_graphics)