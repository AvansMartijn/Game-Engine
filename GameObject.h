#pragma once
#include "PhysicalBody.h"
#include "AbstractGameObjectExtension.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension> > _gameObjectExtensions;
public:
	GameObject();

	PhysicalBody physicalBody;
	// TODO: Move texturePath to an extension, we might need multiple
	std::string texturePath;

	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);
};

