#include "pch.h"
#include "GameObject.h"


GameObject::GameObject() {
	
}

void GameObject::addExtension(std::shared_ptr<AbstractGameObjectExtension> extension)
{
	_gameObjectExtensions.push_back(extension);
}

bool GameObject::hasExtension(const std::type_info& type)
{
	for (shared_ptr<AbstractGameObjectExtension> const& extension : _gameObjectExtensions)
	{
		string givenName = type.name();
		givenName.erase(0, 6);
		string currentName = extension->type;
		if (currentName.compare(givenName) == 0)
			return true;
	}

	return false;
}

void GameObject::render(const unique_ptr<Window>& window) {
	window->renderTexture(textureKey, { (int)b2body->GetPosition().x, (int)b2body->GetPosition().y, 100, 100});
}

std::shared_ptr<AbstractGameObjectExtension> GameObject::getExtension(const std::type_info& type) {
	for (shared_ptr<AbstractGameObjectExtension>& extension : _gameObjectExtensions)
	{
		string givenName = type.name();
		givenName.erase(0, 6);
		string currentName = extension->type;
		if (currentName.compare(givenName) == 0)
			return extension;
	}
	return nullptr;
}


