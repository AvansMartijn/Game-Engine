#include "TextUiElement.h"

TextUiElement::TextUiElement(std::string txt, std::string fontKey, int fontSize, Rect rect, Color fgColor, Color bgColor, bool center) {
    _text = txt;
    _fontKey = fontKey;
    _rect = rect;
    _foregroundColor = fgColor;
    _backgroundColor = bgColor;
    _fontSize = fontSize;
    _center = center;
}

void TextUiElement::preRender(const unique_ptr<Window>& window) {
    _font = window->getFont(_fontKey, _fontSize);
}

TextUiElement::~TextUiElement() {}

void TextUiElement::render(const unique_ptr<Window>& window) {
    window->renderText(_text, _font, _rect, _foregroundColor, _backgroundColor, _center);
}

void TextUiElement::onClick() {}

bool TextUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}