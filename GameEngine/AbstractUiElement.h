#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractUiElement __declspec(dllexport)
#else
#define GAMEENGINE_AbstractUiElement __declspec(dllimport)
#endif
#include "Window.h"
#include "Rect.h"
#include <functional>

/// <summary>
/// Element to be rendered on the screen.
/// </summary>
class Window;
class AbstractGame;
class GAMEENGINE_AbstractUiElement AbstractUiElement {
protected:
	shared_ptr<AbstractGame> _game;
public:
	Rect rect;

	AbstractUiElement();
	~AbstractUiElement();

	/// <summary>
	/// prerender
	/// </summary>
	/// <param name="window"></param>
	virtual void preRender(const unique_ptr<Window>& window) = 0;
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	virtual void render(const unique_ptr<Window>& window) = 0;
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
	virtual void registerGame(shared_ptr<AbstractGame> game);
	/// <summary>
	/// The onclick function. This function needs to be changed so it calls a function.
	/// </summary>
	std::function<void(shared_ptr<AbstractGame>)> onClick;

	// TODO: DEZE OMZETTEN NAAR SMART PTR
};