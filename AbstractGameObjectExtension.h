#pragma once
#include <memory>
#include <iostream>

using namespace std;

class GameObject;
class AbstractGameObjectExtension
{
	public:
		shared_ptr<GameObject> _subject;
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

