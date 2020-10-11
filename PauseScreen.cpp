#include "PauseScreen.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	cout << "PAUSE\n";

	SDL_Rect rect = { 0, 0, 100, 100 };
	SDL_Color bgColor = { 255, 0, 0, 255 };
	ButtonUiElement button = ButtonUiElement("Resume", rect, bgColor, { 0, 0, 0 });
	button.registerGame(_game);

	uiElements.push_back(make_shared<ButtonUiElement>(button));

	TextUiElement text = TextUiElement("Hello World", 32, { 300, 200, 0, 0 }, { 255, 0, 0 }, { 0, 0, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(text));

	ImageUiElement img = ImageUiElement("res/gfx/KINGKROOL.png", { 200, 200, 100, 100 });
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
		cout << "ESCAPE\n";
		_game->switchScreen(0);

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
