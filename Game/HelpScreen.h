#include "AbstractScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"
#include "Screens.h"
#include "ControllManager.h"

class HelpScreen : public AbstractScreen
{
private:
	shared_ptr<TextUiElement> StoryText;
	shared_ptr<TextUiElement> StoryTitle;


	shared_ptr<ImageUiElement> keybindingsImage;
	shared_ptr<TextUiElement> _fps;

	std::vector<shared_ptr<TextUiElement>> srollableElements;

	int offset = 0;
	int anchor = 0;
public:
	using AbstractScreen::AbstractScreen;
	HelpScreen();
	~HelpScreen();

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