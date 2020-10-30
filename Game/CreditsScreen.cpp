#include "CreditsScreen.h"

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}

void CreditsScreen::onInit() {
	const Color bgColor = { 192, 192, 192 };
	const string font = "Paint";

	const string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;


	TextUiElement title = TextUiElement("Credits", font, 60, { 10, 10, 0, 0 }, { 210, 190, 70 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(title));

	//TODO: Een keer helemaal mooi maken voor nu tijd saven
	TextUiElement line = TextUiElement("Team Mike", font, 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(line));


	ButtonUiElement backButton = ButtonUiElement("Back", { (1080 / 2) - 220, 550, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	uiElements.push_back(make_shared<ButtonUiElement>(backButton));

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
		_game->switchScreen(Screens::MainMenu);

		break;
	default:
		break;
	}
}

void CreditsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}
