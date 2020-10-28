#include "CreditsScreen.h"

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}

void CreditsScreen::onInit() {
	Color bgColor = { 192, 192, 192 };

	string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;


	TextUiElement title = TextUiElement("Credits", "Paint", 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(title));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("Team Mike", "Paint", 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(line));

	for (int i = 0; i < 6; i++)
	{
		posy += 50;
		posx += 50;
		TextUiElement lineOfC = TextUiElement(teamMembers[i], "Paint", 28, { posy, posx, 0, 0 }, { 0, 0, 0 }, { 255, 255, 255 }, true);
		uiElements.push_back(make_shared<TextUiElement>(lineOfC));
	}
}

void CreditsScreen::onTick(){}

void CreditsScreen::onScreenShowed(){}

void CreditsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK TO PAUZE
		_game->switchScreen(4);

		break;
	default:
		break;
	}
}

void CreditsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
