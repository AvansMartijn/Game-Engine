#include "AbstractScreen.h"
#include <TextUiElement.h>
#include <ImageUiElement.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "LevelData.h"
#include "GameSettings.h"
#include "ControllManager.h"

class StartNewLevelScreen : public AbstractScreen {
private:
	TextUiElement* _storyText;
	TextUiElement* _storyTitle;
	ImageUiElement* _keybindingsImage;

	unique_ptr<AbstractUiElement> _backgroundElement;
	std::vector<unique_ptr<AbstractUiElement>> _scrollableUiElement;

	int _offset = 0;
	int _anchor = 0;

public:
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
	/// <summary>
	/// Handle the mouse wheel input.
	/// </summary>
	/// <param name="e">The mouse wheel input</param>
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
	/// <summary>
	/// Renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	void render(const unique_ptr<Window>& window);
	/// <summary>
	/// Pre renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	void preRender(const unique_ptr<Window>& window);
};