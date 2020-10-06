#pragma once
#include <memory>
#include <iostream>

using namespace std;

class GameObject;
class AbstractGameObjectExtension
{
public:
	string type;
	virtual void registerSubject(GameObject* subject);
  
protected:
	shared_ptr<GameObject> _subject;
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

