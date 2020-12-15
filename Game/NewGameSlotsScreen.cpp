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
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	ImageUiElement logoWesley = ImageUiElement("LogoWesley", { ((1080 - 700) / 2) , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_unique<ImageUiElement>(logoWesley));

	TextUiElement title = TextUiElement("New Game", font, 40, { 700, 75, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	TextUiElement subTitle = TextUiElement("Select slot to start new game", font, 20, { 700, 120, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_unique<TextUiElement>(subTitle));

	ButtonUiElement slot1 = ButtonUiElement("Slot 1", { 700, 170, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot1.registerGame(_game);
	slot1.onClick = [](shared_ptr<AbstractGame> game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 1;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot1 = 0;
		GameSettings::getInstance().save();

		game->switchScreen(Screens::StartNewGame);
	};
	_slot1Button = addUiElement<ButtonUiElement>(make_unique<ButtonUiElement>(slot1));

	ButtonUiElement slot2 = ButtonUiElement("Slot 2", { 700, 220, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot2.registerGame(_game);
	slot2.onClick = [](shared_ptr<AbstractGame> game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 2;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot2 = 0;
		GameSettings::getInstance().save();

		game->switchScreen(Screens::StartNewGame);
	};
	_slot2Button = addUiElement<ButtonUiElement>(make_unique<ButtonUiElement>(slot2));

	ButtonUiElement slot3 = ButtonUiElement("Slot 3", { 700, 270, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	slot3.registerGame(_game);
	slot3.onClick = [](shared_ptr<AbstractGame> game) {
		//set currentLevel to the current playing slot
		GameSettings::getInstance().saveGame.currentSlot = 3;
		//set the Slot1 to current level
		GameSettings::getInstance().saveGame.slot3 = 0;
		GameSettings::getInstance().save();

		game->switchScreen(Screens::StartNewGame);
	};

	_slot3Button = addUiElement<ButtonUiElement>(make_unique<ButtonUiElement>(slot3));

	TextUiElement note = TextUiElement("* The selected level slot will be overidden", font, 12, { 700, 320, width, height }, { 255, 255, 255 }, bgColor, false);
	_uiElements.push_back(make_unique<TextUiElement>(note));

	ButtonUiElement backButton = ButtonUiElement("Back", { 700, 400, width, height }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	addFpsElement("Portal");
}

void NewGameSlotsScreen::onTick() {
	updateFpsElement();
}

void NewGameSlotsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
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

void NewGameSlotsScreen::onScreenShowed(vector<std::string> args)
{
	/*if (GameSettings::getInstance().saveGame.slot1 == -1) 
		_slot1Button->text = "Slot 1 - Empty";
	else 
		_slot1Button->text = "Slot 1 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot1).levelName;

	if (GameSettings::getInstance().saveGame.slot2 == -1)
		_slot2Button->text = "Slot 2 - Empty";
	else
		_slot2Button->text = "Slot 2 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot2).levelName;

	if (GameSettings::getInstance().saveGame.slot3 == -1)
		_slot3Button->text = "Slot 3 - Empty";
	else
		_slot3Button->text = "Slot 3 - " + GameSettings::getInstance().getLevelByIndex(GameSettings::getInstance().saveGame.slot3).levelName;*/
}

void NewGameSlotsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
void NewGameSlotsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

