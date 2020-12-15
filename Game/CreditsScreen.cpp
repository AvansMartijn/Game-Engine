#include "CreditsScreen.h"
#include "Utilities.h"

CreditsScreen::CreditsScreen() {}
CreditsScreen::~CreditsScreen() {}

void CreditsScreen::onInit() {
	_begin = std::chrono::steady_clock::now();

	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";

	const string teamMembers[]{ "Lars (laari)", "Wesley (bob)", "Martijn (mardy.tk/wonenzoals)", "Xandor (jeboyx)", "Mike (King K Rool)", "Chiel (MC Vaper)" };
	int posy = 100, posx = 100;

	_backgroundImage = make_unique<ImageUiElement>(ImageUiElement("Background", { 0 , 0, 1080, 720 }));


	TextUiElement title = TextUiElement("Credits", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	TextUiElement line = TextUiElement("Team Mike", font, 40, { 100, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	_scrollableElements.push_back(make_unique<TextUiElement>(line));
	_line = _scrollableElements.back().get();
	_anchor = _line->rect.y;

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](shared_ptr<AbstractGame> game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	for (int i = 0; i < 6; i++) {
		posy += 50;

		TextUiElement lineOfC = TextUiElement(teamMembers[i], font, 25, { 100, posy, 0, 0 }, { 255, 255, 255 }, bgColor, false);
		_scrollableElements.push_back(make_unique<TextUiElement>(lineOfC));
	}

	TextUiElement wackAMoleText = TextUiElement("Wack-A-Mole", font, 40, { 720, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	_scrollableElements.push_back(make_unique<TextUiElement>(wackAMoleText));

	_scrollableElements.push_back(make_unique<TextUiElement>(TextUiElement("Get a score of 5 and win a \n \"Prize\"", "Portal", 25, { 720, 150, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, true)));
	_wackAMoleInfo = _scrollableElements.back().get();

	_scrollableElements.push_back(make_unique<TextUiElement>(TextUiElement("Score: ", "Portal", 40, { 770, 250, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false)));
	_scoreText = _scrollableElements.back().get();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ButtonUiElement wackButton = ButtonUiElement("O", { 770 + (i * 50), 300 + (j*50), 50, 50 }, bgColor, { 255, 255, 255 }, font, 25);
			wackButton.registerGame(_game);

			_wackAMoleButtons.push_back(make_unique<ButtonUiElement>(wackButton));

			ButtonUiElement* wackButtonPtr = _wackAMoleButtons.back().get();
			wackButtonPtr->onClick = [wackButtonPtr, this](shared_ptr<AbstractGame> game) {
				if (wackButtonPtr == _mole)
					_score++;
				else
					_score = 0;
			};

		}
	}
	_mole = _wackAMoleButtons[0].get();

	ImageUiElement boyzImage = ImageUiElement("Boyz", { 0 , 770, 1080, 720 }, 0, false);
	_theBoyz = addUiElement<ImageUiElement>(make_unique<ImageUiElement>(boyzImage));

	addFpsElement("Portal");
}

void CreditsScreen::onTick() {
	updateFpsElement();

	auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _begin).count();

	if (timePassed >= 500) {
		_begin = std::chrono::steady_clock::now();
		_mole->text = "O";
		_mole = _wackAMoleButtons[Utilities::getInstance().getRandomInt(0, (int)_wackAMoleButtons.size())].get();
		_mole->text = "X";
	}

	if (_score == 5) {
		_scrollLock = false;
		_wackAMoleInfo->text = "You \"Won\" scroll to collect your \n \"prize\"";
	}
	_scoreText->text = "Score: " + to_string(_score);
}

void CreditsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym) {
	case SDLK_ESCAPE: // GO BACK TO PAUSE
		_game->switchScreen(Screens::MainMenu);

		break;
	default:
		break;
	}
}

void CreditsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void CreditsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	if (!_scrollLock) {
		if (e.y > 0) // scroll up
			_offset = 20;
		else if (e.y < 0) // scroll down
			_offset = -20;

		int heightOfScrolBlock = 800;

		int currentY = _line->rect.y;

		if ((currentY += _offset) < _anchor) {
			if ((currentY += _offset) > ((_anchor + heightOfScrolBlock - 200) * -1)) {

				for (const unique_ptr<TextUiElement>& textElement : _scrollableElements)
					textElement->rect.y += _offset;

				for (const unique_ptr<ButtonUiElement>& buttonElement : _wackAMoleButtons)
					buttonElement->rect.y += _offset;

				_theBoyz->rect.y += _offset;
			}
		}
	}
}

void CreditsScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	AbstractScreen::handleMouseClickInput(e);

	if (e.button == SDL_BUTTON_LEFT) {
		for (unique_ptr<ButtonUiElement>& element : _wackAMoleButtons) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick(_game);

				break;
			}
		}
	}
}

void CreditsScreen::preRender(const unique_ptr<Window>& window) {
	AbstractScreen::preRender(window);

	_backgroundImage->preRender(window);

	for (const unique_ptr<TextUiElement>& textElement : _scrollableElements)
		textElement->preRender(window);

	for (const unique_ptr<ButtonUiElement>& buttonElement : _wackAMoleButtons)
		buttonElement->preRender(window);
}

void CreditsScreen::render(const unique_ptr<Window>& window) {
	_backgroundImage->render(window);
	for (const unique_ptr<TextUiElement>& textElement : _scrollableElements)
		textElement->render(window);

	for (const unique_ptr<ButtonUiElement>& buttonElement : _wackAMoleButtons)
		buttonElement->render(window);

	AbstractScreen::render(window);
}