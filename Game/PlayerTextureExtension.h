#pragma once
#include "AbstractGameObjectExtension.h";

class PlayerTextureExtension : public AbstractGameObjectExtension 
{
public:
	PlayerTextureExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new PlayerTextureExtension(); }

	void calculateTextures();
};