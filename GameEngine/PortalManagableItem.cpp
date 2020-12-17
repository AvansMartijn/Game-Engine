#include "pch.h"
#include "PortalManagableItem.h"
#include "Scene.h"
#include <iostream>
#include "GameObjectFacade.h"
#include "Physics.h"

PortalManagableItem::PortalManagableItem() {
	_textureKey = "PortalGun";
	_screenName = "PORTAL GUN";
	//default ammo and cooldown
	_ammo = -1;
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
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension))) {
			MoveExtension* moveExtension = Scene::getInstance().getPlayer()->getExtension<MoveExtension>();

			moveExtension->resetAfkTime();
			moveExtension->currentMovementType = MovementType::IDLE;
		}

		auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _lastUsed).count();
		if (timePassed >= _cooldown) {
			_lastUsed = std::chrono::steady_clock::now();
			Vec2 playerPos = Scene::getInstance().getPlayer()->body.getPosition();
			playerPos.x = Scene::getInstance().metersToPixels(playerPos.x);
			playerPos.y = Scene::getInstance().metersToPixels(playerPos.y);
			b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

			x += (int)diffs.x;
			y += (int)diffs.y;

			double angleRad = atan2(x - playerPos.x, y - playerPos.y);
			double angleDeg = angleRad * (180.0f / M_PI);

			GameObjectFacade gameEngine;
			unique_ptr<GameObject> gameObject = gameEngine.createGameObject({});

			if (fixtureUserData == "portalAbullet")
				gameObject->texture = "Portal1";
			else
				gameObject->texture = "Portal2";

			gameObject->id = Scene::getInstance().getNextAvailableId();

			//Physics::getInstance().addBody(gameObject, x, y, 1.0f, 1.0f, 0.3f, fixed, false);
			Physics::getInstance().addBody(gameObject.get(), Scene::getInstance().pixelsToMeters(playerPos.x), Scene::getInstance().pixelsToMeters(playerPos.y), 0.5f, 0.5f, 0.3f, false, true, true, fixtureUserData);

			int force = 50;
			Vec2 vect = Vec2((float)sin(angleDeg * (b2_pi / 180)) * force, (float)cos(angleDeg * (b2_pi / 180)) * force);
			gameObject->body.applyLinearImpulseToCenter(vect, true);
			if (_ammo > 0)
				_ammo -= 1;
			Scene::getInstance().addGameObject(std::move(gameObject));

		}
	}
}

std::unique_ptr<AbstractManageableItem> PortalManagableItem::clone() const {
	return std::make_unique<PortalManagableItem>(*this);;
}