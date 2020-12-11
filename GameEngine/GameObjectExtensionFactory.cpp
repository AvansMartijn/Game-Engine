#include "pch.h"
#include "GameObjectExtensionFactory.h"
#include "AiExtension.h"
#include "AttackExtension.h"
#include "MoveExtension.h"
#include "CollisionResolutionDefaultExtension.h"
#include "CollisionResolutionPortalExtension.h"
#include "CheckPhysicsExtension.h"
#include "CanWieldExtension.h"
#include "PickupExtension.h"
#include "DoesDamageExtension.h"
#include "IsPortalableExtension.h"
#include "TimerExtension.h"
#include "HealthExtension.h"
#include "AnimationExtension.h"

// TODO: MAKE IT SO WE DON'T NEED TO ADD A KEY (use GetType)
GameObjectExtensionFactory::GameObjectExtensionFactory() {
    registerExtension("AiExtension", &AiExtension::create);
    registerExtension("AttackExtension", &AttackExtension::create);
    registerExtension("MoveExtension", &MoveExtension::create);
    registerExtension("CheckPhysicsExtension", &CheckPhysicsExtension::create);
    registerExtension("CollisionResolutionDefaultExtension", &CollisionResolutionDefaultExtension::create);
    registerExtension("CollisionResolutionPortalExtension", &CollisionResolutionPortalExtension::create);
    registerExtension("CanWieldExtension", &CanWieldExtension::create);
    registerExtension("PickupExtension", &PickupExtension::create);
    registerExtension("DoesDamageExtension", &DoesDamageExtension::create);
    registerExtension("IsPortalableExtension", &IsPortalableExtension::create);
    registerExtension("TimerExtension", &TimerExtension::create);
    registerExtension("HealthExtension", &HealthExtension::create);
    registerExtension("AnimationExtension", &AnimationExtension::create);
}

void GameObjectExtensionFactory::registerExtension(const string& extensionName, CreateExtensionFn pfnCreate) {
    _m_FactoryMap[extensionName] = pfnCreate;
}

AbstractGameObjectExtension* GameObjectExtensionFactory::createExtension(const string& extensionName) {
    FactoryMap::iterator it = _m_FactoryMap.find(extensionName);
    if (it != _m_FactoryMap.end()) {
        AbstractGameObjectExtension* obj = it->second();

        return obj;
    }

    return NULL;
}
