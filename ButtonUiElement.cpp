#include "ButtonUiElement.h"

ButtonUiElement::ButtonUiElement(std::string text, SDL_Rect rect, SDL_Color bgColor, SDL_Color fgColor) {
    _text = text;
    _rectangle = rect;
    _backgroundColor = bgColor;
    _foregroundColor = fgColor;
}

ButtonUiElement::~ButtonUiElement() {}

void ButtonUiElement::preRender(SDL_Renderer* renderer) {

}

void ButtonUiElement::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderFillRect(renderer, &_rectangle);

    TextUiElement txtUiElement = TextUiElement(_text, 12, _rectangle, _foregroundColor, _backgroundColor, false);
    txtUiElement.render(renderer);
}

void ButtonUiElement::onClick() {
    _game->switchScreen(0);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rectangle.x && mouseX <= _rectangle.x + _rectangle.w) && (mouseY > _rectangle.y && mouseY < _rectangle.y + _rectangle.h);
}