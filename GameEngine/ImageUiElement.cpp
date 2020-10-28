#include "pch.h"
#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string textureKey, Rect rect) {
    _rect = rect;
    _textureKey = textureKey;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(const unique_ptr<Window>& window) {}

void ImageUiElement::render(const unique_ptr<Window>& window) {
    window->renderTexture(_textureKey, _rect);
}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}