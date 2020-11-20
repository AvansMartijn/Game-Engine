#include "main.h"
#include "GameFinishedScreen.h"
#include "SettingsScreen.h"



#undef main

int main(int argc, char* argv[]) {
	Game game = { "Game", 1080, 720 };

	GameSettings::getInstance().load();

	GameSettings::getInstance().addLevel(0, { "Level0", LevelType::TILED });
	GameSettings::getInstance().addLevel(1, { "LevelTest", LevelType::TILED });
	GameSettings::getInstance().addLevel(2, { "Default", LevelType::DEFAULT });

	// Register Items
	shared_ptr<GlueManagableItem> glueItem = std::make_shared<GlueManagableItem>();
	Scene::getInstance().addItem("GlueGun", glueItem);

	shared_ptr<ThrusterManagableItem> thrusterItem = std::make_shared<ThrusterManagableItem>();
	Scene::getInstance().addItem("ThrusterGun", thrusterItem);

	shared_ptr<PortalManagableItem> portalItem = std::make_shared<PortalManagableItem>();
	Scene::getInstance().addItem("PortalGun", portalItem);

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

	unique_ptr<HighScoreScreen> HighScoreScreen(new HighScoreScreen);
	HighScoreScreen->registerGame(&game);
	HighScoreScreen->onInit();
	game.screens.push_back(move(HighScoreScreen));

	unique_ptr<GameFinishedScreen> GameFinishedScreen(new GameFinishedScreen);
	GameFinishedScreen->registerGame(&game);
	GameFinishedScreen->onInit();
	game.screens.push_back(move(GameFinishedScreen));

	unique_ptr<SettingsScreen> SettingsScreen(new SettingsScreen);
	SettingsScreen->registerGame(&game);
	SettingsScreen->onInit();
	game.screens.push_back(move(SettingsScreen));


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