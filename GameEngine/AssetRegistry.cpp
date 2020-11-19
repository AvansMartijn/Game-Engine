#include "pch.h"
#include "AssetRegistry.h"
#include "Window.h"

AssetRegistry AssetRegistry::instance;

AssetRegistry::AssetRegistry() {}

void AssetRegistry::registerTexture(std::string textureKey, SDL_Texture* texture) {
	_textures.insert(std::pair<std::string, SDL_Texture*>(textureKey, texture));
}

void AssetRegistry::registerFont(std::string fontKey, std::string fontPath) {
	_fonts.insert(std::pair<std::string, std::string>(fontKey, fontPath));
}

SDL_Texture* AssetRegistry::getTexture(std::string textureKey) {
	return _textures[textureKey];
}

std::string AssetRegistry::getFontPath(std::string fontKey) {
	return _fonts[fontKey];
}

std::string AssetRegistry::getBasePath() const {
	char currentDir[255];
	GetCurrentDirectory(255, currentDir);

	return std::string(currentDir) + "\\";
}

std::vector<FileData> AssetRegistry::getFilesInDirectory(std::string& directory, bool isDeep) const {
	std::string basePath = AssetRegistry::getInstance().getBasePath();

	DIR* dir;
	struct dirent* ent;

	std::vector<std::string> directories;
	std::vector<FileData> files;

	directories.push_back(directory);

	while (!directories.empty()) {
		std::string path = directories.back();
		directories.pop_back();
		if ((dir = opendir((basePath + path).c_str())) != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				if (ent->d_type == DT_DIR && isDeep) {
					std::string name = ent->d_name;

					if (name != "." && name != "..")
						directories.push_back(path + "/" + ent->d_name);
				}
				else if (ent->d_type != DT_DIR) {
					std::string key = path.substr(path.rfind('/') + 1) + "_" + ent->d_name;
					key.erase(key.rfind('.'));

					std::string filePath = path + "/" + ent->d_name;
					files.push_back({ key, filePath });
				}
			}
			closedir(dir);
		}
	}

	return files;
}

std::vector<std::string> AssetRegistry::split(std::string& string, char delimiter) {
	std::vector<std::string> result;

	std::stringstream ss(string);


	while (ss.good()) {
		std::string substr;
		getline(ss, substr, delimiter);

		result.push_back(substr);
	}

	return result;
}

std::string AssetRegistry::getPrefPath(std::string org, std::string app) {
	char* basePath = SDL_GetPrefPath(org.c_str(), app.c_str());
	if (basePath)
		return string(basePath);

	return "";
}