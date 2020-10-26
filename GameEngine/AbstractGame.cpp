#include "pch.h"
#include "AbstractGame.h"

AbstractGame::AbstractGame(const char* title, int width, int height) {
	_window = unique_ptr<Window>(new Window("Fluix", 1080, 720));
	_activeScreen = 0;
}

AbstractGame::~AbstractGame() {
}

void AbstractGame::gameLoop() {
	for (int i = 0; i < screens.size(); i++) {
		for (shared_ptr<AbstractUiElement>& obj : screens[i]->uiElements)
			obj->preRender(_window);
	}

	SDL_Event event;

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	while (running) {
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60.0) {
			//cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			screens.at(_activeScreen)->onTick();

			_window->clear();

			for (shared_ptr<GameObject>& obj : screens.at(_activeScreen)->gameObjects)
				obj->render(_window);

			for (shared_ptr<AbstractUiElement>& obj : screens.at(_activeScreen)->uiElements)
				obj->render(_window);

			_window->display();
			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_KEYDOWN:
					screens.at(_activeScreen)->handleKeyboardInput(event.key);
					break;
				case SDL_MOUSEMOTION:
					screens.at(_activeScreen)->handleMouseMotionInput(event.motion);

					break;
				case SDL_MOUSEBUTTONDOWN:
					screens.at(_activeScreen)->handleMouseClickInput(event.button);

					break;
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
				}
			}
		}
	}
}

void AbstractGame::registerTexture(std::string textureKey, std::string texturePath) {
	_window->registerTexture(textureKey, texturePath);
}

void AbstractGame::registerFont(std::string fontKey, std::string fontPath) {
	_window->registerFont(fontKey, fontPath);
}