#include "pch.h"
#include "TextUiElement.h"

TextUiElement::TextUiElement(std::string txt, std::string fontKey, int fontSize, Rect textRect, Color fgColor, Color bgColor, bool center, bool mulitLine) {
    text = txt;
    _fontKey = fontKey;
    rect = textRect;
    _foregroundColor = fgColor;
    _backgroundColor = bgColor;
    _fontSize = fontSize;
    _center = center;
    _multiLine = mulitLine;
}

TextUiElement::TextUiElement(std::vector<std::string> txt, std::string fontKey, int fontSize, Rect textRect, Color fgColor, Color bgColor, bool center, bool mulitLine) {
    textLines = txt;
    _fontKey = fontKey;
    rect = textRect;
    _foregroundColor = fgColor;
    _backgroundColor = bgColor;
    _fontSize = fontSize;
    _center = center;
    _multiLine = mulitLine;
}

void TextUiElement::preRender(const unique_ptr<Window>& window) {
    _font = window->getFont(_fontKey, _fontSize);
}

TextUiElement::~TextUiElement() {}

void TextUiElement::render(const unique_ptr<Window>& window) {
    if (textLines.size() != 0)
        window->renderMultiLineText(textLines, _font, rect, _foregroundColor, _backgroundColor, _center, _multiLine);
    else
        window->renderText(text, _font, rect, _foregroundColor, _backgroundColor, _center, _multiLine);
    
}

bool TextUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}