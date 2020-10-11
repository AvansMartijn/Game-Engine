#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::onInit() {
	// 0 = Game | 1 = Settings
	// TODO: Maybe use type instead of id
	switchScreen(0);

	Window window = Window("FluixEngine", 1080, 720);

	for (auto& screen : screens) {
		for (auto& obj : screen->gameObjects)
			window.preRender(obj);

		for (auto& obj : screen->uiElements)
			window.preRender(obj);
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
			// TODO: This is really low at the moment, we need to optimize this next (3) sprint.
			cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			screens.at(_activeScreen)->onTick();

			window.clear();

			for (auto& obj : screens.at(_activeScreen)->gameObjects)
				window.render(obj);

			for (auto& obj : screens.at(_activeScreen)->uiElements)
				window.render(obj);

			window.display();

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
	window.cleanUp();
}

void Game::switchScreen(int screenIndex) {
	_activeScreen = screenIndex;

	screens.at(_activeScreen)->onScreenShowed();
}