#include "WorkshopGame.h"

WorkshopGame::WorkshopGame(const char* title, int width, int height) : AbstractGame(title, width, height) {}
WorkshopGame::~WorkshopGame() {}

void WorkshopGame::onInit() {
	// TODO: Register Textures
	registerTexture("Background", "res/gfx/Assets/BG/BG.png");

	std::map<std::string, Rect> sprites;
	sprites.insert(make_pair("Idle", Rect{ 43, 157, 80, 51 }));
	registerTexture("Doggo", "res/gfx/Assets/Entity/Player/Doggo.png", sprites);

	registerTexture("Grass", "res/gfx/Assets/Tiles/2.png");
	registerTexture("Crate", "res/gfx/Assets/Object/Crate.png");
	registerTexture("Bush", "res/gfx/Assets/Object/Bush.png");

	// Register Fonts
	registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");


	// TODO: EXTRA Collision Listener
	shared_ptr<ContactListener> colListener = make_shared<ContactListener>(ContactListener());

	Physics::getInstance().setContactListener(colListener);

	// Zorg ervoor dat alle schermen klaar voor gebruik zijn.
	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->preRender(_window);

	// Open het eerst geregistreerde scherm.
	switchScreen(0);

	// Start de game loop
	gameLoop();
}