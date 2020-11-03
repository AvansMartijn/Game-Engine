
#include "pch.h"
#include "HudUiElement.h"

HudUiElement::HudUiElement(std::string text, Color bgColor, Color fgColor, std::string fontKey, int fontSize) {
    _text = text;
    _backgroundColor = bgColor;
    _foregroundColor = fgColor;
    _fontSize = fontSize;
    _fontKey = fontKey;
}

HudUiElement::~HudUiElement() {}

void HudUiElement::preRender(const unique_ptr<Window>& window) {
    _font = window->getFont(_fontKey, _fontSize);
}

void HudUiElement::render(const unique_ptr<Window>& window) {

    window->renderHud();
}

bool HudUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rect.x && mouseX <= _rect.x + _rect.w) && (mouseY > _rect.y && mouseY < _rect.y + _rect.h);
}