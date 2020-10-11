#include "TextUiElement.h"

TextUiElement::TextUiElement(std::string txt, int fontSize, SDL_Rect rect, SDL_Color fgColor, SDL_Color bgColor) {
    _text = txt;
    _rectangle = rect;
    _foregroundColor = fgColor;
    _backgroundColor = bgColor;
    _fontSize = fontSize;
}

TextUiElement::~TextUiElement() {}

void TextUiElement::render(SDL_Renderer* renderer)
{
    TTF_Font* sans = TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", _fontSize);
    SDL_Surface* sm = TTF_RenderText_Shaded(sans, _text.c_str(), _foregroundColor, _backgroundColor);
    SDL_Texture* msg = SDL_CreateTextureFromSurface(renderer, sm);

    SDL_RenderCopy(renderer, msg, NULL, &_rectangle);
    SDL_FreeSurface(sm);
    SDL_DestroyTexture(msg);
}

void TextUiElement::onClick() {
    std::cout << "YOU CLICKED ME \n";
}

bool TextUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}