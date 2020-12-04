#include "pch.h"
#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string textureKey, Rect rect, int alpha) {
    _rect = rect;
    _textureKey = textureKey;
    _alpha = alpha;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(const unique_ptr<Window>& window) {}

void ImageUiElement::render(const unique_ptr<Window>& window) {
    window->renderTexture(_textureKey, _rect, 0.0f, true, "", _alpha);
}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}