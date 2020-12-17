#include "PauseScreen.h"
#include <Mouse.h>

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Pause", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_unique<TextUiElement>(headerText));

	ButtonUiElement resumeButton = ButtonUiElement("Resume", { 470, 100, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	resumeButton.registerGame(_game);
	resumeButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_unique<ButtonUiElement>(resumeButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { 470, 150, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_unique<ButtonUiElement>(helpButton));

	ButtonUiElement settingsButton = ButtonUiElement("Settings", { 470, 200, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	settingsButton.registerGame(_game);
	settingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Settings); };
	_uiElements.push_back(make_unique<ButtonUiElement>(settingsButton));

	ButtonUiElement restartButton = ButtonUiElement("Restart", { 470, 250, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	restartButton.registerGame(_game);
	restartButton.onClick = [](AbstractGame* game) {  game->switchScreen(Screens::MainGame, { "reset" });};
	_uiElements.push_back(make_unique<ButtonUiElement>(restartButton));

	ButtonUiElement quitGameButton= ButtonUiElement("Quit", { 470, 300, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GameOver); };
	_uiElements.push_back(make_unique<ButtonUiElement>(quitGameButton));

	ImageUiElement walu = ImageUiElement("Hat", { 1080 - 350 , (((720 - 400) - 100) / 2), 300, 300 });
	_uiElements.push_back(make_unique<ImageUiElement>(walu));

	addFpsElement("Portal");
}

void PauseScreen::onTick() {
	updateFpsElement();

	if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::DEFAULT))
		Mouse::getInstance().setCursor(MouseSkins::DEFAULT);
}

void PauseScreen::handleKeyboardInput(KeyboardEvent e) {
	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keyCode) {
	case KEY_ESCAPE:
		_game->switchScreen(Screens::MainGame);
		break;
	default:
		break;
	}
}