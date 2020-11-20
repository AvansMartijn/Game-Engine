#pragma once
#include "AbstractScreen.h"
#include <TextUiElement.h>

class HighScoreScreen : public AbstractScreen
{
private:

	shared_ptr<TextUiElement> scroll;

	shared_ptr<TextUiElement> _row1Text;
	shared_ptr<TextUiElement> _row2Text;
	shared_ptr<TextUiElement> _row3Text;
	shared_ptr<TextUiElement> _row4Text;
	shared_ptr<TextUiElement> _row5Text;


	int offsett = 0;

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
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};

