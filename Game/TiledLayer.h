#pragma once
#include "json.h"

class TiledLayer
{
private:

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
};

inline void from_json(const nlohmann::json& j, TiledLayer& l) {
	j.at("height").get_to(l.height);
	j.at("id").get_to(l.id);
	j.at("name").get_to(l.name);
	j.at("opacity").get_to(l.opacity);
	j.at("type").get_to(l.type);
	j.at("visible").get_to(l.visible);
	j.at("width").get_to(l.width);
	j.at("x").get_to(l.x);
	j.at("y").get_to(l.y);

	// Convert data to GIDs
	std::vector<uint32_t> data = j.at("data").get<std::vector<uint32_t>>();
	for (size_t x = 0; x < data.size(); x++) {
		uint32_t gid = data[x];

		// Apply flags to the data uint
		gid &= ~(0x80000000 | 0x40000000 | 0x20000000);

		l.tileGIDs.push_back(gid);
	}

}