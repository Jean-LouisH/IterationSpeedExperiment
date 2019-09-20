#ifndef VECTOR2_OBJECT_HPP
#define VECTOR2_OBJECT_HPP


class Vector2_Object
{
private:
    double x;
    double y;
public:
    void add(double x, double y);
    Vector2_Object():
        x(0.0),
        y(0.0)
        {};
};

#endif // VECTOR2_OBJECT_HPP
