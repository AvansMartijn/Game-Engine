#include "HighScoreScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "GameSettings.h"

HighScoreScreen::HighScoreScreen() {}

HighScoreScreen::~HighScoreScreen() {}

void HighScoreScreen::onInit()
{
	const Color bgColor = { 28, 28, 28 };
	const Color TColor = { 51,51,51 };
	const string font = "Portal";
	backgroundTrackKey = "Game_Over";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	std::vector<std::string> lines;
	lines.push_back("-");
	TextUiElement scrollText = TextUiElement(lines, "Portal", 25, { 515, 250, 100, 0 }, { 255, 255, 255 }, bgColor, true);
	_scrollableText = make_shared<TextUiElement>(scrollText);
	_uiElements.push_back(_scrollableText);
	_anchor = _scrollableText->_rect.y;

	ImageUiElement portalOrangeImg = ImageUiElement("PortalOrange", { 20 , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_shared<ImageUiElement>(portalOrangeImg));

	ImageUiElement portalPurpleImg = ImageUiElement("PortalPurple", { (1080 - 70) , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_shared<ImageUiElement>(portalPurpleImg));


	ImageUiElement headerImg = ImageUiElement("BackgroundTint", { 0 , 0, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(headerImg));
	
	TextUiElement headerText = TextUiElement("Highscores", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, TColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	ImageUiElement footerImg = ImageUiElement("BackgroundTint", { 0 , 625, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(footerImg));

	ButtonUiElement backButton = ButtonUiElement("Back", { 20, 650, 70, 40 }, TColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}


void HighScoreScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else 
		_fps->text = "  ";
}


void HighScoreScreen::onScreenShowed(vector<string> args) {
	_scrollableText->textLines.clear();
	std::vector<SaveLevel> levels = GameSettings::getInstance().saveGame.levels;
	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto level : levels) {

		_scrollableText->textLines.push_back(level.name);
		_scrollableText->textLines.push_back("------------------------------------------");
		_scrollableText->textLines.push_back(" ");

		std::sort(level.highscores.begin(), level.highscores.end(), [](SaveHighscore a, SaveHighscore b) { return a.score > b.score; });

		int counter = 0;
		for (auto highScore : level.highscores) {
			if (counter == 5)
				break;

			_scrollableText->textLines.push_back(highScore.name + ", " + to_string(highScore.score));
			counter++;
		}
		_scrollableText->textLines.push_back(" ");
		_scrollableText->textLines.push_back(" ");
	}
}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HighScoreScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

	if (e.y > 0) // scroll up
		_offset = 20;
	else if (e.y < 0) // scroll down
		_offset = -20;

	int heightOfScrolBlock = _scrollableText->textLines.size() * 25;
	int currentY = _scrollableText->_rect.y;

	if ((currentY += _offset) < _anchor)
		if ((currentY += _offset) > ((_anchor + heightOfScrolBlock - 200) * -1))
			_scrollableText->_rect.y += _offset;
	
}



