#include "pch.h"
#include "Physics.h"
#include "EntityCategory.h"
#include "CollisionResolutionPortalExtension.h"
#include "TimerExtension.h"

Physics Physics::instance;

Physics::Physics(){
    _gravity = { 0.0f, 10.0f };

    reset();
}

void Physics::step(float timeStep, int velocityIterations, int positionIterations) {
    _world->Step(timeStep, velocityIterations, positionIterations);
    executeDeleteQueue();
    executeTeleportQueue();
    executeSetStaticQueue();
    executeRotateQueue();
    executeExpirationQueue();
}

void Physics::addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    CustomUserData* userData = new CustomUserData;
    userData->index = obj->id;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;
    
    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = CHARACTER;
    fixtureDef.filter.maskBits = SCENERY | CHARACTER | PORTAL;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    CustomUserData* data1 = new CustomUserData;
    data1->type = "playerFixture";
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data1);
    body->CreateFixture(&fixtureDef);

    box.SetAsBox(obj->body.width / 2.1f, obj->body.height / 2, b2Vec2(0, 0.05f), 0);
    fixtureDef.isSensor = true;

    CustomUserData* data2 = new CustomUserData;
    data2->type = "jumpSensor";
    fixtureDef.shape = &box;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data2);
    body->CreateFixture(&fixtureDef);

    b2CircleShape wheelShape;
    wheelShape.m_radius = 0.05f;
    wheelShape.m_p = { 0 - (obj->body.width / 2), 0 + (obj->body.height / 2) };
    b2FixtureDef wheelFix;
    wheelFix.filter.categoryBits = CHARACTER;
    wheelFix.filter.maskBits = SCENERY | CHARACTER;
    wheelFix.shape = &wheelShape;
    CustomUserData* data3 = new CustomUserData;
    data3->type = "feetWheel";
    wheelFix.userData.pointer = reinterpret_cast<uintptr_t>(data3);
    body->CreateFixture(&wheelFix);

    b2CircleShape wheelShape2;
    wheelShape2.m_radius = 0.05f;
    wheelShape2.m_p = { 0 + (obj->body.width / 2), 0 + (obj->body.height / 2) };
    wheelFix.shape = &wheelShape2;
    wheelFix.userData.pointer = reinterpret_cast<uintptr_t>(data3);
    body->CreateFixture(&wheelFix);

    box.SetAsBox(obj->body.width / 2, obj->body.height / 2.1f, b2Vec2(-0.05f, 0), 0);
    b2FixtureDef wheelFix2;
    wheelFix2.filter.categoryBits = CHARACTER;
    wheelFix2.filter.maskBits = SCENERY | CHARACTER;
    wheelFix2.shape = &box;
    wheelFix2.isSensor = true;
    CustomUserData* data5 = new CustomUserData;
    data5->type = "leftArmSensor";
    wheelFix2.userData.pointer = reinterpret_cast<uintptr_t>(data5);
    body->CreateFixture(&wheelFix2);

    box.SetAsBox(obj->body.width / 2, obj->body.height / 2.1f, b2Vec2(0.05f, 0), 0);
    wheelFix2.shape = &box;
    CustomUserData* data4 = new CustomUserData;
    data4->type = "rightArmSensor";
    wheelFix2.userData.pointer = reinterpret_cast<uintptr_t>(data4);
    body->CreateFixture(&wheelFix2);
}

void Physics::addEntity(shared_ptr<GameObject> obj, float x, float y, float width, float height, std::string userDataType) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;

    CustomUserData* userData = new CustomUserData;
    userData->index = obj->id;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = SCENERY;
    fixtureDef.filter.maskBits = -1;

    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    CustomUserData* data = new CustomUserData;
    data->type = userDataType;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data);
    body->CreateFixture(&fixtureDef);

    b2CircleShape wheelShape;
    wheelShape.m_radius = 0.05f;
    wheelShape.m_p = { 0 - (obj->body.width / 2), 0 + (obj->body.height / 2) };
    b2FixtureDef wheelFix;
    wheelFix.shape = &wheelShape;
    CustomUserData* data3 = new CustomUserData;
    data3->type = "feetWheel";
    wheelFix.userData.pointer = reinterpret_cast<uintptr_t>(data3);
    body->CreateFixture(&wheelFix);

    b2CircleShape wheelShape2;
    wheelShape2.m_radius = 0.05f;
    wheelShape2.m_p = { 0 + (obj->body.width / 2), 0 + (obj->body.height / 2) };
    wheelFix.shape = &wheelShape2;
    wheelFix.userData.pointer = reinterpret_cast<uintptr_t>(data3);
    body->CreateFixture(&wheelFix);
}

void Physics::addNonRigidBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, std::string userDataType) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_staticBody;
    CustomUserData* userData = new CustomUserData;
    userData->index = obj->id;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    if (userDataType == "portalSensor") {
        fixtureDef.filter.categoryBits = PORTAL;
        fixtureDef.filter.maskBits = SCENERY | CHARACTER;
    }
    else {
        fixtureDef.filter.categoryBits = SCENERY;
        fixtureDef.filter.maskBits = -1;
    }
    fixtureDef.shape = &box;
    fixtureDef.isSensor = true;
    CustomUserData* data1 = new CustomUserData;
    data1->type = userDataType;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data1);
    body->CreateFixture(&fixtureDef);
}

void Physics::addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation, bool isBullet, std::string userDataType) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    CustomUserData* userData = new CustomUserData;
    userData->index = obj->id;
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(userData);

    if(!fixed)
        bodyDef.type = b2_dynamicBody;

    if (fixedRotation)
        bodyDef.fixedRotation = true;

    if (isBullet)
        bodyDef.bullet = true;

    b2Body* body = _world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    if (isBullet) {
        fixtureDef.filter.categoryBits = BULLET;
        fixtureDef.filter.maskBits = SCENERY | BULLET;
    }
    else {
        fixtureDef.filter.categoryBits = SCENERY;
        fixtureDef.filter.maskBits = -1;
    }
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = friction;

    CustomUserData* data = new CustomUserData;
    data->type = userDataType;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(data);

    body->CreateFixture(&fixtureDef);
}

void Physics::executeTeleportQueue() {
    for (size_t i = 0; i < teleportQueue.size(); i++) {
        TeleportObject teleportObject = teleportQueue.back();
        
        teleportQueue.pop_back();

        b2Vec2 newPosition = { teleportObject.newPosition.x, teleportObject.newPosition.y };

        teleportObject.obj->body.b2body->SetTransform(newPosition, teleportObject.obj->body.b2body->GetAngle());
        if (teleportObject.hasSpeed)
            teleportObject.obj->body.b2body->SetLinearVelocity({ teleportObject.newSpeed.x, teleportObject.newSpeed.y });
    }
}

void Physics::executeDeleteQueue() {
    while (!deleteQueue.empty()) {
        int id = deleteQueue.back();

        deleteQueue.pop_back();

        shared_ptr<GameObject> gameObject = Scene::getInstance().getGameObject(id);
        if (gameObject != nullptr)
            _world->DestroyBody(gameObject->body.b2body);

        Scene::getInstance().removeGameObject(id);
    }
}

void Physics::executeSetStaticQueue() {
    while (!setStaticQueue.empty()) {
        setStaticQueue.back()->body.b2body->SetType(b2_staticBody);
        setStaticQueue.pop_back();
    }
}

void Physics::executeRotateQueue() {
    while (!rotateQueue.empty()) {
        RotateObj rotateObj = rotateQueue.back();
        rotateObj.obj->body.b2body->SetTransform(rotateObj.obj->body.b2body->GetPosition(), rotateObj.angleRad);
        rotateQueue.pop_back();
    }
}

void Physics::executeExpirationQueue() {
    for (int i = 0; i < expirationQueue.size(); i++) {
        int id = expirationQueue.at(i);
        auto body = Scene::getInstance().getGameObject(id);
        if (Scene::getInstance().getGameObject(id)->hasExtension(typeid(TimerExtension))) {
            auto extension = Scene::getInstance().getGameObject(id)->getExtension<TimerExtension>();
            if (extension->isExpired()) {
                expirationQueue.erase(expirationQueue.begin()+ i);
                _world->DestroyBody(Scene::getInstance().getGameObject(id)->body.b2body);
                Scene::getInstance().removeGameObject(id);
            }
        }
    }
}

void Physics::setContactListener(shared_ptr<AbstractContactListener> contactListener) {
    _colListener = contactListener;

    reset();
}

void Physics::reset() {
    clearAllQueues();
    _world = new b2World(_gravity);

    if (_colListener != nullptr)
        _world->SetContactListener(_colListener.get());
}

void Physics::clearAllQueues() {
    deleteQueue.clear();
    teleportQueue.clear();
    expirationQueue.clear();
    rotateQueue.clear();
    setStaticQueue.clear();
}

Vec2 Physics::getLinearVelocity(shared_ptr<GameObject> gameObject) {
    auto linVel = gameObject->body.b2body->GetLinearVelocity();

    return { linVel.x, linVel.y };
}

void Physics::setLinearVelocity(shared_ptr<GameObject> gameObject, const Vec2& vel) {
    gameObject->body.b2body->SetLinearVelocity({ vel.x, vel.y });
}

Vec2 Physics::getPosition(shared_ptr<GameObject> gameObject) {
    auto position = gameObject->body.b2body->GetPosition();

    return { position.x, position.y };
}
