#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GameObject __declspec(dllexport)
#else
#define GAMEENGINE_GameObject __declspec(dllimport)
#endif
//#include "PhysicalBody.h"
#include "AbstractGameObjectExtension.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Window.h"
#include <Box2D.h>
#include "Body.h"
#include "MoveExtension.h"

using namespace std;
class Window;
class GAMEENGINE_GameObject GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension>> _gameObjectExtensions;
public:
	GameObject();
	Body body;

	//PhysicalBody physicalBody;
	// TODO: Move textureKey to an extension, we might need multiple
	// TODO: State to texture map
	std::string textureKey;

	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	void render(const unique_ptr<Window>& window);
	int MetersToPixels(float value);

	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);
};

