#pragma once
#include "Definitions.h"

struct MouseButtonEvent {
    Uint32 type;
    Uint8 button;
    Uint8 state;
    Uint8 clicks;
    Sint32 x;
    Sint32 y;

    MouseButtonEvent() {}

    MouseButtonEvent(SDL_MouseButtonEvent e) {
        button = e.button;
        clicks = e.clicks;
        state = e.state;
        type = e.type;
        x = e.x;
        y = e.y;
    }
};

