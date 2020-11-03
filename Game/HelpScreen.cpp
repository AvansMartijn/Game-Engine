#include "HelpScreen.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
	Color bgColor = { 66, 99, 116 };

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Help", "OpenSans", 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(headerText));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("hierkomt een uitleg over hoe het spel werkt zodra er meer functionaliteit is ", "OpenSans", 34, { 0, 100, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(line));


	ButtonUiElement keyBindingsButton = ButtonUiElement("Keybindings", { (1080 / 2) - 220, 400, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	keyBindingsButton.registerGame(_game);
	keyBindingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::KeyBindings); };
	uiElements.push_back(make_shared<ButtonUiElement>(keyBindingsButton));

	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void HelpScreen::onTick(){}

void HelpScreen::onScreenShowed(){}

void HelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}