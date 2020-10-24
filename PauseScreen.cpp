#include "PauseScreen.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	Color bgColor = { 192, 192, 192 };


	TextUiElement text = TextUiElement("Engine Demo", "OpenSans", 48, { 0, 0, 0, 0 }, { 0, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement button = ButtonUiElement("Resume", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	button.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(button));

	ButtonUiElement showCreditsButton = ButtonUiElement("Credits", { (1080 / 2) - 200, 300, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	showCreditsButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(showCreditsButton));

	ImageUiElement img = ImageUiElement("Krool", { 0 , 0, 100, 100 });
	uiElements.push_back(make_shared<ImageUiElement>(img));


}

void PauseScreen::onTick() {

}

void PauseScreen::onScreenShowed() {

}

void PauseScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::MainGame);
		break;
	case SDLK_SPACE:
		// GO TO CREDITS
		_game->switchScreen(Screens::Credits);
		break;
	case SDLK_h:
		// GO TO HELP
		_game->switchScreen(Screens::Help);
		break;
	case SDLK_m:
		// GO TO HELP
		_game->switchScreen(Screens::MainMenu);
		break;
	default:
		break;
	}
}

void PauseScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}


void PauseScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (auto& element : uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick();

				break;
			}
		}
	}
}
