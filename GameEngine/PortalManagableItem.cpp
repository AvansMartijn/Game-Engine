#include "pch.h"
#include "PortalManagableItem.h"
#include "Scene.h"
#include <iostream>
#include "GameObjectFacade.h"
#include "Physics.h"

PortalManagableItem::PortalManagableItem() {
	_textureKey = "DIY_Weapon";
	//default ammo and cooldown
	_ammo = 0;
	_cooldown = 0;
}

void PortalManagableItem::onLeftClick(int x, int y) {
	shootPortal("portalAbullet", x, y);


}

void PortalManagableItem::onRightClick(int x, int y) {
	shootPortal("portalBbullet", x, y);
}

void PortalManagableItem::shootPortal(std::string fixtureUserData, int x, int y) {
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

			std::cout << "x: " << x << " | " << "y: " << y << " angle degrees: " << angleDeg << std::endl;
			GameObjectFacade gameEngine;
			shared_ptr<GameObject> gameObject = gameEngine.createGameObject({});

			std::map<int, std::string> textures;
			textures.insert(pair<int, std::string>(0, "Mystical_Crystal_Flipped"));

			gameObject->textures = textures;
			gameObject->id = Scene::getInstance().getNextAvailableId();

			//Physics::getInstance().addBody(gameObject, x, y, 1.0f, 1.0f, 0.3f, fixed, false);
			Physics::getInstance().addBody(gameObject, Scene::getInstance().pixelsToMeters(playerPos.x), Scene::getInstance().pixelsToMeters(playerPos.y), 1.0f, 1.0f, 0.3f, false, true, true, fixtureUserData);
			Scene::getInstance().addGameObject(gameObject);

			int force = 50;
			b2Vec2 vect = b2Vec2(sin(angleDeg * (b2_pi / 180)) * force, cos(angleDeg * (b2_pi / 180)) * force);
			gameObject->body.b2body->ApplyLinearImpulseToCenter(vect, true);
			if (_ammo > 0) {
				_ammo -= 1;
			}
		}
	}
}