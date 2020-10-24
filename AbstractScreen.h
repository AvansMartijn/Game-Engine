#pragma once
#include <memory>
#include <vector>
#include "Window.h"
#include "AbstractUiElement.h"
using namespace std;

class AbstractGame;
class AbstractScreen
{
protected:
	AbstractGame* _game;
public:
	AbstractScreen();
	~AbstractScreen();
	
	vector<shared_ptr<GameObject>> gameObjects;
	vector<shared_ptr<AbstractUiElement>> uiElements;

	/// <summary>
	/// Screen enums has to be in right order
	/// the order the screens get created
	/// </summary>
	enum Screens {
		MainGame = 0,
		Pause,
		Credits,
		Help
	};


	/// <summary>
	/// Called one time to create all objects.
	/// </summary>
	virtual void onInit() = 0;
	/// <summary>
	/// Called every tick to update properties.
	/// </summary>
	virtual void onTick() = 0;
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	virtual void onScreenShowed() = 0;
	/// <summary>
	/// Called when the user uses their keyboard.
	/// </summary>
	/// <param name="e">The keyboard event.</param>
	virtual void handleKeyboardInput(SDL_KeyboardEvent e) = 0;
	/// <summary>
	/// Called when the user moves their mouse.
	/// </summary>
	/// <param name="e">The mouse mouse event.</param>
	virtual void handleMouseMotionInput(SDL_MouseMotionEvent e) = 0;
	/// <summary>
	/// Called when the user click their mouse.
	/// </summary>
	/// <param name="e">The mouse click event.</param>
	virtual void handleMouseClickInput(SDL_MouseButtonEvent e) = 0;
	/// <summary>
	/// Adds a reference to the game.
	/// </summary>
	/// <param name="game">A refrence to the game.</param>
	virtual void registerGame(AbstractGame* game);
};

