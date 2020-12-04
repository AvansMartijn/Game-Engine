#include "AbstractScreen.h"
#include <TextUiElement.h>
#include <ImageUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "LevelData.h"
#include "GameSettings.h"
#include "ControllManager.h"


class StartNewLevelScreen : public AbstractScreen
{
private:

	shared_ptr<TextUiElement> StoryTitle;
	shared_ptr<TextUiElement> StoryText;
	shared_ptr<TextUiElement> KeyBindingsTitle;
	shared_ptr<ImageUiElement> keybindingsImage;

	int offsett = 0;

public:
	using AbstractScreen::AbstractScreen;
	StartNewLevelScreen();
	~StartNewLevelScreen();

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
	/// Called when the user switches to this screen.
	/// </summary>
	/// <param name="args">The arguments we want to pass to the next screen</param
	void onScreenShowed(vector<std::string> args);
	/// <summary>
	/// Called when the user moves their mouse.
	/// </summary>
	/// <param name="e">The mouse mouse event.</param>
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};