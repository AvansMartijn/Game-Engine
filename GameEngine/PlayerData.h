#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_PlayerData __declspec(dllexport)
#else
#define GAMEENGINE_PlayerData __declspec(dllimport)
#endif
class GAMEENGINE_PlayerData PlayerData
{
public:
	PlayerData();
	~PlayerData();
	int jumpCounter;

	/// <summary>
	/// Checks if the player can jump.
	/// </summary>
	/// <returns>If the player can jump.</returns>
	bool canJump();

	/// <summary>
	/// Resets the player data.
	/// </summary>
	void reset();
};

