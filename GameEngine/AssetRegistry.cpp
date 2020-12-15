#include "pch.h"
#include "AssetRegistry.h"
#include "Window.h"

AssetRegistry AssetRegistry::instance;

AssetRegistry::AssetRegistry() {}

void AssetRegistry::registerTexture(const std::string& textureKey, std::shared_ptr<SDLTexture> texture) {
	_textures.insert(std::pair<std::string, std::shared_ptr<SDLTexture>>(textureKey, texture));
}

void AssetRegistry::registerFont(const std::string& fontKey, const std::string& fontPath) {
	_fonts.insert(std::pair<std::string, std::string>(fontKey, fontPath));
}

std::shared_ptr<SDLTexture> AssetRegistry::getTexture(const std::string& textureKey) {
	return _textures[textureKey];
}

std::string AssetRegistry::getFontPath(const std::string& fontKey) {
	return _fonts[fontKey];
}

std::string AssetRegistry::getBasePath() const {
	char currentDir[255];
	GetCurrentDirectory(255, currentDir);

	return std::string(currentDir) + "\\";
}

std::vector<FileData> AssetRegistry::getFilesInDirectory(const std::string& basePath, const std::string& directory, bool isDeep, bool shouldAddKey) const {
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
					std::string key = ent->d_name;

					if (shouldAddKey)
						key = path.substr(path.rfind('/') + 1) + "_" + key;

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

std::string AssetRegistry::getPrefPath(const std::string& org, const std::string& app) const {
	char* basePath = SDL_GetPrefPath(org.c_str(), app.c_str());
	if (basePath)
		return string(basePath);

	return "";
}