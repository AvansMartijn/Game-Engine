#include "WorkshopGameScreen.h"

WorkshopGameScreen::WorkshopGameScreen() {}
WorkshopGameScreen::~WorkshopGameScreen() {}

void WorkshopGameScreen::onInit() {
	GameEngine gameEngine;
	// TODO: Add Input
	// TODO: Add Physics
	// TODO: Add Sound
	// TODO: Player Controls

	// TIJD OVER
	// TODO: Add Custom Extension
	// TODO: AI


	
	/** TODO: Add Game Objects. */
	// TODO: Create Player

	// TODO: Create Floor
	vector<string> extensions = { "MoveExtension" };
	shared_ptr<GameObject> gameObject = createGameObject(gameEngine, extensions, "Grass", 0, 0, 100, 100, 1);
}

void WorkshopGameScreen::onTick() {
	// Geef aan dat we de volgende step willen doen voor de physics.
// Eerste param is voor hoe lang we willen simulaten. Tweede Param is hoeveel velocity iterations. Derde Param is hoeveel position iterations.
	Physics::getInstance().step(1.0f / 60.f, 6, 2);
}

void WorkshopGameScreen::render(const unique_ptr<Window>& window) {
	// Render de huidige scene.
	Scene::getInstance().render(window);
}

void WorkshopGameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
}

void WorkshopGameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void WorkshopGameScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

}

// Deze code maak een game object aan.
shared_ptr<GameObject> WorkshopGameScreen::createGameObject(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, int type) {
	// Via een facade wordt een game object aangemaakt welke gebruik maakt van de aangegeven extensions.
	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	
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