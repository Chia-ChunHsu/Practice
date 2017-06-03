#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#define PI 3.1415926535

template<class VarType>class Vector2D
{
public:
    Vector2D()
    {
        _x = 0;
        _y = 0;
    }
    Vector2D<VarType>(VarType x,VarType y)
    {
        _x = x;
        _y = y;
    }
    //dot product
    double operator*(Vector2D &Vector2)
    {
        return _x*Vector2._x+_y*Vector2._y;
    }

    //vector addition
    Vector2D operator+(Vector2D &Vector2)
    {
        Vector2D<VarType> result(_x+Vector2._x,_y+Vector2._y);
        return result;
    }

    //vector minus
    Vector2D operator-(Vector2D &Vector2)
    {
        Vector2D<VarType> result(_x-Vector2._x,_y-Vector2._y);
        return result;
    }

    VarType GetPointX()
    {
        return _x;
    }

    VarType GetPointY()
    {
        return _y;
    }

    double GetAngle(Vector2D &Vector2)
    {
        return acos(this->operator *(Vector2)/this->GetLength()/Vector2.GetLength())*180/PI;
    }

    double GetLength()
    {
        return sqrt(pow(_x,2)+pow(_y,2));
    }

private:
    VarType _x;
    VarType _y;
};

#endif // VECTOR2D_H
