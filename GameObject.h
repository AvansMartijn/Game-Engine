#pragma once
#include <vector>
#include "PhysicalBody.h"
#include <memory>
#include <iostream>
#include "AbstractGameObjectExtension.h"
using namespace std;


class GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension> > _gameObjectExtensions;
public:
	PhysicalBody physicalBody;
	GameObject();
	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);
};

