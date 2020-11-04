#include "GameScreen.h"
#include <GameEngine.h>
#include <TextUiElement.h>

enum PlayerMoves {
	LOOK_RIGHT,
	RUN_RIGHT,
	JUMP_RIGHT,
	FALL_RIGHT
};

GameScreen::GameScreen() {
	score = 1000;
}

void GameScreen::onInit() {
	GameEngine gameEngine;

	begin = std::chrono::steady_clock::now();

	Physics::getInstance().reset();
	_gameObjects.clear();
	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement line = TextUiElement("Team Mike", "Paint", 34, { 100, 100, 0, 0 }, { 255, 0, 0 }, { 255, 255, 255 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(line));

	//// Player
	std::map<int, std::string> textures;
	textures.insert(pair<int, std::string>(PlayerMoves::LOOK_RIGHT, "Player_Look_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::RUN_RIGHT, "Player_Running_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::JUMP_RIGHT, "Player_Jump_Right"));
	textures.insert(pair<int, std::string>(PlayerMoves::FALL_RIGHT, "Player_Fall_Right"));

	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension" };
	_player = createEntity(gameEngine, extensionNames, textures,
		2, 8, 0.8f, 2.0f);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> floor = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 20, 30.6f, 5, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> roof = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 0, 30.6f, 1.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> plat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 7, 1, 1, 0.3f, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> jumpplat = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		10, 7, 1, 1, 0.3f, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> wall = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		15, 12, 1.0f, 12.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> boundLeft = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		0, 10, 1.0f, 20.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> boundRight = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		27, 10, 1.0f, 20.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> wall2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		20, 5, 1.0f, 12.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Tile_Interior_Ground_Center"));
	shared_ptr<GameObject> stage = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		23, 17, 3.0f, 2.0f, 5, true, true);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 3, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 4, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Crate_Metal"));
	shared_ptr<GameObject> crate3 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, textures,
		6, 2, 1, 1, 0.3f, false, false);

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	shared_ptr<GameObject> portal1 = createPortal(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		12, 17.5, 3, 1, "portalSensor");

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));
	shared_ptr<GameObject> portal2 = createPortal(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, textures,
		15, 1.5, 3, 1, "portalSensor");

	textures.clear();
	textures.insert(pair<int, std::string>(0, "Gate_Cropped"));
	shared_ptr<GameObject> exit = createPortal(gameEngine, {}, textures,
		23, 14.8, 2.5, 2.5, "exitSensor");

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);

}

void GameScreen::onTick() {

	auto timePassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();

	if (timePassed >= 1)
	{
		begin = std::chrono::steady_clock::now();
		if (score >= 1)
		{
			score--;
		}
	}

	//TODO: Dont have gamestate in physics, put in repository
	if (Physics::getInstance().gameOver) {
		_game->switchScreen(Screens::GameOver, { to_string(score) });
		Physics::getInstance().gameOver = false;
	}

	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	handlePlayerControls();
}

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = _player->body.b2body->GetLinearVelocity();
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
		if (Physics::getInstance().playerCanJump())
			vel.y = -5;

	_player->body.b2body->SetLinearVelocity(vel);
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause, { to_string(score) });

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

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject, x, y, width, height, friction, fixed, fixedRotation);

	_gameObjects.push_back(gameObject);

	return gameObject;
}

shared_ptr<GameObject> GameScreen::createPortal(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, std::string userDataType = NULL) {
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
	gameObject->textures = textures;

	Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, userDataType);

	_gameObjects.push_back(gameObject);
	return gameObject;
}

void GameScreen::render(const unique_ptr<Window>& window) {
	AbstractScreen::render(window);
	for (shared_ptr<GameObject>& obj : _gameObjects)
		obj->render(window);
}

void GameScreen::reset() {
	AbstractScreen::reset();
	score = 1000;

	onInit();
}