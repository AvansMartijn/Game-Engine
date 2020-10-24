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

	ButtonUiElement mainMenuButton = ButtonUiElement("MainMenu", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	mainMenuButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(mainMenuButton));

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
		_game->switchScreen(0);

		break;

	case SDLK_q:
		_game->switchScreen(5);

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
