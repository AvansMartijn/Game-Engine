#include "CheatHelpScreen.h"
#include "CheatManager.h"
#include <Mouse.h>
#include "ControllManager.h"

void CheatHelpScreen::loadCheatInformation() {
	std::map<std::string, std::string> cheatInformation = CheatManager::getInstance().getCheatInformation();
	
	for (auto const& cheat : cheatInformation) {
		_cheatInformation->text += cheat.first + " - ";
		_cheatInformation->text += cheat.second;
		_cheatInformation->text += "\n";
	}
}

CheatHelpScreen::CheatHelpScreen() {}
CheatHelpScreen::~CheatHelpScreen() {}

void CheatHelpScreen::onInit() {
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

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);

	loadCheatInformation();
}

void CheatHelpScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";

	if (!Mouse::getInstance().isCurrentMouseSkin(Mouse::DEFAULT))
		Mouse::getInstance().setCursor(Mouse::DEFAULT);
}

void CheatHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void CheatHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void CheatHelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}