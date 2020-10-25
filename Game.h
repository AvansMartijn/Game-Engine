#pragma once
#include "AbstractGame.h"
#include "AbstractScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"
#include "AssetRegistry.h"

class Game : public AbstractGame
{
public:
	using AbstractGame::AbstractGame;

	Game();
	~Game();

	/// <summary>
	/// Prepare the game.
	/// </summary>
	void onInit();

	/// <summary>
	/// Switch the current screen to the screen with the given index
	/// </summary>
	/// <param name="screenIndex">The index of the screen we want to display</param>
	void switchScreen(int screenIndex);
};

