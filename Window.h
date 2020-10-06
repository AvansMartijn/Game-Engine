#pragma once
#include "string"
#include "SDL.h"

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	// Dat inline hoeft niet maar is makkelijker om te lezen
	inline bool isClosed() const { return _closed; };

	void pollEvents();
	void clear() const;

private:
	bool init();

private:
	std::string _title;
	int _width;
	int _height;

	bool _closed;

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
};
