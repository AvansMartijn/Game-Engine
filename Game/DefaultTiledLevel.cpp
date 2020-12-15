#include "DefaultTiledLevel.h"
#include <DefaultEntityAI.h>

void DefaultTiledLevel::createLevel(GameEngine gameEngine) {
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

		std::map<std::string, ExtensionProperty> extensionProperties;
		for (auto extensionProperty : go.properties)
			extensionProperties.insert(make_pair(extensionProperty.first, extensionProperty.second.toExtensionProperty()));

		if (go.layer == "tilelayer")
			createTile(gameEngine, go, extensions, extensionProperties, x, y, width, height);
		else if (go.layer == "objectgroup")
			createObject(gameEngine, go, extensions, extensionProperties, x, y, width, height);
	}

	// Create Portals
	shared_ptr<GameObject> portal1 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal1",
		-50, -50, 3, 0.7f, "portalSensor");
	Scene::getInstance().portalA = portal1;

	shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal2",
		-50, -50, 3, 0.7f, "portalSensor");
	Scene::getInstance().portalB = portal2;

	portal1->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>()->link(Scene::getInstance().portalB);
	portal2->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>()->link(Scene::getInstance().portalA);
}

void DefaultTiledLevel::createTile(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, std::map<std::string, ExtensionProperty> extensionProperties, float x, float y, float width, float height) {
	std::string textureKey = getTextureKeyFromPath("Tiled", tiledGameObject.image);

	float friction = 2.5f;
	if (tiledGameObject.properties.find("friction") != tiledGameObject.properties.end())
		friction = tiledGameObject.properties["friction"].valueFloat;

	bool isFixed = true;
	if (tiledGameObject.properties.find("fixed") != tiledGameObject.properties.end())
		isFixed = tiledGameObject.properties["fixed"].valueBool;

	if (tiledGameObject.properties.find("sensor") != tiledGameObject.properties.end()) {
		std::string sensor = tiledGameObject.properties["sensor"].valueString;

		shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, textureKey,
			x, y, width, height, sensor);

		for (shared_ptr<AbstractGameObjectExtension> extension : gameObject->getExtensions())
			extension->fillProperties(extensionProperties);
	}
	else {
		shared_ptr<GameObject> gameObject = createGameObject(gameEngine, extensions, textureKey,
			x, y, width, height, friction, isFixed, false);

		for (shared_ptr<AbstractGameObjectExtension> extension : gameObject->getExtensions())
			extension->fillProperties(extensionProperties);
	}
}

void DefaultTiledLevel::createObject(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, std::map<std::string, ExtensionProperty> extensionProperties, float x, float y, float width, float height) {
	if (tiledGameObject.type == "Player") {
		Scene::getInstance().setPlayer(createPlayer(gameEngine, extensions, "Waluigi", x, y, 0.7f, 1.8f));

		PlayerAnimationHandler animationHandler;
		Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->setAnimationHandler(make_shared<PlayerAnimationHandler>(animationHandler));
		Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->registerAnimations();

		for (shared_ptr<AbstractGameObjectExtension> extension : Scene::getInstance().getPlayer()->getExtensions())
			extension->fillProperties(extensionProperties);
	}
	else if (tiledGameObject.type == "Enemy") {
		shared_ptr<GameObject> enemy = createEnemy(gameEngine, extensions, "Goomba", x, y, 0.7f, 1.0f);

		if (enemy->hasExtension(typeid(AiExtension))) {
			// We only use the default entity ai, so no need to check for anything else.
			shared_ptr<DefaultEntityAI> entityAi = make_shared<DefaultEntityAI>(DefaultEntityAI{});
			entityAi->createBehaviourTree(enemy);

			enemy->getExtension<AiExtension>()->ai = entityAi;
		}

		EnemyAnimationHandler animationHandler;
		enemy->getExtension<AnimationExtension>()->setAnimationHandler(make_shared<EnemyAnimationHandler>(animationHandler));
		enemy->getExtension<AnimationExtension>()->registerAnimations();

		for (shared_ptr<AbstractGameObjectExtension> extension : enemy->getExtensions())
			extension->fillProperties(extensionProperties);
	}
	else if (tiledGameObject.layerType == "Tools") {
		std::string sensor = tiledGameObject.properties["sensor"].valueString;

		shared_ptr<AbstractManageableItem> itemBluePrint = Scene::getInstance().getItem<AbstractManageableItem>(tiledGameObject.type);

		shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, "", x, y, itemBluePrint->getWidth(), itemBluePrint->getHeight(), sensor);

		gameObject->getExtension<PickupExtension>()->itemType = tiledGameObject.type;
		for (shared_ptr<AbstractGameObjectExtension> extension : gameObject->getExtensions())
			extension->fillProperties(extensionProperties);
	}
	else if (tiledGameObject.layerType == "Misc") {
		if (tiledGameObject.type == "Text") {

			std::string text = tiledGameObject.properties["text"].valueString;

			std::vector<std::string> lines;
			std::string::size_type pos = 0;
			std::string::size_type prev = 0;

			while ((pos = text.find("\n", prev)) != std::string::npos) {
				lines.push_back(text.substr(prev, pos - prev));
				prev = pos + 1;
			}
			lines.push_back(text.substr(prev));

			TextUiElement textBox = TextUiElement(lines, "Portal", 20, { (1080 / 2), 600, 0, 0 }, { 0, 0, 0 }, { 255, 255, 255, 100 }, true, true);
			Scene::getInstance().addTextUiElement(make_shared<TextUiElement>(textBox));
		}
	}
}

std::string DefaultTiledLevel::getTextureKeyFromPath(const std::string& prefix, const std::string& path) const {
	// Find file name
	std::string name = path.substr(path.rfind('/') + 1);

	// Remove file type
	name.erase(name.rfind('.'));

	// Find type prefix.
	std::string filePath = path.substr(0, path.rfind('/'));
	std::string typePrefix = filePath.substr(filePath.rfind('/') + 1);

	return prefix != "" ? prefix + "_" + typePrefix + "_" + name : typePrefix + "_" + name;
}