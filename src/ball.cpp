//
// Created by Jose Laruta on 27/5/22.
//

#include "ball.h"

Ball::Ball(int32_t radius,
           Point initial_pos,
           Pen bg_color,
           Pen color,
           Rect limits,
           PicoGraphics *display)
           : radius(radius),
             Object(initial_pos,
                    bg_color,
                    color,
                    limits,
                    display) {

}

void Ball::update() {
    display->set_pen(bg_color);
    display->circle(prev_pos, radius);
    display->set_pen(color);
    display->circle(pos, radius);
}

Rect Ball::get_rect() {
    return Rect(pos.x - radius, pos.y - radius, radius * 2, radius * 2);
}
