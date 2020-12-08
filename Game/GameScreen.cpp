#include "GameScreen.h"
#include <CanWieldExtension.h>
#include "TiledLevelLoader.h"
#include "ControllManager.h"

GameScreen::GameScreen() {}

void GameScreen::onInit() {
	begin = std::chrono::steady_clock::now();
	backgroundTrackKey = "Background_1";
	setupScreen();
	setupGame();
	setupHUD();
	shouldShowFPS = true;
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
	const int fontSize = 19;

	_hudBackgroundImg = make_shared<ImageUiElement>(ImageUiElement("BackgroundHud", { 0 , 620, 300, 100 }, 122));
	_uiElements.push_back(_hudBackgroundImg);
	_gameUiElements.push_back(_hudBackgroundImg);

	_score = make_shared<TextUiElement>(TextUiElement("SCORE: 999", font, fontSize, { 10, 630, 0, 0 }, fgColor, bgColor, false));
	_uiElements.push_back(_score);
	_gameUiElements.push_back(_score);

	_weapon = make_shared<TextUiElement>(TextUiElement("WEAPON: NONE", font, fontSize, { 10, 650, 0, 0 }, fgColor, bgColor, false));
	_uiElements.push_back(_weapon);
	_gameUiElements.push_back(_weapon);

	_ammo = make_shared<TextUiElement>(TextUiElement("AMMO:", font, fontSize, { 10, 670, 0, 0 }, fgColor, bgColor, false));
	_uiElements.push_back(_ammo);
	_gameUiElements.push_back(_ammo);

	_hpBar = make_shared<HpBarUIElement>(HpBarUIElement(158, 695, -150, 20, 0.8f, hpColor, bgColor));
	_uiElements.push_back(_hpBar);
	_gameUiElements.push_back(_hpBar);

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
	_gameUiElements.push_back(_fps);
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
	long timePassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();

	if (Scene::getInstance().getPlayer()->getExtension(typeid(HealthExtension))) {

		shared_ptr<GameObject> gameObject = Scene::getInstance().getPlayer();
		float healthValue = dynamic_pointer_cast<HealthExtension>(gameObject->getExtension(typeid(HealthExtension)))->getHealth();

		if (healthValue <= 0) {
			_game->switchScreen(Screens::GameOver);
			return;
		}
		else {
			_hpBar->percent = healthValue / 100;
		}
	}

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
			std::string result = "WEAPON: " + currentWeapon->getScreemName();
			_weapon->text = result;

			if (currentWeapon->getAmmo() == -1)
				_ammo->text = "AMMO: INFINITE";
			else
				_ammo->text = "AMMO: " + std::to_string(currentWeapon->getAmmo());
		}
		else {
			_weapon->text = "WEAPON: NONE";
			_ammo->text = "AMMO:";
		}

	}


	_score->text = "SCORE: " + std::to_string(Scene::getInstance().score);

	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else if(_fps->text.length() > 0)
		_fps->text = "  ";
	

	// TODO: Execute AI
	for (size_t gameObjectIndex = 0; gameObjectIndex < Scene::getInstance().getEntitiesSize(); gameObjectIndex++) {
		shared_ptr<GameObject> gameObject = Scene::getInstance().getEntityAtIndex(gameObjectIndex);

		if (gameObject->hasExtension(typeid(AiExtension)))
			gameObject->getExtension<AiExtension>()->execute();

		if (gameObject->hasExtension(typeid(EntityMovementExtension)))
			gameObject->getExtension<EnemyTextureExtension>()->calculateTextures();
	}

}

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	SDL_Scancode walkLeft;
	if (ControllManager::getInstance().walkLeftKey.isDefault)
		walkLeft = ControllManager::getInstance().walkLeftKey.defaultSDLKey;
	else
		walkLeft = ControllManager::getInstance().walkLeftKey.userSDLKey;

	if (keystate[walkLeft]) {
		vel.x = -5;
		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = false;
	}

	SDL_Scancode walkRight;
	if (ControllManager::getInstance().walkRightKey.isDefault)
		walkRight = ControllManager::getInstance().walkRightKey.defaultSDLKey;
	else
		walkRight = ControllManager::getInstance().walkRightKey.userSDLKey;

	if (keystate[walkRight]) {
		vel.x = 5;

		Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::RUNNING;
		Scene::getInstance().getPlayerMoveExtension()->isLookingToRight = true;
	}

	SDL_Scancode stop;
	if (ControllManager::getInstance().stopKey.isDefault)
		stop = ControllManager::getInstance().stopKey.defaultSDLKey;
	else
		stop = ControllManager::getInstance().stopKey.userSDLKey;

	if (keystate[stop])
		vel.x = 0;

	if (keystate[SDL_SCANCODE_F])
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50.0f : -50.0f;
	if (keystate[SDL_SCANCODE_F]) {
		vel.x = (Scene::getInstance().getPlayerMoveExtension()->isLookingToRight) ? 50 : -50;
		SoundPlayer::getInstance().playSFX("Thruster_Sound");
	}

	SDL_Scancode jump;
	if (ControllManager::getInstance().jumpKey.isDefault)
		jump = ControllManager::getInstance().jumpKey.defaultSDLKey;
	else
		jump = ControllManager::getInstance().jumpKey.userSDLKey;

	if (keystate[jump]) {
		if (Scene::getInstance().getPlayerMoveExtension()->canJump()) {
			vel.y = -5;
			Scene::getInstance().getPlayerMoveExtension()->currentMovementType = MovementTypes::JUMPING;
			SoundPlayer::getInstance().playSFX("Player_Jump");
		}
	}
	Scene::getInstance().getPlayer()->body.b2body->SetLinearVelocity(vel);

}

void GameScreen::calculatePlayerTexture() {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(PlayerTextureExtension)))
		Scene::getInstance().getPlayer()->getExtension<PlayerTextureExtension>()->calculateTextures();

	//if (moveExtension->isLookingToRight) {
	//	if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
	//		if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
	//		else
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_RIGHT;
	//	}
	//	else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
	//		if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
	//		else
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_RIGHT;
	//	}
	//}
	//else {
	//	if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
	//		if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
	//		else
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_LEFT;
	//	}
	//	else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
	//		if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
	//		else
	//			Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_LEFT;
	//	}
	//}
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

	SDL_Keycode firstGun;
	if (ControllManager::getInstance().equipPortalKey.isDefault)
		firstGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipPortalKey.defaultSDLKey);
	else
		firstGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipPortalKey.userSDLKey);

	SDL_Keycode secondGun;
	if (ControllManager::getInstance().equipThrusterKey.isDefault)
		secondGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipThrusterKey.defaultSDLKey);
	else
		secondGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipThrusterKey.userSDLKey);

	SDL_Keycode thirdGun;
	if (ControllManager::getInstance().equipGlueKey.isDefault)
		thirdGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipGlueKey.defaultSDLKey);
	else
		thirdGun = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().equipGlueKey.userSDLKey);

	if (e.keysym.sym == firstGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(0);
	}
	else if (e.keysym.sym == secondGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(1);
	}
	else if (e.keysym.sym == thirdGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getWieldExtension()->setCurrentItemIndex(2);
	}

	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps) 
		shouldShowFPS = !shouldShowFPS;
	
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

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
	case SDLK_TAB:
		//TODO Open Cheat Window
		_game->switchScreen(Screens::Cheat);
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