#include "KeyBindingsHelpScreen.h"

KeyBindingsHelpScreen::KeyBindingsHelpScreen() {}

KeyBindingsHelpScreen::~KeyBindingsHelpScreen() {}

void KeyBindingsHelpScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Keybindings", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	//TODO PLACHOLDER DATA

	TextUiElement lineText1 = TextUiElement("Walk Right: D ", font, 25, { 450, 140, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(lineText1));

	TextUiElement lineText2 = TextUiElement("Walk Left: A ", font, 25, { 450, 180, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(lineText2));

	TextUiElement lineText3 = TextUiElement("Jump: W ", font, 25, { 450, 220, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(lineText3)); 

	TextUiElement lineText4 = TextUiElement("Left mouse: Shoot ", font, 25, { 450, 260, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(lineText4));


	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void KeyBindingsHelpScreen::onTick() {}

void KeyBindingsHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void KeyBindingsHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void KeyBindingsHelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}
