#pragma once
#include "GameObject.h"
#include <memory>
#include <iostream>
using namespace std;

class AbstractGameObjectExtension
{
	public:
		//shared_ptr<GameObject> _subject;
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

