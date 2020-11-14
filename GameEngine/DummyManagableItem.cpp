#include "pch.h"
#include "DummyManagableItem.h"
#include "Scene.h"
#include <iostream>

DummyManagableItem::DummyManagableItem() {
	_textureKey = "DIY_Weapon";
}

void DummyManagableItem::onLeftClick(int x, int y) {
	int playerX = (int)Scene::getInstance().getPlayer()->body.b2body->GetPosition().x;
	int playerY = (int)Scene::getInstance().getPlayer()->body.b2body->GetPosition().y;
	double angleDeg = atan2((x/40.0f) - playerX, (y/40.0f) - playerY) * (180.0f / 3.141592653589793238463f);

	std::cout << "x: " << x << " | " << "y: " << y << " angle degrees: " << angleDeg << std::endl;
}

void DummyManagableItem::onRightClick(int x, int y) {
	std::cout << "x: " << x << " | " << "y: " << y << std::endl;
}