#include "WorkshopGameScreen.h"

WorkshopGameScreen::WorkshopGameScreen() {}
WorkshopGameScreen::~WorkshopGameScreen() {}

void WorkshopGameScreen::onInit() {
	// TODO: Add background.

	// TODO: Add Custom Extension

	// Lock Zoom
	Scene::getInstance().isLocked = true;
}

void WorkshopGameScreen::setupGame() {
	// We resetten het spel voordat we beginnen
	Scene::getInstance().reset();
	Physics::getInstance().reset();

	/** TODO: Add Game Objects. */
	// TODO: Create Player

	// TODO: Create Floor

	// TODO: Create Objects

	// TODO: End Point
}

void WorkshopGameScreen::onTick() {
	// Geef aan dat we de volgende step willen doen voor de physics.
	Physics::getInstance().step(1.0f / 60.f, 6, 2);

	// TODO: Controls
	if (Scene::getInstance().getPlayer() && Scene::getInstance().getPlayer()->hasExtension(typeid(PlayerMoveExtension)))
		handlePlayerControls();

	// TODO: Extra Game Over
}

void WorkshopGameScreen::handlePlayerControls() {
	// TODO: Player Input 
}

void WorkshopGameScreen::render(const unique_ptr<Window>& window) {
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
shared_ptr<GameObject> WorkshopGameScreen::createGameObject(vector<string> extensions, std::string texture, float x, float y, float width, float height, int type, std::string sensor) {
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
	case 2: // Game Object (Interactable)
		Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, sensor);
		break;
	case 3: // Player
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
		break;
	default:
		break;
	}

	// Voeg game object toe aan de wereld.
	Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}