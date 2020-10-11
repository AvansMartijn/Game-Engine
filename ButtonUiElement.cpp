#include "ButtonUiElement.h"

#include <iostream>
using namespace std;

ButtonUiElement::ButtonUiElement() {}

ButtonUiElement::~ButtonUiElement() {}

void ButtonUiElement::render(SDL_Renderer* renderer)
{
    // TODO: The code does not work here, it does in the window. We really want to seperate it, because not every element will be a rectangle
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderPresent(renderer);
}

void ButtonUiElement::onClick() {
    cout << "YOU CLICKED ME \n";
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= x && mouseX <= x + width) && (mouseY > y && mouseY < y + height);
}