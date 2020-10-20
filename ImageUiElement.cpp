#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string filePath, SDL_Rect rect) {
    _rectangle = rect;
    _filePath = filePath;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(Window* window) {
    //_texture = SdlHelper{}.getTexture(_filePath, renderer);
}

void ImageUiElement::render(Window* window) {
    SDL_RenderCopy(window->getRenderer(), _texture, NULL, &_rectangle);
}

void ImageUiElement::onClick() {}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}