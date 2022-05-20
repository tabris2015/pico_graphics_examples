add_library(lilygo_tdisplay INTERFACE)
target_compile_definitions(lilygo_tdisplay INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/lilygo_tdisplay.cpp
        )

target_include_directories(lilygo_tdisplay INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(lilygo_tdisplay INTERFACE pico_stdlib hardware_spi hardware_pwm hardware_dma st7789 pico_graphics)