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
    for (auto const& cheat : cheatList) {
        if (cheatName == cheat.first) {
            if (cheat.second.get()->Execute()) {
                Scene::getInstance().activatedCheats.push_back(cheat.first);
                return true;
            }
            break;
        }
    }

    return false;
}

std::map<std::string, std::string> CheatManager::getCheatInformation() {
    return cheatInformation;
}

void CheatManager::initializeCheats() {
    GodmodeCheat godmodeCheat;
    UnlimitedAmmoCheat unlimitedAmmoCheat;
    NoCooldownCheat noCooldownCheat;
    SonicModeCheat sonicModeCheat;
    MartijnModeCheat martijnModeCheat;
    FlyCheat flyCheat;
    AllWeaponsCheat allWeaponsCheat;

    cheatList.insert({ "godmode", std::make_unique<GodmodeCheat>(godmodeCheat) });
    cheatInformation.insert({ "godmode","Gives the play a shitload of health, if you manage to die now you kinda deserve it. :^)" });

    cheatList.insert({ "unlimitedammo", std::make_unique<UnlimitedAmmoCheat>(unlimitedAmmoCheat) });
    cheatInformation.insert({ "unlimitedammo","Will give the player a unlimited amount of ammo." });

    cheatList.insert({ "nocooldown", std::make_unique<NoCooldownCheat>(noCooldownCheat) });
    cheatInformation.insert({ "nocooldown","Sets the cooldown of all guns to 0." });

    cheatList.insert({ "sonicmode", std::make_unique<SonicModeCheat>(sonicModeCheat) });
    cheatInformation.insert({ "sonicmode","Ups the game speed" });

    cheatList.insert({ "martijnmode", std::make_unique<MartijnModeCheat>(martijnModeCheat) });
    cheatInformation.insert({ "martijnmode","reset the game speed" });
    
    cheatList.insert({ "flyboi", std::make_unique<FlyCheat>(flyCheat) });
    cheatInformation.insert({ "flyboi","Allows you to fly." });

    cheatList.insert({ "allweapons", std::make_unique<AllWeaponsCheat>(allWeaponsCheat) });
    cheatInformation.insert({"allweapons", "Gives acces to all the weapons in the game." });
}

bool CheatManager::isCheat(std::string cheatName) {
    bool isCheat = false;
    for (auto const& cheat : cheatList) {
        if (cheatName == cheat.first) {
            isCheat = true;
            break;
        }
    }
    return isCheat;
}
