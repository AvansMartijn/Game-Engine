#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	backgroundTrackKey = "Background_Menu";
	const int width = 200;
	const int height = 40;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	ImageUiElement AdImage = ImageUiElement("AdPlaceholder", { 60 , 120, 200, 500 }, 0, false);
	_uiElements.push_back(make_unique<ImageUiElement>(AdImage));

	ImageUiElement logoWesley = ImageUiElement("LogoWesley", { ((1080 - 700) / 2) , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_unique<ImageUiElement>(logoWesley));

	ButtonUiElement startButton = ButtonUiElement("New Game", { 700, 75, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	startButton.registerGame(_game);
	startButton.onClick = [](shared_ptr<AbstractGame> game) {
		game->switchScreen(Screens::NewGame);
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { 700, 125, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	loadButton.registerGame(_game);
	loadButton.onClick = [](shared_ptr<AbstractGame> game) {
		game->switchScreen(Screens::LoadGame);
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(loadButton));

	ButtonUiElement loadCustomButton = ButtonUiElement("Load Custom Map", { 700, 175, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	loadCustomButton.registerGame(_game);

	loadCustomButton.onClick = [](shared_ptr<AbstractGame> game) {
		game->switchScreen(Screens::LoadCustomMap);
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(loadCustomButton));

	ButtonUiElement helpButton = ButtonUiElement("Help", { 700, 225, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	helpButton.registerGame(_game);
	helpButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::Help); };
	_uiElements.push_back(make_unique<ButtonUiElement>(helpButton));

	ButtonUiElement highscoreButton = ButtonUiElement("Highscores", { 700, 275, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	highscoreButton.registerGame(_game);
	highscoreButton.onClick = [](shared_ptr<AbstractGame> game) {   game->switchScreen(Screens::HighScore); };
	_uiElements.push_back(make_unique<ButtonUiElement>(highscoreButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { 700, 325, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	creditButton.registerGame(_game);
	creditButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::Credits); };
	_uiElements.push_back(make_unique<ButtonUiElement>(creditButton));

	ButtonUiElement settingsButton = ButtonUiElement("Settings", { 700, 375, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	settingsButton.registerGame(_game);
	settingsButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::Settings); };
	_uiElements.push_back(make_unique<ButtonUiElement>(settingsButton));

	ButtonUiElement exitbutton = ButtonUiElement("Exit", { 700, 425, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	exitbutton.registerGame(_game);
	exitbutton.onClick = [](shared_ptr<AbstractGame> game) { exit(0); };
	_uiElements.push_back(make_unique<ButtonUiElement>(exitbutton));

	addFpsElement("Portal");
	
	Mouse::getInstance().setCursor(MouseSkins::DEFAULT);
}

void MainMenuScreen::onTick() {
	updateFpsElement();
}

void MainMenuScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym) {
	case SDLK_d:
		_game->switchScreen(Screens::MainGame, { "default", "Default", "reset" });

		break;
	case SDLK_F5:
		GameSettings::getInstance().load();

		break;
	}
}

void MainMenuScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void MainMenuScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

