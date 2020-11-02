#include "PauseScreen.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement text = TextUiElement("  PAUSE   ", "Portal", 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement resumeButton = ButtonUiElement("Resume", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	resumeButton.registerGame(_game);
	resumeButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	uiElements.push_back(make_shared<ButtonUiElement>(resumeButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { (1080 / 2) - 200, 300, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement quitGameButton= ButtonUiElement("Quit", { (1080 / 2) - 200, 500, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GameOver); };
	uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void PauseScreen::onTick() {}

void PauseScreen::onScreenShowed() {}

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