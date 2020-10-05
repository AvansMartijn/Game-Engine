#pragma once
#include <memory>
#include <iostream>

using namespace std;

class GameObject;
class AbstractGameObjectExtension
{
	public:
		string type;
		shared_ptr<GameObject> _subject;
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

