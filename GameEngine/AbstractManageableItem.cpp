#include "pch.h"
#include "AbstractManageableItem.h"
#include "Scene.h"

AbstractManageableItem::AbstractManageableItem() {
	_width = 0.8f;
	_height = 0.4f;
	shouldRender = true;
}

AbstractManageableItem::~AbstractManageableItem() {}

std::string AbstractManageableItem::getTextureKey() {
	return _textureKey;
}

std::string AbstractManageableItem::getScreemName()
{
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

long AbstractManageableItem::getLastUsed()
{
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(_lastUsed);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
	return value.count();
}

void AbstractManageableItem::setAmmo(int amount) {
	_ammo = amount;
}

void AbstractManageableItem::setCooldown(long amount) {
	_cooldown = amount;
}

void AbstractManageableItem::setOwner(shared_ptr<GameObject> owner) {
	_owner = owner;
}

void AbstractManageableItem::render(const unique_ptr<Window>& window) {
	bool isLookingToLeft = _owner->hasExtension(typeid(MoveExtension)) ? _owner->getExtension<MoveExtension>()->isLookingToLeft : false;

	b2Vec2 position = _owner->body.b2body->GetPosition();

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

	rect.x -= diffs.x;
	rect.y -= diffs.y;

	if(shouldRender)
		window->renderTexture(_textureKey, rect, 0.0F, isLookingToLeft);
}

