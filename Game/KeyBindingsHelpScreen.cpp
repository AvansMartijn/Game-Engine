#include "KeyBindingsHelpScreen.h"

void KeyBindingsHelpScreen::loadKeybinding()
{
	if (ControllManager::getInstance().toggleFPSKey.isDefault) {
		_fpsKey->text = ControllManager::getInstance().toggleFPSKey.defaultKey;
	} 
	else {
		_fpsKey->text = ControllManager::getInstance().toggleFPSKey.userKey;
	}

	if (ControllManager::getInstance().walkLeftKey.isDefault) {
		_walkLeftKey->text = ControllManager::getInstance().walkLeftKey.defaultKey;
	}
	else {
		_walkLeftKey->text = ControllManager::getInstance().walkLeftKey.userKey;
	}

	if (ControllManager::getInstance().walkRightKey.isDefault) {
		_walkRightKey->text = ControllManager::getInstance().walkRightKey.defaultKey;
	}
	else {
		_walkRightKey->text = ControllManager::getInstance().walkRightKey.userKey;
	}

	if (ControllManager::getInstance().stopKey.isDefault) {
		_stopKey->text = ControllManager::getInstance().stopKey.defaultKey;
	}
	else {
		_stopKey->text = ControllManager::getInstance().stopKey.userKey;
	}

	if (ControllManager::getInstance().jumpKey.isDefault) {
		_jumpKey->text = ControllManager::getInstance().jumpKey.defaultKey;
	}
	else {
		_jumpKey->text = ControllManager::getInstance().jumpKey.userKey;
	}

	if (ControllManager::getInstance().equipPortalKey.isDefault) {
		_equipPortalGunKey->text = ControllManager::getInstance().equipPortalKey.defaultKey;
	}
	else {
		_equipPortalGunKey->text = ControllManager::getInstance().equipPortalKey.userKey;
	}

	if (ControllManager::getInstance().equipThrusterKey.isDefault) {
		_equipThrusterGunKey->text = ControllManager::getInstance().equipThrusterKey.defaultKey;
	}
	else {
		_equipThrusterGunKey->text = ControllManager::getInstance().equipThrusterKey.userKey;
	}

	if (ControllManager::getInstance().equipGlueKey.isDefault) {
		_equipGlueGunKey->text = ControllManager::getInstance().equipGlueKey.defaultKey;
	}
	else {
		_equipGlueGunKey->text = ControllManager::getInstance().equipGlueKey.userKey;
	}
}

void KeyBindingsHelpScreen::changeText(shared_ptr<TextUiElement> text)
{
	if (_listingForInput)
		loadKeybinding();
	text->text = "PUSH KEY";
}

KeyBindingsHelpScreen::KeyBindingsHelpScreen() {}

KeyBindingsHelpScreen::~KeyBindingsHelpScreen() {}

void KeyBindingsHelpScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "OpenSans";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Keybindings", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, true);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	//LABELS LEFT
	TextUiElement fpsHeader = TextUiElement("FPS", font, 25, { 350, 100, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(fpsHeader));

	TextUiElement fpsText = TextUiElement("Toggle FPS Counter", font, 20, { 375, 140, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(fpsText));

	TextUiElement movementHeader = TextUiElement("MOVEMENT", font, 25, { 350, 180, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(movementHeader));

	TextUiElement walkLeftText = TextUiElement("Walk Left", font, 20, { 375, 220, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(walkLeftText));

	TextUiElement walkRightText = TextUiElement("Walk Right", font, 20, { 375, 260, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(walkRightText));

	TextUiElement stopText = TextUiElement("Stop", font, 20, { 375, 300, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(stopText));

	TextUiElement jumpText = TextUiElement("Jump", font, 20, { 375, 340, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(jumpText));

	TextUiElement weaponsHeader = TextUiElement("WEAPONS", font, 25, { 350, 380, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(weaponsHeader));

	TextUiElement equipPortalGunText = TextUiElement("Equip First Gun", font, 20, { 375, 420, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(equipPortalGunText));

	TextUiElement equipThrusterGunText = TextUiElement("Equip Second Gun", font, 20, { 375, 460, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(equipThrusterGunText));

	TextUiElement equipGlueGunText = TextUiElement("Equip Third Gun", font, 20, { 375, 500, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(equipGlueGunText));

	//LABELS RIGHT
	_fpsKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 140, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_fpsKey);

	_walkLeftKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 220, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_walkLeftKey);

	_walkRightKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 260, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_walkRightKey);

	_stopKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 300, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_stopKey);

	_jumpKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 340, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_jumpKey);

	_equipPortalGunKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 420, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_equipPortalGunKey);

	_equipThrusterGunKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 460, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_equipThrusterGunKey);

	_equipGlueGunKey = make_shared<TextUiElement>(TextUiElement(" ", font, 20, { 600, 500, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false));
	_uiElements.push_back(_equipGlueGunKey);

	//BUTTONS
	ButtonUiElement toggleFPSButton = ButtonUiElement("Change", { 750, 135, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	toggleFPSButton.onClick = [this](AbstractGame* game) { _listingForInput = true, _currentAction = "toggleFPS"; changeText(_fpsKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(toggleFPSButton));

	ButtonUiElement walkLeftButton = ButtonUiElement("Change", { 750, 215, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	walkLeftButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "walkLeft"; changeText(_walkLeftKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(walkLeftButton));

	ButtonUiElement walkRightButton = ButtonUiElement("Change", { 750, 255, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	walkRightButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "walkRight"; changeText(_walkRightKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(walkRightButton));

	ButtonUiElement stopButton = ButtonUiElement("Change", { 750, 295, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	stopButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "stop"; changeText(_stopKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(stopButton));

	ButtonUiElement jumpButton = ButtonUiElement("Change", { 750, 335, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	jumpButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "jump"; changeText(_jumpKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(jumpButton));

	ButtonUiElement equipPortalButton = ButtonUiElement("Change", { 750, 415, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	equipPortalButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "equipPortal"; changeText(_equipPortalGunKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(equipPortalButton));

	ButtonUiElement equipThrusterButton = ButtonUiElement("Change", { 750, 455, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	equipThrusterButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "equipThruster"; changeText(_equipThrusterGunKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(equipThrusterButton));

	ButtonUiElement equipGlueButton = ButtonUiElement("Change", { 750, 495, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	equipGlueButton.onClick = [this](AbstractGame* game) { _listingForInput = true; _currentAction = "equipGlue"; changeText(_equipGlueGunKey); };
	_uiElements.push_back(make_shared<ButtonUiElement>(equipGlueButton));

	ButtonUiElement resetButton = ButtonUiElement("Reset All", { 350, 545, 70, 30 }, bgColor, { 255, 255, 255 }, font, 20);
	resetButton.onClick = [this](AbstractGame* game) { ControllManager::getInstance().resetControls(); loadKeybinding();};
	_uiElements.push_back(make_shared<ButtonUiElement>(resetButton));

	ButtonUiElement backButton = ButtonUiElement("Save & Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); ControllManager::getInstance().saveControls();};
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	loadKeybinding();

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}

void KeyBindingsHelpScreen::onScreenShowed(vector<std::string> args)
{
	loadKeybinding();
}

void KeyBindingsHelpScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void KeyBindingsHelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	if (_listingForInput)
	{
		std::string keyPressed = SDL_GetScancodeName(e.keysym.scancode);
		SDL_Scancode KeyPressedSDL = e.keysym.scancode;
		_listingForInput = false;
		
		ControllManager::getInstance().updateControl(_currentAction, keyPressed, KeyPressedSDL);
		loadKeybinding();
	}

	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void KeyBindingsHelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void KeyBindingsHelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}