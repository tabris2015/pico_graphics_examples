//
// Created by Jose Laruta on 27/5/22.
//

#ifndef PICO_GRAPH_BOX_H
#define PICO_GRAPH_BOX_H
#include "object.h"

class Box : public Object {
private:
    int32_t w;
    int32_t h;
public:
    Box(int32_t w,
        int32_t h,
        Point initial_pos,
        Pen bg_color,
        Pen color,
        Rect limits,
        PicoGraphics * display);
    void update();
    Rect get_rect();
    Rect get_rect(Point center);
};


#endif //PICO_GRAPH_BOX_H
