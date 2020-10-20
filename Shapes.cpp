#include "Shapes.h"
#include "SDL_Image.h"
#include <iostream>

Shapes g_ShapeDrawer;

Shapes::~Shapes()
{
	SDL_DestroyTexture(_texture);
}

// TODO: Shapes
void Shapes::drawCube(SDL_Renderer* renderer, SDL_Color color, int x, int y, int width, int height)
{
	_cube.w = width;
	_cube.h = height;
	_cube.x = x;
	_cube.y = y;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_RenderFillRect(renderer, &_cube);
	SDL_RenderPresent(renderer);
}

void Shapes::drawImage(SDL_Renderer* renderer, std::string image_path, int x, int y, int width, int height)
{
	auto surface = IMG_Load(image_path.c_str());
	if (!surface)
		std::cerr << "Failed to create surface in image drawer! \n";

	_texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(!_texture)
		std::cerr << "Failed to create texture in image drawer! \n";

	SDL_FreeSurface(surface);

	_cube.w = width;
	_cube.h = height;
	_cube.x = x;
	_cube.y = y;
	SDL_RenderCopy(renderer, _texture, nullptr, &_cube);
	SDL_RenderPresent(renderer);
	_texture = nullptr;
}


