#pragma once
#include "json.h"
#include "TiledProperty.h"
#include <vector>
#include <string>

class TiledObject
{
private:
public:
	int height;
	int id;
	std::string name;
	std::vector<TiledProperty> properties;
	int rotation;
	std::string type;
	bool visible;
	int width;
	int x;
	int y;
};

inline void from_json(const nlohmann::json& j, TiledObject& l) {
	j.at("height").get_to(l.height);
	j.at("id").get_to(l.id);
	j.at("name").get_to(l.name);
	j.at("properties").get_to(l.properties);
	j.at("rotation").get_to(l.rotation);
	j.at("type").get_to(l.type);
	j.at("visible").get_to(l.visible);
	j.at("width").get_to(l.width);
	j.at("x").get_to(l.x);
	j.at("y").get_to(l.y);
}