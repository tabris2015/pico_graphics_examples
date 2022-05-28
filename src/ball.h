//
// Created by Jose Laruta on 27/5/22.
//

#ifndef PICO_GRAPH_BALL_H
#define PICO_GRAPH_BALL_H
#include "object.h"

class Ball : public Object{
private:
    int32_t radius;
public:
    Ball(int32_t radius,
         Point initial_pos,
         Pen bg_color,
         Pen color,
         Rect limits,
         PicoGraphics * display);
    void update();
    Rect get_rect();
};


#endif //PICO_GRAPH_BALL_H
