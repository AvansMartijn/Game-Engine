#pragma once
#include "AbstractScreen.h"
#include <TextUiElement.h>
#include "ControllManager.h"
#include "ImageUiElement.h"

class HighScoreScreen : public AbstractScreen {
private:
	unique_ptr<TextUiElement> _scrollableText;
	unique_ptr<ImageUiElement> _backgroundImage;

	int _offset = 0;
	int _anchor = 0;
public:
	HighScoreScreen();
	~HighScoreScreen();
	// Inherited via AbstractScreen
	void onInit() override;
	/// <summary>
	/// updates every tick
	/// </summary>
	void onTick() override;
	/// <summary>
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
	/// <summary>
	/// Handles keyboard input
	/// </summary>
	/// <param name="e"></param>
	void handleKeyboardInput(SDL_KeyboardEvent e) override;
	/// <summary>
	/// handles mouse input
	/// </summary>
	/// <param name="e"></param>
	void handleMouseMotionInput(SDL_MouseMotionEvent e) override;
	/// <summary>
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
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
};

