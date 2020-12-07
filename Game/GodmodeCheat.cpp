#include "GodmodeCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool GodmodeCheat::Execute()
{
	auto Player = Scene::getInstance().getPlayer();
	if (Player->hasExtension(typeid(HealthExtension)))
	{
		shared_ptr<HealthExtension> Extension = dynamic_pointer_cast<HealthExtension>(Player->getExtension(typeid(HealthExtension)));
		Extension->setHealth(MAXINT);
		return true;
	}
}
