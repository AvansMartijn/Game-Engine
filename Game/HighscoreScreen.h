#pragma once
#include "AbstractScreen.h"
#include <TextUiElement.h>
#include "ControllManager.h"

class HighScoreScreen : public AbstractScreen {
private:
	shared_ptr<TextUiElement> _scrollableText;

	int _offset = 0;
	int _anchor = 0;
	shared_ptr<TextUiElement> _fps;

public:
	using AbstractScreen::AbstractScreen;
	HighScoreScreen();
	~HighScoreScreen();
	// Inherited via AbstractScreen
	virtual void onInit() override;
	/// <summary>
	/// updates every tick
	/// </summary>
	virtual void onTick() override;
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
	/// <summary>
	/// Handles keyboard input
	/// </summary>
	/// <param name="e"></param>
	virtual void handleKeyboardInput(SDL_KeyboardEvent e) override;
	/// <summary>
	/// handles mouse input
	/// </summary>
	/// <param name="e"></param>
	virtual void handleMouseMotionInput(SDL_MouseMotionEvent e) override;
	/// <summary>
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};

