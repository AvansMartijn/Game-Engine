#include "pch.h"
#include "HpBarUIElement.h"
#include "AbstractUiElement.h"
#include "AbstractGame.h"

#include <string>
#include <iostream>

HpBarUIElement::HpBarUIElement(int x, int y, int w, int h, float percentage, const Color& fgColor, const Color& bgColor) {
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    percent = percentage;
    _bgColor = bgColor;
    _fgColor = fgColor;
}

HpBarUIElement::~HpBarUIElement() {}

void HpBarUIElement::preRender(const unique_ptr<Window>& window) {}

void HpBarUIElement::render(const unique_ptr<Window>& window) {
    window->renderHPBar(_x, _y, _w, _h, percent, _fgColor, _bgColor);
}

bool HpBarUIElement::isInBound(int mouseX, int mouseY) const  {
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w) && (mouseY > rect.y && mouseY < rect.y + rect.h);
}
