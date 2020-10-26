#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::onInit() {
	Window win = Window("FluixEngine", 1080, 720);
	_window = &win;
	_window->registerTexture("Krool", "res/gfx/KINGKROOL.png");
	_window->registerTexture("Border", "res/gfx/Border.png");
	_window->registerTexture("Background", "res/gfx/bg.png");
	_window->registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");
	_window->registerFont("Paint", "res/fonts/Paint Drops.ttf");
	_window->registerFont("Portal", "res/fonts/PortalFont.ttf");

	// 0 = Game | 1 = Settings
	// TODO: Maybe use type instead of id
	switchScreen(0);
	
	gameLoop();
}

void Game::switchScreen(int screenIndex) {
	_activeScreen = screenIndex;

	screens.at(_activeScreen)->onScreenShowed();
}