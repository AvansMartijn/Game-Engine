
//#include <iostream>
//#include "main.h"
//
//int main(int argc, char* argv[]) {
//	Game game;
//
//	// The screens have to be created outside the Game class, using "this" will create problems.
//	unique_ptr<GameScreen> gameScreen(new GameScreen);
//	gameScreen->registerGame(&game);
//	gameScreen->onInit();
//	// move screen + ownership to game instance
//	game.screens.push_back(move(gameScreen));
//
//
//	unique_ptr<PauseScreen> pauseScreen(new PauseScreen);
//	pauseScreen->registerGame(&game);
//	pauseScreen->onInit();
//	game.screens.push_back(move(pauseScreen));
//
//	unique_ptr<CreditsScreen> creditsScreen(new CreditsScreen);
//	creditsScreen->registerGame(&game);
//	creditsScreen->onInit();
//	game.screens.push_back(move(creditsScreen));
//
//	unique_ptr<HelpScreen> helpScreen(new HelpScreen);
//	helpScreen->registerGame(&game);
//	helpScreen->onInit();
//	game.screens.push_back(move(helpScreen));
//
//	unique_ptr<MainMenuScreen> mainMenuScreen(new MainMenuScreen);
//	mainMenuScreen->registerGame(&game);
//	mainMenuScreen->onInit();
//	game.screens.push_back(move(mainMenuScreen));
//
//	game.onInit();
//
//	return 0;
//}


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