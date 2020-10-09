#include "GameObjectExtensionFactory.h"
#include "AiExtension.h"
#include "AttackExtension.h"
#include "MoveExtension.h"


GameObjectExtensionFactory::GameObjectExtensionFactory()
{
    registerExtension("AiExtension", &AiExtension::create);
    registerExtension("AttackExtension", &AttackExtension::create);
    registerExtension("MoveExtension", &MoveExtension::create);
}

void GameObjectExtensionFactory::registerExtension(const string& extensionName, CreateExtensionFn pfnCreate)
{
    _m_FactoryMap[extensionName] = pfnCreate;
}

AbstractGameObjectExtension* GameObjectExtensionFactory::createExtension(const string& extensionName)
{
    FactoryMap::iterator it = _m_FactoryMap.find(extensionName);
    if (it != _m_FactoryMap.end())
    {
        auto obj = it->second();
        obj->type = extensionName;
        return obj;
    }

    return NULL;
}