#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Mouse __declspec(dllexport)
#else
#define GAMEENGINE_Mouse __declspec(dllimport)
#endif
#include "pch.h"
#include "SDL.h"
#include <iostream>

class GAMEENGINE_Mouse Mouse {
public:
	static Mouse& getInstance() { return _instance; }

	Mouse(const Mouse&) = delete;
	Mouse(Mouse&&) = delete;
	Mouse& operator=(const Mouse&) = delete;
	Mouse& operator=(Mouse&&) = delete;

	enum MouseSkins {
		DEFAULT = 0,
		CROSSHAIR,
		WAIT,
		BEAM,
		NONE
	};

	/// <summary>
	/// Checks if the current mouse skin is current skin
	/// </summary>
	/// <param name="skin"></param>
	/// <returns></returns>
	bool isCurrentMouseSkin(MouseSkins skin);

	/// <summary>
	/// Change mouse cursor 1
	/// </summary>
	/// <param name="skin"></param>
	void setCursor(MouseSkins skin);

private:
	Mouse();
	static Mouse _instance;

	MouseSkins _currentSkin;

};