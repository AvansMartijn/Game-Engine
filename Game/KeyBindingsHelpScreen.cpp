#include "KeyBindingsHelpScreen.h"

KeyBindingsHelpScreen::KeyBindingsHelpScreen() {}

KeyBindingsHelpScreen::~KeyBindingsHelpScreen() {}

void KeyBindingsHelpScreen::onInit() {
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Keybindings", "OpenSans", 60, { 0, 10, 0, 0 }, { 210, 190, 70 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(headerText));

	//TODO PLACHOLDER DATA

	TextUiElement lineText1 = TextUiElement("Forward: D ", "OpenSans", 20, { 0, 100, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(lineText1));

	TextUiElement lineText2 = TextUiElement("Back: A ","OpenSans", 20, { 0, 150, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(lineText2));

	TextUiElement lineText3 = TextUiElement("Jump: W ", "OpenSans", 20, { 0, 200, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(lineText3));


	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	backButton.registerGame(_game);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void KeyBindingsHelpScreen::onTick() {}

void KeyBindingsHelpScreen::onScreenShowed() {}

void KeyBindingsHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void KeyBindingsHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}