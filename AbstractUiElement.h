#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

/// <summary>
/// Element to be rendered on the screen.
/// </summary>
class AbstractGame;
class AbstractUiElement
{
protected:
	AbstractGame* _game;
	SDL_Rect _rectangle;
public:
	AbstractUiElement();
	~AbstractUiElement();

	/// This is called one time before going into the render loop.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	virtual void preRender(SDL_Renderer* renderer) = 0;
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	virtual void render(SDL_Renderer* renderer) = 0;
	/// <summary>
	/// The function executed when the element is clicked on.
	/// </summary>
	virtual void onClick() = 0;
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
};

