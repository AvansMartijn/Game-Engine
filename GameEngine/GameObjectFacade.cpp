#include "pch.h"
#include "GameObjectFacade.h"

shared_ptr<GameObject> GameObjectFacade::CreateGameObject(vector<string> extensionNames)
{
	builder.buildGameObject();
	builder.addExtension(extensionNames);
	return builder.getResult();
}
