#include "Game.h"

Game::Game(const char* title, int width, int height) : AbstractGame(title, width, height) {}

Game::~Game() {}

void Game::onInit() {
	registerTexture("Krool", "res/gfx/KINGKROOL.png");
	registerTexture("Border", "res/gfx/Border.png");
	registerTexture("Background", "res/gfx/bg.png");
	registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");
	registerFont("Paint", "res/fonts/Paint Drops.ttf");
	registerFont("Portal", "res/fonts/PortalFont.ttf");

	switchScreen(4);

	for (int i = 0; i < screens.size(); i++) {
		for (shared_ptr<AbstractUiElement>& uiElement : screens[i]->uiElements)
			uiElement->preRender(_window);
	}

	gameLoop();
}

void Game::switchScreen(int screenIndex) {
	if (screenIndex + 1 <= screens.size()) {
		_activeScreen = screenIndex;
		screens.at(_activeScreen)->onScreenShowed();
	}
}