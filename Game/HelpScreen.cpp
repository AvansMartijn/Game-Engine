#include "HelpScreen.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Help", "OpenSans", 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(title));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("Help wat komt er op het help scherm???", "OpenSans", 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(line));

	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	backButton.registerGame(_game);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(game->getPreviousScreen()); };
	uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void HelpScreen::onTick(){}

void HelpScreen::onScreenShowed(){}

void HelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(_game->getPreviousScreen());

		break;
	default:
		break;
	}
}

void HelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}