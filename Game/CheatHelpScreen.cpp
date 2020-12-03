#include "CheatHelpScreen.h"

CheatHelpScreen::CheatHelpScreen() {}
CheatHelpScreen::~CheatHelpScreen() {}

void CheatHelpScreen::onInit()
{
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Cheats Overview", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Cheat); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void CheatHelpScreen::onTick()
{

}

void CheatHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e)
{

}

void CheatHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e)
{

}

void CheatHelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e)
{

}