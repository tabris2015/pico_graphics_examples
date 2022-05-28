//
// Created by Jose Laruta on 27/5/22.
//

#ifndef PICO_GRAPH_OBJECT_H
#define PICO_GRAPH_OBJECT_H
#include "pico_graphics.hpp"

using namespace pimoroni;
class Object {
public:
    Point pos;
    Point prev_pos;
    Pen color;
    Pen bg_color;
    Rect limits;
    Rect bbox;
    PicoGraphics * display;
public:
    Object(Point initial_pos,
           Pen bg_color,
           Pen color,
           Rect limits,
           PicoGraphics * display);
    void set_position(Point new_pos);
    void move(int32_t dx, int32_t dy);
    void update();
    Rect get_rect();
};


#endif //PICO_GRAPH_OBJECT_H
