#pragma once
#include "AbstractScreen.h"
#include "Physics.h"
#include "GameEngine.h"
#include "ImageUiElement.h"
#include <memory>
#include "AbstractGame.h"
#include "PlayerMoveExtension.h"

class WorkshopGameScreen : public AbstractScreen {
private:
	std::shared_ptr<ImageUiElement> _backgroundImage;
	GameEngine _gameEngine;
public:
	WorkshopGameScreen();
	~WorkshopGameScreen();

	void onInit();
	void setupGame();

	void onTick();
	void handlePlayerControls();

	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
	void render(const unique_ptr<Window>& window);
	void onScreenShowed(vector<std::string> args = {});

	shared_ptr<GameObject> createGameObject(vector<string> extensions, std::string texture, float x, float y, float width, float height, int type = 0, std::string sensor = "fixture");
};

