#include "GameObject.h"

void GameObject::addExtension(std::shared_ptr<AbstractGameObjectExtension> extension)
{
    
    _gameObjectExtensions.push_back(extension);
    extension->_subject.reset(this);

}

bool GameObject::hasExtension(const std::type_info& type)
{
	bool counter = false;
	for (auto const& extension : _gameObjectExtensions) 
	{
		string givenName = type.name();
		givenName.erase(0, 6);

		string currentName = extension->type;

		cout << givenName << '\n';
		cout << currentName << '\n';

		//TODO: these 2 value are not the smae but still returns true...
		if (currentName.compare(givenName) == 0);
		{
			counter = true;
		}
	}

	return counter;
}

std::shared_ptr<AbstractGameObjectExtension> GameObject::GetExtension(const std::type_info& type) {


	for (auto& extension : _gameObjectExtensions)
	{
		if (typeid(extension) == type)
		{
			return extension;
		}
	}
	return nullptr;
}


