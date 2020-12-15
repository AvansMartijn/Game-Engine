#pragma once
#include "AbstractScreen.h"
#include "GameObject.h"
#include "Window.h"
#include "GameObjectBuilder.h"
#include "MoveExtension.h"
#include "AbstractGame.h"
#include "Physics.h"
#include <iostream>
#include "Screens.h"
#include "CollisionResolutionPortalExtension.h"
#include "ImageUiElement.h"
#include <chrono>
#include <GameEngine.h>
#include <TextUiElement.h>
#include <HpBarUIElement.h>
#include "ControllManager.h"
#include "PickupExtension.h"
#include "ThrusterManagableItem.h"
#include "GlueManageableItem.h"
#include "PortalManagableItem.h"
#include "AbstractLevelLoader.h"
#include "DefaultLevelLoader.h"
#include "SoundPlayer.h"
#include "TiledLevelLoader.h"
#include "GameSettings.h"
#include <TextUiElement.h>
#include <HealthExtension.h>
#include <Mouse.h>

using namespace std;

class GameScreen : public AbstractScreen {
private:
	std::chrono::steady_clock::time_point begin;
	GameEngine _gameEngine;

	// TODO: OMZETTEN
	std::vector<std::shared_ptr<AbstractManageableItem>> _availableItems;

	// TODO: OMZETTEN
	shared_ptr<AbstractLevelLoader> _levelLoader;

	// TODO: CHANGE
	vector<unique_ptr<AbstractUiElement>> _gameUiElements;
	unique_ptr<ImageUiElement> _backgroundImg;
	TextUiElement* _weapon;
	TextUiElement* _score;
	HpBarUIElement* _hpBar;
	TextUiElement* _ammo;

	std::string _name;
public:
	GameScreen();

	/// <summary>
	/// Called one time to create all objects.
	/// </summary>
	void onInit();
	/// <summary>
	/// Sets the game up.
	/// </summary>
	void setupGame();
	/// <summary>
	/// Set's the screen up.
	/// </summary>
	void setupScreen();
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param>
	virtual void onScreenShowed(vector<std::string> args = {});
	/// <summary>
	/// Set's the HUD up.
	/// </summary>
	void setupHUD();
	/// <summary>
	/// Called every tick to update properties.
	/// </summary>
	void onTick();
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
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
	/// <summary>
	/// Called when the user click their mouse.
	/// </summary>
	/// <param name="e">The mouse click event.</param>
	void handleMouseClickInput(SDL_MouseButtonEvent e);
	/// <summary>
	/// Pre renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	void preRender(const unique_ptr<Window>& window);
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

