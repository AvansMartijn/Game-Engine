#pragma once
#include "AbstractScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "GameSettings.h"
#include "ControllManager.h"
#include <KeyboardEvent.h>

class GameFinishedScreen : public AbstractScreen {
private:
	TextUiElement* _bodyText;
	TextUiElement* _nameText;
	ButtonUiElement* _nextLevelButton;
public:
	GameFinishedScreen();
	~GameFinishedScreen();

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
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
	/// <summary>
	/// Called when the user uses their keyboard.
	/// </summary>
	/// <param name="e">The keyboard event.</param>
	void handleKeyboardInput(KeyboardEvent e);
};

