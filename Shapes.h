#pragma once
#include <SDL.h>

class Shapes {
public:
	void DrawCube(SDL_Renderer* renderer, SDL_Color color, int x, int y, int width, int height);

private:
	int _width;
	int _height;
	int _x;
	int _y;

	SDL_Rect _cube;
};

extern Shapes g_ShapeDrawer;