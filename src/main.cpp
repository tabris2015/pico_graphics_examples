#include "pico/stdlib.h"
//#include "drivers/st7789/st7789.hpp"
#include "lilygo_tdisplay.h"

// new pins
#define WIDTH 135
#define HEIGHT 240
#define MOSI_PIN 3
#define SCK_PIN 2
#define CS_PIN 5
#define DC_PIN 1
#define BL_PIN 4
#define PWR_ON_PIN 22

using namespace pimoroni;
using namespace lilygo;

uint16_t buffer[WIDTH * HEIGHT];

LilygoTDisplay display(buffer, WIDTH, HEIGHT, spi0,
                       CS_PIN, DC_PIN, SCK_PIN, MOSI_PIN, BL_PIN, PWR_ON_PIN);
int main() {
//    gpio_init(LED_PIN);
//    gpio_init(RESET_PIN);
//    gpio_set_dir(LED_PIN, GPIO_OUT);
//    gpio_set_dir(RESET_PIN, GPIO_OUT);
    display.init();
    display.set_backlight(127);
    Rect box(15, 15, WIDTH - 30, HEIGHT - 30);
    Point p(25, 25);
    display.set_pen(255, 255, 0);
    display.rectangle(box);
    display.set_pen(40, 0, 170);
    display.text("hola", p, 25, 4);
    display.update();
    while(true) {
        if(display.is_pressed(LilygoTDisplay::A))
        {
            p += Point(0, 1);
        }
        else if(display.is_pressed(LilygoTDisplay::B))
        {
            p -= Point(0, 1);
        }
        else {
            p += Point(0, 0);
        }
        display.set_pen(255, 255, 0);
        display.rectangle(box);
        display.set_pen(40, 0, 170);
        display.text("hola", p, 25, 4);
        display.update();
        sleep_ms(10);
    }
}