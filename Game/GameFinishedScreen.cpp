#include "GameFinishedScreen.h"
#include <Mouse.h>
#include "Utilities.h"

GameFinishedScreen::GameFinishedScreen() {}

GameFinishedScreen::~GameFinishedScreen() {}

void GameFinishedScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Level Finished", font, 60, { 0, 0, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement bodyText = TextUiElement("Score:", font, 48, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);

	TextUiElement nameLabelText = TextUiElement("Type your name:", font, 48, { 100, 200, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(nameLabelText));

	ImageUiElement walu = ImageUiElement("Win", { 1080 - 350 , ((720 - 400) / 2) + 50, 400, 400 });
	_uiElements.push_back(make_shared<ImageUiElement>(walu));

	TextUiElement nameText = TextUiElement(" ", font, 48, { 100, 300, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_nameText = make_shared<TextUiElement>(nameText);
	_uiElements.push_back(_nameText);

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);

	ButtonUiElement nextLevelButton = ButtonUiElement("Next level & Save", { 500, 600, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	nextLevelButton.registerGame(_game);
	nextLevelButton.onClick = [this](AbstractGame* game) {
		LevelData currentLevelData = GameSettings::getInstance().getCurrentLevel();

		auto test = GameSettings::getInstance().getNextLevel().levelName;
		auto test2 = GameSettings::getInstance().getCurrentLevel().levelName;
		//Checks for next level
		if (!GameSettings::getInstance().getNextLevel().levelName.empty()) {
			LevelData levelData = GameSettings::getInstance().getNextLevel();

			game->switchScreen(Screens::Loading, { to_string(Screens::MainGame),levelData.levelType == LevelType::DEFAULT ? "default" : "tiled", levelData.levelName, "reset" });

			if (GameSettings::getInstance().saveGame.currentSlot == 1)
				GameSettings::getInstance().saveGame.slot1++;
			if (GameSettings::getInstance().saveGame.currentSlot == 2) 
				GameSettings::getInstance().saveGame.slot2++;
			if (GameSettings::getInstance().saveGame.currentSlot == 3) 
				GameSettings::getInstance().saveGame.slot3++;

			GameSettings::getInstance().save();

			if (GameSettings::getInstance().isStoryLevel(currentLevelData)) {
				int foundIndex = -1;
				for (size_t levelIndex = 0; levelIndex < GameSettings::getInstance().saveGame.levels.size(); levelIndex++) {
					SaveLevel saveLevel = GameSettings::getInstance().saveGame.levels[levelIndex];

					if (saveLevel.name == currentLevelData.levelName) {
						foundIndex = (int)levelIndex;

						break;
					}
				}

				std::string name = _nameText->text;
				Utilities::getInstance().trim(name);

				if (name == "")
					_nameText->text = "Waluigi";

				if (!Scene::getInstance().hasCheated)
					GameSettings::getInstance().saveGame.levels[foundIndex].highscores.push_back({ _nameText->text ,Scene::getInstance().score });
				GameSettings::getInstance().save();
			}
		}
		else
			game->switchScreen(Screens::Credits);
	};
	_nextLevelButton = make_shared<ButtonUiElement>(nextLevelButton);
	_uiElements.push_back(_nextLevelButton);

	ButtonUiElement quitGameButton = ButtonUiElement("Main menu", { 500, 650, 200, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [this](AbstractGame* game) {
		LevelData currentLevelData = GameSettings::getInstance().getCurrentLevel();

		if (GameSettings::getInstance().isStoryLevel(currentLevelData)) {
			int foundIndex = -1;
			for (size_t levelIndex = 0; levelIndex < GameSettings::getInstance().saveGame.levels.size(); levelIndex++) {
				SaveLevel saveLevel = GameSettings::getInstance().saveGame.levels[levelIndex];

				if (saveLevel.name == currentLevelData.levelName) {
					foundIndex = (int)levelIndex;
					break;
				}
			}

			std::string name = _nameText->text;
			Utilities::getInstance().trim(name);

			if (name == "")
				_nameText->text = "Waluigi";

			if (!Scene::getInstance().hasCheated)
				GameSettings::getInstance().saveGame.levels[foundIndex].highscores.push_back({ _nameText->text ,Scene::getInstance().score });

			GameSettings::getInstance().save();
		}
		game->switchScreen(Screens::MainMenu);
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));
}

void GameFinishedScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";

	if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::DEFAULT))
		Mouse::getInstance().setCursor(MouseSkins::DEFAULT);

	if (Scene::getInstance().activatedCheats.size() > 0)
		Scene::getInstance().activatedCheats.clear();
}

void GameFinishedScreen::onScreenShowed(vector<string> args) {

	if (Scene::getInstance().hasCheated)
		_bodyText->text = "No Score For Cheaters >:(";
	else
		_bodyText->text = "  Score: " + to_string(Scene::getInstance().score);
	
	if (GameSettings::getInstance().getNextLevel().levelName.empty())
		_nextLevelButton->text = "Credits";
	else
		_nextLevelButton->text = "Next level";
}

void GameFinishedScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Scancode test = e.keysym.scancode;
	std::string test3 = SDL_GetScancodeName(test);
	if (e.keysym.sym == SDLK_BACKSPACE) {
		if (_nameText->text.size() > 1)
			_nameText->text.pop_back();
	}
	if (_nameText->text.length() < 21) {
		if (e.keysym.sym == SDLK_SPACE)
			_nameText->text.push_back(' ');
		if (e.keysym.sym >= 97 && e.keysym.sym <= 122)
			_nameText->text.push_back((char)e.keysym.sym);
	}
	
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

}

void GameFinishedScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameFinishedScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

