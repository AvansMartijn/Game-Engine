#include "GameScreen.h"
#include <CanWieldExtension.h>

enum PlayerMoves {
	LOOK_RIGHT,
	RUN_RIGHT,
	JUMP_RIGHT,
	FALL_RIGHT,
	LOOK_LEFT,
	RUN_LEFT,
	JUMP_LEFT,
	FALL_LEFT
};
#include <TextUiElement.h>
#include "TiledLevelLoader.h"

GameScreen::GameScreen() {}

void GameScreen::onInit() {
	begin = std::chrono::steady_clock::now();
	backgroundTrackKey = "Background_1";
	setupScreen();
	setupGame();
	setupHUD();
}

void GameScreen::setupScreen() {
	ImageUiElement backgroundImg = ImageUiElement("BackgroundGame", { 0 , 0, 2160, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));
}

void GameScreen::setupHUD() {
	const Color bgColor = { 0, 0, 0, 0.8 };
	const Color fgColor = { 210, 190, 70 };
	const string font = "Portal";
	const int fontSize = 24;
	TextUiElement lives = TextUiElement("LIVES: 3", font, fontSize, { 5, 10, 0, 0 }, fgColor, bgColor, false);
	_uiElements.push_back(make_shared<TextUiElement>(lives));

	TextUiElement weapon = TextUiElement("CURRENT WEAPON: NULL", font, fontSize, { 5, 40, 0, 0 }, fgColor, bgColor, false);
	_uiElements.push_back(make_shared<TextUiElement>(weapon));

}

void GameScreen::setupGame() {
	// Items
	shared_ptr<GlueManagableItem> glueItem = std::make_shared<GlueManagableItem>();
	Scene::getInstance().addItem(glueItem);

	// Items
	shared_ptr<ThrusterManagableItem> thrusterItem = std::make_shared<ThrusterManagableItem>();
	Scene::getInstance().addItem(thrusterItem);

	// Items
	shared_ptr<PortalManagableItem> portalItem = std::make_shared<PortalManagableItem>();
	Scene::getInstance().addItem(portalItem);

	// Player
	std::map<int, std::string> textures;
	textures.insert(pair<int, std::string>(PlayerMoves::LOOK_RIGHT, "Player_Look_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::RUN_RIGHT, "Player_Running_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::JUMP_RIGHT, "Player_Jump_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::FALL_RIGHT, "Player_Fall_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::LOOK_LEFT, "Player_Look_Left"));
	textures.insert(pair<int, std::string>(PlayerMoves::RUN_LEFT, "Player_Running_Left"));
	textures.insert(pair<int, std::string>(PlayerMoves::JUMP_LEFT, "Player_Jump_Left"));
	textures.insert(pair<int, std::string>(PlayerMoves::FALL_LEFT, "Player_Fall_Left"));

	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension", "CanWieldExtension" };
	Scene::getInstance().setPlayer(createEntity(_gameEngine, extensionNames, textures,
		2, 8, 0.8f, 2.0f));

	// Weapon Block
	textures.clear();
	shared_ptr<GameObject> weaponGlue = createNonRigidBody(_gameEngine, { "PickupExtension" }, textures,
		8, 17.5f, glueItem->getWidth(), glueItem->getHeight(), "pickupSensor");

	// Weapon Block
	textures.clear();
	shared_ptr<GameObject> weaponThruster = createNonRigidBody(_gameEngine, { "PickupExtension" }, textures,
		8, 17.5f, thrusterItem->getWidth(), thrusterItem->getHeight(), "pickupSensor");

	// Weapon Block
	textures.clear();
	shared_ptr<GameObject> weaponPortal = createNonRigidBody(_gameEngine, { "PickupExtension" }, textures,
		8, 17.5f, portalItem->getWidth(), portalItem->getHeight(), "pickupSensor");

	// Normal Blocks
	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> floor = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 20, 30.6f, 5, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> roof = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 0, 30.6f, 1.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> plat = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 7, 1, 1, 0.3f, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> jumpplat = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		10, 7, 1, 1, 0.3f, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> wall = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 12, 1.0f, 12.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> boundLeft = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		0, 11, 1.0f, 23.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> boundRight = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		27, 11, 1.0f, 23.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> wall2 = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		20, 5, 1.0f, 12.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> stage = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		23, 17, 3.0f, 2.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 3, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate2 = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 4, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate3 = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 2, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Portal1"));
	shared_ptr<GameObject> portal1 = createNonRigidBody(_gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalA = portal1;

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Portal2"));
	shared_ptr<GameObject> portal2 = createNonRigidBody(_gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		-50, -50, 3, 0.7, "portalSensor");
	Scene::getInstance().portalB = portal2;


	textures.clear();
	textures.insert(pair<int, std::string>(0, "Gate_Cropped"));
	shared_ptr<GameObject> exit = createNonRigidBody(_gameEngine, {}, textures,
		23, 14.8f, 2.5f, 2.5f, "exitSensor");

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);

	// Item Binding
	dynamic_pointer_cast<PickupExtension>(weaponGlue->getExtension(typeid(PickupExtension)))->setItem(glueItem);
	dynamic_pointer_cast<PickupExtension>(weaponThruster->getExtension(typeid(PickupExtension)))->setItem(thrusterItem);
	dynamic_pointer_cast<PickupExtension>(weaponPortal->getExtension(typeid(PickupExtension)))->setItem(portalItem);

	// TODO: Remove this is just for testing the system.
	//Scene::getInstance().getWieldExtension()->addItem(dummyItem);
	if (_levelLoader)
		_levelLoader->createLevel(_gameEngine, _name);
}

void GameScreen::onScreenShowed(vector<std::string> args) {
	for (size_t i = 0; i < args.size(); i++) {
		std::string arg = args[i];

		if (arg == "tiled")
			_levelLoader = make_shared<TiledLevelLoader>(TiledLevelLoader());
		else if (arg == "default")
			_levelLoader = make_shared<DefaultLevelLoader>(DefaultLevelLoader());
		else
			_name = arg;
	}

	reset();
}

void GameScreen::onTick() {
	auto timePassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();

	if (timePassed >= 1)
	{
		begin = std::chrono::steady_clock::now();
		if (Scene::getInstance().score >= 1)
			Scene::getInstance().score--;
	}

	if (Scene::getInstance().gameOver) {
		_game->switchScreen(Screens::GameFinished);
		Scene::getInstance().gameOver = false;
	}

	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	if (Scene::getInstance().player) {
		handlePlayerControls();
		calculatePlayerTexture();
	}
}

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity();

	b2Vec2 vel = Scene::getInstance().player->body.b2body->GetLinearVelocity();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) {
		vel.x = -5;
		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = false;
	}

	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) {
		vel.x = 5;

		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = true;
	}

	if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
		vel.x = 0;

	if (keystate[SDL_SCANCODE_F])
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50.0f : -50.0f;
	if (keystate[SDL_SCANCODE_F]) {
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50 : -50;
		SoundPlayer::getInstance().playSFX("Thruster_Sound");
	}

	if (keystate[SDL_SCANCODE_SPACE] || keystate[SDL_SCANCODE_W]) {
		if (Scene::getInstance().getPlayerMoveExtension()->canJump()) {
			vel.y = -5;
			Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::JUMPING;
			SoundPlayer::getInstance().playSFX("Player_Jump");
		}
	}
	Scene::getInstance().getPlayer()->body.b2body->SetLinearVelocity(vel);
}

void GameScreen::calculatePlayerTexture() {
	shared_ptr<MoveExtension> moveExtension = Scene::getInstance().getPlayerMoveExtension();

	if (moveExtension->isLookingToRight) {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_RIGHT;
		}
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_LEFT;
		}
	}
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	case SDLK_1:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(0);

		break;
	case SDLK_2:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(1);

		break;
	case SDLK_3:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(2);

		break;
	case SDLK_4:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(3);

		break;
	case SDLK_5:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(4);

		break;
	case SDLK_6:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(5);

		break;
	case SDLK_7:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(6);

		break;
	case SDLK_8:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(7);

		break;
	case SDLK_9:
		Scene::getInstance().getWieldExtension()->setCurrentItemIndex(8);

		break;
	case SDLK_p:
		_game->reset();
	case SDLK_KP_PLUS:
		if(Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
		break;
	case SDLK_KP_MINUS:
	if (Scene::getInstance().zoom > 10)
		Scene::getInstance().zoom -= 3.0f;
	default:
		break;
	}
}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		shared_ptr<CanWieldExtension> wieldExtension = Scene::getInstance().getWieldExtension();

		switch (e.button) {
		case SDL_BUTTON_LEFT:
			wieldExtension->onLeftClick(e.x, e.y);

			break;
		case SDL_BUTTON_RIGHT:
			wieldExtension->onRightClick(e.x, e.y);

			break;
		}
	}
}

void GameScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	if (e.y > 0) // scroll up
	{
		// Put code for handling "scroll up" here!
		if (Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
	}
	else if (e.y < 0) // scroll down
	{
		// Put code for handling "scroll down" here!
		if (Scene::getInstance().zoom > 10)
			Scene::getInstance().zoom -= 3.0f;
	}

}

shared_ptr<GameObject> GameScreen::createEntity(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, textures, x, y, width, height, -1, false, false);
}

shared_ptr<GameObject> GameScreen::createGameObject(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures , float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject, x, y, width, height, friction, fixed, fixedRotation);

	Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}

shared_ptr<GameObject> GameScreen::createNonRigidBody(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, std::string userDataType = NULL) {
	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, userDataType);

	Scene::getInstance().addGameObject(gameObject);
	return gameObject;
}

void GameScreen::render(const unique_ptr<Window>& window) {
	AbstractScreen::render(window);

	Scene::getInstance().render(window);
	if(Scene::getInstance().getWieldExtension()->getCurrentItem() != nullptr)
		Scene::getInstance().getWieldExtension()->getCurrentItem()->render(window);
}

void GameScreen::reset() {
	AbstractScreen::reset();
	Scene::getInstance().reset();

	Physics::getInstance().reset();
	setupGame();
}