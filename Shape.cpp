#include "Shape.h"

int Shape::getWidth()
{
    return max.x - min.x;
}

int Shape::getHeight()
{
    return max.y - min.y;
}
