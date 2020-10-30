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
	virtual void switchScreen(int screenIndex) = 0;



	/// <summary>
	/// Registers a texture in the registry.
	/// </summary>
	/// <param name="textureKey">The texture registry key.</param>
	/// <param name="texturePath">The path to the texture.</param>
	void registerTexture(std::string textureKey, std::string texturePath);

	/// <summary>
	/// Registers a font in the registry.
	/// </summary>
	/// <param name="fontKey">The font registry key.</param>
	/// <param name="fontPath">The path to the font.</param>
	void registerFont(std::string fontKey, std::string fontPath);
protected:

	/// <summary>
/// Switch the current screen to the screen with the given index
/// </summary>
	virtual int getPreviousScreen() = 0;

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

