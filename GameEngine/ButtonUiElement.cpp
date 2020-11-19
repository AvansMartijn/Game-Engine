#include "pch.h"
#include "ButtonUiElement.h"

ButtonUiElement::ButtonUiElement(std::string text, Rect rect, Color bgColor, Color fgColor, std::string fontKey, int fontSize) {
    _text = text;
    _rect = rect;
    _backgroundColor = bgColor;
    _foregroundColor = fgColor;
    _fontSize = fontSize;
    _fontKey = fontKey;
}

ButtonUiElement::~ButtonUiElement() {}

void ButtonUiElement::preRender(const unique_ptr<Window>& window) {
    _font = window->getFont(_fontKey, _fontSize);
}

void ButtonUiElement::render(const unique_ptr<Window>& window) {

    // Draw a line arround the box
    Rect _border = _rect;
    _border.x -= 3;
    _border.h += 0;
    _border.w += 0;
    window->renderRectangle(_border, Color{ 255, 255, 255, 255 });

    window->renderRectangle(_rect, _backgroundColor);

    Rect txtRect = _rect;
    txtRect.x = txtRect.x + 10;
    txtRect.y = txtRect.y + txtRect.h / 7;

    window->renderText(_text, _font, txtRect, _foregroundColor, _backgroundColor, false);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rect.x && mouseX <= _rect.x + _rect.w) && (mouseY > _rect.y && mouseY < _rect.y + _rect.h);
}