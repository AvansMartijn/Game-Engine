#include "pch.h"
#include "ThrusterManagableItem.h"
#include "Scene.h"
#include <iostream>

ThrusterManagableItem::ThrusterManagableItem() {
	_textureKey = "ThrusterGun";
	_screenName = "THRUSTER GUN";
	//default ammo and cooldown
	_ammo = -1;
	//cooldown in ms
	_cooldown = 5000;
}

void ThrusterManagableItem::onLeftClick(int x, int y) {
	if (_ammo > 0 || _ammo == -1) {
		if (Scene::getInstance().getPlayer()->hasExtension(typeid(MoveExtension))) {
			MoveExtension* moveExtension = Scene::getInstance().getPlayer()->getExtension<MoveExtension>();

			moveExtension->resetAfkTime();
			moveExtension->currentMovementType = MovementType::IDLE;
		}

		auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _lastUsed).count();
		if (timePassed >= _cooldown) {
			_lastUsed = std::chrono::steady_clock::now();

			b2Vec2 playerPos = Scene::getInstance().getPlayer()->body.b2body->GetPosition();
			playerPos.x = Scene::getInstance().metersToPixels(playerPos.x);
			playerPos.y = Scene::getInstance().metersToPixels(playerPos.y);
			b2Vec2 diffs = { playerPos.x - (1080 / 2), playerPos.y - (720 / 2) };

			x += (int) diffs.x;
			y += (int) diffs.y;

			double angleRad = atan2(x - playerPos.x, y - playerPos.y);
			double angleDeg = angleRad * (180.0f / 3.141592653589793238463f);

			//apply impulse thrust
			int force = -50;
			b2Vec2 vect = b2Vec2((float)sin(angleDeg * (b2_pi / 180)) * force, (float)cos(angleDeg * (b2_pi / 180)) * force);
			Scene::getInstance().getPlayer()->body.b2body->ApplyLinearImpulseToCenter(vect, true);
			if (_ammo > 0)
				_ammo -= 1;
		}
	}
}

void ThrusterManagableItem::onRightClick(int x, int y) {
	onLeftClick(x, y);
}

std::unique_ptr<AbstractManageableItem> ThrusterManagableItem::clone() const {
	return std::make_unique<ThrusterManagableItem>(*this);
}