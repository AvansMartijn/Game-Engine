#include "ButtonUiElement.h"

ButtonUiElement::ButtonUiElement(std::string text, SDL_Rect rect, SDL_Color bgColor, SDL_Color fgColor, int fontSize) {
    _text = text;
    _rectangle = rect;
    _backgroundColor = bgColor;
    _foregroundColor = fgColor;
    _fontSize = fontSize;
}

ButtonUiElement::~ButtonUiElement() {}

void ButtonUiElement::preRender(SDL_Renderer* renderer) {
    _sdlHelper = SdlHelper{};
    _font = TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", _fontSize);
}

void ButtonUiElement::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderFillRect(renderer, &_rectangle);

    SDL_Surface* surface = TTF_RenderText_Shaded(_font, _text.c_str(), _foregroundColor, _backgroundColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect txtRect = _rectangle;
    txtRect.x = (1080 / 2);
    txtRect.y = txtRect.y + txtRect.h / 4;
   _sdlHelper.renderText(_text, _font, &txtRect, renderer, surface, texture, false);
}

void ButtonUiElement::onClick() {
    _game->switchScreen(0);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rectangle.x && mouseX <= _rectangle.x + _rectangle.w) && (mouseY > _rectangle.y && mouseY < _rectangle.y + _rectangle.h);
}