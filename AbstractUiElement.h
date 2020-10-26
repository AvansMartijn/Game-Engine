#pragma once
#include "Window.h"
#include "Rect.h"
#include <functional>

/// <summary>
/// Element to be rendered on the screen.
/// </summary>
class Window;
class AbstractGame;
class AbstractUiElement
{
public:
	AbstractUiElement();
	~AbstractUiElement();

	/// This is called one time before going into the render loop.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	virtual void preRender(Window* window) = 0;
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	virtual void render(Window* window) = 0;
	/// <summary>
	/// Checks if the mouse is within the bounds of the element.
	/// </summary>
	/// <param name="mouseX">X coordinate of the mouse</param>
	/// <param name="mouseY">Y coordinate of the mouse</param>
	/// <returns></returns>
	virtual bool isInBound(int mouseX, int mouseY) = 0;
	/// <summary>
	/// Register the game to the element.
	/// </summary>
	/// <param name="game">The Game</param>
	virtual void registerGame(AbstractGame* game);

	/// <summary>
	/// The onclick function. This function needs to be changed so it calls a function.
	/// </summary>
	std::function<void(AbstractGame*)> onClick;
protected:
	AbstractGame* _game;
	Rect _rect;
};