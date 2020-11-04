#include "GameScreen.h"
#include <TextUiElement.h>

enum PlayerMoves {
	LOOK_RIGHT,
	RUN_RIGHT,
	JUMP_RIGHT,
	FALL_RIGHT
};

GameScreen::GameScreen() {}

void GameScreen::onInit() {
	begin = std::chrono::steady_clock::now();

	setupScreen();
	setupGame();
}

void GameScreen::setupScreen() {
	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));
}

void GameScreen::setupGame() {
	//// Player
	std::map<int, std::string> textures;
	textures.insert(pair<int, std::string>(PlayerMoves::LOOK_RIGHT, "Player_Look_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::RUN_RIGHT, "Player_Running_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::JUMP_RIGHT, "Player_Jump_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::FALL_RIGHT, "Player_Fall_Right"));

	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension" };
	Scene::getInstance().player = createEntity(_gameEngine, extensionNames, textures,
		2, 8, 0.8f, 2.0f);

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
		0, 10, 1.0f, 20.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> boundRight = createGameObject(_gameEngine, { "CheckPhysicsExtension" }, textures,
		27, 10, 1.0f, 20.0f, 5, true, true);

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
	textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	shared_ptr<GameObject> portal1 = createNonRigidBody(_gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		12, 17.5f, 3, 1, "portalSensor");

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	shared_ptr<GameObject> portal2 = createNonRigidBody(_gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		15, 1.5f, 3, 1, "portalSensor");

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Gate_Cropped"));
	shared_ptr<GameObject> exit = createNonRigidBody(_gameEngine, {}, textures,
		23, 14.8f, 2.5f, 2.5f, "exitSensor");

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);
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
		_game->switchScreen(Screens::GameOver);
		Scene::getInstance().gameOver = false;
	}

	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	handlePlayerControls();
}

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = Scene::getInstance().player->body.b2body->GetLinearVelocity();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])
		vel.x = -5;

	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])
		vel.x = 5;

	if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
		vel.x = 0;

	if (keystate[SDL_SCANCODE_F])
		vel.x = -50;

	if (keystate[SDL_SCANCODE_G])
		vel.x = 50;

	if (keystate[SDL_SCANCODE_SPACE] || keystate[SDL_SCANCODE_W])
		if (Scene::getInstance().playerData.canJump())
			vel.y = -5;

	Scene::getInstance().player->body.b2body->SetLinearVelocity(vel);
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	case SDLK_p:
		_game->reset();

		break;
	default:
		break;
	}
}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {}

shared_ptr<GameObject> GameScreen::createEntity(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, textures, x, y, width, height, -1, false, false);
}

shared_ptr<GameObject> GameScreen::createGameObject(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures , float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
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
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, userDataType);

	Scene::getInstance().addGameObject(gameObject);
	return gameObject;
}

void GameScreen::render(const unique_ptr<Window>& window) {
	AbstractScreen::render(window);

	Scene::getInstance().render(window);
}

void GameScreen::reset() {
	AbstractScreen::reset();
	Scene::getInstance().reset();

	Physics::getInstance().reset();
	setupGame();
}