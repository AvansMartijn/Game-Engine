#include "PauseScreen.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement text = TextUiElement("  PAUSE   ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement resumeButton = ButtonUiElement("Resume", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	resumeButton.registerGame(_game);
	resumeButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_shared<ButtonUiElement>(resumeButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { (1080 / 2) - 200, 250, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement RestartButton = ButtonUiElement("Restart", { (1080 / 2) - 200, 400, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	RestartButton.registerGame(_game);
	RestartButton.onClick = [](AbstractGame* game) {  game->reset(); game->switchScreen(Screens::MainGame);};
	_uiElements.push_back(make_shared<ButtonUiElement>(RestartButton));

	ButtonUiElement quitGameButton= ButtonUiElement("Quit", { (1080 / 2) - 200, 550, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GameOver); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void PauseScreen::onTick() {}

void PauseScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::MainGame);
		break;
	default:
		break;
	}
}

void PauseScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void PauseScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}
