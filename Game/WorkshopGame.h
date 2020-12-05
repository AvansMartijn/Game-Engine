#pragma once
#include "AbstractGame.h"
#include "ContactListener.h"

class WorkshopGame : public AbstractGame {
public:
	WorkshopGame(const char* title, int width, int height);
	~WorkshopGame();

	void onInit();
};

