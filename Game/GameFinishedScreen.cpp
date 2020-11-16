#include "GameFinishedScreen.h"
#include <IOFiles.h>


GameFinishedScreen::GameFinishedScreen() {}

GameFinishedScreen::~GameFinishedScreen() {}

void GameFinishedScreen::onInit()
{
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("  GAME FINISHED   ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("  Score: ", font, 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	TextUiElement nameLabelText = TextUiElement("  Name:   ", font, 48, { 100, 200, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(nameLabelText));

	TextUiElement nameText = TextUiElement(" ", font, 48, { 100, 300, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_nameText = make_shared<TextUiElement>(nameText);
	_uiElements.push_back(_nameText);


	ButtonUiElement NextLevelButton = ButtonUiElement("Next level", { (1080 / 2) - 200, 400, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	NextLevelButton.registerGame(_game);
	NextLevelButton.onClick = [this](AbstractGame* game) {
		IOFiles ioFiles;
		std::string scoreRow = to_string(Scene::getInstance().score) + "," + _nameText->text;
		ioFiles.writeToFile("Highscores", scoreRow, true);

		game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(NextLevelButton));


	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { (1080 / 2) - 200, 600, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [this](AbstractGame* game) {
		IOFiles ioFiles;
		std::string scoreRow = to_string(Scene::getInstance().score) + "," + _nameText->text;
		ioFiles.writeToFile("Highscores", scoreRow, true);

		game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));

}

void GameFinishedScreen::onTick() {}

void GameFinishedScreen::onScreenShowed(vector<string> args) {

	_bodyText->text = "  Score: " + to_string(Scene::getInstance().score);
}

void GameFinishedScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	if (e.keysym.sym == SDLK_BACKSPACE) {
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

void GameFinishedScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameFinishedScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

