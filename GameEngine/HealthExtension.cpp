#include "pch.h"
#include "HealthExtension.h"


HealthExtension::HealthExtension()
{
	type = "HealthExtension";
	//default health is 100;
	_health = 100;
}

int HealthExtension::getHealth() {
	return _health;
}

void HealthExtension::setHealth(int value) {
	_health = value;
}

void HealthExtension::reduceHealth(int value) {
	_health -= value;
}
