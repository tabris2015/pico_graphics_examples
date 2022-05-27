//
// Created by pepe on 20-05-22.
//
pragma once
#include "pico/stdlib.h"

namespace game {
    class Object {
    public:
        Object();
        void move();
        void draw();
    private:
        uint16_t x;
        uint16_t y;
        bool active;
    }
}