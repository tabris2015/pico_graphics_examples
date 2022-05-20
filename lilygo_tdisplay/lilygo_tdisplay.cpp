#include <math.h>
#include <string.h>

#include "hardware/gpio.h"  // Workaround SDK bug - https://github.com/raspberrypi/pico-sdk/issues/3
#include "hardware/pwm.h"

#include "lilygo_tdisplay.h"

const uint8_t LED_R = 25;

namespace lilygo {

    LilygoTDisplay::LilygoTDisplay(uint16_t *buf, int width, int height, spi_inst_t *spi,
                                   uint cs, uint dc, uint sck, uint mosi, uint bl, uint8_t pwr)
            : PicoGraphics(width, height, buf),
            screen(width, height, buf, spi, cs, dc, sck, mosi, pimoroni::PIN_UNUSED, bl)  {
        __fb = buf;
    }

    void LilygoTDisplay::init() {
        // setup the led for pwm control
        pwm_config cfg = pwm_get_default_config();
        pwm_config_set_output_polarity(&cfg, true, true);

        // red
        pwm_set_wrap(pwm_gpio_to_slice_num(LED_R), 65535);
        pwm_init(pwm_gpio_to_slice_num(LED_R), &cfg, true);
        gpio_set_function(LED_R, GPIO_FUNC_PWM);

        // setup button inputs
        gpio_set_function(A, GPIO_FUNC_SIO); gpio_set_dir(A, GPIO_IN); gpio_pull_up(A);
        gpio_set_function(B, GPIO_FUNC_SIO); gpio_set_dir(B, GPIO_IN); gpio_pull_up(B);
        gpio_set_dir(R, GPIO_OUT); gpio_put(R, true);

        // power on pin
        gpio_init(PWR);
        gpio_set_dir(PWR, GPIO_OUT);
        gpio_put(PWR, 1);
        // initialise the screen
        screen.init();
    }

    void LilygoTDisplay::update() {
        screen.update();
    }

    void LilygoTDisplay::set_backlight(uint8_t brightness) {
        screen.set_backlight(brightness);
    }

    void LilygoTDisplay::set_led(uint8_t r) {
        // gamma correct the provided 0-255 brightness value onto a
        // 0-65535 range for the pwm counter
        static const float gamma = 2.8;

        uint16_t value;

        // red
        value = (uint16_t)(pow((float)(r) / 255.0f, gamma) * 65535.0f + 0.5f);
        pwm_set_gpio_level(LED_R, value);
    }

    bool LilygoTDisplay::is_pressed(uint8_t button) {
        return !gpio_get(button);
    }

    void LilygoTDisplay::flip() {
        screen.flip();
    }
}
