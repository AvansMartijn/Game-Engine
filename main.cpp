#include "main.h"


int main(int argc, char* argv[]) {
	Game game;

	// The screens have to be created outside the Game class, using "this" will create problems.
	unique_ptr<GameScreen> gameScreen(new GameScreen);
	gameScreen->registerGame(&game);
	gameScreen->onInit();
	// move screen + ownership to game instance
	game.screens.push_back(move(gameScreen));

	unique_ptr<PauseScreen> pauseScreen(new PauseScreen);
	pauseScreen->registerGame(&game);
	pauseScreen->onInit();
	game.screens.push_back(move(pauseScreen));

	game.onInit();

	return 0;
}