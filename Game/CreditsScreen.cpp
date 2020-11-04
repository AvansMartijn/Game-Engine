#include "CreditsScreen.h"

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}

void CreditsScreen::onInit() {
	const Color bgColor = { 192, 192, 192 };
	const string font = "Paint";
	const string fontPortal = "Portal";

	const string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Credits", font, 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 255, 255, 255 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("Team Mike", font, 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(line));


	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, fontPortal, 40);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	for (int i = 0; i < 6; i++)
	{
		posy += 50;
		posx += 50;
		TextUiElement lineOfC = TextUiElement(teamMembers[i], font, 28, { posy, posx, 0, 0 }, { 0, 0, 0 }, { 255, 255, 255 }, true);
		_uiElements.push_back(make_shared<TextUiElement>(lineOfC));
	}
}

void CreditsScreen::onTick(){}

void CreditsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
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
