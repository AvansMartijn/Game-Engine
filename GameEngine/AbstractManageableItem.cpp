#include "pch.h"
#include "AbstractManageableItem.h"
#include "Scene.h"

AbstractManageableItem::AbstractManageableItem() {
	_width = 0.8f;
	_height = 0.4f;
}

AbstractManageableItem::~AbstractManageableItem() {}

std::string AbstractManageableItem::getTextureKey() {
	return _textureKey;
}

float AbstractManageableItem::getWidth() {
	return _width; 
}

float AbstractManageableItem::getHeight() {
	return _height; 
}

int AbstractManageableItem::getAmmo() {
	return _ammo;
}

float AbstractManageableItem::getCooldown() {
	return _cooldown;
}

void AbstractManageableItem::setAmmo(int amount) {
	_ammo = amount;
}

void AbstractManageableItem::setCooldown(float amount) {
	_cooldown = amount;
}

void AbstractManageableItem::setOwner(shared_ptr<GameObject> owner) {
	_owner = owner;
}

void AbstractManageableItem::render(const unique_ptr<Window>& window) {
	bool isLookingRight = _owner->hasExtension(typeid(MoveExtension)) ? dynamic_pointer_cast<MoveExtension>(_owner->getExtension(typeid(MoveExtension)))->isLookingToRight : false;

	b2Vec2 position = _owner->body.b2body->GetPosition();

	float x = position.x;
	if (!isLookingRight)
		x -= (_width + (_width / 3));
	else
		x += _width / 3;
	float y = position.y - (_height / 2);

	position.x = Scene::getInstance().metersToPixels(position.x);
	position.y = Scene::getInstance().metersToPixels(position.y);
	b2Vec2 diffs = { position.x - (window->getWidth() / 2), position.y - (window->getHeight() / 2) };
	Rect rect = {
		Scene::getInstance().metersToPixels(x),
		Scene::getInstance().metersToPixels(y),
		Scene::getInstance().metersToPixels(_width),
		Scene::getInstance().metersToPixels(_height)
	};

	rect.x -= diffs.x;
	rect.y -= diffs.y;


	window->renderTexture(_textureKey, rect, 0.0F, isLookingRight);
}

