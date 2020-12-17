#pragma once
#include "Definitions.h"
#include <SDL_events.h>

struct MouseWheelEvent {
    Uint32 type;
    Sint32 x;
    Sint32 y;
    Uint32 direction;

    MouseWheelEvent() {}

    MouseWheelEvent(SDL_MouseWheelEvent e) {
        type = e.type;
        x = e.x;
        y = e.y;
        direction = e.direction;
    }
};