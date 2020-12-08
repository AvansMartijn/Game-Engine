#include "CheatManager.h"
#include "GodmodeCheat.h"
#include "UnlimitedAmmoCheat.h"
#include "NoCooldownCheat.h"
#include "SonicModeCheat.h"
#include "MartijnModeCheat.h"
#include "Scene.h"

CheatManager CheatManager::_instance;

CheatManager::CheatManager() {
}

bool CheatManager::executeCheat(std::string Cheat)
{
    for (auto const& cheat : CheatList)
    {
        if (Cheat == cheat.first) {
            if (cheat.second.get()->Execute()) {
                return true;
            }
            break;
        }
    }
}

std::map<std::string, std::string> CheatManager::getCheatInformation()
{
    return CheatInformation;
}

void CheatManager::initializeCheats()
{
    GodmodeCheat godmodeCheat;
    UnlimitedAmmoCheat unlimitedAmmoCheat;
    NoCooldownCheat noCooldownCheat;
    SonicModeCheat sonicModeCheat;
    MartijnModeCheat martijnModeCheat;

    CheatList.insert({ "godmode", std::make_unique<GodmodeCheat>(godmodeCheat) });
    CheatInformation.insert({ "godmode","Gives the play a shitload of health, if you manage to die now you kinda deserve it. :^)" });

    CheatList.insert({ "unlimitedammo", std::make_unique<UnlimitedAmmoCheat>(unlimitedAmmoCheat) });
    CheatInformation.insert({ "unlimitedammo","Will give the player a unlimited amount of ammo." });

    CheatList.insert({ "nocooldown", std::make_unique<NoCooldownCheat>(noCooldownCheat) });
    CheatInformation.insert({ "nocooldown","Sets the cooldown of all guns to 0." });

    CheatList.insert({ "sonicmode", std::make_unique<SonicModeCheat>(sonicModeCheat) });
    CheatInformation.insert({ "sonicmode","Ups the game speed" });

    CheatList.insert({ "martijnmode", std::make_unique<MartijnModeCheat>(martijnModeCheat) });
    CheatInformation.insert({ "martijnmode","reset the game speed" });
}

bool CheatManager::isCheat(std::string Cheat)
{
    bool isCheat = false;
    for (auto const& cheat : CheatList)
    {
        if (Cheat == cheat.first) {
            isCheat = true;
            break;
        }
    }
    return isCheat;
}
