#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";
	const int width = 500;
	const int height = 75;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement text = TextUiElement("  LATROP 2   ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement startButton = ButtonUiElement("Start New Game", { (1080 / 2) - 220, 100, width, height }, bgColor, { 180, 102, 13 }, font, 40);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) {
		game->switchScreen(Screens::MainGame, { "default", "Default" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { (1080 / 2) - 220, 200, width, height }, bgColor, { 180, 102, 13 }, font, 40);
	loadButton.registerGame(_game);
	// TODO: Load Game
	loadButton.onClick = [](AbstractGame* game) { 
		game->switchScreen(Screens::MainGame, { "tiled", "LevelTest" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(loadButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { (1080 / 2) - 220, 300 , width, height }, bgColor, { 180, 102, 13 }, font, 40);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement highscoreButton = ButtonUiElement("Highscores", { (1080 / 2) - 220, 400, width, height }, bgColor, { 180, 102, 13 }, font, 40);
	highscoreButton.registerGame(_game);
	highscoreButton.onClick = [](AbstractGame* game) {   game->switchScreen(Screens::HighScore); };
	_uiElements.push_back(make_shared<ButtonUiElement>(highscoreButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { (1080 / 2) - 220, 500, width, height }, bgColor, { 180, 102, 13 }, font, 40);
	creditButton.registerGame(_game);
	creditButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Credits); };
	_uiElements.push_back(make_shared<ButtonUiElement>(creditButton));

	ButtonUiElement exitbutton = ButtonUiElement("Exit", { (1080 / 2) - 220, 600, width, height }, bgColor, { 180, 102, 13 }, font, 40);
	exitbutton.registerGame(_game);
	exitbutton.onClick = [](AbstractGame* game) { exit(0); };
	_uiElements.push_back(make_shared<ButtonUiElement>(exitbutton));
}

void MainMenuScreen::onTick() {}

void MainMenuScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void MainMenuScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void MainMenuScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

