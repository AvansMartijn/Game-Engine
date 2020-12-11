#include "pch.h"
#include "GlueManageableItem.h"
#include "Scene.h"
#include <iostream>
#include "GameObjectFacade.h"
#include "Physics.h"

GlueManagableItem::GlueManagableItem() {
	_textureKey = "GlueGun";
	_screenName = "GLUE GUN";
	//default ammo and cooldown
	_ammo = -1;
	_cooldown = 500;

}

void GlueManagableItem::onLeftClick(int x, int y) {
	if (_ammo > 0 || _ammo == -1) {
		auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _lastUsed).count();
		if (timePassed >= _cooldown) {
			_lastUsed = std::chrono::steady_clock::now();
			b2Vec2 playerPos = Scene::getInstance().getPlayer()->body.b2body->GetPosition();
			playerPos.x = Scene::getInstance().metersToPixels(playerPos.x);
			playerPos.y = Scene::getInstance().metersToPixels(playerPos.y);
			b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

			x = x + diffs.x;
			y = y + diffs.y;

			double angleRad = atan2(x - playerPos.x, y - playerPos.y);
			double angleDeg = angleRad * (180.0f / M_PI);

			//std::cout << "x: " << x << " | " << "y: " << y << " angle degrees: " << angleDeg << "ammo: " << _ammo << std::endl;
			GameObjectFacade gameEngine;
			shared_ptr<GameObject> gameObject = gameEngine.createGameObject({"TimerExtension"});


			gameObject->texture = "Blob";
			gameObject->id = Scene::getInstance().getNextAvailableId();

			//Physics::getInstance().addBody(gameObject, x, y, 1.0f, 1.0f, 0.3f, fixed, false);
			Physics::getInstance().addBody(gameObject, Scene::getInstance().pixelsToMeters(playerPos.x), Scene::getInstance().pixelsToMeters(playerPos.y), 0.5f, 0.5f, 0.3f, false, false, true, "glueBullet");
			Scene::getInstance().addGameObject(gameObject);
			Physics::getInstance().expirationQueue.push_back(gameObject->id);

			int force = 30;
			b2Vec2 vect = b2Vec2(sin(angleDeg * (b2_pi / 180)) * force, cos(angleDeg * (b2_pi / 180)) * force);
			gameObject->body.b2body->ApplyLinearImpulseToCenter(vect, true);
			if (_ammo > 0) {
				_ammo -= 1;
			}
		}
	}

}

void GlueManagableItem::onRightClick(int x, int y) {
	onLeftClick(x, y);
}