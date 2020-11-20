#include "LoadCustomLevelScreen.h"

LoadCustomLevelScreen::LoadCustomLevelScreen() {}
LoadCustomLevelScreen::~LoadCustomLevelScreen() {}

void LoadCustomLevelScreen::onInit() {
	_files = AssetRegistry::getInstance().getFilesInDirectory("res/levels", false);
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	y = 100;
	offset = 0;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));


	for (int i = 0; i < _files.size(); i++)
	{
		//if (files[i].path.find("Level_") == string::npos) 
		//	currentName.push_back(files[i].path);

		LevelData levelData = { _files[i].key, LevelType::TILED };

		shared_ptr<ButtonUiElement> _line;
		ButtonUiElement lineOfC = ButtonUiElement(levelData.levelName, { 430, y, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
		lineOfC.registerGame(_game);
		lineOfC.onClick = [&, &i](AbstractGame* game) {
			game->switchScreen(Screens::MainGame, { _files[i] == LevelType::TILED ? "default" : "tiled", key, "reset" });
		};
		_line = make_shared<ButtonUiElement>(lineOfC);
		_uiElements.push_back(_line);
		uiList.push_back(_line);
		y += 35;

	}

	// Fixing the string


	TextUiElement title = TextUiElement("Custom levels", font, 60, { 5, 10, 100, 130 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void LoadCustomLevelScreen::onTick() {}

void LoadCustomLevelScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
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
	if (e.y > 0) // scroll up
		offset = 10;
	else if (e.y < 0) // scroll down
		offset = -10;

	for(int i = 0; i <  uiList.size(); i++)
		uiList[i]->_rect.y += offset;
	
}


