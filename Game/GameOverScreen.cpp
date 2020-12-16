#include "GameOverScreen.h"
#include <Mouse.h>


GameOverScreen::GameOverScreen() {}

GameOverScreen::~GameOverScreen() {}

void GameOverScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	backgroundTrackKey = "Game_Over";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Game Over, you lost", font, 60, { 0, 0, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("Score: 0", font, 40, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_bodyText = addUiElement<TextUiElement>(make_unique<TextUiElement>(bodyText));

	ImageUiElement walu = ImageUiElement("Lose", { ((1080 - 400) / 2) + 50 , ((720 - 400) / 2) + 50, 400, 400 });
	_uiElements.push_back(make_unique<ImageUiElement>(walu));

	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { 500, 650, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_unique<ButtonUiElement>(quitGameButton));

	addFpsElement("Portal");
}

void GameOverScreen::onTick() {
	updateFpsElement();

	if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::DEFAULT))
		Mouse::getInstance().setCursor(MouseSkins::DEFAULT);

	if (Scene::getInstance().activatedCheats.size() > 0)
		Scene::getInstance().activatedCheats.clear();
}

void GameOverScreen::onScreenShowed(vector<string> args) {
	_bodyText->text = "  Score: " + to_string(Scene::getInstance().score);
}

void GameOverScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void GameOverScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameOverScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

