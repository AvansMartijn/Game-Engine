#include "pch.h"
#include "DummyManagableItem.h"
#include "Scene.h"
#include <iostream>

// TODO: KAN DEZE WEG?
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
}

void DummyManagableItem::onRightClick(int x, int y) {}