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

using namespace std;

/// <summary>
/// The game class needs to be based of this class.
/// </summary>
 class GAMEENGINE_AbstractGame AbstractGame
{
public:
	AbstractGame();
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
	/// Switch the current screen to the screen with the given index
	/// </summary>
	/// <param name="screenIndex">The index of the screen we want to display</param>
	virtual void switchScreen(int screenIndex) = 0;
protected:
	/// <summary>
	/// The index of the visible screen.
	/// </summary>
	int _activeScreen;

	SDLWrapper _sdl;
	SDLImageWrapper _sdlImage;
	SDLTtfWrapper _sdlTtf;
	unique_ptr<Window> _window;
};

