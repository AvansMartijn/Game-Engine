#include "pch.h"
#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(const std::string& textureKey, const Rect& imageRect, int alpha, bool flipRight) {
    rect = imageRect;
    _textureKey = textureKey;
    _alpha = alpha;
    _flipRight = flipRight;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::preRender(const unique_ptr<Window>& window) {}

void ImageUiElement::render(const unique_ptr<Window>& window) {
    window->renderTexture(_textureKey, rect, 0.0f, _flipRight, _alpha);
}

bool ImageUiElement::isInBound(int mouseX, int mouseY) const {
    return false;
}