#include "pch.h"
#include "GameObject.h"
#include "Physics.h"

GameObject::GameObject() {
	currentState = 0;
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
		metersToPixels((position.x - (body.width / 2))),
		metersToPixels((position.y - (body.height / 2))),
		metersToPixels(body.width),
		metersToPixels(body.height)
	};
	float radians = body.b2body->GetAngle();
	float degrees = radians * (180.0f / 3.141592653589793238463f);
	bool flipLeft = false;
	if (hasExtension(typeid(MoveExtension)))
		flipLeft = Physics::getInstance().isMovingLeft(body);

	window->renderTexture(textures[currentState], rect, degrees, flipLeft);
}

int GameObject::metersToPixels(float value) {
	return (int)(50.0f * value);
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

void GameObject::addTexture(int state, std::string textureKey) {
	textures.insert(std::pair<int, std::string>(state, textureKey));
}


