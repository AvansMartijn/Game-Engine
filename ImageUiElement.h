#pragma once
#include "AbstractUiElement.h"
#include <string>
#include "SDL_image.h"
#include "SdlHelper.h"
#include <iostream>
using namespace std;

class ImageUiElement: public AbstractUiElement
{
private:
	std::string _filePath;
public:
	ImageUiElement(std::string filePath, SDL_Rect rect);
	~ImageUiElement();

	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

