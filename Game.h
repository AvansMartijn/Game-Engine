#pragma once
#include "AbstractGame.h"

class Game : public AbstractGame
{
public:
	using AbstractGame::AbstractGame;

	void init();
	void switchScreen(int screenIndex);
};

