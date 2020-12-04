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

	ButtonUiElement slot1 = ButtonUiElement("Slot 1", { 700, 170, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot1.registerGame(_game);
	slot1.onClick = [](AbstractGame* game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 1;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot1 = 0;
		GameSettings::getInstance().save();


		game->switchScreen(Screens::StartNewGame);
	};
	slot1Button = make_shared<ButtonUiElement>(slot1);
	_uiElements.push_back(slot1Button);

	ButtonUiElement slot2 = ButtonUiElement("Slot 2", { 700, 220, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot2.registerGame(_game);
	slot2.onClick = [](AbstractGame* game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 2;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot2 = 0;
		GameSettings::getInstance().save();

		game->switchScreen(Screens::StartNewGame);
	};
	slot2Button = make_shared<ButtonUiElement>(slot2);
	_uiElements.push_back(slot2Button);

	ButtonUiElement slot3 = ButtonUiElement("Slot 3", { 700, 270, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot3.registerGame(_game);
	slot3.onClick = [](AbstractGame* game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 3;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot3 = 0;
		GameSettings::getInstance().save();

		game->switchScreen(Screens::StartNewGame);
	};

	slot3Button = make_shared<ButtonUiElement>(slot3);
	_uiElements.push_back(slot3Button);

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

void NewGameSlotsScreen::onScreenShowed(vector<std::string> args)
{
	if (GameSettings::getInstance().saveGame.slot1 == -1) 
		slot1Button->_text = "Slot 1 - Empty";
	else 
		slot1Button->_text = "Slot 1 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot1).levelName;

	if (GameSettings::getInstance().saveGame.slot2 == -1)
		slot2Button->_text = "Slot 2 - Empty";
	else
		slot2Button->_text = "Slot 2 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot2).levelName;

	if (GameSettings::getInstance().saveGame.slot3 == -1)
		slot3Button->_text = "Slot 3 - Empty";
	else
		slot3Button->_text = "Slot 3 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot3).levelName;
}

void NewGameSlotsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void NewGameSlotsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

