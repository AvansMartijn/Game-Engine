#include "SonicModeCheat.h"
#include "Game.h"

bool SonicModeCheat::execute() {
    Scene::getInstance().tickRate = 200.0;
    return true;
}
