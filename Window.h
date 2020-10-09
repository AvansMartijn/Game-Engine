#pragma once
#include "string"
#include "SDL.h"
#include "GameObject.h"

class Window {
public:
	Window(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(const shared_ptr<GameObject>& gameObject);
	void display();
	~Window();

	// Dat inline hoeft niet maar is makkelijker om te lezen
	inline bool isClosed() const { return _closed; };

	//void pollEvents();
	//void clear() const;

private:
	bool init();

private:
	//std::string _title;
	//int _width;
	//int _height;

	bool _closed;

	SDL_Window* _window;
	SDL_Renderer* _renderer;
};
