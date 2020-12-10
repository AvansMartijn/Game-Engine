#pragma once
#include "AbstractGameObjectExtension.h";

class EnemyTextureExtension : public AbstractGameObjectExtension 
{
public:
	EnemyTextureExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new EnemyTextureExtension(); }

	void calculateTextures();
};

