#include "KeyBindingsHelpScreen.h"

KeyBindingsHelpScreen::KeyBindingsHelpScreen() {}

KeyBindingsHelpScreen::~KeyBindingsHelpScreen() {}

void KeyBindingsHelpScreen::onInit() {
	const Color bgColor = { 66, 99, 116 };
	const string font = "OpenSans";
	const string fontPortal = "OpenSans";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Keybindings", font, 60, { 0, 10, 0, 0 }, { 210, 190, 70 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	//TODO PLACHOLDER DATA

	TextUiElement lineText1 = TextUiElement("Forward: D ", font, 20, { 0, 100, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(lineText1));

	TextUiElement lineText2 = TextUiElement("Back: A ", font, 20, { 0, 150, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(lineText2));

	TextUiElement lineText3 = TextUiElement("Jump: W ", font, 20, { 0, 200, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(lineText3));


	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, fontPortal, 40);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void KeyBindingsHelpScreen::onTick() {}

void KeyBindingsHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void KeyBindingsHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void KeyBindingsHelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}
