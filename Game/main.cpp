#include "main.h"



#undef main

int main(int argc, char* argv[]) {
	Game game = { "Game", 1080, 720 };
	
	// The screens have to be created outside the Game class, using "this" will create problems.
	unique_ptr<GameScreen> gameScreen(new GameScreen);
	gameScreen->registerGame(&game);
	gameScreen->onInit();
	game.screens.push_back(move(gameScreen));

	unique_ptr<PauseScreen> pauseScreen(new PauseScreen);
	pauseScreen->registerGame(&game);
	pauseScreen->onInit();
	game.screens.push_back(move(pauseScreen));

	unique_ptr<CreditsScreen> creditsScreen(new CreditsScreen);
	creditsScreen->registerGame(&game);
	creditsScreen->onInit();
	game.screens.push_back(move(creditsScreen));

	unique_ptr<HelpScreen> helpScreen(new HelpScreen);
	helpScreen->registerGame(&game);
	helpScreen->onInit();
	game.screens.push_back(move(helpScreen));

	unique_ptr<MainMenuScreen> mainMenuScreen(new MainMenuScreen);
	mainMenuScreen->registerGame(&game);
	mainMenuScreen->onInit();
	game.screens.push_back(move(mainMenuScreen));

	unique_ptr<GameOverScreen> gameOverScreen(new GameOverScreen);
	gameOverScreen->registerGame(&game);
	gameOverScreen->onInit();
	game.screens.push_back(move(gameOverScreen));

	unique_ptr<KeyBindingsHelpScreen> keyBindingsHelpScreen(new KeyBindingsHelpScreen);
	keyBindingsHelpScreen->registerGame(&game);
	keyBindingsHelpScreen->onInit();
	game.screens.push_back(move(keyBindingsHelpScreen));

	game.onInit();

	return 0;
}



//#include <iostream>
//
//#include "GameEngine.h" //Api Facade
//#include <Talker.h> //Exposed class
//
//#include "main.h"
//
//int main()
//{
//	std::cout << "Hello World!\n";
//	std::cout << EngineDoSomthing() << "\n";
//	std::cout << EngineDoSomthingElse() << "\n";
//
//	Talker talk;
//	std::cout << talk.Talk() << "\n";
//
//	return 0;
//}