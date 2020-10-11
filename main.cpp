#include "main.h"
#include <iostream>
#include "Game.h"
#include "GameScreen.h"
#include "PauseScreen.h"
/*
#include "Windows.h"
#include "SDL.h"
#include "Window.h"
#include "GameObjectExtensionFactory.h"
#include "AbstractEntityAi.h"
#include "AbstractBehaviour.h"
#include "GameObjectBuilder.h"
#include "AttackExtension.h"
#include "MoveExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"
#include "CheckPhysicsExtension.h"
#include "IEMath.h"

#include <list>
#include <thread>
#include "DefaultEntityAI.h"
*/

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