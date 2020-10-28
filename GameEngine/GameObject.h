#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GameObject __declspec(dllexport)
#else
#define GAMEENGINE_GameObject __declspec(dllimport)
#endif
// TODO: Mischien kan hier een facade voor worden gebruikt?
#include "PhysicalBody.h"
#include "AbstractGameObjectExtension.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Window.h"

using namespace std;

class Window;
class GAMEENGINE_GameObject GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension>> _gameObjectExtensions;
public:
	GameObject();

	PhysicalBody physicalBody;
	// TODO: Move textureKey to an extension, we might need multiple
	std::string textureKey;

	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	void render(const unique_ptr<Window>& window);

	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);
};

