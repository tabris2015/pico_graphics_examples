//
// Created by Jose Laruta on 27/5/22.
//

#include "box.h"

Box::Box(int32_t w,
         int32_t h,
         Point initial_pos,
         Pen bg_color,
         Pen color,
         Rect limits,
         PicoGraphics *display)
         :w(w), h(h),
          Object(initial_pos,
                 bg_color,
                 color,
                 limits,
                 display) {

}

void Box::update() {
    display->set_pen(bg_color);
    display->rectangle(get_rect(prev_pos));
    display->set_pen(color);
    display->rectangle(get_rect());
}

Rect Box::get_rect() {
    return Rect(pos.x - w / 2, pos.y - h / 2, w, h);
}

Rect Box::get_rect(Point center) {
    return Rect(center.x - w / 2, center.y - h / 2, w, h);
}
