#include "MartijnModeCheat.h"
#include <Scene.h>

bool MartijnModeCheat::Execute() {
    Scene::getInstance().tickRate = 60.0;
    return true;
}
