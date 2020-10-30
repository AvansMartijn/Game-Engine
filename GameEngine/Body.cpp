#include "pch.h"
#include "Body.h"

void Body::SetOrient(real radians)
{
    orient = radians;
    SetOrient(radians);
}

void Body::CanRotate(bool can) {
    canRotate = can;
}
