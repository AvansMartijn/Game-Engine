#include "main.h"


int main(int argc, char* argv[]) {
	Game game = Game{};

	// The screens have to be created outside the Game class, using "this" will create problems.
	GameScreen gameScreen = GameScreen{};
	gameScreen.registerGame(&game);
	gameScreen.onInit();
	game.screens.push_back(make_shared<GameScreen>(gameScreen));

	PauseScreen pauseScreen = PauseScreen{};
	pauseScreen.registerGame(&game);
	pauseScreen.onInit();
	game.screens.push_back(make_shared<PauseScreen>(pauseScreen));

	game.onInit();

	return 0;
}