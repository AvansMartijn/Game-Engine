#include "Game.h"
#include "AbstractGame.h"
#include "AbstractScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"

void Game::init() {
	// 0 = Game | 1 = Settings
	switchScreen(1);

	Window window = Window("FluixEngine", 1080, 720);

	SDL_Event event;

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	while (running) {
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60.0) {
			// TODO: Commented this out, not sure if we still need this.
			//cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			// TODO: If you change screen (from 1 -> 0, this does not update)
			screens.at(_activeScreen)->tick();

			window.clear();

			// This has to be here. When moved to scene the window closes.
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

	// TODO: Why is this empty on KEY -> ESCAPE.
	screens.at(_activeScreen)->init();
}