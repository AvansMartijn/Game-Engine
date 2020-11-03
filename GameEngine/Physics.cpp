#include "pch.h"
#include "Physics.h"

Physics Physics::instance;

Physics::Physics(){
    _gravity = { 0.0f, 10.0f };
    reset();
}

void Physics::step(float timeStep, int velocityIterations, int positionIterations) {
    _world->Step(timeStep, velocityIterations, positionIterations);
    executeTeleportQueue();
}

void Physics::increaseCanJumpCounter() {
    _canJumpCounter++;
}

void Physics::decreaseCanJumpCounter() {
    _canJumpCounter--;
}

bool Physics::playerCanJump() {
    return _canJumpCounter > 0;
}

shared_ptr<GameObject> Physics::getGameObject(int index) {
    return _gameObjects[index];
}

void Physics::addGameObject(int index, shared_ptr<GameObject> obj){
    _gameObjects.insert(std::pair<int, shared_ptr<GameObject>>(index, obj));
}

void Physics::addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    CustomUserData* userData = new CustomUserData;
    userData->index = _gameObjects.size() + 1;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;
    
    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    CustomUserData* data1 = new CustomUserData;
    data1->type = "fixture";
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data1);
    body->CreateFixture(&fixtureDef);

    box.SetAsBox(obj->body.width / 4, obj->body.height / 2, b2Vec2(0, 0.01f), 0);
    fixtureDef.isSensor = true;

    CustomUserData* data2 = new CustomUserData;
    data2->type = "jumpSensor";
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data2);
    body->CreateFixture(&fixtureDef);

    addGameObject(userData->index, obj);
}

void Physics::addPortal(shared_ptr<GameObject> obj, float x, float y, float width, float height) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_staticBody;
    CustomUserData* userData = new CustomUserData;
    userData->index = _gameObjects.size() + 1;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.isSensor = true;
    CustomUserData* data1 = new CustomUserData;
    data1->type = "portalSensor";
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data1);
    body->CreateFixture(&fixtureDef);

    addGameObject(userData->index, obj);
}

void Physics::addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
    obj->body.width = width;
    obj->body.height = height;
    

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    CustomUserData* userData = new CustomUserData;
    userData->index = _gameObjects.size() + 1;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    if(!fixed)
        bodyDef.type = b2_dynamicBody;

    if (fixedRotation)
        bodyDef.fixedRotation = true;

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = friction;

    CustomUserData* data = new CustomUserData;
    data->type = "fixture";
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data);

    body->CreateFixture(&fixtureDef);
    addGameObject(userData->index, obj);
}

bool Physics::isMovingLeft(Body body) {
    return body.b2body->GetLinearVelocity().x < -2;
}

void Physics::executeTeleportQueue() {
    for (size_t i = 0; i < teleportQueue.size(); i++) {
        TeleportObject teleportObject = teleportQueue.back();

        teleportQueue.pop_back();

        b2Vec2 newPosition = { teleportObject.to->body.b2body->GetPosition().x, teleportObject.to->body.b2body->GetPosition().y };
        
        // TODO: Decide which side we have to fall though.
        // TODO: Keep the velocity.
        // TODO: Decide exact height
        newPosition.y += teleportObject.from->body.height + (teleportObject.to->body.height / 4);

        teleportObject.from->body.b2body->SetTransform(newPosition, teleportObject.from->body.b2body->GetAngle());
    }
}

void Physics::reset() {
    _canJumpCounter = 0;
    _world = new b2World(_gravity);
    _world->SetContactListener(&_colListener);
}
//void Physics::UpdatePositions() {
//    for (shared_ptr<GameObject>& obj : updatePositionList) {
//        obj->body.b2body->SetTransform({ 0, 0 }, 0);
//    }
//}

