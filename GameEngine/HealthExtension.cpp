#include "pch.h"
#include "HealthExtension.h"
#include "GameObject.h"

HealthExtension::HealthExtension() {
	type = getType();
	_health = 100;
}

int HealthExtension::getHealth() {
	return _health;
}

void HealthExtension::setHealth(int value) {
	_health = value;
}

void HealthExtension::reduceHealth(int value) {
	if (_subject->hasExtension(typeid(MoveExtension)))
		_subject->getExtension<MoveExtension>()->currentMovementType = MovementType::HURTING;

	_health -= value;
}

void HealthExtension::fillProperties(std::map<std::string, ExtensionProperty> extensionProperties) {
	if (extensionProperties.find("health") != extensionProperties.end())
		_health = extensionProperties["health"].valueInt;
}
