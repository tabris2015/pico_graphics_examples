#pragma once

#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"

namespace lilygo {

    class LilygoTDisplay : public pimoroni::PicoGraphics {
    public:
        static const int WIDTH = 240;
        static const int HEIGHT = 135;
        static const int PORTRAIT_WIDTH  = 135;
        static const int PORTRAIT_HEIGHT = 240;
        static const uint8_t A = 6;
        static const uint8_t B = 7;
        static const uint8_t R = 0;
        static const uint8_t PWR = 22;

        uint16_t *__fb;
    private:
        pimoroni::ST7789 screen;
        spi_inst_t *spi = PIMORONI_SPI_DEFAULT_INSTANCE;

    public:
        LilygoTDisplay(uint16_t *buf, int width, int height, spi_inst_t *spi,
                       uint cs, uint dc, uint sck, uint mosi, uint bl, uint8_t pwr);

        void init();
        void update();
        void set_backlight(uint8_t brightness);
        void set_led(uint8_t r);
        bool is_pressed(uint8_t button);
        void flip();
    };

}
