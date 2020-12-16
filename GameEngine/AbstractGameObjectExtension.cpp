#include "pch.h"
#include "AbstractGameObjectExtension.h"
#include <map>

void AbstractGameObjectExtension::registerSubject(GameObject* subject) {
	_subject = subject;
}

void AbstractGameObjectExtension::fillProperties(std::map<std::string, ExtensionProperty> properties) {}