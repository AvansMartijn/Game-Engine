#include "CheatScreen.h"
#include "CheatManager.h"
#include <Mouse.h>
#include "ControllManager.h"
#include <Utilities.h>

CheatScreen::CheatScreen() {}
CheatScreen::~CheatScreen() {}

void CheatScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Cheats", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	TextUiElement enterCheat = TextUiElement("Enter Cheat", font, 30, { 250, 300, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(enterCheat));

	TextUiElement cheatText = TextUiElement(" ", font, 30, { 100, 350, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_cheatText = addUiElement<TextUiElement>(make_unique<TextUiElement>(cheatText));

	ButtonUiElement cheatHelp = ButtonUiElement("Cheat Overview", { 400, 650, 180, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	cheatHelp.registerGame(_game);
	cheatHelp.onClick = [](AbstractGame* game) { game->switchScreen(Screens::CheatHelp); };
	_uiElements.push_back(make_unique<ButtonUiElement>(cheatHelp));

	ButtonUiElement backButton = ButtonUiElement("Back", { 600, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	addFpsElement("Portal");
}

void CheatScreen::onTick() {
	updateFpsElement();

	if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::BEAM))
		Mouse::getInstance().setCursor(MouseSkins::BEAM);
}

void CheatScreen::onScreenShowed(vector<std::string> args) {
	_cheatText->text = " ";
}

void CheatScreen::handleKeyboardInput(KeyboardEvent e) {
	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;

	if (e.keyCode == KEY_RETURN) {
		std::string cheat = _cheatText->text;

		Utilities::getInstance().trim(cheat);
		if (CheatManager::getInstance().isCheat(cheat)) {
			if (CheatManager::getInstance().executeCheat(cheat)) {
				Scene::getInstance().hasCheated = true;
				_cheatText->text = "Cheat Activated";
				Scene::getInstance().activatedCheats.push_back(cheat);
			}
		}
		else {
			_cheatText->text = "Cheat Not Found";
		}
	}

	if (e.keyCode == KEY_BACKSPACE) {
		if (_cheatText->text.size() == 1)
			_cheatText->text = " ";
		else if (_cheatText->text.size() > 1)
			_cheatText->text.pop_back();
	}
	if (_cheatText->text.length() <= 20) {
		if (e.keyCode == KEY_SPACE)
			_cheatText->text.push_back(' ');
		if (e.keyCode >= 97 && e.keyCode <= 122)
			_cheatText->text.push_back((char)e.keyCode);
	}
}