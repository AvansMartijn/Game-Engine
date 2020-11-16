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

	TextUiElement bodyText = TextUiElement("  Score: ", "Portal", 48, { 100, 100, 0, 0 }, { 180, 102, 13 }, { 7, 16, 29 }, true);
	_bodyText = make_shared<TextUiElement>(bodyText);
	_uiElements.push_back(_bodyText);


	ButtonUiElement quitGameButton = ButtonUiElement("Back", { (1080 / 2) - 200, 500, 500, 100 }, bgColor, { 180, 102, 13 }, font, 40);
	quitGameButton.registerGame(_game);
	quitGameButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(quitGameButton));

}

void HighScoreScreen::onTick() {}

void HighScoreScreen::onScreenShowed(vector<string> args) {
	IOFiles ioFiles;
	std::vector<std::string> lines = ioFiles.readFromFile("Highscores");
	std::map<int, std::string, std::greater<int>> scores;

	for (auto line : lines)
	{
		std::stringstream ss(line);
		std::vector<std::string> result;

		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}
		scores.insert({ stoi(result[0]),result[1] });
	}

	int counter = 0;
	std::string highscores;
	for (auto test : scores)
	{
		if (counter < 10)
		{
			counter++;
			highscores +=  to_string(counter) + "(";
			highscores += to_string(test.first);
			highscores += ", ";
			highscores += test.second;
			highscores += "), ";
			highscores += " ";
		}
		else
			break;
	}

	if (highscores == "")
		highscores = "No Highscores";

	_bodyText->text = highscores;
	//_bodyText->text = "  Score: " + to_string(Scene::getInstance().score);
}

void HighScoreScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void HighScoreScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HighScoreScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

