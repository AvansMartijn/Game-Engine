#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string textureKey, Rect rect) {
    _rect = rect;
    _textureKey = textureKey;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(Window* window) {}

void ImageUiElement::render(Window* window) {
    window->renderTexture(_textureKey, _rect);
}

void ImageUiElement::onClick() {}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}