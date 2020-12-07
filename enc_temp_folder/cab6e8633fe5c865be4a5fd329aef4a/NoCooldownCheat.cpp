#include "NoCooldownCheat.h"
#include "Scene.h"

void NoCooldownCheat::Execute()
{
	auto gun1 = Scene::getInstance().getWieldExtension().get()[0];
}
