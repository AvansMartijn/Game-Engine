#include "ControllManager.h"
#include "GameSettings.h"

ControllManager ControllManager::_instance;

ControllManager::ControllManager() {}

void ControllManager::resetControls() {
	this->toggleFPSKey.isDefault = true;
	this->toggleFPSKey.userKey.clear();
	this->toggleFPSKey.userSDLKey = SDL_SCANCODE_0;

	this->walkLeftKey.isDefault = true;
	this->walkLeftKey.userKey.clear();
	this->walkLeftKey.userSDLKey = SDL_SCANCODE_0;

	this->walkRightKey.isDefault = true;
	this->walkRightKey.userKey.clear();
	this->walkRightKey.userSDLKey = SDL_SCANCODE_0;

	this->stopKey.isDefault = true;
	this->stopKey.userKey.clear();
	this->stopKey.userSDLKey = SDL_SCANCODE_0;

	this->jumpKey.isDefault = true;
	this->jumpKey.userKey.clear();
	this->jumpKey.userSDLKey = SDL_SCANCODE_0;

	this->equipPortalKey.isDefault = true;
	this->equipPortalKey.userKey.clear();
	this->equipPortalKey.userSDLKey = SDL_SCANCODE_0;

	this->equipThrusterKey.isDefault = true;
	this->equipThrusterKey.userKey.clear();
	this->equipThrusterKey.userSDLKey = SDL_SCANCODE_0;

	this->equipGlueKey.isDefault = true;
	this->equipGlueKey.userKey.clear();
	this->equipGlueKey.userSDLKey = SDL_SCANCODE_0;
}

void ControllManager::saveControls() {
	SaveKeybindings kb;
	kb.toggleFPSKey = this->toggleFPSKey;
	kb.walkLeftKey = this->walkLeftKey;
	kb.walkRightKey = this->walkRightKey;
	kb.stopKey = this->stopKey;
	kb.jumpKey = this->jumpKey;
	kb.equipPortalKey = this->equipPortalKey;
	kb.equipThrusterKey = this->equipThrusterKey;
	kb.equipGlueKey = this->equipGlueKey;

	GameSettings::getInstance().saveGame.settings.cm = kb;
	GameSettings::getInstance().save();
}

bool ControllManager::validKey(const SDL_Scancode& key, const std::string& action) {
	bool valid = true;
	std::vector<SDL_Scancode> invalidKeys;
	invalidKeys.push_back(SDL_SCANCODE_ESCAPE);
	invalidKeys.push_back(SDL_SCANCODE_GRAVE);

	if (action != "toggleFPS") {
		if (this->toggleFPSKey.isDefault)
			invalidKeys.push_back(this->toggleFPSKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->toggleFPSKey.userSDLKey);
	} 
	else if (action != "walkLeft") {
		if (this->walkLeftKey.isDefault)
			invalidKeys.push_back(this->walkLeftKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->walkLeftKey.userSDLKey);
	}
	else if (action != "walkRight") {
		if (this->walkRightKey.isDefault)
			invalidKeys.push_back(this->walkRightKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->walkRightKey.userSDLKey);
	}
	else if (action != "stop") {
		if (this->stopKey.isDefault)
			invalidKeys.push_back(this->stopKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->stopKey.userSDLKey);
	}
	else if (action != "jump") {
		if (this->jumpKey.isDefault)
			invalidKeys.push_back(this->jumpKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->jumpKey.userSDLKey);
	}
	else if (action != "equipPortal") {
		if (this->equipPortalKey.isDefault)
			invalidKeys.push_back(this->equipPortalKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->equipPortalKey.userSDLKey);
	}
	else if (action != "equipThruster") {
		if (this->equipThrusterKey.isDefault)
			invalidKeys.push_back(this->equipThrusterKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->equipThrusterKey.userSDLKey);
	}
	else if (action != "equipGlue") {
		if (this->equipThrusterKey.isDefault)
			invalidKeys.push_back(this->equipGlueKey.defaultSDLKey);
		else
			invalidKeys.push_back(this->equipGlueKey.userSDLKey);
	}

	for (size_t i = 0; i < invalidKeys.size(); i++) {
		SDL_Scancode key2 = invalidKeys[i];
		if (key2 == key) {
			valid = false;
			break;
		}
	}

	return valid;
}

void ControllManager::initializeControls() {
	SaveKeybindings controls = GameSettings::getInstance().saveGame.settings.cm;
	if (GameSettings::getInstance().saveGame.settings.cm.toggleFPSKey.defaultKey != "") {
		this->toggleFPSKey = KeybindingData(controls.toggleFPSKey.defaultKey, controls.toggleFPSKey.userKey, controls.toggleFPSKey.defaultSDLKey, controls.toggleFPSKey.userSDLKey, controls.toggleFPSKey.isDefault);
		this->walkLeftKey = KeybindingData(controls.walkLeftKey.defaultKey, controls.walkLeftKey.userKey, controls.walkLeftKey.defaultSDLKey, controls.walkLeftKey.userSDLKey, controls.walkLeftKey.isDefault);
		this->walkRightKey = KeybindingData(controls.walkRightKey.defaultKey, controls.walkRightKey.userKey, controls.walkRightKey.defaultSDLKey, controls.walkRightKey.userSDLKey, controls.walkRightKey.isDefault);
		this->stopKey = KeybindingData(controls.stopKey.defaultKey, controls.stopKey.userKey, controls.stopKey.defaultSDLKey, controls.stopKey.userSDLKey, controls.stopKey.isDefault);
		this->jumpKey = KeybindingData(controls.jumpKey.defaultKey, controls.jumpKey.userKey, controls.jumpKey.defaultSDLKey, controls.jumpKey.userSDLKey, controls.jumpKey.isDefault);
		this->equipPortalKey = KeybindingData(controls.equipPortalKey.defaultKey, controls.equipPortalKey.userKey, controls.equipPortalKey.defaultSDLKey, controls.equipPortalKey.userSDLKey, controls.equipPortalKey.isDefault);
		this->equipThrusterKey = KeybindingData(controls.equipThrusterKey.defaultKey, controls.equipThrusterKey.userKey, controls.equipThrusterKey.defaultSDLKey, controls.equipThrusterKey.userSDLKey, controls.equipThrusterKey.isDefault);
		this->equipGlueKey = KeybindingData(controls.equipGlueKey.defaultKey, controls.equipGlueKey.userKey, controls.equipGlueKey.defaultSDLKey, controls.equipGlueKey.userSDLKey, controls.equipGlueKey.isDefault);
	}
	else if (GameSettings::getInstance().saveGame.settings.cm.toggleFPSKey.defaultKey == "") {
		this->toggleFPSKey = KeybindingData("F3", SDL_SCANCODE_F3);
		this->walkLeftKey = KeybindingData("A", SDL_SCANCODE_A);
		this->walkRightKey = KeybindingData("D", SDL_SCANCODE_D);
		this->stopKey = KeybindingData("S", SDL_SCANCODE_S);
		this->jumpKey = KeybindingData("SPACE", SDL_SCANCODE_SPACE);
		this->equipPortalKey = KeybindingData("1", SDL_SCANCODE_1);
		this->equipThrusterKey = KeybindingData("2", SDL_SCANCODE_2);
		this->equipGlueKey = KeybindingData("3", SDL_SCANCODE_3);
	}
}

void ControllManager::updateControl(const std::string& action, const std::string& userKey, const SDL_Scancode& userSDLKey) {
	if (!validKey(userSDLKey, action))
		return;

	if (action == "toggleFPS") {
		this->toggleFPSKey.isDefault = false;
		this->toggleFPSKey.userKey = userKey;
		this->toggleFPSKey.userSDLKey = userSDLKey;
	}
	else if (action == "walkLeft") {
		this->walkLeftKey.isDefault = false;
		this->walkLeftKey.userKey = userKey;
		this->walkLeftKey.userSDLKey = userSDLKey;
	}
	else if (action == "walkRight") {
		this->walkRightKey.isDefault = false;
		this->walkRightKey.userKey = userKey;
		this->walkRightKey.userSDLKey = userSDLKey;
	}
	else if (action == "stop") {
		this->stopKey.isDefault = false;
		this->stopKey.userKey = userKey;
		this->stopKey.userSDLKey = userSDLKey;
	}
	else if (action == "jump") {
		this->jumpKey.isDefault = false;
		this->jumpKey.userKey = userKey;
		this->jumpKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipPortal") {
		this->equipPortalKey.isDefault = false;
		this->equipPortalKey.userKey = userKey;
		this->equipPortalKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipThruster") {
		this->equipThrusterKey.isDefault = false;
		this->equipThrusterKey.userKey = userKey;
		this->equipThrusterKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipGlue") {
		this->equipGlueKey.isDefault = false;
		this->equipGlueKey.userKey = userKey;
		this->equipGlueKey.userSDLKey = userSDLKey;
	}
}
