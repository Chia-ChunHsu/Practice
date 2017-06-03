#include "vector2d.h"

//template<class VarType>
//Vector2D<VarType>::Vector2D()
//{
//    _x = 0;
//    _y = 0;
//}

//template<class VarType>
//Vector2D<VarType>::Vector2D(VarType x, VarType y)
//{
//    _x = x;
//    _y = y;
//}
//template<class VarType>
//double Vector2D<VarType>::operator*(Vector2D &Vector2)
//{
//    return _x*Vector2._x+_y*Vector2._y;
//}

//template<class VarType>
//Vector2D<VarType> Vector2D<VarType>::operator+(Vector2D &Vector2)
//{
//    Vector2D<VarType> result(_x+Vector2._x,_y+Vector2._y);
//    return result;
//}
//template<class VarType>
//Vector2D<VarType> Vector2D<VarType>::operator-(Vector2D &Vector2)
//{
//    Vector2D<VarType> result(_x-Vector2._x,_y-Vector2._y);
//    return result;
//}
//template<class VarType>
//VarType Vector2D<VarType>::GetPointX()
//{
//    return _x;
//}
//template<class VarType>
//VarType Vector2D<VarType>::GetPointY()
//{
//    return _y;
//}
//template<class VarType>
//double Vector2D<VarType>::GetAngle(Vector2D &Vector2)
//{
//    return acos(this->operator *(Vector2)/this->GetLength()/Vector2.GetLength())*180/PI;
//}
//template<class VarType>
//double Vector2D<VarType>::GetLength()
//{
//    return sqrt(pow(_x,2)+pow(_y,2));
//}
