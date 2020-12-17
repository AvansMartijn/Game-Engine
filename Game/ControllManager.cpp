#include "ControllManager.h"
#include "GameSettings.h"
#include <Utilities.h>

ControllManager ControllManager::_instance;

ControllManager::ControllManager() {}

void ControllManager::resetControls() {
	this->toggleFPSKey.isDefault = true;
	this->toggleFPSKey.userKey.clear();
	this->toggleFPSKey.userScanKey = SCANCODE_0;

	this->walkLeftKey.isDefault = true;
	this->walkLeftKey.userKey.clear();
	this->walkLeftKey.userScanKey = SCANCODE_0;

	this->walkRightKey.isDefault = true;
	this->walkRightKey.userKey.clear();
	this->walkRightKey.userScanKey = SCANCODE_0;

	this->stopKey.isDefault = true;
	this->stopKey.userKey.clear();
	this->stopKey.userScanKey = SCANCODE_0;

	this->jumpKey.isDefault = true;
	this->jumpKey.userKey.clear();
	this->jumpKey.userScanKey = SCANCODE_0;

	this->equipPortalKey.isDefault = true;
	this->equipPortalKey.userKey.clear();
	this->equipPortalKey.userScanKey = SCANCODE_0;

	this->equipThrusterKey.isDefault = true;
	this->equipThrusterKey.userKey.clear();
	this->equipThrusterKey.userScanKey = SCANCODE_0;

	this->equipGlueKey.isDefault = true;
	this->equipGlueKey.userKey.clear();
	this->equipGlueKey.userScanKey = SCANCODE_0;
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

bool ControllManager::validKey(const Scancode& key, const std::string& action) {
	bool valid = true;

	std::vector<Scancode> invalidKeys;
	invalidKeys.push_back(Scancode::SCANCODE_ESCAPE);
	invalidKeys.push_back(Scancode::SCANCODE_GRAVE); // Grave

	if (action != "toggleFPS") {
		if (this->toggleFPSKey.isDefault)
			invalidKeys.push_back(this->toggleFPSKey.defaultScanKey);
		else
			invalidKeys.push_back(this->toggleFPSKey.userScanKey);
	} 
	else if (action != "walkLeft") {
		if (this->walkLeftKey.isDefault)
			invalidKeys.push_back(this->walkLeftKey.defaultScanKey);
		else
			invalidKeys.push_back(this->walkLeftKey.userScanKey);
	}
	else if (action != "walkRight") {
		if (this->walkRightKey.isDefault)
			invalidKeys.push_back(this->walkRightKey.defaultScanKey);
		else
			invalidKeys.push_back(this->walkRightKey.userScanKey);
	}
	else if (action != "stop") {
		if (this->stopKey.isDefault)
			invalidKeys.push_back(this->stopKey.defaultScanKey);
		else
			invalidKeys.push_back(this->stopKey.userScanKey);
	}
	else if (action != "jump") {
		if (this->jumpKey.isDefault)
			invalidKeys.push_back(this->jumpKey.defaultScanKey);
		else
			invalidKeys.push_back(this->jumpKey.userScanKey);
	}
	else if (action != "equipPortal") {
		if (this->equipPortalKey.isDefault)
			invalidKeys.push_back(this->equipPortalKey.defaultScanKey);
		else
			invalidKeys.push_back(this->equipPortalKey.userScanKey);
	}
	else if (action != "equipThruster") {
		if (this->equipThrusterKey.isDefault)
			invalidKeys.push_back(this->equipThrusterKey.defaultScanKey);
		else
			invalidKeys.push_back(this->equipThrusterKey.userScanKey);
	}
	else if (action != "equipGlue") {
		if (this->equipThrusterKey.isDefault)
			invalidKeys.push_back(this->equipGlueKey.defaultScanKey);
		else
			invalidKeys.push_back(this->equipGlueKey.userScanKey);
	}

	for (size_t i = 0; i < invalidKeys.size(); i++) {
		int key2 = invalidKeys[i];
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
		this->toggleFPSKey = KeybindingData(controls.toggleFPSKey.defaultKey, controls.toggleFPSKey.userKey, controls.toggleFPSKey.defaultScanKey, controls.toggleFPSKey.userScanKey, controls.toggleFPSKey.isDefault);
		this->walkLeftKey = KeybindingData(controls.walkLeftKey.defaultKey, controls.walkLeftKey.userKey, controls.walkLeftKey.defaultScanKey, controls.walkLeftKey.userScanKey, controls.walkLeftKey.isDefault);
		this->walkRightKey = KeybindingData(controls.walkRightKey.defaultKey, controls.walkRightKey.userKey, controls.walkRightKey.defaultScanKey, controls.walkRightKey.userScanKey, controls.walkRightKey.isDefault);
		this->stopKey = KeybindingData(controls.stopKey.defaultKey, controls.stopKey.userKey, controls.stopKey.defaultScanKey, controls.stopKey.userScanKey, controls.stopKey.isDefault);
		this->jumpKey = KeybindingData(controls.jumpKey.defaultKey, controls.jumpKey.userKey, controls.jumpKey.defaultScanKey, controls.jumpKey.userScanKey, controls.jumpKey.isDefault);
		this->equipPortalKey = KeybindingData(controls.equipPortalKey.defaultKey, controls.equipPortalKey.userKey, controls.equipPortalKey.defaultScanKey, controls.equipPortalKey.userScanKey, controls.equipPortalKey.isDefault);
		this->equipThrusterKey = KeybindingData(controls.equipThrusterKey.defaultKey, controls.equipThrusterKey.userKey, controls.equipThrusterKey.defaultScanKey, controls.equipThrusterKey.userScanKey, controls.equipThrusterKey.isDefault);
		this->equipGlueKey = KeybindingData(controls.equipGlueKey.defaultKey, controls.equipGlueKey.userKey, controls.equipGlueKey.defaultScanKey, controls.equipGlueKey.userScanKey, controls.equipGlueKey.isDefault);
	}
	else if (GameSettings::getInstance().saveGame.settings.cm.toggleFPSKey.defaultKey == "") {
		this->toggleFPSKey = KeybindingData("F3", Scancode::SCANCODE_F3);
		this->walkLeftKey = KeybindingData("A", Scancode::SCANCODE_A);
		this->walkRightKey = KeybindingData("D", Scancode::SCANCODE_D);
		this->stopKey = KeybindingData("S", Scancode::SCANCODE_S);
		this->jumpKey = KeybindingData("SPACE", Scancode::SCANCODE_SPACE);
		this->equipPortalKey = KeybindingData("1", Scancode::SCANCODE_1);
		this->equipThrusterKey = KeybindingData("2", Scancode::SCANCODE_2);
		this->equipGlueKey = KeybindingData("3", Scancode::SCANCODE_3);
	}
}

void ControllManager::updateControl(const std::string& action, const std::string& userKey, const Scancode& userScanKey) {
	if (!validKey(userScanKey, action))
		return;

	if (action == "toggleFPS") {
		this->toggleFPSKey.isDefault = false;
		this->toggleFPSKey.userKey = userKey;
		this->toggleFPSKey.userScanKey = userScanKey;
	}
	else if (action == "walkLeft") {
		this->walkLeftKey.isDefault = false;
		this->walkLeftKey.userKey = userKey;
		this->walkLeftKey.userScanKey = userScanKey;
	}
	else if (action == "walkRight") {
		this->walkRightKey.isDefault = false;
		this->walkRightKey.userKey = userKey;
		this->walkRightKey.userScanKey = userScanKey;
	}
	else if (action == "stop") {
		this->stopKey.isDefault = false;
		this->stopKey.userKey = userKey;
		this->stopKey.userScanKey = userScanKey;
	}
	else if (action == "jump") {
		this->jumpKey.isDefault = false;
		this->jumpKey.userKey = userKey;
		this->jumpKey.userScanKey = userScanKey;
	}
	else if (action == "equipPortal") {
		this->equipPortalKey.isDefault = false;
		this->equipPortalKey.userKey = userKey;
		this->equipPortalKey.userScanKey = userScanKey;
	}
	else if (action == "equipThruster") {
		this->equipThrusterKey.isDefault = false;
		this->equipThrusterKey.userKey = userKey;
		this->equipThrusterKey.userScanKey = userScanKey;
	}
	else if (action == "equipGlue") {
		this->equipGlueKey.isDefault = false;
		this->equipGlueKey.userKey = userKey;
		this->equipGlueKey.userScanKey = userScanKey;
	}
}
