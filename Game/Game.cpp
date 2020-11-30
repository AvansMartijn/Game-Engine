#include "Game.h"

Game::Game(const char* title, int width, int height) : AbstractGame(title, width, height) {}

Game::~Game() {}

void Game::onInit() {
	registerTexture("Player_Look_Right", "res/gfx/Assets/Entity/Player/Looking_Right.png");
	registerTexture("Player_Look_Left", "res/gfx/Assets/Entity/Player/Looking_Left.png");

	registerTexture("Player_Jump_Right", "res/gfx/Assets/Entity/Player/Jumping_Right.png");
	registerTexture("Player_Jump_Left", "res/gfx/Assets/Entity/Player/Jumping_Left.png");

	registerTexture("Player_Fall_Right", "res/gfx/Assets/Entity/Player/Falling_Right.png");
	registerTexture("Player_Fall_Left", "res/gfx/Assets/Entity/Player/Falling_Left.png");

	registerTexture("Player_Running_Right", "res/gfx/Assets/Entity/Player/Running_Right.png");
	registerTexture("Player_Running_Left", "res/gfx/Assets/Entity/Player/Running_Left.png");

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

	registerTexture("DIY_Weapon", "res/gfx/Assets/Items/DIY_Weapon.png");

  
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