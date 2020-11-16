#include "GameOverScreen.h"
#include <IOFiles.h>


GameOverScreen::GameOverScreen() {}

GameOverScreen::~GameOverScreen() {}

void GameOverScreen::onInit() {
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("  GAME OVER: YOU LOSE  ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("  Score (DOESN'T COUNT): ", font, 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	TextUiElement nameLabelText = TextUiElement("  Name:   ", font, 48, { 100, 200, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(nameLabelText));

	TextUiElement nameText = TextUiElement(" ", font, 48, { 100, 300, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_nameText = make_shared<TextUiElement>(nameText);
	_uiElements.push_back(_nameText);

	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { (1080 / 2) - 200, 500, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void GameOverScreen::onTick() {}

void GameOverScreen::onScreenShowed(vector<string> args) {

	_bodyText->text = "  Score (DOESN'T COUNT): " + to_string(Scene::getInstance().score);
}

void GameOverScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	if (e.keysym.sym == SDLK_BACKSPACE){
		if (_nameText->text.size() > 1)
		{
			_nameText->text.pop_back();
		}
	}
	if (e.keysym.sym == SDLK_SPACE)
	{
		_nameText->text.push_back(' ');
	}
	if (e.keysym.sym >= 97 && e.keysym.sym <= 122)
	{
		_nameText->text.push_back((char)e.keysym.sym);
	}
}

void GameOverScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameOverScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

