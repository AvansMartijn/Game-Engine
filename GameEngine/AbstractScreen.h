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

using namespace std;

class GameEngine;
class AbstractGame;
class GAMEENGINE_AbstractScreen AbstractScreen
{
protected:
	AbstractGame* _game;
public:
	AbstractScreen();
	~AbstractScreen();

	vector<shared_ptr<GameObject>> gameObjects;
	vector<shared_ptr<AbstractUiElement>> uiElements;

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
	virtual void handleMouseClickInput(SDL_MouseButtonEvent e);
	/// <summary>
	/// Adds a reference to the game.
	/// </summary>
	/// <param name="game">A refrence to the game.</param>
	virtual void registerGame(AbstractGame* game);

	/// <summary>
	/// Creates a new entity.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="extensions">The extensions which this game object will use.</param>
	/// <param name="textureKey">The texture we want to use.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The object width.</param>
	/// <param name="height">The object height.</param>
	/// <returns>The created entity.</returns>
	shared_ptr<GameObject> createEntity(GameEngine gameEngine, vector<string> extensions, std::string textureKey, float x, float y, float width, float height);

	/// <summary>
	/// Creates a new game object.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="extensions">The extensions which this game object will use.</param>
	/// <param name="textureKey">The texture we want to use.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The object width.</param>
	/// <param name="height">The object height.</param>
	/// <param name="friction">The friction value.</param>
	/// <param name="fixed">If this object should use fixtures.</param>
	/// <param name="fixedRotation"></param>
	/// <returns>The created game object.</returns>
	shared_ptr<GameObject> createGameObject(GameEngine gameEngine, vector<string> extensions, std::string textureKey, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);
};

