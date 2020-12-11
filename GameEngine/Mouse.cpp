#include "pch.h"
#include "Mouse.h"

Mouse Mouse::_instance;

Mouse::Mouse() { }

void Mouse::setCursor(MouseSkins skin)
{
	SDL_Cursor* cursor;

	switch (skin)
	{
	case DEFAULT:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
		_currentSkin = DEFAULT;
		break;
	case CROSSHAIR:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
		_currentSkin = CROSSHAIR;
		break;
	case WAIT:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_WAIT);
		_currentSkin = WAIT;
		break;
	case BEAM:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
		_currentSkin = BEAM;
		break;
	case NONE:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_NO);
		_currentSkin = NONE;
		break;
	default:
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	}
	SDL_SetCursor(cursor);
}

bool Mouse::isCurrentMouseSkin(MouseSkins skin) {
	return _currentSkin == skin;
}
