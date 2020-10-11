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
	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

