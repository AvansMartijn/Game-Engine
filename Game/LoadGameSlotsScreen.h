#pragma once
#include "AbstractScreen.h"
#include <ImageUiElement.h>
#include <ButtonUiElement.h>
#include "GameSettings.h"
#include "Screens.h"
#include "ControllManager.h"

class LoadGameSlotsScreen : public AbstractScreen {
private:
	ButtonUiElement* _slot1Button;
	ButtonUiElement* _slot2Button;
	ButtonUiElement* _slot3Button;
public:
	LoadGameSlotsScreen();
	~LoadGameSlotsScreen();

	/// <summary>
	/// Called one time to create all objects.
	/// </summary>
	void onInit();
	/// <summary>
	/// Called every tick to update properties.
	/// </summary>
	void onTick();
	/// <summary>
	/// Called when the user uses their keyboard.
	/// </summary>
	/// <param name="e">The keyboard event.</param>
	void handleKeyboardInput(SDL_KeyboardEvent e);

	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
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
};