#include "SettingsScreen.h"


SettingsScreen::SettingsScreen() {}
SettingsScreen::~SettingsScreen() {}

void SettingsScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";


	int posy = 100, posx = 100;


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));


	TextUiElement title = TextUiElement("Settings", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	
	TextUiElement soundLabel = TextUiElement("Sound:", font, 40, { 470, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(soundLabel));


	ButtonUiElement soundPlus = ButtonUiElement("+", { 470, 150, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundPlus.registerGame(_game);
	soundPlus.onClick = [](AbstractGame* game) { 
	
		//TODO: MARTIJN
		//sound PLUS
	
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundPlus));

	ButtonUiElement soundMin = ButtonUiElement("-", { 470, 200, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundMin.registerGame(_game);
	soundMin.onClick = [](AbstractGame* game) { 

		//TODO: MARTIJN
		//sound MIN
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundMin));


	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

}

void SettingsScreen::onTick() {}

void SettingsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK 
		_game->switchScreen(Screens::GoBack);
		break;
	default:
		break;
	}
}

void SettingsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void SettingsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

