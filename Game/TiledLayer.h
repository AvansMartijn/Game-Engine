#pragma once
#include "json.h"
#include "TiledObject.h"

class TiledLayer {
public:
	int height;
	int id;
	std::string name;
	int opacity;
	std::string type;
	bool visible;
	int width;
	int x;
	int y;
	std::vector<uint32_t> tileGIDs;
	std::vector<TiledObject> objects;
};

inline void from_json(const nlohmann::json& j, TiledLayer& l) {
	j.at("id").get_to(l.id);
	j.at("name").get_to(l.name);
	j.at("opacity").get_to(l.opacity);
	j.at("type").get_to(l.type);
	j.at("visible").get_to(l.visible);

	j.at("x").get_to(l.x);
	j.at("y").get_to(l.y);

	if (l.type != "objectgroup") {
		j.at("width").get_to(l.width);
		j.at("height").get_to(l.height);
		
		// Convert data to GIDs
		std::vector<uint32_t> data = j.at("data").get<std::vector<uint32_t>>();
		for (size_t x = 0; x < data.size(); x++) {
			uint32_t gid = data[x];

			// Apply flags to the data uint
			gid &= ~(0x80000000 | 0x40000000 | 0x20000000);

			l.tileGIDs.push_back(gid);
		}
	}
	else {
		j.at("objects").get_to(l.objects);
	}
}