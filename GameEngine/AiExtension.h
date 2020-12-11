#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AiExtension __declspec(dllexport)
#else
#define GAMEENGINE_AiExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractEntityAI.h"

/// <summary>
/// AI Capabilities
/// </summary>
class GAMEENGINE_AiExtension AiExtension : public AbstractGameObjectExtension {
public:
	std::shared_ptr<AbstractEntityAI> ai;

	AiExtension();

	/// <summary>
	/// Execute the AI.
	/// </summary>
	void execute();

	static AbstractGameObjectExtension* __stdcall create() { return new AiExtension(); }
};

