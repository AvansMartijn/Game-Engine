#include "WorkshopGame.h"
WorkshopGame::WorkshopGame(const char* title, int width, int height) : AbstractGame(title, width, height) {}
WorkshopGame::~WorkshopGame() {}

void WorkshopGame::onInit() {
	// TODO: Register Textures
	registerTexture("Doggo", "res/gfx/Assets/Entity/Player/Doggo.jpg");
	registerTexture("Grass", "res/gfx/Assets/Tiles/2.png");
	// Register Fonts
	registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");

	// TODO: Register Audio

	// TODO: EXTRA Collision Listener

	Physics::getInstance().reset();

	// Zorg ervoor dat alle schermen klaar voor gebruik zijn.
	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->preRender(_window);

	// Open het eerst geregistreerde scherm.
	switchScreen(0);

	// Start de game loop
	gameLoop();
}