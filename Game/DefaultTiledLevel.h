#pragma once
#include "AbstractLevel.h"
#include "TiledGameObject.h"
#include <sstream>
#include <GlueManageableItem.h>
#include <ThrusterManagableItem.h>
#include <PortalManagableItem.h>
#include <CollisionResolutionPortalExtension.h>
#include <DoesDamageExtension.h>
#include <AiExtension.h>
#include "EnemyAnimationHandler.h"
#include "PlayerAnimationHandler.h"

class DefaultTiledLevel : public AbstractLevel {
private:
public:
	std::vector<TiledGameObject> gameObjects;
	int tileWidth;
	int tileHeight;

	/// <summary>
	/// Create the level.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	void createLevel(GameEngine& gameEngine);

	/// <summary>
	/// Creates the tile.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	/// <param name="tiledGameObject">The tiled game object</param>
	/// <param name="textures">The textures</param>
	/// <param name="extensions">The extensions</param>
	/// <param name="extensionProperties">The extension properties.</param>
	/// <param name="x">The x-coordinate</param>
	/// <param name="y">The y-coordinate</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height</param>
	void createTile(GameEngine& gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, std::map<std::string, ExtensionProperty> extensionProperties, float x, float y, float width, float height);

	/// <summary>
	/// Creates the object.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	/// <param name="tiledGameObject">The tiled game object</param>
	/// <param name="textures">The textures</param>
	/// <param name="extensions">The extensions</param>
	/// <param name="extensionProperties">The extension properties.</param>
	/// <param name="x">The x-coordinate</param>
	/// <param name="y">The y-coordinate</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height</param>
	void createObject(GameEngine& gameEngine, TiledGameObject& tiledGameObject, std::vector<std::string>& extensions, std::map<std::string, ExtensionProperty> extensionProperties, float x, float y, float width, float height);

	/// <summary>
	/// Get's the texture key from the path.
	/// </summary>
	/// <param name="prefix">The prefix we want to use.</param>
	/// <param name="path">The texture path.</param>
	/// <returns>The texture key.</returns>
	std::string getTextureKeyFromPath(const std::string& prefix, const std::string& path) const;
};