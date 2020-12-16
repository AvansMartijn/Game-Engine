#include "pch.h"
#include "GameObject.h"
#include "Physics.h"

GameObject::GameObject() {}

void GameObject::render(const unique_ptr<Window>& window) {
	GameObject* player = Scene::getInstance().getPlayer();

	//get object position
	Vec2 position = body.getPosition();
	Rect rect = {
		Scene::getInstance().metersToPixels((position.x - (body.width / 2))),
		Scene::getInstance().metersToPixels((position.y - (body.height / 2))),
		Scene::getInstance().metersToPixels(body.width),
		Scene::getInstance().metersToPixels(body.height)
	};
	float radians = body.getAngle();

	float degrees = radians * (180.0f / 3.141592653589793238463f);

	if (player && !Scene::getInstance().isLocked) {
		// calc camera offset
		Vec2 playerPos = player->body.getPosition();
		playerPos.x = (float)metersToPixels(playerPos.x);
		playerPos.y = (float)metersToPixels(playerPos.y);
		Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

		//apply camera offset
		rect.x -= (int)diffs.x;
		rect.y -= (int)diffs.y;
	}


	if (hasExtension(typeid(AnimationExtension))) {
		AnimationExtension* animation = getExtension<AnimationExtension>();
		if (animation->getAnimationHandler() != nullptr) {
			Rect sprite = animation->getCurrentSprite();

			window->renderSprite(texture, rect, sprite, degrees, animation->shouldFlipLeft());
		}
	}
	else
		window->renderTexture(texture, rect, degrees, false);
}

int GameObject::metersToPixels(float value) {
	return (int)(Scene::getInstance().zoom * value);
}


void GameObject::addExtension(std::unique_ptr<AbstractGameObjectExtension> extension) {
	_gameObjectExtensions.push_back(std::move(extension));
}

bool GameObject::hasExtension(const std::type_info& type) {
	for (const unique_ptr<AbstractGameObjectExtension>& extension : _gameObjectExtensions) {
		string givenName = type.name();
		givenName.erase(0, 6);
		string currentName = extension->type;
		if (currentName.compare(givenName) == 0)
			return true;
	}

	return false;
}

vector<unique_ptr<AbstractGameObjectExtension>>& GameObject::getExtensions() {
	return _gameObjectExtensions;
}

AbstractGameObjectExtension* GameObject::getExtension(const std::type_info& type) {
	for (unique_ptr<AbstractGameObjectExtension>& extension : _gameObjectExtensions) {
		string givenName = type.name();
		givenName.erase(0, 6);
		string currentName = extension->type;
		if (currentName.compare(givenName) == 0)
			return extension.get();
	}
	return nullptr;
}