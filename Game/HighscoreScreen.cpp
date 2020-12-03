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

	TextUiElement scrollText = TextUiElement("-", "Portal", 25, { 515, 250, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
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
	fps->text = "FPS: " + std::to_string(_game->currentFPS);
}

void HighScoreScreen::onScreenShowed(vector<string> args) {

	scroll->text = "";
	std::vector<SaveLevel> levels = GameSettings::getInstance().saveGame.levels;
	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto level : levels) {
		scroll->text += "------------------------------------------";
		scroll->text += " \n";
		scroll->text += level.name;
		scroll->text += " \n";
		scroll->text += "------------------------------------------";
		scroll->text += " \n";

		std::sort(level.highscores.begin(), level.highscores.end(), [](SaveHighscore a, SaveHighscore b) { return a.score > b.score; });

		int counter = 0;
		for (auto highScore : level.highscores) {
			if (counter == 5)
				break;

			scroll->text += highScore.name;
			scroll->text += ", ";
			scroll->text += to_string(highScore.score);
			scroll->text += " \n";
			counter++;
		}
		scroll->text += " \n";
		scroll->text += " ";
		scroll->text += " \n";
	}
}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HighScoreScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

	if (e.y > 0) // scroll up
		offsett = 10;
	else if (e.y < 0) // scroll down
		offsett = -10;

	scroll->_rect.y += offsett;
}



