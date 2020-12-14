#include "pch.h"
#include "GameObjectExtensionFactory.h"
#include "AiExtension.h"
#include "MoveExtension.h"
#include "CollisionResolutionDefaultExtension.h"
#include "CollisionResolutionPortalExtension.h"
#include "CanWieldExtension.h"
#include "PickupExtension.h"
#include "DoesDamageExtension.h"
#include "IsPortalableExtension.h"
#include "TimerExtension.h"
#include "HealthExtension.h"
#include "AnimationExtension.h"

GameObjectExtensionFactory::GameObjectExtensionFactory() {
    registerExtension(AiExtension::getType(), &AiExtension::create);
    registerExtension(MoveExtension::getType(), &MoveExtension::create);
    registerExtension(CollisionResolutionDefaultExtension::getType(), &CollisionResolutionDefaultExtension::create);
    registerExtension(CollisionResolutionPortalExtension::getType(), &CollisionResolutionPortalExtension::create);
    registerExtension(CanWieldExtension::getType(), &CanWieldExtension::create);
    registerExtension(PickupExtension::getType(), &PickupExtension::create);
    registerExtension(DoesDamageExtension::getType(), &DoesDamageExtension::create);
    registerExtension(IsPortalableExtension::getType(), &IsPortalableExtension::create);
    registerExtension(TimerExtension::getType(), &TimerExtension::create);
    registerExtension(HealthExtension::getType(), &HealthExtension::create);
    registerExtension(AnimationExtension::getType(), &AnimationExtension::create);
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
