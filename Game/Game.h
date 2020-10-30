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

	int getPreviousScreen();

	void switchScreen(int screenIndex);
};

