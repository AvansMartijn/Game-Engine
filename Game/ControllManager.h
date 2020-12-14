#pragma once
#include <string>
#include "KeybindingData.h"

class ControllManager {
private:
	ControllManager();
	static ControllManager _instance;
public:
	KeybindingData toggleFPSKey;
	KeybindingData walkLeftKey;
	KeybindingData walkRightKey;
	KeybindingData stopKey;
	KeybindingData jumpKey;
	KeybindingData equipPortalKey;
	KeybindingData equipThrusterKey;
	KeybindingData equipGlueKey;

	static ControllManager& getInstance() { return _instance; }
	
	ControllManager(const ControllManager&) = delete;
	ControllManager(ControllManager&&) = delete;
	ControllManager& operator=(const ControllManager&) = delete;
	ControllManager& operator=(ControllManager&&) = delete;

	/// <summary>
	/// Resets the controls.
	/// </summary>
	void resetControls();

	/// <summary>
	/// Saves the controls.
	/// </summary>
	void saveControls();

	/// <summary>
	/// Checks if the given key is valid.
	/// </summary>
	/// <param name="key">The scancode.</param>
	/// <param name="action">The action.</param>
	/// <returns>If the key is valid.</returns>
	bool validKey(const SDL_Scancode& key, const std::string& action);

	/// <summary>
	/// Register all the controls.
	/// </summary>
	void initializeControls();

	/// <summary>
	/// Update the controls.
	/// </summary>
	/// <param name="action">The action</param>
	/// <param name="userKey">The user key.</param>
	/// <param name="userSDLKey">The user scancode.</param>
	void updateControl(const std::string& action, const std::string& userKey, const SDL_Scancode& userSDLKey);
};