#pragma once
//API
#include "AbstractGame.h"
#include "AbstractScreen.h"
#include "AssetRegistry.h"
/////////

#include "GameScreen.h"
#include "PauseScreen.h"
#include "CreditsScreen.h"
#include "HelpScreen.h"
#include "MainMenuScreen.h"  
#include "KeyBindingsHelpScreen.h"
#include "Screens.h"
#include "HighscoreScreen.h"
#include "GameOverScreen.h"
#include "GameSettings.h"
#include "LevelData.h"
#include "LibCurl.h"

//engine
#include "GameEngine.h" 


class Game : public AbstractGame
{

public:
	using AbstractGame::AbstractGame;

	Game(const char* title, int width, int height);
	~Game();

	/// <summary>
	/// Prepare the game.
	/// </summary>
	void onInit();
	/// <summary>
	/// Switch the current screen to the screen with the given index
	/// </summary>
	int getPreviousScreen();
	/// <summary>
	/// Switch the current screen to the screen with the given index
	/// </summary>
	/// <param name="screenIndex">The index of the screen we want to display</param>
	/// <param name="args">The arguments we want to pass to the next screen</param>
	void switchScreen(int screenIndex, vector<std::string> args = {});
};

