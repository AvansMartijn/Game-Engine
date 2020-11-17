#include "DefaultTiledLevel.h"
void DefaultTiledLevel::createLevel(GameEngine gameEngine) {
	for (size_t gameObjectIndex = 0; gameObjectIndex < gameObjects.size(); gameObjectIndex++) {
		TiledGameObject go = gameObjects[gameObjectIndex];

		std::cout << go.image << endl;
	}
}