#pragma once
#include "AbstractUiElement.h"
#include "SDL_image.h"
#include "SdlHelper.h"

#include <string>
#include <iostream>
using namespace std;

class ImageUiElement: public AbstractUiElement
{
private:
	std::string _filePath;
	SDL_Texture* _texture;
public:
	ImageUiElement(std::string filePath, SDL_Rect rect);
	~ImageUiElement();

	void preRender(SDL_Renderer* renderer);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(SDL_Renderer* renderer);
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
};

