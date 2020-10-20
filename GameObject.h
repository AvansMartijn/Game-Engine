#pragma once
#include "PhysicalBody.h"
#include "AbstractGameObjectExtension.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "SdlHelper.h"
#include <SDL.h>
#include "Window.h"

using namespace std;

class Window;
class GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension>> _gameObjectExtensions;
public:
	GameObject();

	PhysicalBody physicalBody;
	// TODO: Move texturePath to an extension, we might need multiple
	std::string texturePath;
	// TODO: Use facade instead of direct texture.
	SDL_Texture* texture;

	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);
	void preRender(Window* window);
};

