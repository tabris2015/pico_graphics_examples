//
// Created by Jose Laruta on 27/5/22.
//

#include "object.h"


Object::Object(Point initial_pos,
               Pen bg_color,
               Pen color,
               Rect limits,
               PicoGraphics * display)
: pos(initial_pos),
bg_color(bg_color),
color(color),
prev_pos(initial_pos),
limits(limits),
display(display){
    pos.clamp(limits);
}

void Object::set_position(Point new_pos) {
    prev_pos = pos;
    pos = new_pos;
    pos.clamp(limits);
}

void Object::update() {
}

void Object::move(int32_t dx, int32_t dy) {
    prev_pos = pos;
    pos += Point(dx, dy);
    pos.clamp(limits);
}

Rect Object::get_rect() {
    return Rect();
}
