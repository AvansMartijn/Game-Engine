#include "pch.h"
#include "AbstractGame.h"

AbstractGame::AbstractGame(const char* title, int width, int height) {
	_window = unique_ptr<Window>(new Window("Fluix", 1080, 720));
	_activeScreen = 0;
}

AbstractGame::~AbstractGame() {
}

void AbstractGame::gameLoop() {
	for (int i = 0; i < screens.size(); i++) {
		for (shared_ptr<AbstractUiElement>& obj : screens[i]->uiElements)
			obj->preRender(_window);
	}

	SDL_Event event;

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	while (running) {
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60.0) {
			//cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			screens.at(_activeScreen)->onTick();

			_window->clear();

			for (shared_ptr<GameObject>& obj : screens.at(_activeScreen)->gameObjects)
				obj->render(_window);

			for (shared_ptr<AbstractUiElement>& obj : screens.at(_activeScreen)->uiElements)
				obj->render(_window);

			_window->display();
			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_KEYDOWN:
					screens.at(_activeScreen)->handleKeyboardInput(event.key);
					break;
				case SDL_MOUSEMOTION:
					screens.at(_activeScreen)->handleMouseMotionInput(event.motion);

					break;
				case SDL_MOUSEBUTTONDOWN:
					screens.at(_activeScreen)->handleMouseClickInput(event.button);

					break;
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
				}
			}
		}
	}
}

void AbstractGame::registerTexture(std::string textureKey, std::string texturePath) {
	_window->registerTexture(textureKey, texturePath);
}

void AbstractGame::registerFont(std::string fontKey, std::string fontPath) {
	_window->registerFont(fontKey, fontPath);
}

void AbstractGame::saveHighscoreToFile(std::string currentLevel, double highscore)
{
	//This will determine the first place when highscores are exactly the same.
	time_t TimeInSecondsSince01_01_1970 = time(0);

	vector<std::string> Highscores = this->getHighscoresFromFile("allLevels");

	std::string TimeToString = std::to_string(TimeInSecondsSince01_01_1970);
	std::string Highscore = std::to_string(highscore);
	std::string scoreToPushIntoFile = currentLevel + "," + Highscore + "," + TimeToString;

	Highscores.push_back(scoreToPushIntoFile);

	ofstream outFile;
	outFile.open("Highscore.txt");

	if (outFile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	outFile.clear();

	for (int i = 0; i < Highscores.size(); i++)
	{
		outFile << Highscores[i] << endl;
	}

	outFile.close();
}

vector<std::string> AbstractGame::getHighscoresFromFile(std::string currentLevel)
{
	ifstream inFile;
	vector<std::string> Highscores;
	inFile.open("Highscore.txt");

	if (inFile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	std::string item;

	while (!inFile.eof())
	{
		inFile >> item;
		std::string level = item.substr(0, item.find(','));
		if (level == currentLevel || currentLevel == "allLevels")
		{
			if(item.length() > 0)
				Highscores.push_back(item);
		}
	}

	inFile.close();

	return Highscores;
}
