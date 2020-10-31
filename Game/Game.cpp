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

	for (size_t i = 0; i < screens.size(); i++) {
		for (shared_ptr<AbstractUiElement>& uiElement : screens[i]->uiElements)
			uiElement->preRender(_window);
	}

	gameLoop();
}

int Game::getPreviousScreen() {
	if (_previousScreens.size() > 0)
	{
		int value = _previousScreens.top();
		_previousScreens.pop();
		return value;
	}
	return -1;
}

void Game::switchScreen(int screenIndex) {

	size_t index = screenIndex;
	if (index == -1)
		index = this->getPreviousScreen();
	else if (_activeScreen)
		_previousScreens.push(_activeScreen);

	if (index + 1 <= screens.size()) {
		_activeScreen = index;
		screens.at(_activeScreen)->onScreenShowed();
	}
}