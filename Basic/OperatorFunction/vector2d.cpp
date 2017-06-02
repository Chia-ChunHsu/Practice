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

double Vector2D::operator*(Vector2D &Vector2)
{
    return _x*Vector2._x+_y*Vector2._y;
}

Vector2D Vector2D::operator+(Vector2D &Vector2)
{
    Vector2D result(_x+Vector2._x,_y+Vector2._y);
    return result;
}

Vector2D Vector2D::operator-(Vector2D &Vector2)
{
    Vector2D result(_x-Vector2._x,_y-Vector2._y);
    return result;
}

int Vector2D::GetPointX()
{
    return _x;
}

int Vector2D::GetPointY()
{
    return _y;
}
