#include "CreditsScreen.h"

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}

void CreditsScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";


	const string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));


	TextUiElement title = TextUiElement("Credits", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	TextUiElement line = TextUiElement("Team Mike", font, 40, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(line));


	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	for (int i = 0; i < 6; i++)
	{
		posy += 50;
		posx += 50;
		TextUiElement lineOfC = TextUiElement(teamMembers[i], font, 25, { posy, posx, 0, 0 }, { 255, 255, 255 }, bgColor, true);
		_uiElements.push_back(make_shared<TextUiElement>(lineOfC));
	}

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);

}

void CreditsScreen::onTick(){
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void CreditsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK TO PAUSE
		_game->switchScreen(Screens::MainMenu);

		break;
	default:
		break;
	}
}

void CreditsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void CreditsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

