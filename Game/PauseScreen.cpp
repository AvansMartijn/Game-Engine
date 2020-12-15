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
	resumeButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_unique<ButtonUiElement>(resumeButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { 470, 150, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	helpButton.registerGame(_game);
	helpButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_unique<ButtonUiElement>(helpButton));

	ButtonUiElement settingsButton = ButtonUiElement("Settings", { 470, 200, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	settingsButton.registerGame(_game);
	settingsButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::Settings); };
	_uiElements.push_back(make_unique<ButtonUiElement>(settingsButton));

	ButtonUiElement restartButton = ButtonUiElement("Restart", { 470, 250, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	restartButton.registerGame(_game);
	restartButton.onClick = [](shared_ptr<AbstractGame> game) {  game->switchScreen(Screens::MainGame, { "reset" });};
	_uiElements.push_back(make_unique<ButtonUiElement>(restartButton));

	ButtonUiElement quitGameButton= ButtonUiElement("Quit", { 470, 300, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::GameOver); };
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

void PauseScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym) {
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::MainGame);
		break;
	default:
		break;
	}
}

void PauseScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void PauseScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}
