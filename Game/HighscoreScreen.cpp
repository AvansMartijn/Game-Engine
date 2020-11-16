#include "HighScoreScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include <IOFiles.h>


HighScoreScreen::HighScoreScreen() {}

HighScoreScreen::~HighScoreScreen() {}

void HighScoreScreen::onInit()
{
	const Color bgColor = { 66, 99, 116 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("  HIGHSCORES   ", font, 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement row1Text = TextUiElement(" - ", "Portal", 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_row1Text = make_shared<TextUiElement>(row1Text);
	_uiElements.push_back(_row1Text);

	TextUiElement row2Text = TextUiElement(" - ", "Portal", 48, { 100, 200, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_row2Text = make_shared<TextUiElement>(row2Text);
	_uiElements.push_back(_row2Text);

	TextUiElement row3Text = TextUiElement(" - ", "Portal", 48, { 100, 300, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_row3Text = make_shared<TextUiElement>(row3Text);
	_uiElements.push_back(_row3Text);

	TextUiElement row4Text = TextUiElement(" - ", "Portal", 48, { 100, 400, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_row4Text = make_shared<TextUiElement>(row4Text);
	_uiElements.push_back(_row4Text);

	TextUiElement row5Text = TextUiElement(" - ", "Portal", 48, { 100, 500, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_row5Text = make_shared<TextUiElement>(row5Text);
	_uiElements.push_back(_row5Text);


	ButtonUiElement quitGameButton = ButtonUiElement("Back", { (1080 / 2) - 200, 600, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));

}

void HighScoreScreen::onTick() {}

void HighScoreScreen::onScreenShowed(vector<string> args) {
	IOFiles ioFiles;

	std::vector<std::string> lines = ioFiles.readFromFile("Highscores");
	std::multimap<int, std::string, std::greater<int>> scores;

	for (auto line : lines)
	{
		std::stringstream stringstream(line);
		std::vector<std::string> result;

		while (stringstream.good())
		{
			string substr;
			getline(stringstream, substr, ',');
			result.push_back(substr);
		}
		scores.insert({ stoi(result[0]), result[1] });
	}

	int counter = 0;
	std::string highscore;

	for (auto test : scores)
	{
		highscore.clear();
		if (counter < 5)
		{
			counter++;
			highscore +=  to_string(counter) + ". ";
			highscore += to_string(test.first);
			highscore += ", ";
			highscore += test.second;
			highscore += " ";

			if (counter == 1)
				_row1Text->text = highscore;
			if (counter == 2)
				_row2Text->text = highscore;
			if (counter == 3)
				_row3Text->text = highscore;
			if (counter == 4)
				_row4Text->text = highscore;
			if (counter == 5)
				_row5Text->text = highscore;
		}
		else
		{
			break;
		}
	}

	if (highscore == "")
		highscore = "No Highscores";
}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HighScoreScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

