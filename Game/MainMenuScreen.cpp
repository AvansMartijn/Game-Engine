#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	backgroundTrackKey = "Background_Menu";
	const int width = 200;
	const int height = 40;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	ImageUiElement logoWesley = ImageUiElement("LogoWesley", { ((1080 - 700) / 2) , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_shared<ImageUiElement>(logoWesley));

	ButtonUiElement startButton = ButtonUiElement("New Game", { 700, 75, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) {
		game->switchScreen(Screens::MainGame, { "default", "Default" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { 700, 125, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	loadButton.registerGame(_game);
	// TODO: Load Game
	loadButton.onClick = [](AbstractGame* game) { 
		game->switchScreen(Screens::MainGame, { "tiled", "Level_2" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(loadButton));

	ButtonUiElement loadCustomButton = ButtonUiElement("Load Custom Map", { 700, 175, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	loadCustomButton.registerGame(_game);
	// TODO: Load Game
	loadCustomButton.onClick = [](AbstractGame* game) {
		game->switchScreen(Screens::LoadCustomMap);
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(loadCustomButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { 700, 225, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement highscoreButton = ButtonUiElement("Highscores", { 700, 275, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	highscoreButton.registerGame(_game);
	highscoreButton.onClick = [](AbstractGame* game) {   game->switchScreen(Screens::HighScore); };
	_uiElements.push_back(make_shared<ButtonUiElement>(highscoreButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { 700, 325, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	creditButton.registerGame(_game);
	creditButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Credits); };
	_uiElements.push_back(make_shared<ButtonUiElement>(creditButton));

	ButtonUiElement settingsButton = ButtonUiElement("Settings", { 700, 375, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	settingsButton.registerGame(_game);
	settingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Settings); };
	_uiElements.push_back(make_shared<ButtonUiElement>(settingsButton));

	ButtonUiElement exitbutton = ButtonUiElement("Exit", { 700, 425, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	exitbutton.registerGame(_game);
	exitbutton.onClick = [](AbstractGame* game) { exit(0); };
	_uiElements.push_back(make_shared<ButtonUiElement>(exitbutton));
}

void MainMenuScreen::onTick() {}

void MainMenuScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void MainMenuScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void MainMenuScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

