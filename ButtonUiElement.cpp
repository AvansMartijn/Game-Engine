#include "ButtonUiElement.h"

ButtonUiElement::ButtonUiElement(SDL_Rect rect, SDL_Color bgColor) {
    _rectangle = rect;
    _backgroundColor = bgColor;
}

ButtonUiElement::~ButtonUiElement() {}

void ButtonUiElement::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderFillRect(renderer, &_rectangle);
}

void ButtonUiElement::onClick() {
    _game->switchScreen(0);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rectangle.x && mouseX <= _rectangle.x + _rectangle.w) && (mouseY > _rectangle.y && mouseY < _rectangle.y + _rectangle.h);
}