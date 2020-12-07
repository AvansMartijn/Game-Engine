#include "PauseScreen.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Pause", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	ButtonUiElement resumeButton = ButtonUiElement("Resume", { 470, 100, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	resumeButton.registerGame(_game);
	resumeButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_shared<ButtonUiElement>(resumeButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { 470, 150, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	helpButton.registerGame(_game);
	helpButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_shared<ButtonUiElement>(helpButton));

	ButtonUiElement settingsButton = ButtonUiElement("Settings", { 470, 200, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	settingsButton.registerGame(_game);
	settingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::Settings); };
	_uiElements.push_back(make_shared<ButtonUiElement>(settingsButton));

	ButtonUiElement RestartButton = ButtonUiElement("Restart", { 470, 250, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	RestartButton.registerGame(_game);
	RestartButton.onClick = [](AbstractGame* game) {  game->switchScreen(Screens::MainGame, { "reset" });};
	_uiElements.push_back(make_shared<ButtonUiElement>(RestartButton));

	ButtonUiElement quitGameButton= ButtonUiElement("Quit", { 470, 300, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GameOver); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));

	ImageUiElement walu = ImageUiElement("Hat", { 1080 - 350 , (((720 - 400) - 100) / 2), 300, 300 });
	_uiElements.push_back(make_shared<ImageUiElement>(walu));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}

void PauseScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void PauseScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::MainGame);
		break;
	default:
		break;
	}
}

void PauseScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void PauseScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}
