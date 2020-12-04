#include "GameOverScreen.h"


GameOverScreen::GameOverScreen() {}

GameOverScreen::~GameOverScreen() {}

void GameOverScreen::onInit()
{
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	backgroundTrackKey = "Game_Over";


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Game Over, you lost", font, 60, { 0, 0, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("Score: 0", font, 40, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	ImageUiElement walu = ImageUiElement("Lose", { ((1080 - 400) / 2) + 50 , ((720 - 400) / 2) + 50, 400, 400 });
	_uiElements.push_back(make_shared<ImageUiElement>(walu));


	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { 500, 650, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainMenu); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void GameOverScreen::onTick() {
	if (shouldShowFPS)
		fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		fps->text = "  ";
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

