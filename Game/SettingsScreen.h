#pragma once
#include "AbstractScreen.h"
#include <TextUiElement.h>
#include "ControllManager.h"


class SettingsScreen : public AbstractScreen {
private:
	shared_ptr<TextUiElement> _soundText;
	shared_ptr<TextUiElement> _soundFxText;
	shared_ptr<TextUiElement> _fps;
	shared_ptr<TextUiElement> _tickSpeed;
public:
	using AbstractScreen::AbstractScreen;
	SettingsScreen();
	~SettingsScreen();

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