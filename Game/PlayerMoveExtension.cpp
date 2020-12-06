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
	if (keyState[SDL_SCANCODE_D])
		vel.x += 0.3f;

	if (keyState[SDL_SCANCODE_A])
		vel.x -= 0.3f;

	if (keyState[SDL_SCANCODE_SPACE])
		vel.y -= 0.5f;

	Scene::getInstance().getPlayer()->body.b2body->SetLinearVelocity(vel);
}