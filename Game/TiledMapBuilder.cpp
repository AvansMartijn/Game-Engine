#include "TiledMapBuilder.h"
using json = nlohmann::json;

TiledMapBuilder::~TiledMapBuilder() {
	if (_inputStream && _inputStream.is_open())
		_inputStream.close();
}

TiledLevel TiledMapBuilder::build(const std::string& fileLocation) {
	_inputStream.open(fileLocation);

	TiledLevel level = json::parse(_inputStream).get<TiledLevel>();
	_inputStream.close();

	return level;
}