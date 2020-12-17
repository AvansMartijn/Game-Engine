#pragma once
#include <cstdint>

typedef uint32_t Uint32;
typedef uint8_t Uint8;
typedef uint32_t Uint32;
typedef uint8_t Uint8;
typedef int32_t Sint32;
#define BUTTON(X)       (1 << ((X)-1))
#define BUTTON_LEFT     1
#define BUTTON_MIDDLE   2
#define BUTTON_RIGHT    3
#define BUTTON_X1       4
#define BUTTON_X2       5
#define BUTTON_LMASK    BUTTON(BUTTON_LEFT)
#define BUTTON_MMASK    BUTTON(BUTTON_MIDDLE)
#define BUTTON_RMASK    BUTTON(BUTTON_RIGHT)
#define SBUTTON_X1MASK  BUTTON(BUTTON_X1)
#define BUTTON_X2MASK   BUTTON(BUTTON_X2)