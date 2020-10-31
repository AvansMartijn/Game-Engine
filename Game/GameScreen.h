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

using namespace std;

class GameScreen : public AbstractScreen
{
private:
	shared_ptr<GameObject> _player;
public:
	using AbstractScreen::AbstractScreen;
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
	Physics physics;
};

