#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractGameObjectExtension __declspec(dllexport)
#else
#define GAMEENGINE_AbstractGameObjectExtension __declspec(dllimport)
#endif

#include <memory>
#include <iostream>

using namespace std;

class GameObject;
class GAMEENGINE_AbstractGameObjectExtension AbstractGameObjectExtension {
protected:
	shared_ptr<GameObject> _subject;
public:
	string type;
	virtual void registerSubject(shared_ptr<GameObject> subject);
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

