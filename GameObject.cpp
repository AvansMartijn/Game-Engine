#include "GameObject.h"


GameObject::GameObject() {

	//_gridPositionX = NULL;
	//_gridPositionY = NULL;
	//_height = NULL;
	//_width = NULL;

	//_physicalBody = NULL;
}

void GameObject::addExtension(std::shared_ptr<AbstractGameObjectExtension> extension)
{
    _gameObjectExtensions.push_back(extension);
	extension->_subject.reset(this);
}

bool GameObject::hasExtension(const std::type_info& type)
{
	
	for (auto const& extension : _gameObjectExtensions) 
	{
		string givenName = type.name();
		givenName.erase(0, 6);

		string currentName = extension->type;

		if (currentName.compare(givenName) == 0)
		{
			return true;
		}
	}

	return false;
}

std::shared_ptr<AbstractGameObjectExtension> GameObject::GetExtension(const std::type_info& type) {


	for (auto& extension : _gameObjectExtensions)
	{
		string givenName = type.name();
		givenName.erase(0, 6);

		string currentName = extension->type;

		if (currentName.compare(givenName) == 0)
		{
			return extension;
		}
	}
	return nullptr;
}


