#include "Game.h"

Game::Game(const char* title, int width, int height) : AbstractGame(title, width, height) {}

Game::~Game() {}

void Game::onInit() {
	registerTexture("Player_Look_Right", "res/gfx/Assets/Entity/Player/Looking_Right.png");
	registerTexture("Player_Look_Left", "res/gfx/Assets/Entity/Player/Looking_Left.png");

	registerTexture("Player_Jump_Right", "res/gfx/Assets/Entity/Player/Jumping_Right.png");
	registerTexture("Player_Jump_Left", "res/gfx/Assets/Entity/Player/Jumping_Left.png");

	registerTexture("Player_Fall_Right", "res/gfx/Assets/Entity/Player/Falling_Right.png");
	registerTexture("Player_Fall_Left", "res/gfx/Assets/Entity/Player/Falling_Left.png");

	registerTexture("Player_Running_Right", "res/gfx/Assets/Entity/Player/Running_Right.png");
	registerTexture("Player_Running_Left", "res/gfx/Assets/Entity/Player/Running_Left.png");

	registerTexture("Crate_Metal", "res/gfx/Assets/Enviroment/Crate_Metal.png");
	registerTexture("Mystical_Crystal_Flipped", "res/gfx/Assets/Enviroment/Mystical_Crystal_Flipped.png");
	registerTexture("Gate_Cropped", "res/gfx/Assets/Enviroment/Gate_Cropped.png");
	registerTexture("Tile_Interior_Ground_Center", "res/gfx/Assets/Tiles/Interior/Ground_Center.png");
	registerTexture("Border", "res/gfx/Border.png");
	registerTexture("Background", "res/gfx/bg.png");
	registerTexture("Krool", "res/gfx/KINGKROOL.png");
	registerTexture("Blob", "res/gfx/Assets/Items/Blob.png");

	registerTexture("DIY_Weapon", "res/gfx/Assets/Items/DIY_Weapon.png");

	registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");
	registerFont("Paint", "res/fonts/Paint Drops.ttf");
	registerFont("Portal", "res/fonts/PortalFont.ttf");

	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->preRender(_window);

	switchScreen(Screens::MainMenu);

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

void Game::switchScreen(int screenIndex, vector<std::string> args) {
	size_t index = screenIndex;
	if (index == -1)
		index = this->getPreviousScreen();
	else if (_activeScreen)
		_previousScreens.push(_activeScreen);

	if (index + 1 <= screens.size()) {
		_activeScreen = index;
		screens.at(_activeScreen)->onScreenShowed(args);
	}
}