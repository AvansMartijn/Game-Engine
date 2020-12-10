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
#include <map>
#include "AnimationExtension.h"

using namespace std;
class Window;
class GAMEENGINE_GameObject GameObject
{
private:
	vector<shared_ptr<AbstractGameObjectExtension>> _gameObjectExtensions;
public:
	GameObject();

	Body body;
	int id;

	std::string texture;

	void addExtension(shared_ptr<AbstractGameObjectExtension> extension);
	bool hasExtension(const std::type_info& type);
	shared_ptr<AbstractGameObjectExtension> getExtension(const std::type_info& type);

	/// <summary>
	/// Renders the game object.
	/// </summary>
	/// <param name="window">The window which we use to draw.</param>
	void render(const unique_ptr<Window>& window);

	/// <summary>
	/// Converts meters to pixels.
	/// </summary>
	/// <param name="value">The amount of meters to convert.</param>
	/// <returns>The value in pixels.</returns>
	int metersToPixels(float value);

	template<typename T>
	std::shared_ptr<T> getExtension() {
		const std::type_info& typeId = typeid(T);

		std::shared_ptr<AbstractGameObjectExtension> baseExtension = getExtension(typeId);

		if (baseExtension == nullptr)
			return nullptr;

		return dynamic_pointer_cast<T>(baseExtension);
	}
};

