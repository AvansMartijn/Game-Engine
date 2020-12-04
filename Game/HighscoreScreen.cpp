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
	scroll = make_shared<TextUiElement>(scrollText);
	_uiElements.push_back(scroll);

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
}


void HighScoreScreen::onTick() {
	if (shouldShowFPS)
		fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else 
		fps->text = "  ";
}


void HighScoreScreen::onScreenShowed(vector<string> args) {
	scroll->textLines.clear();
	std::vector<SaveLevel> levels = GameSettings::getInstance().saveGame.levels;
	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto level : levels) {

		scroll->textLines.push_back(level.name);
		scroll->textLines.push_back("------------------------------------------");
		scroll->textLines.push_back(" ");

		std::sort(level.highscores.begin(), level.highscores.end(), [](SaveHighscore a, SaveHighscore b) { return a.score > b.score; });

		int counter = 0;
		for (auto highScore : level.highscores) {
			if (counter == 5)
				break;

			scroll->textLines.push_back(highScore.name + ", " + to_string(highScore.score));
			counter++;
		}
		scroll->textLines.push_back(" ");
		scroll->textLines.push_back(" ");
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
		offsett = 10;
	else if (e.y < 0) // scroll down
		offsett = -10;

	scroll->_rect.y += offsett;
}



