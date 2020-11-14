#include "pch.h"
#include "DummyManagableItem.h"
#include "Scene.h"
#include <iostream>

DummyManagableItem::DummyManagableItem() {
	_textureKey = "DIY_Weapon";
}

void DummyManagableItem::onLeftClick(int x, int y) {
	b2Vec2 playerPos = Scene::getInstance().getPlayer()->body.b2body->GetPosition();
	playerPos.x = Scene::getInstance().metersToPixels(playerPos.x);
	playerPos.y = Scene::getInstance().metersToPixels(playerPos.y);
	b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

	x = x + diffs.x;
	y = y + diffs.y;

	double angleRad = atan2(x - playerPos.x, y - playerPos.y);
	double angleDeg = angleRad * (180.0f / 3.141592653589793238463f);

	std::cout << "x: " << x << " | " << "y: " << y << " angle degrees: " << angleDeg << std::endl;

	//apply impulse thrust
	int force = -50;
	b2Vec2 vect = b2Vec2(sin(angleDeg * (b2_pi / 180)) * force, cos(angleDeg * (b2_pi / 180)) * force);
	Scene::getInstance().getPlayer()->body.b2body->ApplyLinearImpulseToCenter(vect, true);
}

void DummyManagableItem::onRightClick(int x, int y) {
	std::cout << "x: " << x << " | " << "y: " << y << std::endl;
}