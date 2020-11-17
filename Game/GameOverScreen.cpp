#include "GameOverScreen.h"


GameOverScreen::GameOverScreen() {}

GameOverScreen::~GameOverScreen() {}

void GameOverScreen::onInit()
{
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";
	backgroundTrackKey = "Game_Over";


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("  GAME OVER   ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("  Score: ", font, 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { (1080 / 2) - 200, 500, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));

}

void GameOverScreen::onTick() {}

void GameOverScreen::onScreenShowed(vector<string> args) {
	_bodyText->text = "  Score: " + to_string(Scene::getInstance().score);
}

void GameOverScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void GameOverScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameOverScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

