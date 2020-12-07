#include "CheatHelpScreen.h"
#include "CheatManager.h"

void CheatHelpScreen::loadCheatInformation()
{
	std::map<std::string, std::string> cheatInformation = CheatManager::getInstance().getCheatInformation();
	
	for (auto const& cheat : cheatInformation)
	{
		_cheatInformation->text += cheat.first + " - ";
		_cheatInformation->text += cheat.second;
		_cheatInformation->text += "\n";
	}
}

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

	TextUiElement cheatInformation = TextUiElement(" ", font, 25, { 10, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_cheatInformation = make_shared<TextUiElement>(cheatInformation);
	_uiElements.push_back(_cheatInformation);

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Cheat); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	loadCheatInformation();
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