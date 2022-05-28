#include "pico/stdlib.h"
//#include "drivers/st7789/st7789.hpp"
#include "lilygo_tdisplay.h"
#include "ball.h"
#include "box.h"

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

bool led_state = true;
Pen background_pen;
Pen ball_pen;
Pen player_pen;
Point ball_center_point(25, 25);

void setup()
{
    display.init();
    display.set_backlight(100);
    Rect box(0, 0, WIDTH, HEIGHT);
    display.set_pen(background_pen);
    display.rectangle(box);
    display.update();
}

void update_ball();

int main() {
    background_pen = display.create_pen(50, 50, 50);
    ball_pen = display.create_pen(0, 255, 70);
    player_pen = display.create_pen(200, 255, 200);
    display.init();

    Ball ball(10,
                Point(WIDTH / 2, HEIGHT / 2),
                background_pen,
                ball_pen,
                display.bounds,
                &display);

    Box player(32, 8,
              Point(WIDTH / 2, HEIGHT - 10),
              background_pen,
              player_pen,
              display.bounds,
              &display);

    display.set_backlight(100);
    display.set_pen(background_pen);
    display.rectangle(display.bounds);
    ball.update();
    player.update();
    display.update();
    int32_t vy = 2;
    int32_t vx = 0;

    while (true) {
        if (!display.bounds.contains(ball.get_rect())) {
            vy = - vy;
        }
        if (display.is_pressed(LilygoTDisplay::A)) {
            vx = -2;
        } else if (display.is_pressed(LilygoTDisplay::B)) {
            vx = 2;
        }
        else vx = 0;

        ball.move(0, vy);
        player.move(vx, 0);

        led_state = !led_state;
        display.set_led(led_state ? 255 : 0);
        ball.update();
        player.update();
        display.update();

        sleep_ms(10);
    }
}
