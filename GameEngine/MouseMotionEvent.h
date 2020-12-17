#pragma once
#include "Definitions.h"
#include <SDL_events.h>

struct MouseMotionEvent{
    Uint32 type;
    Uint32 state;
    Sint32 x;
    Sint32 y;
    Sint32 xrel;
    Sint32 yrel;

    MouseMotionEvent() {}

    MouseMotionEvent(SDL_MouseMotionEvent e) {
        type = e.type;
        state = e.state;
        x = e.x;
        y = e.y;
        xrel = e.xrel;
        yrel = e.yrel;
    }
};

