#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D();
    Vector2D(int x,int y);
    //dot product
    double operator*(Vector2D &Vector2);
    //vector addition
    Vector2D operator+(Vector2D &Vector2);
    //vector minus
    Vector2D operator-(Vector2D &Vector2);
    int GetPointX();
    int GetPointY();
private:
    int _x;
    int _y;
};

#endif // VECTOR2D_H
