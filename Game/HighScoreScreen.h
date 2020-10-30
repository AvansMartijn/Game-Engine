#pragma once
#include "AbstractScreen.h"

class HighScoreScreen : public AbstractScreen
{
public:
	using AbstractScreen::AbstractScreen;
	HighScoreScreen();
	~HighScoreScreen();
	// Inherited via AbstractScreen
	virtual void onInit() override;
	virtual void onTick() override;
	virtual void onScreenShowed() override;
	virtual void handleKeyboardInput(SDL_KeyboardEvent e) override;
	virtual void handleMouseMotionInput(SDL_MouseMotionEvent e) override;
};

