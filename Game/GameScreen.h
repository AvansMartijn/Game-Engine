#pragma once
#include "AbstractScreen.h"
#include "GameObject.h"
#include "Window.h"
#include "GameObjectBuilder.h"
#include "MoveExtension.h"
#include "CheckPhysicsExtension.h"
#include "AbstractGame.h"
#include "Physics.h"
#include <iostream>
#include "Screens.h"
#include "CollisionResolutionPortalExtension.h"
#include "ImageUiElement.h"

using namespace std;

class GameScreen : public AbstractScreen
{
private:
	shared_ptr<GameObject> _player;
	vector<shared_ptr<GameObject>> _gameObjects;
public:
	GameScreen();

	/// <summary>
	/// Called one time to create all objects.
	/// </summary>
	void onInit();
	/// <summary>
	/// Called every tick to update properties.
	/// </summary>
	void onTick();
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	void onScreenShowed();
	/// <summary>
	/// Handles the player controls.
	/// </summary>
	void handlePlayerControls();
	/// <summary>
	/// Called when the user uses their keyboard.
	/// </summary>
	/// <param name="e">The keyboard event.</param>
	void handleKeyboardInput(SDL_KeyboardEvent e);
	/// <summary>
	/// Called when the user moves their mouse.
	/// </summary>
	/// <param name="e">The mouse mouse event.</param>
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	/// <summary>
	/// Called when the user click their mouse.
	/// </summary>
	/// <param name="e">The mouse click event.</param>
	void handleMouseClickInput(SDL_MouseButtonEvent e);
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
	shared_ptr<GameObject> createEntity(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height);
	shared_ptr<GameObject> createPortal(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height);

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
	shared_ptr<GameObject> createGameObject(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);
	/// <summary>
	/// Renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	void render(const unique_ptr<Window>& window);
	/// <summary>
	/// Resets the game.
	/// </summary>
	void reset();
};

