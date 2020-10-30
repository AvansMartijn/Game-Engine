#include "pch.h"
#include "Physics.h"

Physics::Physics(){
    gravity = { 0.0f, 40.0f };
    world = new b2World(gravity);
}

void Physics::AddBody(shared_ptr<GameObject> obj, int x, int y, bool fixed) {
    if (fixed) {
        b2BodyDef bodyDef;
        bodyDef.position.Set((float32)x, (float32)y);
        b2Body* body = world->CreateBody(&bodyDef);
        obj->b2body = body;
        b2PolygonShape box;
        box.SetAsBox(10.0f, 50.0f);
        obj->b2body->CreateFixture(&box, 0.0f);

    }
    else {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set((float32)x, (float32)y);
        b2Body* body = world->CreateBody(&bodyDef);
        obj->b2body = body;
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(100.0f, 20.0f);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        body->CreateFixture(&fixtureDef);
    }
}

