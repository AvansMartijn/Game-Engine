#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_HpBarUIElement __declspec(dllexport)
#else
#define GAMEENGINE_HpBarUIElement __declspec(dllimport)
#endif
#include "string"
#include "pch.h"
#include "AbstractUiElement.h"

using namespace std;

/// <summary>
/// HP Bar element
/// </summary>
class GAMEENGINE_HpBarUIElement HpBarUIElement : public AbstractUiElement {
private:
	Color _fgColor;
	Color _bgColor;
	int _x, _y, _w, _h;
public:
	float percent;

	HpBarUIElement(int x, int y, int w, int h, float percentage, Color fgColor, Color bgColor);
	~HpBarUIElement();

	/// <summary>
	/// pre render the element
	/// </summary>
	/// <param name="window"></param>
	void preRender(const unique_ptr<Window>& window);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(const unique_ptr<Window>& window);
	/// <summary>
	/// Checks if the mouse is within the bounds of the element.
	/// </summary>
	/// <param name="mouseX">X coordinate of the mouse</param>
	/// <param name="mouseY">Y coordinate of the mouse</param>
	/// <returns></returns>
	bool isInBound(int mouseX, int mouseY);
};

