#pragma once
#include "AbstractScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "ControllManager.h"

class LoadingScreen: public AbstractScreen {
private: 
	std::vector<std::string> _arguments;
	int _firstTickCounter;
	TextUiElement* _quoteText;
public:
	LoadingScreen();
	~LoadingScreen();

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
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param>
	void onScreenShowed(vector<std::string> args = {});
};

