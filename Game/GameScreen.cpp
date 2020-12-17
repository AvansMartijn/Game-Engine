#include "GameScreen.h"
#include <CanWieldExtension.h>
#include "TiledLevelLoader.h"
#include "Utilities.h"

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
	_backgroundImg = make_unique<ImageUiElement>(ImageUiElement("BackgroundGame", { 0 , 0, 2160, 720 }));
}

void GameScreen::setupHUD() {
	const Color bgColor = { 28, 28, 28, 1 };
	const Color bgRed = { 255, 0, 0, 255 };
	const Color fgColor = { 255, 255, 255 };
	const Color hpColor = { 0, 255, 0 };
	const string font = "Portal";
	const int fontSize = 19;

	_gameUiElements.push_back(make_unique<ImageUiElement>(ImageUiElement("BackgroundHud", { 0 , 620, 240, 100 }, 122)));

	_gameUiElements.push_back(make_unique<TextUiElement>(TextUiElement("SCORE: 999", font, fontSize, { 10, 630, 0, 0 }, fgColor, bgColor, false)));
	_score = static_cast<TextUiElement*>(_gameUiElements.back().get());

	_gameUiElements.push_back(make_unique<TextUiElement>(TextUiElement("WEAPON: NONE", font, fontSize, { 10, 650, 0, 0 }, fgColor, bgColor, false)));
	_weapon = static_cast<TextUiElement*>(_gameUiElements.back().get());

	_gameUiElements.push_back(make_unique<TextUiElement>(TextUiElement("AMMO:", font, fontSize, { 10, 670, 0, 0 }, fgColor, bgColor, false)));
	_ammo = static_cast<TextUiElement*>(_gameUiElements.back().get());

	_gameUiElements.push_back(make_unique<HpBarUIElement>(HpBarUIElement(160, 693, -150, 20, 0.8f, hpColor, bgRed)));
	_hpBar = static_cast<HpBarUIElement*>(_gameUiElements.back().get());

	addFpsElement("Portal");
}

void GameScreen::setupGame() {
	if (_levelLoader) {
		_levelLoader->createLevel(_gameEngine, _name);

		std::string number = _name.substr(_name.length() - 1, 1);
		backgroundTrackKey = "Background_" + number;
	}
}

void GameScreen::onScreenShowed(vector<std::string> args) {
	for (size_t i = 0; i < args.size(); i++) {
		std::string arg = args[i];

		if (arg == "tiled") {
			_levelLoader = make_unique<TiledLevelLoader>(TiledLevelLoader());
			_levelLoader->directory = AssetRegistry::getInstance().getBasePath() + "res\\levels\\";
		}
		else if (arg == "default")
			_levelLoader = make_unique<DefaultLevelLoader>(DefaultLevelLoader());
		else if (arg == "custom")
			_levelLoader->directory = AssetRegistry::getInstance().getPrefPath("Mike", "Latrop 2") + "Levels\\";
		else if (arg == "reset")
			reset();
		else
			_name = arg;
	}
}

void GameScreen::onTick() {
	auto timePassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();

	if (Scene::getInstance().getPlayer()->getExtension<HealthExtension>()) {
		GameObject* gameObject = Scene::getInstance().getPlayer();
		float healthValue = (float)gameObject->getExtension<HealthExtension>()->getHealth();

		if (healthValue <= 0) {
			_game->switchScreen(Screens::GameOver);
			return;
		}
		else
			_hpBar->percent = healthValue / 100;
	}

	if (timePassed >= 1) {
		begin = std::chrono::steady_clock::now();
		if (Scene::getInstance().score >= 1)
			Scene::getInstance().score--;
	}

	if (Scene::getInstance().gameOver) {
		_game->switchScreen(Screens::GameFinished);
		Scene::getInstance().gameOver = false;
	}

	for (size_t gameObjectIndex = 0; gameObjectIndex < Scene::getInstance().getEntitiesSize(); gameObjectIndex++) {
		GameObject* gameObject = Scene::getInstance().getEntityAtIndex((int)gameObjectIndex);

		if (gameObject != nullptr) {
			if (gameObject->hasExtension(typeid(AiExtension)))
				gameObject->getExtension<AiExtension>()->execute();

			if (gameObject->hasExtension(typeid(HealthExtension))) {
				HealthExtension* healthExtension = gameObject->getExtension<HealthExtension>();

				if (healthExtension->getHealth() <= 0) {
					Scene::getInstance().removeEntity((int)gameObjectIndex);
					Physics::getInstance().deleteQueue.push_back(gameObject->id);
				}
			}
		}
	}

	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	if (Scene::getInstance().getPlayer()) {
		handlePlayerControls();

		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension)))
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->updateState();
	}

	for (const auto& gameObject : Scene::getInstance().getGameObjects()) {
		if (gameObject.second != nullptr && gameObject.second->hasExtension(typeid(AnimationExtension)))
			gameObject.second->getExtension<AnimationExtension>()->animate();
	}

	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		AbstractManageableItem* currentWeapon = Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getCurrentItem();
		if (currentWeapon != NULL) {
			_weapon->text = "WEAPON: " + currentWeapon->getScreenName();

			if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::CROSSHAIR))
				Mouse::getInstance().setCursor(MouseSkins::CROSSHAIR);

			for (std::string cheat : Scene::getInstance().activatedCheats) {
				if (cheat == "unlimitedammo" || currentWeapon->getScreenName() == "GLUE GUN")
					_ammo->text = "AMMO: INFINITE";
			}

			if (_ammo->text != "AMMO: INFINITE") {
				if (currentWeapon->getAmmo() == -1) {
					long difference = Utilities::getInstance().convertTimeToLong(std::chrono::steady_clock::now()) - currentWeapon->getLastUsed();
					if (difference == 0 && currentWeapon->getScreenName() != "GLUE GUN")
						_ammo->text = "COOLDOWN: READY";
					else if (difference >= currentWeapon->getCooldown())
						_ammo->text = "COOLDOWN: READY";
					else
						_ammo->text = "COOLDOWN: RECHARGING";
				}
				else {
					long cooldown = Utilities::getInstance().convertTimeToLong(std::chrono::steady_clock::now()) - currentWeapon->getLastUsed();
					if (cooldown == 0)
						_ammo->text = "AMMO: " + std::to_string(currentWeapon->getAmmo());
					else if (cooldown < currentWeapon->getCooldown())
						_ammo->text = "COOLDOWN: RECHARGING";
					else if (cooldown >= currentWeapon->getCooldown())
						_ammo->text = "AMMO: " + std::to_string(currentWeapon->getAmmo());
				}

			}
		}
		else {
			if (!Mouse::getInstance().isCurrentMouseSkin(MouseSkins::NONE))
				Mouse::getInstance().setCursor(MouseSkins::NONE);
			_weapon->text = "WEAPON: NONE";
			_ammo->text = "AMMO:";
		}
	}
	_score->text = "SCORE: " + std::to_string(Scene::getInstance().score);

	updateFpsElement();
}

void GameScreen::handlePlayerControls() {
	const Uint8* keystate = Utilities::getInstance().getKeyboardState();

	Scancode walkLeft;
	if (ControllManager::getInstance().walkLeftKey.isDefault)
		walkLeft = ControllManager::getInstance().walkLeftKey.defaultScanKey;
	else
		walkLeft = ControllManager::getInstance().walkLeftKey.userScanKey;

	if (keystate[walkLeft]) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension))) {
			MoveExtension* moveExtension = Scene::getInstance().getPlayer()->getExtension<MoveExtension>();
			if (moveExtension->leftArmCounter <= 0)
				moveExtension->moveX(-5);
		}
	}

	Scancode walkRight;
	if (ControllManager::getInstance().walkRightKey.isDefault)
		walkRight = ControllManager::getInstance().walkRightKey.defaultScanKey;
	else
		walkRight = ControllManager::getInstance().walkRightKey.userScanKey;

	if (keystate[walkRight]) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension))) {
			MoveExtension* moveExtension = Scene::getInstance().getPlayer()->getExtension<MoveExtension>();
			if (moveExtension->rightArmCounter <= 0)
				moveExtension->moveX(5);
		}
	}

	Scancode stop;
	if (ControllManager::getInstance().stopKey.isDefault)
		stop = ControllManager::getInstance().stopKey.defaultScanKey;
	else
		stop = ControllManager::getInstance().stopKey.userScanKey;

	if (keystate[stop])
		Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->moveX(0);

	Scancode jump;
	if (ControllManager::getInstance().jumpKey.isDefault)
		jump = ControllManager::getInstance().jumpKey.defaultScanKey;
	else
		jump = ControllManager::getInstance().jumpKey.userScanKey;

	if (keystate[jump]) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension))) {
			MoveExtension* moveExtension = Scene::getInstance().getPlayer()->getExtension<MoveExtension>();
			if (moveExtension->canJump()) {
				moveExtension->moveY(-5);
				SoundPlayer::getInstance().playSFX("Player_Jump");
			}
		}
	}
}

void GameScreen::handleKeyboardInput(KeyboardEvent e) {
	Scancode firstGun;

	if (ControllManager::getInstance().equipPortalKey.isDefault)
		firstGun = ControllManager::getInstance().equipPortalKey.defaultScanKey;
	else
		firstGun = ControllManager::getInstance().equipPortalKey.userScanKey;

	Scancode secondGun;
	if (ControllManager::getInstance().equipThrusterKey.isDefault)
		secondGun = ControllManager::getInstance().equipThrusterKey.defaultScanKey;
	else
		secondGun = ControllManager::getInstance().equipThrusterKey.userScanKey;

	Scancode thirdGun;
	if (ControllManager::getInstance().equipGlueKey.isDefault)
		thirdGun = ControllManager::getInstance().equipGlueKey.defaultScanKey;
	else
		thirdGun = ControllManager::getInstance().equipGlueKey.userScanKey;

	if (e.scanCode == firstGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(0);
	}
	else if (e.scanCode == secondGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(1);
	}
	else if (e.scanCode == thirdGun) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(2);
	}

	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;
	
	switch (e.keyCode) {
	case KEY_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	case KEY_4:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(3);

		break;
	case KEY_5:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(4);

		break;
	case KEY_6:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(5);

		break;
	case KEY_7:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(6);

		break;
	case KEY_8:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(7);

		break;
	case KEY_9:
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension)))
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->setCurrentItemIndex(8);

		break;
	case KEY_TAB:
		_game->switchScreen(Screens::Cheat);
		break;
	case KEY_PAGEUP:
		if (Scene::getInstance().tickRate + 10 <= 250)
			Scene::getInstance().tickRate = Scene::getInstance().tickRate + 10;
		break;
	case KEY_PAGEDOWN:
		if (Scene::getInstance().tickRate - 10 > 0)
			Scene::getInstance().tickRate = Scene::getInstance().tickRate - 10;
		break;
	case KEY_HOME:
		Scene::getInstance().tickRate = 60.0;
		break;
	case KEY_p:
		_game->reset();
	case KEY_KP_PLUS:
		if(Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
		break;
	case KEY_KP_MINUS:
	if (Scene::getInstance().zoom > 10)
		Scene::getInstance().zoom -= 3.0f;
	default:
		break;
	}
}

void GameScreen::handleMouseClickInput(MouseButtonEvent e) {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		CanWieldExtension* wieldExtension = Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>();

		switch (e.button) {
		case BUTTON_LEFT:
			wieldExtension->onLeftClick(e.x, e.y);

			break;
		case BUTTON_RIGHT:
			wieldExtension->onRightClick(e.x, e.y);

			break;
		}
	}
}

void GameScreen::handleMouseWheelInput(MouseWheelEvent e) {
	if (e.y > 0) {
		// Put code for handling "scroll up" here!
		if (Scene::getInstance().zoom < 60)
			Scene::getInstance().zoom += 3.0f;
	}
	else if (e.y < 0) {
		// Put code for handling "scroll down" here!
		if (Scene::getInstance().zoom > 10)
			Scene::getInstance().zoom -= 3.0f;
	}
}

void GameScreen::preRender(const unique_ptr<Window>& window) {
	_backgroundImg->preRender(window);

	for (const unique_ptr<AbstractUiElement>& uiElement : _gameUiElements)
		uiElement->preRender(window);

	AbstractScreen::preRender(window);
}

void GameScreen::render(const unique_ptr<Window>& window) {
	_backgroundImg->render(window);

	Scene::getInstance().render(window);

	for(const unique_ptr<AbstractUiElement>& uiElement : _gameUiElements)
		uiElement->render(window);

	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		if (Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getCurrentItem() != nullptr)
			Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getCurrentItem()->render(window);
	}
}

void GameScreen::reset() {
	AbstractScreen::reset();
	Scene::getInstance().reset();

	Physics::getInstance().reset();
	setupGame();
}