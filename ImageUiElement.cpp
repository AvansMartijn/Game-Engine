#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string filePath, SDL_Rect rect) {
    _rectangle = rect;
    _filePath = filePath;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(SDL_Renderer* renderer) {
    _texture = SdlHelper{}.getTexture(_filePath, renderer);
}

void ImageUiElement::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, _texture, NULL, &_rectangle);
}

void ImageUiElement::onClick() {}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}