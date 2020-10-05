#include "GameObject.h"

void GameObject::addExtension(std::shared_ptr<AbstractGameObjectExtension> extension)
{
    
    _gameObjectExtensions.push_back(extension);
    extension->_subject.reset(this);

}

bool GameObject::hasExtension(const std::type_info& type)
{
	bool counter = false;
	//TODO: check if is statement is working
	for (auto const& extension : _gameObjectExtensions) 
	{
		string name = type.name();
		name = name.erase(0, 6);

		cout << name << '\n';
		cout << extension->type << '\n';


		//TODO: these 2 value are not the smae but still returns true...
		if (extension->type == name);
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


