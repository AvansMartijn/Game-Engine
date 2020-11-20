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
	const string font = "Portal";
	backgroundTrackKey = "Game_Over";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement scrollText = TextUiElement("-", "Portal", 25, { 515, 250, 100, 0 }, { 255, 255, 255 }, bgColor, false, 200);
	scroll = make_shared<TextUiElement>(scrollText);
	_uiElements.push_back(scroll);

	TextUiElement headerText = TextUiElement("Highscores", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement _bodyText = TextUiElement("Level 1", font, 25, { 100, 160, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(_bodyText));

	ImageUiElement backgroundImg2 = ImageUiElement("Line", { 230 , 200, 620, 1});
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg2));


	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));
}

void HighScoreScreen::onTick() {}

void HighScoreScreen::onScreenShowed(vector<string> args) {

	scroll->text = "";


	//get list from curFt level
	std::vector<SaveLevel> levels = GameSettings::getInstance().saveGame.levels;

	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto level : levels)
	{
		scroll->text += "-";
		scroll->text += level.name += "-                  ";
		for (auto highScore : level.highscores)
		{
			scroll->text += highScore.name += ", ";
			scroll->text += to_string(highScore.score) += "                    ";
		}
	}

	//IOFiles ioFiles;

	/*std::vector<std::string> lines = ioFiles.readFromFile("Highscores");
	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto line : lines) {
		std::stringstream stringstream(line);
		std::vector<std::string> result;

		while (stringstream.good()) {
			string substr;
			getline(stringstream, substr, ',');
			result.push_back(substr);
		}
		scores.insert({ stoi(result[0]), result[1] });
	}*/

	//int counter = 0;
	//std::string highscore;

	//for (auto score : scores) {
	//	highscore.clear();
	//	if (counter < 5) {
	//		counter++;
	//		highscore +=  to_string(counter) + ". ";
	//		highscore += to_string(score.first);
	//		highscore += ", ";
	//		highscore += score.second;
	//		highscore += " ";

	//		if (counter == 1)
	//			_row1Text->text = highscore;
	//		if (counter == 2)
	//			_row2Text->text = highscore;
	//		if (counter == 3)
	//			_row3Text->text = highscore;
	//		if (counter == 4)
	//			_row4Text->text = highscore;
	//		if (counter == 5)
	//			_row5Text->text = highscore;
	//	}
	//	else {
	//		break;
	//	}
	//}

	//if (highscore == "")
	//	highscore = "No Highscores";
}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HighScoreScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

	if (e.y > 0) // scroll up
		offsett = 10;
	else if (e.y < 0) // scroll down
		offsett = -10;

	scroll->_rect.y += offsett;

	/*for (auto test : _uiElements)
	{
		if(test == scoll)
			test->_rect.y += offsett;
	}*/
}



