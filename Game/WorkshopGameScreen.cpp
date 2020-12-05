#include "WorkshopGameScreen.h"

WorkshopGameScreen::WorkshopGameScreen() {}
WorkshopGameScreen::~WorkshopGameScreen() {}

void WorkshopGameScreen::onInit() {
	// TODO: Add background.
	_backgroundImage = make_shared<ImageUiElement>(ImageUiElement("Background", { 0, 0, 1080, 720 }));
	_uiElements.push_back(_backgroundImage);

	// TIJD OVER
	// TODO: Add Custom Extension
	// TODO: AI
	Scene::getInstance().isLocked = true;
}

void WorkshopGameScreen::setupGame() {
	// We resetten het spel voordat we beginnen
	Scene::getInstance().reset();

	/** TODO: Add Game Objects. */
	// TODO: Create Player
	shared_ptr<GameObject> player = createGameObject({ "CheckPhysicsExtension", "MoveExtension" }, "Doggo", 1, Scene::getInstance().pixelsToMeters(720) - 10, 2, 1.5, 2);
	player->currentState = "Idle";
	Scene::getInstance().setPlayer(player);

	// TODO: Create Floor
	for (size_t i = 0; i < 15; i++)
		createGameObject({ "MoveExtension" }, "Grass", 1 + (i * 2), Scene::getInstance().pixelsToMeters(720) - 1, 2, 2, 1);

	// TODO: Create Objects
	createGameObject({ "" }, "Crate", 10, Scene::getInstance().pixelsToMeters(720) - 10, 2, 2, 0);

	// TODO: End Point
	createGameObject({ "" }, "Bush", Scene::getInstance().pixelsToMeters(1080) - 2, Scene::getInstance().pixelsToMeters(720) - 3, 2.5, 2, 1);
}

void WorkshopGameScreen::onTick() {
	// Geef aan dat we de volgende step willen doen voor de physics.
	Physics::getInstance().step(1.0f / 60.f, 6, 2);

	// TODO: Controls
	if (Scene::getInstance().getPlayer() && Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension)))
		handlePlayerControls();
}

void WorkshopGameScreen::handlePlayerControls() {
	// Haal de huidige velocity op.
	b2Vec2 vel = Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity();
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	// TODO: Move
	if (keyState[SDL_SCANCODE_D])
		vel.x += 0.3f;

	if (keyState[SDL_SCANCODE_A])
		vel.x -= 0.3f;

	if (keyState[SDL_SCANCODE_SPACE])
			vel.y -= 0.5f;

	Scene::getInstance().getPlayer()->body.b2body->SetLinearVelocity(vel);
}

void WorkshopGameScreen::render(const unique_ptr<Window>& window) {
	// TODO: Render BG
	_backgroundImage->render(window);

	// Render de huidige scene.
	Scene::getInstance().render(window);
}

void WorkshopGameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_l:
		Scene::getInstance().isLocked = !Scene::getInstance().isLocked;

		break;
	default:
		break;
	}
}

void WorkshopGameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void WorkshopGameScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	// Scrollen, dit is om te laten zien straks.
	if (e.y > 0) {
		if (Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
	}
	else if (e.y < 0) {
		if (Scene::getInstance().zoom > 10)
			Scene::getInstance().zoom -= 3.0f;
	}
}

void WorkshopGameScreen::onScreenShowed(vector<std::string> args) {
	setupGame();
}

// Deze code maak een game object aan.
shared_ptr<GameObject> WorkshopGameScreen::createGameObject(vector<string> extensions, std::string texture, float x, float y, float width, float height, int type) {
	// Via een facade wordt een game object aangemaakt welke gebruik maakt van de aangegeven extensions.
	shared_ptr<GameObject> gameObject = _gameEngine.createGameObject(extensions);
	
	// Vervolgens ken je een texture & id toe.
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	// Hier voegen we het object toe aan de physics engine. 
	switch (type)
	{
	case 0: // Game Object (Not Static)
		Physics::getInstance().addBody(gameObject, x, y, width, height, 1.0f, false, false);
		break;
	case 1: // Game Object (Static)
		Physics::getInstance().addBody(gameObject, x, y, width, height, 1.0f, true, false);
		break;
	case 2: // Player
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
		break;
	default:
		break;
	}

	// Voeg game object toe aan de wereld.
	Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}