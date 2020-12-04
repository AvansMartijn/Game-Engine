#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_HealthExtension __declspec(dllexport)
#else
#define GAMEENGINE_HealthExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"


class GAMEENGINE_HealthExtension HealthExtension : public AbstractGameObjectExtension
{
private:
	int _health;
public:
	HealthExtension();
	int getHealth();
	void setHealth(int value);
	void reduceHealth(int value);
	static AbstractGameObjectExtension* __stdcall create() { return new HealthExtension(); }
};

