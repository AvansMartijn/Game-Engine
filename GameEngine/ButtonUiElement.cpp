#include "pch.h"
#include "ButtonUiElement.h"

ButtonUiElement::ButtonUiElement(std::string btnText, Rect btnRect, Color bgColor, Color fgColor, std::string fontKey, int fontSize) {
    text = btnText;
    rect = btnRect;
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
    Rect _border = rect;
    _border.x -= 3;
    _border.h += 0;
    _border.w += 0;
    window->renderRectangle(_border, Color{ 255, 255, 255, 255 });

    window->renderRectangle(rect, _backgroundColor);

    Rect txtRect = rect;
    txtRect.x = txtRect.x + 10;
    txtRect.y = txtRect.y + txtRect.h / 7;

    window->renderText(text, _font, txtRect, _foregroundColor, _backgroundColor, false);
}

bool ButtonUiElement::isInBound(int mouseX, int mouseY) {
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w) && (mouseY > rect.y && mouseY < rect.y + rect.h);
}