#include "main.h"

#undef main

int main(int argc, char* argv[]) {
	// Hier wordt de core van de game geregeld. Denk aan dingen zoals SDL / Window en Audio.
	WorkshopGame game = { "Game", 1080, 720 };

	// Hier worden de schermen toegevoegd.
	unique_ptr<WorkshopUiScreen> menuScreen(new WorkshopUiScreen);
	menuScreen->registerGame(&game);
	menuScreen->onInit();
	game.screens.push_back(move(menuScreen));

	unique_ptr<WorkshopGameScreen> gameScreen(new WorkshopGameScreen);
	gameScreen->registerGame(&game);
	gameScreen->onInit();
	game.screens.push_back(move(gameScreen));
	
	// Initalise het spel.
	game.onInit();

	return 0;
}