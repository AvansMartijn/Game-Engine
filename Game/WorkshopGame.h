#pragma once
#include "AbstractGame.h"

class WorkshopGame : public AbstractGame {
public:
	WorkshopGame(const char* title, int width, int height);
	~WorkshopGame();

	void onInit();

	int getPreviousScreen();

	void switchScreen(int screenIndex, vector<std::string> args = {});
};

