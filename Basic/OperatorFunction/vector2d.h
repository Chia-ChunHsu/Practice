#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D();
    Vector2D(int x,int y);
    double operator*(Vector2D &vector2);
    Vector2D operator+(Vector2D &Vector2);
private:
    int _x;
    int _y;
};

#endif // VECTOR2D_H
