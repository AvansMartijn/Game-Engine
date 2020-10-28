#pragma once


#include "Material.h"
#include "MassData.h"
#include "Shape.h"
#include "Body.h"
#include "IEMath.h"


class PhysicalBody
{
private:
	Material _material;
	MassData _massData;

public:
	Shape shape;
	Body body;

};

