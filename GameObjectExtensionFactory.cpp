#include "GameObjectExtensionFactory.h"
#include "AiExtension.h"
#include "AttackExtension.h"


GameObjectExtensionFactory::GameObjectExtensionFactory()
{
    Register("Ai", &AiExtension::Create);
    Register("Attack", &AttackExtension::Create);
}

void GameObjectExtensionFactory::Register(const string& extensionName, CreateExtensionFn pfnCreate)
{
    m_FactoryMap[extensionName] = pfnCreate;
}

AbstractGameObjectExtension* GameObjectExtensionFactory::CreateExtension(const string& extensionName)
{
    FactoryMap::iterator it = m_FactoryMap.find(extensionName);
    if (it != m_FactoryMap.end())
        return it->second();
    return NULL;
}