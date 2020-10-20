#pragma once
#include "AbstractUiElement.h"
#include <string>
#include <iostream>

using namespace std;

class ImageUiElement: public AbstractUiElement
{
public:
	ImageUiElement(std::string imageKey, Rect rect);
	~ImageUiElement();

	/// This is called one time before going into the render loop.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void preRender(Window* window);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(Window* window);
	/// <summary>
	/// The function executed when the element is clicked on.
	/// </summary>
	void onClick();
	/// <summary>
	/// Checks if the mouse is within the bounds of the element.
	/// </summary>
	/// <param name="mouseX">X coordinate of the mouse</param>
	/// <param name="mouseY">Y coordinate of the mouse</param>
	/// <returns></returns>
	bool isInBound(int mouseX, int mouseY);
private:
	std::string _textureKey;
};

