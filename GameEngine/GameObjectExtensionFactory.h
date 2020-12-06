#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GameObjectExtensionFactory __declspec(dllexport)
#else
#define GAMEENGINE_GameObjectExtensionFactory __declspec(dllimport)
#endif
#include "GameObject.h"
#include "AbstractGameObjectExtension.h"

#include <vector>
#include <map>
#include <string>


using namespace std;

class GAMEENGINE_GameObjectExtensionFactory GameObjectExtensionFactory
{
private:
    GameObjectExtensionFactory();
    GameObjectExtensionFactory(const GameObjectExtensionFactory&) { }
    GameObjectExtensionFactory& operator=(const GameObjectExtensionFactory&) { return *this; }

    typedef map<string, CreateExtensionFn> FactoryMap;

    FactoryMap _m_FactoryMap;

public:
    ~GameObjectExtensionFactory() { _m_FactoryMap.clear(); }

    static GameObjectExtensionFactory* get()
    {
        static GameObjectExtensionFactory instance;
        return &instance;
    }

    void registerExtension(const string& extensionName, CreateExtensionFn pfnCreate);

    AbstractGameObjectExtension* createExtension(const string& extensionName);

};




