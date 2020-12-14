#include "main.h"
#include "GameFinishedScreen.h"
#include "SettingsScreen.h"
#include "LoadCustomlevelScreen.h"
#include "ControllManager.h"
#include "LoadingScreen.h"
#include "NewGameSlotsScreen.h"
#include "LoadGameSlotsScreen.h"
#include "CheatScreen.h"
#include "CheatHelpScreen.h"
#include "CheatManager.h"
#include "StartNewLevelScreen.h"

#undef main

int main(int argc, char* argv[]) {
	//Game gameObject = { string("Game").c_str(), 1080, 720 };

	shared_ptr<Game> game = make_shared<Game>("Game", 1080, 720);
	GameSettings::getInstance().load();

	GameSettings::getInstance().addLevel(0, { "Tutorial_Level_1", LevelType::TILED });
	GameSettings::getInstance().addLevel(1, { "Tutorial_Level_2", LevelType::TILED });
	GameSettings::getInstance().addLevel(2, { "Tutorial_Level_3", LevelType::TILED });
	GameSettings::getInstance().addLevel(3, { "Level_1", LevelType::TILED });
	GameSettings::getInstance().addLevel(4, { "Level_2", LevelType::TILED });
	GameSettings::getInstance().addLevel(5, { "Level_3", LevelType::TILED });
	GameSettings::getInstance().addLevel(6, { "Level_4", LevelType::TILED });
	GameSettings::getInstance().addLevel(7, { "Level_5", LevelType::TILED });

	//Init Controlls
	ControllManager::getInstance().initializeControls();

	//Init Cheats
	CheatManager::getInstance().initializeCheats();

	// Register Items
	shared_ptr<GlueManagableItem> glueItem = std::make_shared<GlueManagableItem>();
	Scene::getInstance().addItem("GlueGun", glueItem);

	shared_ptr<ThrusterManagableItem> thrusterItem = std::make_shared<ThrusterManagableItem>();
	Scene::getInstance().addItem("ThrusterGun", thrusterItem);

	shared_ptr<PortalManagableItem> portalItem = std::make_shared<PortalManagableItem>();
	Scene::getInstance().addItem("PortalGun", portalItem);

	// The screens have to be created outside the Game class, using "this" will create problems.
	unique_ptr<GameScreen> gameScreen(new GameScreen);
	gameScreen->registerGame(game);
	gameScreen->onInit();
	game->screens.push_back(move(gameScreen));

	unique_ptr<PauseScreen> pauseScreen(new PauseScreen);
	pauseScreen->registerGame(game);
	pauseScreen->onInit();
	game->screens.push_back(move(pauseScreen));

	unique_ptr<CreditsScreen> creditsScreen(new CreditsScreen);
	creditsScreen->registerGame(game);
	creditsScreen->onInit();
	game->screens.push_back(move(creditsScreen));

	unique_ptr<HelpScreen> helpScreen(new HelpScreen);
	helpScreen->registerGame(game);
	helpScreen->onInit();
	game->screens.push_back(move(helpScreen));

	unique_ptr<MainMenuScreen> mainMenuScreen(new MainMenuScreen);
	mainMenuScreen->registerGame(game);
	mainMenuScreen->onInit();
	game->screens.push_back(move(mainMenuScreen));

	unique_ptr<GameOverScreen> gameOverScreen(new GameOverScreen);
	gameOverScreen->registerGame(game);
	gameOverScreen->onInit();
	game->screens.push_back(move(gameOverScreen));

	unique_ptr<KeyBindingsHelpScreen> keyBindingsHelpScreen(new KeyBindingsHelpScreen);
	keyBindingsHelpScreen->registerGame(game);
	keyBindingsHelpScreen->onInit();
	game->screens.push_back(move(keyBindingsHelpScreen));

	unique_ptr<HighScoreScreen> HighScoreScreen(new HighScoreScreen);
	HighScoreScreen->registerGame(game);
	HighScoreScreen->onInit();
	game->screens.push_back(move(HighScoreScreen));

	unique_ptr<GameFinishedScreen> GameFinishedScreen(new GameFinishedScreen);
	GameFinishedScreen->registerGame(game);
	GameFinishedScreen->onInit();
	game->screens.push_back(move(GameFinishedScreen));

	unique_ptr<SettingsScreen> SettingsScreen(new SettingsScreen);
	SettingsScreen->registerGame(game);
	SettingsScreen->onInit();
	game->screens.push_back(move(SettingsScreen));

	unique_ptr<LoadCustomLevelScreen> LoadCustomlevelScreen(new LoadCustomLevelScreen);
	LoadCustomlevelScreen->registerGame(game);
	LoadCustomlevelScreen->onInit();
	game->screens.push_back(move(LoadCustomlevelScreen));

	unique_ptr<LoadingScreen> LoadingScreen(new LoadingScreen);
	LoadingScreen->registerGame(game);
	LoadingScreen->onInit();
	game->screens.push_back(move(LoadingScreen));

	unique_ptr<NewGameSlotsScreen> NewGameSlotsScreen(new NewGameSlotsScreen);
	NewGameSlotsScreen->registerGame(game);
	NewGameSlotsScreen->onInit();
	game->screens.push_back(move(NewGameSlotsScreen));

	unique_ptr<LoadGameSlotsScreen> LoadGameSlotsScreen(new LoadGameSlotsScreen);
	LoadGameSlotsScreen->registerGame(game);
	LoadGameSlotsScreen->onInit();
	game->screens.push_back(move(LoadGameSlotsScreen));

	unique_ptr<CheatScreen> CheatScreen(new CheatScreen);
	CheatScreen->registerGame(game);
	CheatScreen->onInit();
	game->screens.push_back(move(CheatScreen));

	unique_ptr<CheatHelpScreen> CheatHelpScreen(new CheatHelpScreen);
	CheatHelpScreen->registerGame(game);
	CheatHelpScreen->onInit();
	game->screens.push_back(move(CheatHelpScreen));
	
	unique_ptr<StartNewLevelScreen> StartNewLevelScreen(new StartNewLevelScreen);
	StartNewLevelScreen->registerGame(game);
	StartNewLevelScreen->onInit();
	game->screens.push_back(move(StartNewLevelScreen));

	game->onInit();

	return 0;
}