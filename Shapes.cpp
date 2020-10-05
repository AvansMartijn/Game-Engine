#include "Shapes.h"

Shapes g_ShapeDrawer;

void Shapes::DrawCube(SDL_Renderer* renderer, SDL_Color color, int x, int y, int width, int height)
{
	_cube.w = width;
	_cube.h = height;
	_cube.x = x;
	_cube.y = y;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_RenderFillRect(renderer, &_cube);
	SDL_RenderPresent(renderer);
	// Clear als het goed is de renderer
	SDL_RenderClear(renderer);
}

