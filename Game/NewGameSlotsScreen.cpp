#include "NewGameSlotsScreen.h"
#include <TextUiElement.h>


NewGameSlotsScreen::NewGameSlotsScreen() {}
NewGameSlotsScreen::~NewGameSlotsScreen() {}

void NewGameSlotsScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	backgroundTrackKey = "Background_Menu";
	const int width = 200;
	const int height = 40;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	ImageUiElement logoWesley = ImageUiElement("LogoWesley", { ((1080 - 700) / 2) , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_shared<ImageUiElement>(logoWesley));

	TextUiElement title = TextUiElement("New Game", font, 40, { 700, 75, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	TextUiElement subTitle = TextUiElement("Select slot to start new game", font, 20, { 700, 120, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_shared<TextUiElement>(subTitle));

	ButtonUiElement slot1 = ButtonUiElement("Slot 1 - Test Slot", { 700, 170, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot1.registerGame(_game);
	slot1.onClick = [](AbstractGame* game) {
		GameSettings::getInstance().saveGame.currentLevel = 0;
		GameSettings::getInstance().save();

		LevelData levelData = GameSettings::getInstance().getCurrentLevel();
		game->switchScreen(Screens::Loading, { to_string(Screens::MainGame), levelData.levelType == LevelType::DEFAULT ? "default" : "tiled", levelData.levelName, "reset" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(slot1));

	ButtonUiElement slot2 = ButtonUiElement("Slot 2", { 700, 220, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot2.onClick = [](AbstractGame* game) {};
	_uiElements.push_back(make_shared<ButtonUiElement>(slot2));

	ButtonUiElement slot3 = ButtonUiElement("Slot 3", { 700, 270, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot3.registerGame(_game);
	_uiElements.push_back(make_shared<ButtonUiElement>(slot3));

	TextUiElement note = TextUiElement("* The selected level slot will be overidden", font, 12, { 700, 320, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_shared<TextUiElement>(note));

	ButtonUiElement backButton = ButtonUiElement("Back", { 700, 400, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
	
}

void NewGameSlotsScreen::onTick() {}

void NewGameSlotsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_d:
		_game->switchScreen(Screens::MainGame, { "default", "Default", "reset" });

		break;
	case SDLK_F5:
		GameSettings::getInstance().load();

		break;
	}
}

void NewGameSlotsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void NewGameSlotsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

