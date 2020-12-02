#include "pch.h"
#include "GameObject.h"
#include "Physics.h"

GameObject::GameObject() {
	currentState = "";
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
	// calc camera offset
	b2Vec2 playerPos = Scene::getInstance().getPlayer()->body.b2body->GetPosition();
	playerPos.x = metersToPixels(playerPos.x);
	playerPos.y = metersToPixels(playerPos.y);
	b2Vec2 diffs = { playerPos.x - (window->getWidth() / 2), playerPos.y - (window->getHeight() / 2) };
	std::shared_ptr<GameObject> player = Scene::getInstance().getPlayer();

	//get object position
	b2Vec2 position = body.b2body->GetPosition();
	Rect rect = {
		Scene::getInstance().metersToPixels((position.x - (body.width / 2))),
		Scene::getInstance().metersToPixels((position.y - (body.height / 2))),
		Scene::getInstance().metersToPixels(body.width),
		Scene::getInstance().metersToPixels(body.height)
	};
	float radians = body.b2body->GetAngle();
	float degrees = radians * (180.0f / 3.141592653589793238463f);

	if (player) {
		// calc camera offset
		b2Vec2 playerPos = player->body.b2body->GetPosition();
		playerPos.x = metersToPixels(playerPos.x);
		playerPos.y = metersToPixels(playerPos.y);
		b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

		//apply camera offset
		rect.x -= diffs.x;
		rect.y -= diffs.y;
	}

	//render
	window->renderTexture(texture, rect, degrees, false, currentState);
}


int GameObject::metersToPixels(float value) {
	return (int)(Scene::getInstance().zoom * value);
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