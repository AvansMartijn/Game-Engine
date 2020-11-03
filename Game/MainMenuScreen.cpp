#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement text = TextUiElement("  LATROP 2   ", "Portal", 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement startButton = ButtonUiElement("Start New Game", { (1080 / 2) - 220, 100, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) { 
		game->reset();
		game->switchScreen(Screens::MainGame); 
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { (1080 / 2) - 220, 250, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	loadButton.registerGame(_game);
	// TODO: Load Game
	loadButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_shared<ButtonUiElement>(loadButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { (1080 / 2) - 220, 400, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	helpButton.registerGame(_game);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	creditButton.registerGame(_game);
	creditButton.registerGame(_game);
	creditButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Credits); };
	_uiElements.push_back(make_shared<ButtonUiElement>(creditButton));
}

void MainMenuScreen::onTick() {}

void MainMenuScreen::onScreenShowed() {}

void MainMenuScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void MainMenuScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}