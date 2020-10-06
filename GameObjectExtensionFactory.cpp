#include "GameObjectExtensionFactory.h"
#include "AiExtension.h"
#include "AttackExtension.h"


GameObjectExtensionFactory::GameObjectExtensionFactory()
{
    Register("AiExtension", &AiExtension::Create);
    Register("AttackExtension", &AttackExtension::Create);
}

void GameObjectExtensionFactory::Register(const string& extensionName, CreateExtensionFn pfnCreate)
{
    _m_FactoryMap[extensionName] = pfnCreate;
}

AbstractGameObjectExtension* GameObjectExtensionFactory::CreateExtension(const string& extensionName)
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