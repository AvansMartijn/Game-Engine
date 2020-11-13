#include "pch.h"
#include "AbstractManageableItem.h"

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
	Rect rect = {
		window->metersToPixels(x),
		window->metersToPixels(y),
		window->metersToPixels(_width),
		window->metersToPixels(_height)
	};


	window->renderTexture(_textureKey, rect, 0.0F, isLookingRight);
}

