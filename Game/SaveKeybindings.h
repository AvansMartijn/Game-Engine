#pragma once
#include "KeybindingData.h"

class SaveKeybindings {
public:
	KeybindingData toggleFPSKey;
	KeybindingData walkLeftKey;
	KeybindingData walkRightKey;
	KeybindingData stopKey;
	KeybindingData jumpKey;
	KeybindingData equipPortalKey;
	KeybindingData equipThrusterKey;
	KeybindingData equipGlueKey;

	SaveKeybindings() { }
};

inline void to_json(nlohmann::json& j, const SaveKeybindings& cm) {
	j = nlohmann::json{
		{ "toggleFPSKey", cm.toggleFPSKey },
		{ "walkLeftKey", cm.walkLeftKey },
		{ "walkRightKey", cm.walkRightKey },
		{ "stopKey", cm.stopKey },
		{ "jumpKey", cm.jumpKey },
		{ "equipPortalKey", cm.equipPortalKey },
		{ "equipThrusterKey", cm.equipThrusterKey },
		{ "equipGlueKey", cm.equipGlueKey }
	};
}

inline void from_json(const nlohmann::json& j, SaveKeybindings& cm) {
	j.at("toggleFPSKey").get_to(cm.toggleFPSKey);
	j.at("walkLeftKey").get_to(cm.walkLeftKey);
	j.at("walkRightKey").get_to(cm.walkRightKey);
	j.at("stopKey").get_to(cm.stopKey);
	j.at("jumpKey").get_to(cm.jumpKey);
	j.at("equipPortalKey").get_to(cm.equipPortalKey);
	j.at("equipThrusterKey").get_to(cm.equipThrusterKey);
	j.at("equipGlueKey").get_to(cm.equipGlueKey);
}

