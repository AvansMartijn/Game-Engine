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

TextUiElement::~TextUiElement() {}

void TextUiElement::preRender(SDL_Renderer* renderer) {

}

void TextUiElement::render(SDL_Renderer* renderer)
{
    TTF_Font* sansFont = TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", _fontSize);
    SDL_Surface* messageSurface = TTF_RenderText_Shaded(sansFont, _text.c_str(), _foregroundColor, _backgroundColor);
    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);

    SDL_Rect rect;
    rect.x = _rectangle.x;
    rect.y = _rectangle.y;
    rect.w = messageSurface->w;
    rect.h = messageSurface->h;
    if (_center) {
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);

        rect.x = dm.w / 2;
    }

    SDL_RenderCopy(renderer, messageTexture, NULL, &rect);
    SDL_FreeSurface(messageSurface);
    SDL_DestroyTexture(messageTexture);
}

void TextUiElement::onClick() {}

bool TextUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}