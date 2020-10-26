#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::onInit() {
	_window = unique_ptr<Window>(new Window("FluixEngine", 1080, 720));
	_window->registerTexture("Krool", "res/gfx/KINGKROOL.png");
	_window->registerTexture("Border", "res/gfx/Border.png");
	_window->registerTexture("Background", "res/gfx/bg.png");
	_window->registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");
	_window->registerFont("Paint", "res/fonts/Paint Drops.ttf");
	_window->registerFont("Portal", "res/fonts/PortalFont.ttf");

	// 0 = Game | 1 = Settings
	// TODO: Maybe use type instead of id
	switchScreen(0);

	for (auto& screen : screens) {
		for (auto& uiElement : screen->uiElements)
			uiElement->preRender(_window);
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

			for (auto& gameObject : screens.at(_activeScreen)->gameObjects)
				gameObject->render(_window);

			for (auto& uiElement : screens.at(_activeScreen)->uiElements)
				uiElement->render(_window);

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

void Game::switchScreen(int screenIndex) {
	_activeScreen = screenIndex;
	screens.at(_activeScreen)->onScreenShowed();
}