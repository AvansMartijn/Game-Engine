#include "CreditsScreen.h"
#include <random>

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}



std::default_random_engine& random_engine_credits() {
	static std::random_device rd{};
	static std::default_random_engine re{ rd() };
	return re;
}

int random_int_credits(int low, int high) {
	assert(high > low);
	std::uniform_int_distribution<int> d{ low, high - 1 };
	return d(random_engine_credits());
}

void CreditsScreen::onInit() {

	begin = std::chrono::steady_clock::now();

	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";

	const string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Credits", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	shared_ptr<TextUiElement> Title = make_shared<TextUiElement>(title);
	_uiElements.push_back(Title);

	TextUiElement line = TextUiElement("Team Mike", font, 40, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	Line = make_shared<TextUiElement>(line);
	_uiElements.push_back(Line);
	_scrollableElements.push_back(Line);
	anchor = Line->_rect.y;


	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));


	for (int i = 0; i < 6; i++) {
		posy += 50;

		TextUiElement lineOfC = TextUiElement(teamMembers[i], font, 25, { 100, posy, 0, 0 }, { 255, 255, 255 }, bgColor, false);
		shared_ptr<TextUiElement> LineOfC = make_shared<TextUiElement>(lineOfC);
		_uiElements.push_back(LineOfC);
		_scrollableElements.push_back(LineOfC);
	}


	TextUiElement wackAMoleText = TextUiElement("Wack-A-Mole", font, 40, { 720, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	shared_ptr<TextUiElement> WackAMoleText = make_shared<TextUiElement>(wackAMoleText);
	_uiElements.push_back(WackAMoleText);
	_scrollableElements.push_back(WackAMoleText);

	WackAMoleInfo = make_shared<TextUiElement>(TextUiElement("Get a score of 5 and win a \n \"Prize\"", "Portal", 25, { 720, 150, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, true));
	_uiElements.push_back(WackAMoleInfo);
	_scrollableElements.push_back(WackAMoleInfo);

	scoreText = make_shared<TextUiElement>(TextUiElement("Score: ", "Portal", 40, { 770, 250, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(scoreText);
	_scrollableElements.push_back(scoreText);


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ButtonUiElement wackButton = ButtonUiElement("O", { 770 + (i * 50), 300 + (j*50), 50, 50 }, bgColor, { 255, 255, 255 }, font, 25);
			wackButton.registerGame(_game);
			
			shared_ptr<ButtonUiElement> WackButton = make_shared<ButtonUiElement>(wackButton);

			WackButton->onClick = [WackButton, this](AbstractGame* game) {
				if (WackButton == _mole)
					score++;
				else
					score = 0;
			};
			_uiElements.push_back(WackButton);
			_wackAMoleButtons.push_back(WackButton);
		}
	}
	_mole = _wackAMoleButtons[0];

	
	ImageUiElement BoyzImage = ImageUiElement("Boyz", { 0 , 770, 1080, 720 }, 0, false);
	_theBoyz = make_shared<ImageUiElement>(BoyzImage);
	_uiElements.push_back(_theBoyz);

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);



}

void CreditsScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";


	long timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();

	if (timePassed >= 500) {
		begin = std::chrono::steady_clock::now();
		_mole->_text = "O";
		_mole = _wackAMoleButtons[random_int_credits(0, _wackAMoleButtons.size())];
		_mole->_text = "X";
			
	}

	if (score == 5) {
		scrollLock = false;
		WackAMoleInfo->text = "You \"Won\" scroll to collect your \n \"prize\"";
	}
	scoreText->text = "Score: " + to_string(score);
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

void CreditsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	if (!scrollLock)
	{
		if (e.y > 0) // scroll up
			offset = 20;
		else if (e.y < 0) // scroll down
			offset = -20;


		int heightOfScrolBlock = 800;

		int currentY = Line->_rect.y;

		if ((currentY += offset) < anchor) {
			if ((currentY += offset) > ((anchor + heightOfScrolBlock - 200) * -1)) {

				for (auto textElement : _scrollableElements)
					textElement->_rect.y += offset;

				for (auto buttonElement : _wackAMoleButtons)
					buttonElement->_rect.y += offset;

				_theBoyz->_rect.y += offset;
			}
		}
	}

}

