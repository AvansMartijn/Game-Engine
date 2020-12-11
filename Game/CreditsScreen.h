#include "AbstractScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"
#include "Screens.h"
#include "ControllManager.h"

class CreditsScreen : public AbstractScreen
{
private:
	shared_ptr<TextUiElement> _fps;

	int _offset{ 0 };
	int _anchor{ 0 };
	bool _scrollLock = true;
	shared_ptr<TextUiElement> _line;

	std::vector<shared_ptr<TextUiElement>> _scrollableElements;
	shared_ptr<ImageUiElement> _theBoyz;

	//wack-A-Mole
	std::chrono::steady_clock::time_point _begin;
	int _score{ 0 };
	shared_ptr<TextUiElement> _scoreText;
	shared_ptr<TextUiElement> _wackAMoleInfo;
	shared_ptr<ButtonUiElement> _mole;
	
	std::vector<shared_ptr<ButtonUiElement>> _wackAMoleButtons;
public:
	using AbstractScreen::AbstractScreen;
	CreditsScreen();
	~CreditsScreen();

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
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};