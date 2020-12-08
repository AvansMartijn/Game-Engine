#pragma once
#include "ParticleSystem.h"
#include <SDL_image.h>

class Particles : public ParticleSystem
{
public:
    Particles() {}
    virtual ~Particles() {}

    enum PatticleStyle
    {
        NONE,
        FIRE,
        FIRE_WORK,
        SUN,
        GALAXY,
        FLOWER,
        METEOR,
        SPIRAL,
        EXPLOSION,
        SMOKE,
        SNOW,
        RAIN,
    };

    PatticleStyle style_ = NONE;
    void setStyle(PatticleStyle style);
    SDL_Texture* getDefaultTexture()
    {
        static SDL_Texture* t = IMG_LoadTexture(_renderer, "res/gfx/fire.png");
        //printf(SDL_GetError());
        return t;
    }
};
