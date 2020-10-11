#pragma once
#include "AbstractGame.h"
#include "AbstractScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"

class Game : public AbstractGame
{
public:
	using AbstractGame::AbstractGame;

	Game();
	~Game();

	void onInit();
	void switchScreen(int screenIndex);
};

