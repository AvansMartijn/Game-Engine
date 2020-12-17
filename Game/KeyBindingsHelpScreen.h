#pragma once
#include "AbstractScreen.h"
#include <ImageUiElement.h>
#include <TextUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "ControllManager.h"
#include <KeyboardEvent.h>

class KeyBindingsHelpScreen : public AbstractScreen {
private:
	std::string _currentAction;
	bool _listingForInput = false;

	TextUiElement* _fpsKey;
	TextUiElement* _walkLeftKey;
	TextUiElement* _walkRightKey;
	TextUiElement* _stopKey;
	TextUiElement* _jumpKey;
	TextUiElement* _equipPortalGunKey;
	TextUiElement* _equipThrusterGunKey;
	TextUiElement* _equipGlueGunKey;

	/// <summary>
	/// Loads the keybindings from saveFile
	/// </summary>
	void loadKeybinding();
	/// <summary>
	/// Changes the text of the current key with "CLICK BUTTON", also resets to default values if _islisting is allready true
	/// </summary>
	void changeText(TextUiElement* text);
public:
	KeyBindingsHelpScreen();
	~KeyBindingsHelpScreen();

	/// <summary>
	/// Called one time to create all objects.
	/// </summary>
	void onInit();
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
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

