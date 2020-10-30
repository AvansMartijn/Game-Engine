#include "HighScoreScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>

HighScoreScreen::HighScoreScreen() {}

HighScoreScreen::~HighScoreScreen() {}

void HighScoreScreen::onInit()
{
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("  HIGHSCORES   ", "Portal", 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("  TODO   ", "Portal", 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(bodyText));

	ButtonUiElement quitGameButton = ButtonUiElement("Back", { (1080 / 2) - 200, 500, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void HighScoreScreen::onTick() {}

void HighScoreScreen::onScreenShowed() {}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}