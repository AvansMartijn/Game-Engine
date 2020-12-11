#include "CheatManager.h"
#include "GodmodeCheat.h"
#include "UnlimitedAmmoCheat.h"
#include "NoCooldownCheat.h"
#include "SonicModeCheat.h"
#include "MartijnModeCheat.h"
#include "Scene.h"
#include "FlyCheat.h"
#include "AllWeaponsCheat.h"

CheatManager CheatManager::_instance;

CheatManager::CheatManager() {}

bool CheatManager::executeCheat(std::string cheatName) {
    for (auto const& cheat : _cheatList) {
        if (cheatName == cheat.first) {
            if (cheat.second->Execute()) {
                Scene::getInstance().activatedCheats.push_back(cheat.first);
                return true;
            }
            break;
        }
    }

    return false;
}

std::map<std::string, std::string> CheatManager::getCheatInformation() {
    return _cheatInformation;
}

void CheatManager::initializeCheats() {
    GodmodeCheat godmodeCheat;
    UnlimitedAmmoCheat unlimitedAmmoCheat;
    NoCooldownCheat noCooldownCheat;
    SonicModeCheat sonicModeCheat;
    MartijnModeCheat martijnModeCheat;
    FlyCheat flyCheat;
    AllWeaponsCheat allWeaponsCheat;

    _cheatList.insert({ "godmode", std::make_unique<GodmodeCheat>(godmodeCheat) });
    _cheatInformation.insert({ "godmode","Gives the play a shitload of health, if you manage to die now you kinda deserve it. :^)" });

    _cheatList.insert({ "unlimitedammo", std::make_unique<UnlimitedAmmoCheat>(unlimitedAmmoCheat) });
    _cheatInformation.insert({ "unlimitedammo","Will give the player a unlimited amount of ammo." });

    _cheatList.insert({ "nocooldown", std::make_unique<NoCooldownCheat>(noCooldownCheat) });
    _cheatInformation.insert({ "nocooldown","Sets the cooldown of all guns to 0." });

    _cheatList.insert({ "sonicmode", std::make_unique<SonicModeCheat>(sonicModeCheat) });
    _cheatInformation.insert({ "sonicmode","Ups the game speed" });

    _cheatList.insert({ "martijnmode", std::make_unique<MartijnModeCheat>(martijnModeCheat) });
    _cheatInformation.insert({ "martijnmode","reset the game speed" });
    
    _cheatList.insert({ "flyboi", std::make_unique<FlyCheat>(flyCheat) });
    _cheatInformation.insert({ "flyboi","Allows you to fly." });

    _cheatList.insert({ "allweapons", std::make_unique<AllWeaponsCheat>(allWeaponsCheat) });
    _cheatInformation.insert({"allweapons", "Gives acces to all the weapons in the game." });
}

bool CheatManager::isCheat(std::string cheatName) {
    bool isCheat = false;
    for (auto const& cheat : _cheatList) {
        if (cheatName == cheat.first) {
            isCheat = true;

            break;
        }
    }

    return isCheat;
}
