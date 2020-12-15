#include "MartijnModeCheat.h"
#include <Scene.h>

bool MartijnModeCheat::execute() {
    Scene::getInstance().tickRate = 60.0;
    return true;
}
