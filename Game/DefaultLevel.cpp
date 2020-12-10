#include "DefaultLevel.h"

void DefaultLevel::createLevel(GameEngine gameEngine) {

	//// Player
	//std::map<int, std::string> textures;
	//textures.insert(pair<int, std::string>(PlayerMoves::LOOK_RIGHT, "Player_Look_Right"));
	//textures.insert(pair<int, std::string>(PlayerMoves::RUN_RIGHT, "Player_Running_Right"));
	//textures.insert(pair<int, std::string>(PlayerMoves::JUMP_RIGHT, "Player_Jump_Right"));
	//textures.insert(pair<int, std::string>(PlayerMoves::FALL_RIGHT, "Player_Fall_Right"));
	//textures.insert(pair<int, std::string>(PlayerMoves::LOOK_LEFT, "Player_Look_Left"));
	//textures.insert(pair<int, std::string>(PlayerMoves::RUN_LEFT, "Player_Running_Left"));
	//textures.insert(pair<int, std::string>(PlayerMoves::JUMP_LEFT, "Player_Jump_Left"));
	//textures.insert(pair<int, std::string>(PlayerMoves::FALL_LEFT, "Player_Fall_Left"));

	//vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension" };
	//Scene::getInstance().setPlayer(createEntity(gameEngine, extensionNames, textures,
	//	2, 8, 0.8f, 2.0f));

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> floor = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	15, 20, 30.6f, 5, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> roof = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	15, 0, 30.6f, 1.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> plat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	6, 7, 1, 1, 0.3f, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> jumpplat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	10, 7, 1, 1, 0.3f, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> wall = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	15, 12, 1.0f, 12.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> boundLeft = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	0, 11, 1.0f, 23.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> boundRight = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	27, 11, 1.0f, 23.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> wall2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	20, 5, 1.0f, 12.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	//shared_ptr<GameObject> stage = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	23, 17, 3.0f, 2.0f, 5, true, true);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	//shared_ptr<GameObject> crate = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	6, 3, 1, 1, 0.3f, false, false);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	//shared_ptr<GameObject> crate2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	6, 4, 1, 1, 0.3f, false, false);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	//shared_ptr<GameObject> crate3 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
	//	6, 2, 1, 1, 0.3f, false, false);

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	//shared_ptr<GameObject> portal1 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
	//	12, 17.5f, 3, 1, "portalSensor");

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	//shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
	//	15, 1.5f, 3, 1, "portalSensor");

	//textures.clear();
	//textures.insert(pair<int, std::string>(0, "Gate_Cropped"));
	//shared_ptr<GameObject> exit = createNonRigidBody(gameEngine, {}, textures,
	//	23, 14.8f, 2.5f, 2.5f, "exitSensor");

	//dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	//dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);


	// Player
	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension", "CanWieldExtension" };			
	Scene::getInstance().setPlayer(createEntity(gameEngine, extensionNames, "Waluigi",
		2, 8, 0.7f, 1.8f));
	Scene::getInstance().getPlayer()->currentState = MoveExtension::LOOK_RIGHT;

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
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalA = portal1;

	shared_ptr<GameObject> portal2 = createNonRigidBody(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Portal2",
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalB = portal2;

	shared_ptr<GameObject> exit = createNonRigidBody(gameEngine, {}, "Gate_Cropped",
		23, 14.8f, 2.5f, 2.5f, "exitSensor");

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);

	// Item Binding
	dynamic_pointer_cast<PickupExtension>(weaponGlue->getExtension(typeid(PickupExtension)))->setItem(glueItem);
	dynamic_pointer_cast<PickupExtension>(weaponGlue2->getExtension(typeid(PickupExtension)))->setItem(glueItem2);
	dynamic_pointer_cast<PickupExtension>(weaponThruster->getExtension(typeid(PickupExtension)))->setItem(thrusterItem);
	dynamic_pointer_cast<PickupExtension>(weaponPortal->getExtension(typeid(PickupExtension)))->setItem(portalItem);

}
