#include "Game.h"

Game::Game(const char* title, int width, int height) : AbstractGame(title, width, height) {}

Game::~Game() {}

void Game::onInit() {
	// Sprites
	std::map<std::string, Rect> sprites;
	sprites.insert(std::make_pair(PlayerMoves::LOOK_RIGHT, Rect{ 662, 78, 318, 456 }));
	sprites.insert(std::make_pair(PlayerMoves::LOOK_LEFT, Rect{ 253, 78, 318, 456 }));

	sprites.insert(std::make_pair(PlayerMoves::JUMP_RIGHT, Rect{ 2555, 676, 293, 496 }));
	sprites.insert(std::make_pair(PlayerMoves::JUMP_LEFT, Rect{ 2058, 654, 385, 519}));

	sprites.insert(std::make_pair(PlayerMoves::RUN_RIGHT, Rect{ 542, 735, 448, 448 }));
	sprites.insert(std::make_pair(PlayerMoves::RUN_LEFT, Rect{ 44, 735, 448, 448 }));

	registerTexture("Waluigi", "res/gfx/Assets/Entity/Player/Waluigi.png", sprites);

	sprites.clear();
	sprites.insert(std::make_pair<std::string, Rect>("Player_Look_Right", { 23, 0, 86, 76 }));
	registerTexture("Goomba_SpriteSheet", "res/gfx/Assets/Entity/Goomba/Goomba.png", sprites);

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

	registerTexture("DIY_Weapon", "res/gfx/Assets/Items/DIY_Weapon.png");

	LibCurl libcurl;
	auto location = libcurl.PerformRequest("https://d2slcw3kip6qmk.cloudfront.net/marketing/press/images/template-gallery/print-banners-lush-sale-advertising-01.jpg");

	registerTexture("AdPlaceholder", location);
	registerTexture("Background", "res/gfx/Background.png");
	registerTexture("BackgroundGame", "res/gfx/GameBackground.png");
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
	registerMusicTrack("Background_3", "res/music/Game_Background_2.mp3");
	registerMusicTrack("Game_Over", "res/music/Game_Over.mp3");

	//SFX
	registerSFXTrack("Player_Jump", "res/music/Jump_Sound.wav");
	registerSFXTrack("Thruster_Sound", "res/music/Thruster_Sound.wav");
	registerSFXTrack("Glue_Sound", "res/music/Glue_Sound.ogg");

	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->preRender(_window);

	switchScreen(Screens::MainMenu);


	gameLoop();
}

int Game::getPreviousScreen() {
	if (_previousScreens.size() > 0)
	{
		int value = _previousScreens.top();
		_previousScreens.pop();
		return value;
	}
	return -1;
}

void Game::switchScreen(int screenIndex, vector<std::string> args) {
	size_t index = screenIndex;
	if (index == -1)
		index = this->getPreviousScreen();
	else if (_activeScreen)
		_previousScreens.push(_activeScreen);

	if (index + 1 <= screens.size()) {
		_activeScreen = index;
		screens.at(_activeScreen)->onScreenShowed(args);
	}

	const std::string& trackKey = screens.at(_activeScreen)->backgroundTrackKey;
	
	if (trackKey != "" && trackKey != SoundPlayer::getInstance().playingTrackKey) {
		playMusicTrack(trackKey);
	}
}