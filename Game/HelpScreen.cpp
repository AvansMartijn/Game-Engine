#include "HelpScreen.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Help", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("hierkomt een uitleg over hoe het spel werkt zodra er meer functionaliteit is ", font, 25, { 0, 100, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(line));

	ButtonUiElement keyBindingsButton = ButtonUiElement("Keybindings", { 475, 600, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	keyBindingsButton.registerGame(_game);
	keyBindingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::KeyBindings); };
	_uiElements.push_back(make_shared<ButtonUiElement>(keyBindingsButton));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void HelpScreen::onTick(){}

void HelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}