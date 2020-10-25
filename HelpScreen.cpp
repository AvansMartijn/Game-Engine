#include "HelpScreen.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
	Color bgColor = { 192, 192, 192 };
	ImageUiElement img = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(img));

	TextUiElement title = TextUiElement("Help", "OpenSans", 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(title));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("Help wat komt er op het help scherm???", "OpenSans", 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(line));


}

void HelpScreen::onTick()
{
}

void HelpScreen::onScreenShowed()
{
}



void HelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK TO PAUZE
		_game->switchScreen(1);

		break;
	default:
		break;
	}
}

void HelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void HelpScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (auto& element : uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick();

				break;
			}
		}
	}
}
