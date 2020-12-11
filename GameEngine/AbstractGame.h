#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractGame __declspec(dllexport)
#else
#define GAMEENGINE_AbstractGame __declspec(dllimport)
#endif

#include <memory>
#include "SDLWrapper.h"
#include "SDLImageWrapper.h"
#include "SDLTtfWrapper.h"
#include "AbstractScreen.h"
#include <vector>
#include "Window.h"
#include <stack>
#include "SoundPlayer.h"

using namespace std;

/// <summary>
/// The game class needs to be based of this class.
/// </summary>
class GAMEENGINE_AbstractGame AbstractGame
{
public:
	AbstractGame(const char* title, int width, int height);
	~AbstractGame();

	/// <summary>
	/// All the possible screens the game has.
	/// </summary>
	vector<unique_ptr<AbstractScreen>> screens;

	/// <summary>
	/// Prepare the game.
	/// </summary>
	virtual void onInit() = 0;

	/// <summary>
	/// Runs the basic game loop.
	/// </summary>
	/// <param name="game"></param>
	virtual void gameLoop();

	/// <summary>
	/// Switch the current screen to the screen with the given index
	/// </summary>
	/// <param name="screenIndex">The index of the screen we want to display</param>
	/// <param name="args">The arguments we want to pass to the next screen</param>
	virtual void switchScreen(int screenIndex, vector<std::string> args = {});

	/// <summary>
	/// Switch the current screen to the screen with the given index
	/// </summary>
	virtual int getPreviousScreen();

	/// <summary>
	/// Registers a texture in the registry.
	/// </summary>
	/// <param name="textureKey">The texture registry key.</param>
	/// <param name="texturePath">The path to the texture.</param>
	/// <param name="isReversed">If the texture should be reversed.</param>
	void registerTexture(std::string textureKey, std::string texturePath, bool isReversed = false);

	/// <summary>
	/// Registers a font in the registry.
	/// </summary>
	/// <param name="fontKey">The font registry key.</param>
	/// <param name="fontPath">The path to the font.</param>
	void registerFont(std::string fontKey, std::string fontPath);

	/// <summary>
	/// Adds all textures within a directory to the registry.
	/// </summary>
	/// <param name="prefix">The prefix we want to use for these textures.</param>
	/// <param name="directory">The directory which we want to add.</param>
	/// <param name="isDeep">If we should scan the directories within this directory.</param>
	void registerTextures(std::string prefix, std::string directory, bool isDeep);
	/// <summary>
	/// Registers a soundtrack in the registry.
	/// </summary>
	/// <param name="musicTrackKey">Soundtrack key</param>
	/// <param name="trackPath">Soundtrak path</param>
	void registerMusicTrack(const std::string& musicTrackKey, const std::string& trackPath);

	void registerSFXTrack(const std::string& sfxTrackKey, const std::string& trackPath);

	void playMusicTrack(const std::string& musicTrackKey);

	/// <summary>
	/// Resets the game.
	/// </summary>
	void reset();

	int currentFPS;
private:
	/// <summary>
	/// Sets up values to calculate fps
	/// </summary>
	void initFps();

	/// <summary>
	/// Calculates the current fps
	/// </summary>
	void calculateFps();

	#define FRAME_VALUES 10
	// An array to store frame times:
	Uint32 _frametimes[FRAME_VALUES];

	// Last calculated SDL_GetTicks
	Uint32 _frametimelast;

	// total frames rendered
	Uint32 _framecount;

	// the value you want
	int _framespersecond;


protected:
	/// <summary>
	/// The index of the visible screen.
	/// </summary>
	int _activeScreen;

	/// <summary>
	/// Previous visted screens for back functionalitie
	/// </summary>
	std::stack<int> _previousScreens;

	SDLWrapper _sdl;
	SDLImageWrapper _sdlImage;
	SDLTtfWrapper _sdlTtf;
	unique_ptr<Window> _window;
};

