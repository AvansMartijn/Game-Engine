#include "pch.h"
#include "GlueManageableItem.h"
#include "Scene.h"
#include <iostream>
#include "GameObjectFacade.h"
#include "Physics.h"

GlueManagableItem::GlueManagableItem() {
	_textureKey = "DIY_Weapon";
}

void GlueManagableItem::onLeftClick(int x, int y) {
	b2Vec2 playerPos = Scene::getInstance().getPlayer()->body.b2body->GetPosition();
	playerPos.x = Scene::getInstance().metersToPixels(playerPos.x);
	playerPos.y = Scene::getInstance().metersToPixels(playerPos.y);
	b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

	x = x + diffs.x;
	y = y + diffs.y;

	double angleRad = atan2(x - playerPos.x, y - playerPos.y);
	double angleDeg = angleRad * (180.0f / M_PI);

	std::cout << "x: " << x << " | " << "y: " << y << " angle degrees: " << angleDeg << std::endl;
	GameObjectFacade gameEngine;
	shared_ptr<GameObject> gameObject = gameEngine.createGameObject({});

	std::map<int, std::string> textures;
	textures.insert(pair<int, std::string>(0, "Blob"));

	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	//Physics::getInstance().addBody(gameObject, x, y, 1.0f, 1.0f, 0.3f, fixed, false);
	Physics::getInstance().addBody(gameObject, Scene::getInstance().pixelsToMeters(playerPos.x), Scene::getInstance().pixelsToMeters(playerPos.y), 1.0f, 1.0f, 0.3f, false, false, true, "glueBullet");
	Scene::getInstance().addGameObject(gameObject);

	int force = 50;
	b2Vec2 vect = b2Vec2(sin(angleDeg * (b2_pi / 180)) * force, cos(angleDeg * (b2_pi / 180)) * force);
	gameObject->body.b2body->ApplyLinearImpulseToCenter(vect, true);


}

void GlueManagableItem::onRightClick(int x, int y) {
	std::cout << "x: " << x << " | " << "y: " << y << std::endl;
}