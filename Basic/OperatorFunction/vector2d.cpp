#include "vector2d.h"

Vector2D::Vector2D()
{
    _x = 0;
    _y = 0;
}

Vector2D::Vector2D(int x, int y)
{
    _x = x;
    _y = y;
}

double Vector2D::operator*(Vector2D &vector2)
{
    return _x*vector2._x+_y*vector2._y;
}

Vector2D Vector2D::operator+(Vector2D &vector2)
{
    return vector2;
}
