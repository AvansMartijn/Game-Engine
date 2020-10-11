#pragma once
#include "AbstractScreen.h"
#include "GameObject.h"
#include "Window.h"
#include "GameObjectBuilder.h"
#include "MoveExtension.h"
#include "CheckPhysicsExtension.h"
#include "AbstractGame.h"

#include <iostream>

using namespace std;

class GameScreen: public AbstractScreen
{
private:
	shared_ptr<GameObject> _player;
public:
	using AbstractScreen::AbstractScreen;
	GameScreen();
	void onInit();
	void onTick();
	void onScreenShowed();
	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseClickInput(SDL_MouseButtonEvent e);
};

