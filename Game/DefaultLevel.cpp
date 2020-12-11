#include "DefaultLevel.h"

void DefaultLevel::createLevel(GameEngine gameEngine) {
	// Player
	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension", "CanWieldExtension", "AnimationExtension" };			
	Scene::getInstance().setPlayer(createEntity(gameEngine, extensionNames, "Waluigi",
		2, 8, 0.7f, 1.8f));
	Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->setAnimationHandler({});

	PlayerAnimationHandler animationHandler;
	Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->setAnimationHandler(make_shared<PlayerAnimationHandler>(animationHandler));
	Scene::getInstance().getPlayer()->getExtension<AnimationExtension>()->registerAnimations();

	// Weapon Block
	shared_ptr<GlueManagableItem> glueItemBlueprint = Scene::getInstance().getItem<GlueManagableItem>("GlueGun");
	std::shared_ptr<GlueManagableItem> glueItem = std::make_shared<GlueManagableItem>(*glueItemBlueprint);
	glueItem->setAmmo(5);
	glueItem->setCooldown(500);
	shared_ptr<GameObject> weaponGlue = createNonRigidBody(gameEngine, { "PickupExtension" }, "",
		8, 17.5f, glueItem->getWidth(), glueItem->getHeight(), "pickupSensor");

	std::shared_ptr<GlueManagableItem> glueItem2 = std::make_shared<GlueManagableItem>(*glueItemBlueprint);
	glueItem2->setAmmo(10);
	glueItem2->setCooldown(500);
	shared_ptr<GameObject> weaponGlue2 = createNonRigidBody(gameEngine, { "PickupExtension" }, "",
		12, 17.5f, glueItem2->getWidth(), glueItem2->getHeight(), "pickupSensor");

	//shared_ptr<AbstractManageableItem> glueItem = 


	shared_ptr<AbstractManageableItem> thrusterItem = Scene::getInstance().getItem("ThrusterGun");
	thrusterItem->setAmmo(-1);
	thrusterItem->setCooldown(1500);
	shared_ptr<GameObject> weaponThruster = createNonRigidBody(gameEngine, { "PickupExtension" }, "",
		8, 17.5f, thrusterItem->getWidth(), thrusterItem->getHeight(), "pickupSensor");

	shared_ptr<AbstractManageableItem> portalItem = Scene::getInstance().getItem("PortalGun");
	portalItem->setAmmo(-1);
	portalItem->setCooldown(0);
	shared_ptr<GameObject> weaponPortal = createNonRigidBody(gameEngine, { "PickupExtension" }, "",
		8, 17.5f, portalItem->getWidth(), portalItem->getHeight(), "pickupSensor");

	// Normal Blocks
	shared_ptr<GameObject> floor = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		15, 20, 30.6f, 5, 5, true, true);

	shared_ptr<GameObject> roof = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		15, 0, 30.6f, 1.0f, 5, true, true);

	shared_ptr<GameObject> plat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		6, 7, 1, 1, 0.3f, true, true);

	shared_ptr<GameObject> jumpplat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		10, 7, 1, 1, 0.3f, true, true);

	shared_ptr<GameObject> wall = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		15, 12, 1.0f, 12.0f, 5, true, true);

	shared_ptr<GameObject> boundLeft = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		0, 11, 1.0f, 23.0f, 5, true, true);

	shared_ptr<GameObject> boundRight = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		27, 11, 1.0f, 23.0f, 5, true, true);

	shared_ptr<GameObject> wall2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		20, 5, 1.0f, 12.0f, 5, true, true);


	shared_ptr<GameObject> stage = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		23, 17, 3.0f, 2.0f, 5, true, true);

	shared_ptr<GameObject> crate = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		6, 3, 1, 1, 0.3f, false, false);

	shared_ptr<GameObject> crate2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		6, 4, 1, 1, 0.3f, false, false);

	shared_ptr<GameObject> crate3 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		6, 2, 1, 1, 0.3f, false, false);

	shared_ptr<GameObject> portal1 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal1",
		-50, -50, 3, 0.7f, "portalSensor");
	Scene::getInstance().portalA = portal1;

	shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal2",
		-50, -50, 3, 0.7f, "portalSensor");
	Scene::getInstance().portalB = portal2;

	shared_ptr<GameObject> exit = createNonRigidBody(gameEngine, {}, "Gate_Cropped",
		23, 14.8f, 2.5f, 2.5f, "exitSensor");

	portal1->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>()->link(Scene::getInstance().portalB);
	portal2->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>()->link(Scene::getInstance().portalA);

	//// Item Binding
	weaponGlue->getExtension<PickupExtension>()->setItem(glueItem);
	weaponGlue2->getExtension<PickupExtension>()->setItem(glueItem2);
	weaponThruster->getExtension<PickupExtension>()->setItem(thrusterItem);
	weaponPortal->getExtension<PickupExtension>()->setItem(portalItem);

}
