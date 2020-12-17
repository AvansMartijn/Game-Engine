#include "CheatHelpScreen.h"
#include "CheatManager.h"
#include <Mouse.h>
#include "ControllManager.h"
#include <Utilities.h>

void CheatHelpScreen::loadCheatInformation() {
	std::map<std::string, std::string> cheatInformation = CheatManager::getInstance().getCheatInformation();
	
	for (const auto& cheat : cheatInformation) {
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
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Cheats Overview", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	TextUiElement cheatInformation = TextUiElement(" ", font, 25, { 10, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_cheatInformation = addUiElement<TextUiElement>(make_unique<TextUiElement>(cheatInformation));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Cheat); };
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	addFpsElement("Portal");
	loadCheatInformation();
}

void CheatHelpScreen::onTick() {
	updateFpsElement();

	if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::DEFAULT))
		Mouse::getInstance().setCursor(MouseSkins::DEFAULT);
}

void CheatHelpScreen::handleKeyboardInput(KeyboardEvent e) {
	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;
}
