#include "TextUiElement.h"
#include "SDL.h"

TextUiElement::TextUiElement(std::string txt, int fontSize, SDL_Rect rect, SDL_Color fgColor, SDL_Color bgColor, bool center) {
    _text = txt;
    _rectangle = rect;
    _foregroundColor = fgColor;
    _backgroundColor = bgColor;
    _fontSize = fontSize;
    _center = center;
}

TextUiElement::~TextUiElement() {
    if (_font != NULL)
        TTF_CloseFont(_font);
}

void TextUiElement::preRender(SDL_Renderer* renderer) {
    _sdlHelper = SdlHelper{};
    _font = TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", _fontSize);
}

void TextUiElement::render(SDL_Renderer* renderer)
{
    SDL_Surface* surface = TTF_RenderText_Shaded(_font, _text.c_str(), _foregroundColor, _backgroundColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    _sdlHelper.renderText(_text, _font, &_rectangle, renderer, surface, texture, false);
}

void TextUiElement::onClick() {}

bool TextUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}