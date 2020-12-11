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

		if (go.layer == "tilelayer")
			createTile(gameEngine, go, extensions, x, y, width, height);
		else if (go.layer == "objectgroup")
			createObject(gameEngine, go, extensions, x, y, width, height);
	}

	// Create Portals
	shared_ptr<GameObject> portal1 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal1",
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalA = portal1;

	shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal2",
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalB = portal2;

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);

}

void DefaultTiledLevel::createTile(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, float x, float y, float width, float height) {
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
	}
	else {
		shared_ptr<GameObject> gameObject = createGameObject(gameEngine, extensions, textureKey,
			x, y, width, height, friction, isFixed, false);


		if (tiledGameObject.properties.find("damage") != tiledGameObject.properties.end())
			dynamic_pointer_cast<DoesDamageExtension>(gameObject->getExtension(typeid(DoesDamageExtension)))->damage = tiledGameObject.properties["damage"].valueInt;
	}
}

void DefaultTiledLevel::createObject(GameEngine gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, float x, float y, float width, float height) {
	if (tiledGameObject.type == "Player") {
		Scene::getInstance().setPlayer(createPlayer(gameEngine, extensions, "Waluigi", x, y, 0.7f, 1.8f));

		PlayerAnimationHandler animationHandler;
		Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->setAnimationHandler(make_shared<PlayerAnimationHandler>(animationHandler));
		Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->registerAnimations();
	}
	else if (tiledGameObject.type == "Enemy") {
		shared_ptr<GameObject> enemy = createEnemy(gameEngine, extensions, "Goomba", x, y, 0.7f, 1.0f);
		if (tiledGameObject.properties.find("health") != tiledGameObject.properties.end() && enemy->hasExtension(typeid(HealthExtension)))
			enemy->getExtension<HealthExtension>()->setHealth(tiledGameObject.properties["health"].valueInt);

		if (enemy->hasExtension(typeid(AiExtension))) {
			// We only use the default entity ai, so no need to check for anything else.
			shared_ptr<DefaultEntityAI> entityAi = make_shared<DefaultEntityAI>(DefaultEntityAI{});
			entityAi->createBehaviourTree(enemy);

			enemy->getExtension<AiExtension>()->ai = entityAi;
		}

		EnemyAnimationHandler animationHandler;
		enemy->getExtension<AnimationExtension>()->setAnimationHandler(make_shared<EnemyAnimationHandler>(animationHandler));
		enemy->getExtension<AnimationExtension>()->registerAnimations();
	}
	else if (tiledGameObject.layerType == "Tools") {
		std::string sensor = tiledGameObject.properties["sensor"].valueString;
		//TODO:: v DAt MOET NETTER

		//TODO:: DIT MOET NETTER
		if (tiledGameObject.type == "GlueGun") {
			shared_ptr<GlueManagableItem> itemBluePrint = Scene::getInstance().getItem<GlueManagableItem>(tiledGameObject.type);
			std::shared_ptr<GlueManagableItem> item = std::make_shared<GlueManagableItem>(*itemBluePrint);
			if (tiledGameObject.properties.find("ammo") != tiledGameObject.properties.end())
				item->setAmmo(tiledGameObject.properties["ammo"].valueInt);

			if (tiledGameObject.properties.find("cooldown") != tiledGameObject.properties.end())
				item->setCooldown(tiledGameObject.properties["cooldown"].valueInt);

			shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, "", x, y, item->getWidth(), item->getHeight(), sensor);
			dynamic_pointer_cast<PickupExtension>(gameObject->getExtension(typeid(PickupExtension)))->setItem(item);

		}
		//TODO:: DIT MOET NETTER
		else if (tiledGameObject.type == "ThrusterGun") {
			shared_ptr<ThrusterManagableItem> itemBluePrint = Scene::getInstance().getItem<ThrusterManagableItem>(tiledGameObject.type);

			std::shared_ptr<ThrusterManagableItem> item = std::make_shared<ThrusterManagableItem>(*itemBluePrint);
			if (tiledGameObject.properties.find("ammo") != tiledGameObject.properties.end())
				item->setAmmo(tiledGameObject.properties["ammo"].valueInt);

			if (tiledGameObject.properties.find("cooldown") != tiledGameObject.properties.end())
				item->setCooldown(tiledGameObject.properties["cooldown"].valueInt);

			shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, "", x, y, item->getWidth(), item->getHeight(), sensor);
			dynamic_pointer_cast<PickupExtension>(gameObject->getExtension(typeid(PickupExtension)))->setItem(item);

		}
		//TODO:: DIT MOET NETTER
		else {
			shared_ptr<PortalManagableItem> itemBluePrint = Scene::getInstance().getItem<PortalManagableItem>(tiledGameObject.type);

			std::shared_ptr<PortalManagableItem> item = std::make_shared<PortalManagableItem>(*itemBluePrint);
			if (tiledGameObject.properties.find("ammo") != tiledGameObject.properties.end())
				item->setAmmo(tiledGameObject.properties["ammo"].valueInt);

			if (tiledGameObject.properties.find("cooldown") != tiledGameObject.properties.end())
				item->setCooldown(tiledGameObject.properties["cooldown"].valueInt);

			shared_ptr<GameObject> gameObject = createNonRigidBody(gameEngine, extensions, "", x, y, item->getWidth(), item->getHeight(), sensor);
			dynamic_pointer_cast<PickupExtension>(gameObject->getExtension(typeid(PickupExtension)))->setItem(item);

		}
		//TODO:: ^DAt MOET NETTER

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