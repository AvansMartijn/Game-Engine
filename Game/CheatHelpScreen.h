#include "AbstractScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"
#include "Screens.h"
#include <KeyboardEvent.h>

#pragma once
class CheatHelpScreen : public AbstractScreen {
private:
	TextUiElement* _cheatInformation;

	void loadCheatInformation();
public:
	using AbstractScreen::AbstractScreen;
	CheatHelpScreen();
	~CheatHelpScreen();

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

