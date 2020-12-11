#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractScreen __declspec(dllexport)
#else
#define GAMEENGINE_AbstractScreen __declspec(dllimport)
#endif

#include <memory>
#include <vector>
#include "Window.h"
#include "AbstractUiElement.h"
#include "Physics.h"
#include "TextUIElement.h"

using namespace std;

class GameEngine;
class AbstractGame;
class GAMEENGINE_AbstractScreen AbstractScreen {
protected:
	AbstractGame* _game;
	vector<shared_ptr<AbstractUiElement>> _uiElements;
public:
	bool shouldShowFPS;
	std::string backgroundTrackKey = "";

	AbstractScreen();
	~AbstractScreen();


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
	/// <param name="args">The arguments we want to pass to the next screen</param>
	virtual void onScreenShowed(vector<std::string> args = {});
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
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	virtual void handleMouseWheelInput(SDL_MouseWheelEvent e) = 0;
	/// <summary>
	/// Called when the user click their mouse.
	/// </summary>
	/// <param name="e">The mouse click event.</param>
	virtual void handleMouseClickInput(SDL_MouseButtonEvent e);
	/// <summary>
	/// Adds a reference to the game.
	/// </summary>
	/// <param name="game">A refrence to the game.</param>
	virtual void registerGame(AbstractGame* game);
	/// <summary>
	/// Renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	virtual void render(const unique_ptr<Window>& window);
	/// <summary>
	/// Pre renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	virtual void preRender(const unique_ptr<Window>& window);
	/// <summary>
	/// Resets the game.
	/// </summary>
	virtual void reset();
};

