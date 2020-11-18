#include "DefaultTiledLevel.h"

void DefaultTiledLevel::createLevel(GameEngine gameEngine) {
	std::map<int, std::string> textures;

	for (size_t gameObjectIndex = 0; gameObjectIndex < gameObjects.size(); gameObjectIndex++) {
		TiledGameObject go = gameObjects[gameObjectIndex];

		std::string textureKey = getTextureKeyFromPath("Tiled", go.image);

		textures.clear();
		textures.insert(pair<int, std::string>(0, textureKey));

		//float x = go.x * go.width;
		//float y = go.y * go.height;

		float baseWidth = 1.0f / tileWidth;
		float baseHeight = 1.0f / tileHeight;
		float width = baseWidth * go.width;
		float height = baseHeight * go.height;
		float x = go.x * 1.0f;
		float y = go.y * 1.0f;

		shared_ptr<GameObject> floor = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
			x, y, width, height, 5, true, false);

	}
}

std::string DefaultTiledLevel::getTextureKeyFromPath(std::string prefix, std::string& path) {
	// Find file name
	std::string name = path.substr(path.rfind('/') + 1);

	// Remove file type
	name.erase(name.rfind('.'));

	// Find type prefix.
	std::string filePath = path.substr(0, path.rfind('/'));
	std::string typePrefix = filePath.substr(filePath.rfind('/') + 1);

	return prefix != "" ? prefix + "_" + typePrefix + "_" + name : typePrefix + "_" + name;
}