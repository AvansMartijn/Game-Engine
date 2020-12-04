#include "LoadCustomLevelScreen.h"

LoadCustomLevelScreen::LoadCustomLevelScreen() {}
LoadCustomLevelScreen::~LoadCustomLevelScreen() {}

void LoadCustomLevelScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const std::string font = "Portal";
	const std::string fontPortal = "Portal";
	y = 100;
	offset = 0;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	_files = AssetRegistry::getInstance().getFilesInDirectory("res/levels", false, false);

	for (size_t i = 0; i < _files.size(); i++) {
		LevelData levelData = { _files[i].key, LevelType::TILED };

		shared_ptr<ButtonUiElement> _line;
		ButtonUiElement lineOfC = ButtonUiElement(levelData.levelName, { 430, y, 720, 40 }, bgColor, { 255, 255, 255 }, font, 25);
		lineOfC.registerGame(_game);
		lineOfC.onClick = [levelData](AbstractGame* game) {
			GameSettings::getInstance().saveGame.currentSlot = 0;
			game->switchScreen(Screens::Loading, { to_string(Screens::MainGame),levelData.levelType == LevelType::DEFAULT ? "default" : "tiled", levelData.levelName, "reset" });
			
		};
		_line = make_shared<ButtonUiElement>(lineOfC);
		_uiElements.push_back(_line);
		uiList.push_back(_line);
		y += 35;

	}


	TextUiElement title = TextUiElement("Custom levels", font, 60, { 5, 10, 100, 130 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void LoadCustomLevelScreen::onTick() {
	if (shouldShowFPS)
		fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		fps->text = "  ";
}

void LoadCustomLevelScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK TO PAUSE
		_game->switchScreen(Screens::MainMenu);
		break;
	default:
		break;
	}
}

void LoadCustomLevelScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void LoadCustomLevelScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

	if (_files.size() > 20) {
		if (e.y > 0) // scroll up
			offset = 10;
		else if (e.y < 0) // scroll down
			offset = -10;

		for (int i = 0; i < uiList.size(); i++)
			uiList[i]->_rect.y += offset;
	}
}


