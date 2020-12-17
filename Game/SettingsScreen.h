#pragma once
#include "AbstractScreen.h"
#include <TextUiElement.h>
#include "ControllManager.h"


class SettingsScreen : public AbstractScreen {
private:
	TextUiElement* _soundText;
	TextUiElement* _soundFxText;
	TextUiElement* _tickSpeed;
public:
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
	void handleKeyboardInput(KeyboardEvent e);
};