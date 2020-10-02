#pragma once
#include "Material.h"
#include "MassData.h"
#include "Shape.h"
class PhysicalBody
{
private:
	Material _material;
	MassData _massData;
	Shape _shape;
};

