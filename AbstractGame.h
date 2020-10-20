#pragma once
#include <memory>
#include "SDLWrapper.h"
#include "SDLImageWrapper.h"
#include "AbstractScreen.h"
#include <vector>
#include "Window.h"
#include "SDLTtfWrapper.h"

using namespace std;

/// <summary>
/// The game class needs to be based of this class.
/// </summary>
class AbstractGame
{
public:
	AbstractGame();
	~AbstractGame();

	/// <summary>
	/// All the possible screens the game has.
	/// </summary>
	vector<shared_ptr<AbstractScreen>> screens;

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
	Window* _window;
};

