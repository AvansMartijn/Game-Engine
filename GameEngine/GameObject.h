#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GameObject __declspec(dllexport)
#else
#define GAMEENGINE_GameObject __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Window.h"
#include "Body.h"
#include "MoveExtension.h"
#include <map>
#include "AnimationExtension.h"

using namespace std;
class Window;
class GAMEENGINE_GameObject GameObject {
private:
	vector<unique_ptr<AbstractGameObjectExtension>> _gameObjectExtensions;

	/// <summary>
	/// Get's an extension from type_info.
	/// </summary>
	/// <param name="type">The typeinfo for the type.</param>
	/// <returns>The extension/</returns>
	AbstractGameObjectExtension* getExtension(const std::type_info& type);
public:
	GameObject();
	GameObject(const GameObject&) = delete;
	GameObject& operator =(const GameObject&) = delete;

	Body body;
	int id;

	std::string texture;

	/// <summary>
	/// Adds an extension.
	/// </summary>
	/// <param name="extension">The extension we want to add</param>
	void addExtension(unique_ptr<AbstractGameObjectExtension> extension);

	/// <summary>
	/// Checks if the given extension is available.
	/// </summary>
	/// <param name="type">The extension we want to check for.</param>
	/// <returns>If the extension is available.</returns>
	bool hasExtension(const std::type_info& type);

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

	/// <summary>
	/// Get's all the extensions for this game object.
	/// </summary>
	/// <returns>All the extensions.</returns>
	vector<unique_ptr<AbstractGameObjectExtension>>& getExtensions();

	/// <summary>
	/// Get's the extension with the given type.
	/// </summary>
	/// <typeparam name="T">The extension type.</typeparam>
	/// <returns>The extension.</returns>
	template<typename T>
	T* getExtension() {
		const std::type_info& typeId = typeid(T);

		AbstractGameObjectExtension* baseExtension = getExtension(typeId);

		if (baseExtension == nullptr)
			return nullptr;

		return static_cast<T*>(baseExtension);
	}

	/// <summary>
	/// Get's the extension with the given type (T1).
	/// </summary>
	/// <typeparam name="T1">The return type.</typeparam>
	/// <typeparam name="T2">The type id type.</typeparam>
	/// <returns>The extension.</returns>
	template<typename T1, typename T2>
	T1* getExtension() {
		const std::type_info& typeId = typeid(T2);

		AbstractGameObjectExtension* baseExtension = getExtension(typeId);

		if (baseExtension == nullptr)
			return nullptr;

		return static_cast<T1*>(baseExtension);
	}
};

