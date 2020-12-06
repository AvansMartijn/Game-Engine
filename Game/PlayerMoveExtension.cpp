#include "PlayerMoveExtension.h"
#include <Scene.h>

PlayerMoveExtension::PlayerMoveExtension() {
	type = "PlayerMoveExtension";
}

void PlayerMoveExtension::move() {
	// Haal de huidige velocity op.
	b2Vec2 vel = Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity();
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	// TODO: Movement

}