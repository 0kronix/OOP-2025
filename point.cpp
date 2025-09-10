#include <iostream>
#include <cmath>

struct point {
    float x;
    float y;
};

void InitPoint(point* p, float x, float y) {
    (*p).x = x;
    (*p).y = y;
};

void PrintPnt(point* p) {
    std::cout << (*p).x << " " << (*p).y << std::endl;
}



struct circle {
    point cntr;
    float rad;
};

void InitCircle(circle* c, float x, float y, float rad) {
    (*c).cntr.x = x;
    (*c).cntr.y = y;
    (*c).rad = rad;
};

void PrintCircle(circle* c)
{
    std::cout << (*c).center.x << " " << (*c).center.y << std::endl;
    std::cout << (*c).rad << std::endl;
}

float LenCircle(circle* c)
{
    return 6.28 * (*c).rad;
}

float SCircle(circle* c)
{
    return 3.14 * (*c).rad * (*c).rad;
}



struct square {
    point t;
    float a;
};

void InitSquare(square* s, float x, float y, float a) {
    (*s).t.x = x;
    (*s).t.y = y;
    (*s).a = a;
};

float LenSquare(square* s)
{
    return 4 * (*s).a;
}

float SSquare(square* s)
{
    return (*s).a * (*s).a;
}



bool InShapeCircle(circle* c, float x, float y)
{
    return (x - (*c).cntr.x) * (x - (*c).cntr.x) + (y - (*c).cntr.y) * (y - (*c).cntr.y) <= (*c).rad;
}



bool InShapeSquare(square* s, float x, float y)
{
    point o;
    o.x = (*s).t.x + (*s).a
    o.y = (*s).t.y + (*s).a
    return x > (*s).t.x && x < o.x && y > (*s).t.y && y < o.y
}



bool OnContourCircle(circle* c, float x, float y)
{
    return (x - (*c).cntr.x) * (x - (*c).cntr.x) + (y - (*c).cntr.y) * (y - (*c).cntr.y) == (*c).rad;
}



bool OnContourSquare(square* s, float x, float y)
{
    point o;
    o.x = (*s).t.x + (*s).a
    o.y = (*s).t.y + (*s).a
    return (x == (*s).t.x || x == o.x) && (y == (*s).t.y || y == o.y)
}