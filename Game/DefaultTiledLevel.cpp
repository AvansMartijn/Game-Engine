#include "DefaultTiledLevel.h"

void DefaultTiledLevel::createLevel(GameEngine gameEngine) {
	std::map<int, std::string> textures;

	for (size_t gameObjectIndex = 0; gameObjectIndex < gameObjects.size(); gameObjectIndex++) {
		TiledGameObject go = gameObjects[gameObjectIndex];

		float baseWidth = 1.0f / tileWidth;
		float baseHeight = 1.0f / tileHeight;
		float width = baseWidth * go.width;
		float height = baseHeight * go.height;
		float x = go.x * 1.0f;
		float y = go.y * 1.0f;

		float yLeftOver = 1.0f - height;
		if (height < 1)
			y = y + (yLeftOver / 2);
		std::string extensionsString = go.properties["extensions"].valueString;
		std::vector<std::string> extensions = AssetRegistry::getInstance().split(extensionsString, ',');

		if (go.layer == "tilelayer")
			createTile(gameEngine, go, textures, extensions, x, y, width, height);
		else if (go.layer == "objectgroup")
			createObject(gameEngine, go, textures, extensions, x, y, width, height);
	}

	// Create Portals
	textures.clear();
	textures.insert(pair<int, std::string>(0, "Portal1"));
	shared_ptr<GameObject> portal1 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalA = portal1;

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Portal2"));
	shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalB = portal2;

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);

}

void DefaultTiledLevel::createTile(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::map<int, std::string>& textures, std::vector<std::string>& extensions, float x, float y, float width, float height) {
	std::string textureKey = getTextureKeyFromPath("Tiled", tiledGameObject.image);

	textures.clear();
	textures.insert(pair<int, std::string>(0, textureKey));

	float friction = 2.5f;
	if (tiledGameObject.properties.find("friction") != tiledGameObject.properties.end())
		friction = tiledGameObject.properties["friction"].valueFloat;

	bool isFixed = true;
	if (tiledGameObject.properties.find("fixed") != tiledGameObject.properties.end())
		isFixed = tiledGameObject.properties["fixed"].valueBool;

	if (tiledGameObject.properties.find("sensor") != tiledGameObject.properties.end()) {
		std::string sensor = tiledGameObject.properties["sensor"].valueString;

		createNonRigidBody(gameEngine, extensions, textures,
			x, y, width, height, sensor);
	}
	else {
		createGameObject(gameEngine, extensions, textures,
			x, y, width, height, friction, isFixed, false);
	}
}

void DefaultTiledLevel::createObject(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::map<int, std::string>& textures, std::vector<std::string>& extensions, float x, float y, float width, float height) {
	if (tiledGameObject.type == "Player") {
		textures.clear();
		textures.insert(pair<int, std::string>(PlayerMoves::LOOK_RIGHT, "Player_Look_Right"));
		textures.insert(pair<int, std::string>(PlayerMoves::RUN_RIGHT, "Player_Running_Right"));
		textures.insert(pair<int, std::string>(PlayerMoves::JUMP_RIGHT, "Player_Jump_Right"));
		textures.insert(pair<int, std::string>(PlayerMoves::FALL_RIGHT, "Player_Fall_Right"));
		textures.insert(pair<int, std::string>(PlayerMoves::LOOK_LEFT, "Player_Look_Left"));
		textures.insert(pair<int, std::string>(PlayerMoves::RUN_LEFT, "Player_Running_Left"));
		textures.insert(pair<int, std::string>(PlayerMoves::JUMP_LEFT, "Player_Jump_Left"));
		textures.insert(pair<int, std::string>(PlayerMoves::FALL_LEFT, "Player_Fall_Left"));

		Scene::getInstance().setPlayer(createEntity(gameEngine, extensions, textures,
			x, y, 0.7f, 1.8f));
	}
	else if (tiledGameObject.layerType == "Entities") {

	}
	else if (tiledGameObject.layerType == "Tools") {
		std::string sensor = tiledGameObject.properties["sensor"].valueString;
		shared_ptr<AbstractManageableItem> item = Scene::getInstance().getItem(tiledGameObject.type);
		textures.clear();

		if (tiledGameObject.properties.find("ammo") != tiledGameObject.properties.end())
			item->setAmmo(tiledGameObject.properties["ammo"].valueInt);

		if (tiledGameObject.properties.find("cooldown") != tiledGameObject.properties.end())
			item->setCooldown(tiledGameObject.properties["cooldown"].valueInt);

		shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, textures, x, y, item->getWidth(), item->getHeight(), sensor);
		dynamic_pointer_cast<PickupExtension>(gameObject->getExtension(typeid(PickupExtension)))->setItem(item);
	}
}

std::string DefaultTiledLevel::getTextureKeyFromPath(std::string prefix, std::string& path) const {
	// Find file name
	std::string name = path.substr(path.rfind('/') + 1);

	// Remove file type
	name.erase(name.rfind('.'));

	// Find type prefix.
	std::string filePath = path.substr(0, path.rfind('/'));
	std::string typePrefix = filePath.substr(filePath.rfind('/') + 1);

	return prefix != "" ? prefix + "_" + typePrefix + "_" + name : typePrefix + "_" + name;
}