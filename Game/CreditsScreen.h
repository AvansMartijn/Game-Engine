#include "AbstractScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"
#include "Screens.h"
#include "ControllManager.h"
#include <KeyboardEvent.h>

class CreditsScreen : public AbstractScreen {
private:
	int _offset{ 0 };
	int _anchor{ 0 };
	bool _scrollLock = true;
	TextUiElement* _line;
	unique_ptr<ImageUiElement> _backgroundImage;

	std::vector<unique_ptr<TextUiElement>> _scrollableElements;
	ImageUiElement* _theBoyz;

	//wack-A-Mole
	std::chrono::steady_clock::time_point _begin;
	int _score{ 0 };
	TextUiElement* _scoreText;
	TextUiElement* _wackAMoleInfo;
	ButtonUiElement* _mole;
	
	std::vector<unique_ptr<ButtonUiElement>> _wackAMoleButtons;
public:
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
	void handleKeyboardInput(KeyboardEvent e);
	/// <summary>
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	void handleMouseWheelInput(MouseWheelEvent e);
	/// <summary>
	/// Called when the user click their mouse.
	/// </summary>
	/// <param name="e">The mouse click event.</param>
	void handleMouseClickInput(MouseButtonEvent e);
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