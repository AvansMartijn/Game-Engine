#include "Game.h"
#include "CollisionListener.h"

Game::Game(const char* title, int width, int height) : AbstractGame(title, width, height) {}

Game::~Game() {}

void Game::onInit() {
	// Textures
	registerTexture("Waluigi", "res/gfx/Assets/Entity/Player/Waluigi.png");
	registerTexture("Goomba", "res/gfx/Assets/Entity/Goomba/Goomba.png", true);
	registerTexture("Crate_Metal", "res/gfx/Assets/Enviroment/Crate_Metal.png");
	registerTexture("Mystical_Crystal_Flipped", "res/gfx/Assets/Enviroment/Mystical_Crystal_Flipped.png");
	registerTexture("Portal1", "res/gfx/Assets/Enviroment/Portal1.png");
	registerTexture("Portal2", "res/gfx/Assets/Enviroment/Portal2.png");
	registerTexture("Gate_Cropped", "res/gfx/Assets/Enviroment/Gate_Cropped.png");
	registerTexture("Tile_Interior_Ground_Center", "res/gfx/Assets/Tiles/Interior/Ground_Center.png");
	registerTexture("Border", "res/gfx/Border.png");
	registerTexture("Krool", "res/gfx/KINGKROOL.png");
	registerTexture("Blob", "res/gfx/Assets/Items/Blob.png");
	registerTexture("Loading", "res/gfx/LoadingImage.png");
	registerTexture("Lose", "res/gfx/Sad.png");
	registerTexture("Win", "res/gfx/Win.png");
	registerTexture("Hat", "res/gfx/Pauze.png");
	registerTexture("Boyz", "res/gfx/theBoyz.png");

	registerTexture("Spikes", "res/levels/Assets/Killable/Spikes.png");
	registerTexture("Portable", "res/levels/Assets/Portable/Center.png");
	registerTexture("Finish", "res/levels/Assets/Finish/Center-Empty-Inside.png");

	//guns
	registerTexture("GlueGun", "res/gfx/Assets/Items/GlueGun.png");
	registerTexture("PortalGun", "res/gfx/Assets/Items/PortalGun.png");
	registerTexture("ThrusterGun", "res/gfx/Assets/Items/ThrusterGun.png");


	registerTexture("PortalOrange", "res/gfx/Portal1.png");
	registerTexture("PortalPurple", "res/gfx/Portal2.png");

	registerTexture("Keybindings", "res/gfx/tutorial.png");

	registerTexture("DIY_Weapon", "res/gfx/Assets/Items/DIY_Weapon.png");
	registerTexture("GlueGun", "res/gfx/Assets/Items/GlueGun.png");
	registerTexture("PortalGun", "res/gfx/Assets/Items/PortalGun.png");
	registerTexture("ThrusterGun", "res/gfx/Assets/Items/ThrusterGun.png");

	LibCurl libcurl;
	std::string location = libcurl.PerformRequest("https://latropads.mardy.tk/ad.jpg");

	registerTexture("AdPlaceholder", location);
	registerTexture("Background", "res/gfx/Background.png");
	registerTexture("BackgroundTint", "res/gfx/BackgroundTint.png");
	registerTexture("BackgroundGame", "res/gfx/GameBackground.png");
	registerTexture("BackgroundHud", "res/gfx/BackgroundHud.png");
	registerTexture("Logo", "res/gfx/LatropLogo.png");
	registerTexture("Line", "res/gfx/Line.png");
	registerTexture("LogoWesley", "res/gfx/LatropLogoWesley.png");

	//Font
	registerFont("OpenSans", "res/fonts/OpenSans-Regular.ttf");
	registerFont("Paint", "res/fonts/Paint Drops.ttf");
	registerFont("Portal", "res/fonts/PortalFont.ttf");
	registerTextures("Tiled", "res/levels/assets/", true);

	//Music
	registerMusicTrack("Background_Menu", "res/music/Main_Menu.mp3");
	registerMusicTrack("Background_1", "res/music/Game_Background_1.mp3");
	registerMusicTrack("Background_2", "res/music/Game_Background_2.mp3");
	registerMusicTrack("Background_3", "res/music/Game_Background_3.mp3");
	registerMusicTrack("Background_4", "res/music/Game_Background_4.mp3");
	registerMusicTrack("Background_5", "res/music/Game_Background_5.mp3");
	registerMusicTrack("Game_Over", "res/music/Game_Over.mp3");

	//SFX
	registerSFXTrack("Player_Jump", "res/music/Jump_Sound.wav");
	registerSFXTrack("Thruster_Sound", "res/music/Thruster_Sound.wav");
	registerSFXTrack("Glue_Sound", "res/music/Glue_Sound.ogg");

	//create collision listener
	shared_ptr<CollisionListener> colListener = make_shared<CollisionListener>(CollisionListener());
	Physics::getInstance().setContactListener(colListener);


	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->preRender(_window);

	switchScreen(Screens::MainMenu);

	gameLoop();
}