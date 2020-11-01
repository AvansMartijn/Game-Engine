#include "pch.h"
#include "GameObject.h"
#include "Physics.h"
#include "MoveExtension.h"


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
	b2Vec2 position = body.b2body->GetPosition();
	Rect rect = {
		MetersToPixels((position.x - (body.width / 2))),
		MetersToPixels((position.y - (body.height / 2))),
		MetersToPixels(body.width),
		MetersToPixels(body.height)
	};
	float radians = body.b2body->GetAngle();
	double degrees = radians * (180.0 / 3.141592653589793238463);
	bool flipLeft = false;
	if (hasExtension(typeid(MoveExtension))) {
		Physics ph;
		flipLeft = ph.IsMovingLeft(body);
	}
	window->renderTexture(textureKey, rect, degrees, flipLeft);
}

int GameObject::MetersToPixels(float value) {
	return (int)50.0f * value;
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


