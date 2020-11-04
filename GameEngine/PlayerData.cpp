#include "pch.h"
#include "PlayerData.h"

PlayerData::PlayerData() {}

PlayerData::~PlayerData() {}

bool PlayerData::canJump() {
	return jumpCounter > 0;
}

void PlayerData::reset() {
	jumpCounter = 0;
}