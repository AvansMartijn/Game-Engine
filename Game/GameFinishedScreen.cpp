#include "GameFinishedScreen.h"
#include <IOFiles.h>


GameFinishedScreen::GameFinishedScreen() {}

GameFinishedScreen::~GameFinishedScreen() {}

void GameFinishedScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Level Finished", font, 60, { 0, 0, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("Score:", font, 48, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	TextUiElement nameLabelText = TextUiElement("Name:", font, 48, { 100, 200, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(nameLabelText));

	TextUiElement nameText = TextUiElement(" ", font, 48, { 100, 300, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_nameText = make_shared<TextUiElement>(nameText);
	_uiElements.push_back(_nameText);


	ButtonUiElement nextLevelButton = ButtonUiElement("Next level", { 500, 600, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	nextLevelButton.registerGame(_game);
	nextLevelButton.onClick = [this](AbstractGame* game) {
		IOFiles ioFiles;
		std::string scoreRow = to_string(Scene::getInstance().score) + "," + _nameText->text;
		ioFiles.writeToFile("Highscores", scoreRow, true);

		game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(nextLevelButton));

	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { 500, 650, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
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

