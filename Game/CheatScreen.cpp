#include "CheatScreen.h"

CheatScreen::CheatScreen() {}
CheatScreen::~CheatScreen() {}

void CheatScreen::onInit()
{
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Cheats", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	ButtonUiElement cheatHelp = ButtonUiElement("Cheat Overview", { 400, 650, 180, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	cheatHelp.registerGame(_game);
	cheatHelp.onClick = [](AbstractGame* game) { game->switchScreen(Screens::CheatHelp); };
	_uiElements.push_back(make_shared<ButtonUiElement>(cheatHelp));

	ButtonUiElement backButton = ButtonUiElement("Back", { 600, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void CheatScreen::onTick()
{
}

void CheatScreen::handleKeyboardInput(SDL_KeyboardEvent e)
{
}

void CheatScreen::handleMouseMotionInput(SDL_MouseMotionEvent e)
{
}

void CheatScreen::handleMouseWheelInput(SDL_MouseWheelEvent e)
{
}