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

void ButtonUiElement::preRender(Window* window) {
    _font = window->getFont(_fontKey, _fontSize);
}

void ButtonUiElement::render(Window* window){

    // Draw a line arround the box
    Rect _border = _rect;
    _border.x -= 3;
    _border.y -= 3;
    _border.h += 6;
    _border.w += 6;
    window->renderRectangle(_border, Color{ 0, 0, 0, 255 });

    window->renderRectangle(_rect, _backgroundColor);

    Rect txtRect = _rect;
    txtRect.x = window->getWidth() / 2 - 60;
    txtRect.y = txtRect.y + txtRect.h / 4;
    
    window->renderText(_text, _font, txtRect, _foregroundColor, _backgroundColor, false);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= _rect.x && mouseX <= _rect.x + _rect.w) && (mouseY > _rect.y && mouseY < _rect.y + _rect.h);
}