#include "CheatManager.h"
#include "GodmodeCheat.h"
#include "UnlimitedAmmoCheat.h"
#include "NoCooldownCheat.h"

CheatManager CheatManager::_instance;

CheatManager::CheatManager() {
}

void CheatManager::executeCheat(std::string Cheat)
{
    for (auto const& cheat : CheatList)
    {
        if (Cheat == cheat.first) {
            cheat.second.get()->Execute();
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

    CheatList.insert({ "godmode", std::make_unique<GodmodeCheat>(godmodeCheat) });
    CheatInformation.insert({ "godmode","Will make the player in invulnerable." });

    CheatList.insert({ "unlimitedammo", std::make_unique<UnlimitedAmmoCheat>(unlimitedAmmoCheat) });
    CheatInformation.insert({ "unlimitedammo","Will give the player a unlimited amount of glue gun ammo." });

    CheatList.insert({ "nocooldown", std::make_unique<NoCooldownCheat>(noCooldownCheat) });
    CheatInformation.insert({ "nocooldown","Sets the thrustergun cooldown to 0." });
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
