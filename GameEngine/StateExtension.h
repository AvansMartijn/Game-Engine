#pragma once
#include "AbstractGameObjectExtension.h"

// TODO: WAT DOEN WE HIER MEE?
class StateExtension : public AbstractGameObjectExtension {
private:
	bool _state;
public:
	/// <summary>
	/// Changes the state of the object.
	/// </summary>
	void changeState();
	static AbstractGameObjectExtension* __stdcall create() { return new StateExtension(); }
};

