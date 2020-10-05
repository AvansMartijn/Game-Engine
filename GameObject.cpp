#include "GameObject.h"

void GameObject::addExtension(std::shared_ptr<AbstractGameObjectExtension> extension)
{
    
    _gameObjectExtensions.push_back(extension);
    extension->_subject.reset(this);

}

bool GameObject::hasExtension(const std::type_info& type)
{
	//TODO: check if is statement is working
	for (auto const& extension : _gameObjectExtensions) 
	{

		cout << type.name() << '\n';

		cout << extension->type << '\n';


		if (extension->type == type.name());
		{
			return true;
		}
	}
	return false;
}

std::shared_ptr<AbstractGameObjectExtension> GameObject::GetExtension(const std::type_info& type) {


	//TODO: check if is statement is working
	for (auto& extension : _gameObjectExtensions)
	{
		if (typeid(extension) == type)
		{
			return extension;
		}
	}
	return nullptr;
}


