#include "pch.h"
#include "AbstractManageableItem.h"
#include "Scene.h"
#include "Utilities.h"

AbstractManageableItem::AbstractManageableItem() {
	_width = 0.8f;
	_height = 0.4f;
	shouldRender = true;
}

AbstractManageableItem::~AbstractManageableItem() {}

std::string AbstractManageableItem::getTextureKey() {
	return _textureKey;
}

std::string AbstractManageableItem::getScreenName() {
	return _screenName;
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

long AbstractManageableItem::getCooldown() {
	return _cooldown;
}

long AbstractManageableItem::getLastUsed() {
	return Utilities::getInstance().convertTimeToLong(_lastUsed);
}

void AbstractManageableItem::setAmmo(int amount) {
	_ammo = amount;
}

void AbstractManageableItem::setCooldown(long cooldown) {
	_cooldown = cooldown;
}

void AbstractManageableItem::setOwner(GameObject* owner) {
	_owner = owner;
}

void AbstractManageableItem::render(const unique_ptr<Window>& window) {
	bool isLookingToLeft = _owner->hasExtension(typeid(MoveExtension)) ? _owner->getExtension<MoveExtension>()->isLookingToLeft : false;

	Vec2 position = _owner->body.getPosition();

	float x = position.x;
	if (isLookingToLeft)
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

	rect.x -= (int)diffs.x;
	rect.y -= (int)diffs.y;

	if(shouldRender)
		window->renderTexture(_textureKey, rect, 0.0F, isLookingToLeft);
}