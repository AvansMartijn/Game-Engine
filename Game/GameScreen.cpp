#include "GameScreen.h"
#include <CanWieldExtension.h>
#include "TiledLevelLoader.h"

GameScreen::GameScreen() {}

void GameScreen::onInit() {
	begin = std::chrono::steady_clock::now();
	backgroundTrackKey = "Background_1";
	setupScreen();
	setupGame();
	setupHUD();
}

void GameScreen::setupScreen() {
	_backgroundImg = make_shared<ImageUiElement>(ImageUiElement("BackgroundGame", { 0 , 0, 2160, 720 }));
	_uiElements.push_back(_backgroundImg);
}

void GameScreen::setupHUD() {
	const Color bgColor = { 28, 28, 28, 1 };
	const Color fgColor = { 255, 255, 255 };
	const Color hpColor = { 0, 255, 0 };
	const string font = "Portal";
	const int fontSize = 24;
	//_lives = make_shared<TextUiElement>(TextUiElement("LIVES: 3", font, fontSize, { 5, 10, 0, 0 }, fgColor, bgColor, false));
	//_uiElements.push_back(_lives);
	//_gameUiElements.push_back(_lives);

	_weapon = make_shared<TextUiElement>(TextUiElement("CURRENT WEAPON: NONE", font, fontSize, { 5, 40, 0, 0 }, fgColor, bgColor, false));
	_uiElements.push_back(_weapon);
	_gameUiElements.push_back(_weapon);
	

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
	_gameUiElements.push_back(_fps);


	// int x, int y, int w, int h, float Percent, Color FGColor, Color BGColor

	_hpBar = make_shared<HpBarUIElement>(HpBarUIElement(5, 70, 150, 20, 0.8f, hpColor, bgColor));
	_uiElements.push_back(_hpBar);
	_gameUiElements.push_back(_hpBar);

}

void GameScreen::setupGame() {
	if (_levelLoader)
		_levelLoader->createLevel(_gameEngine, _name);
}

void GameScreen::onScreenShowed(vector<std::string> args) {
	for (size_t i = 0; i < args.size(); i++) {
		std::string arg = args[i];

		if (arg == "tiled")
			_levelLoader = make_shared<TiledLevelLoader>(TiledLevelLoader());
		else if (arg == "default")
			_levelLoader = make_shared<DefaultLevelLoader>(DefaultLevelLoader());
		else if (arg == "reset")
			reset();
		else
			_name = arg;
	}
}

void GameScreen::onTick() {
	auto timePassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();

	if (timePassed >= 1)
	{
		begin = std::chrono::steady_clock::now();
		if (Scene::getInstance().score >= 1)
			Scene::getInstance().score--;
	}

	if (Scene::getInstance().gameOver) {
		_game->switchScreen(Screens::GameFinished);
		Scene::getInstance().gameOver = false;
	}

	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	if (Scene::getInstance().getPlayer()) {
		handlePlayerControls();
		calculatePlayerTexture();
	}

	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		shared_ptr<AbstractManageableItem> currentWeapon = Scene::getInstance().getWieldExtension()->getCurrentItem();
		if (currentWeapon != NULL) {
			std::string result = "CURRENT WEAPON: " + currentWeapon->getScreemName();
			_weapon->text = result;
		}
	}

	_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	
}

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) {
		vel.x = -5;
		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = false;
	}

	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) {
		vel.x = 5;

		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = true;
	}

	if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
		vel.x = 0;

	if (keystate[SDL_SCANCODE_F])
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50.0f : -50.0f;
	if (keystate[SDL_SCANCODE_F]) {
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50 : -50;
		SoundPlayer::getInstance().playSFX("Thruster_Sound");
	}

	if (keystate[SDL_SCANCODE_SPACE] || keystate[SDL_SCANCODE_W]) {
		if (Scene::getInstance().getPlayerMoveExtension()->canJump()) {
			vel.y = -5;
			Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::JUMPING;
			SoundPlayer::getInstance().playSFX("Player_Jump");
		}
	}
	Scene::getInstance().getPlayer()->body.b2body->SetLinearVelocity(vel);
}

void GameScreen::calculatePlayerTexture() {
	shared_ptr<MoveExtension> moveExtension = Scene::getInstance().getPlayerMoveExtension();

	if (moveExtension->isLookingToRight) {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_RIGHT;
		}
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_LEFT;
		}
	}
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	case SDLK_1:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(0);

		break;
	case SDLK_2:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(1);

		break;
	case SDLK_3:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(2);

		break;
	case SDLK_4:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(3);

		break;
	case SDLK_5:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(4);

		break;
	case SDLK_6:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(5);

		break;
	case SDLK_7:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(6);

		break;
	case SDLK_8:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(7);

		break;
	case SDLK_9:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(8);

		break;
	case SDLK_p:
		_game->reset();
	case SDLK_KP_PLUS:
		if(Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
		break;
	case SDLK_KP_MINUS:
	if (Scene::getInstance().zoom > 10)
		Scene::getInstance().zoom -= 3.0f;
	default:
		break;
	}
}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		shared_ptr<CanWieldExtension> wieldExtension = Scene::getInstance().getWieldExtension();

		switch (e.button) {
		case SDL_BUTTON_LEFT:
			wieldExtension->onLeftClick(e.x, e.y);

			break;
		case SDL_BUTTON_RIGHT:
			wieldExtension->onRightClick(e.x, e.y);

			break;
		}
	}
}

void GameScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	if (e.y > 0) // scroll up
	{
		// Put code for handling "scroll up" here!
		if (Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
	}
	else if (e.y < 0) // scroll down
	{
		// Put code for handling "scroll down" here!
		if (Scene::getInstance().zoom > 10)
			Scene::getInstance().zoom -= 3.0f;
	}

}

void GameScreen::render(const unique_ptr<Window>& window) {
	_backgroundImg->render(window);

	Scene::getInstance().render(window);

	for (size_t gameUiElementIndex = 0; gameUiElementIndex < _gameUiElements.size(); gameUiElementIndex++)
		_gameUiElements[gameUiElementIndex]->render(window);

  if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		if (Scene::getInstance().getWieldExtension()->getCurrentItem() != nullptr)
			Scene::getInstance().getWieldExtension()->getCurrentItem()->render(window);
	}
}

void GameScreen::reset() {
	AbstractScreen::reset();
	Scene::getInstance().reset();

	Physics::getInstance().reset();
	setupGame();
}