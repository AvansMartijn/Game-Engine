#include "SonicModeCheat.h"
#include "Game.h"

bool SonicModeCheat::Execute() {
    Scene::getInstance().tickRate = 200.0;
    return true;
}
