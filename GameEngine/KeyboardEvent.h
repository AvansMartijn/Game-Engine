#pragma once
#include "Definitions.h"
#include "Keycode.h"
#include "Scancode.h"

struct KeyboardEvent {
    Uint8 state;
    Uint8 repeat;
    Keycode keyCode;
    Scancode scanCode;

    KeyboardEvent() {}
    KeyboardEvent(SDL_KeyboardEvent e) {
        state = e.state;
        repeat = e.repeat;
        keyCode = (Keycode)e.keysym.sym;
        scanCode = (Scancode)e.keysym.scancode;
    }
};

