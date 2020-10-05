#pragma once
#include <SDL.h>
#include "string"

class Shapes {
public:
	void DrawCube(SDL_Renderer* renderer, SDL_Color color, int x, int y, int width, int height);
	void DrawImage(SDL_Renderer* renderer, std::string image_path, int x, int y, int width, int height);
	~Shapes();

private:
	int _width;
	int _height;
	int _x;
	int _y;
	
	SDL_Texture* _texture = nullptr;
	SDL_Rect _cube;
};

extern Shapes g_ShapeDrawer;