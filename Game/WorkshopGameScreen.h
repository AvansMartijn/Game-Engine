#pragma once
#include "AbstractScreen.h"
#include "Physics.h"
#include "GameEngine.h"

class WorkshopGameScreen : public AbstractScreen {
public:
	WorkshopGameScreen();
	~WorkshopGameScreen();

	void onInit();
	void onTick();

	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
	void render(const unique_ptr<Window>& window);

	shared_ptr<GameObject> createGameObject(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, int type = 0);
};

