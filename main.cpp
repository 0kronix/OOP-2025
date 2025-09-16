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

bool CirclesIntersect(circle* c1, circle* c2) {
    float dx = (*c1).cntr.x - (*c2).cntr.x;
    float dy = (*c1).cntr.y - (*c2).cntr.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance <= (*c1).rad + (*c2).rad;
}

bool SquaresIntersect(square* s1, square* s2) {
    float s1_right = (*s1).t.x + (*s1).a;
    float s1_bottom = (*s1).t.y + (*s1).a;
    float s2_right = (*s2).t.x + (*s2).a;
    float s2_bottom = (*s2).t.y + (*s2).a;
    
    return !((*s1).t.x > s2_right || s1_right < (*s2).t.x || (*s1).t.y > s2_bottom || s1_bottom < (*s2).t.y);
}

bool CircleSquareIntersect(circle* c, square* s) {
    float closestX = std::clamp((*c).cntr.x, (*s).t.x, (*s).t.x + (*s).a);
    float closestY = std::clamp((*c).cntr.y, (*s).t.y, (*s).t.y + (*s).a);
    float dx = (*c).cntr.x - closestX;
    float dy = (*c).cntr.y - closestY;
    float distance_squared = dx * dx + dy * dy;
    
    return distance_squared <= (*c).rad * (*c).rad;
}

bool CircleInCircle(circle* c1, circle* c2) {
    float dx = (*c1).cntr.x - (*c2).cntr.x;
    float dy = (*c1).cntr.y - (*c2).cntr.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance + (*c1).rad <= (*c2).rad;
}

bool SquareInSquare(square* s1, square* s2) {
    float s1_right = (*s1).t.x + (*s1).a;
    float s1_bottom = (*s1).t.y + (*s1).a;
    float s2_right = (*s2).t.x + (*s2).a;
    float s2_bottom = (*s2).t.y + (*s2).a;
    
    return (*s1).t.x >= (*s2).t.x && s1_right <= s2_right && (*s1).t.y >= (*s2).t.y && s1_bottom <= s2_bottom;
}

bool SquareInCircle(square* s, circle* c) {
    point corners[4] = {
        {(*s).t.x, (*s).t.y},
        {(*s).t.x + (*s).a, (*s).t.y},
        {(*s).t.x, (*s).t.y + (*s).a},
        {(*s).t.x + (*s).a, (*s).t.y + (*s).a}
    };
    
    for (int i = 0; i < 4; i++) {
        float dx = corners[i].x - (*c).cntr.x;
        float dy = corners[i].y - (*c).cntr.y;
        float distance_squared = dx * dx + dy * dy;
        if (distance_squared > (*c).rad * (*c).rad) {
            return false;
        }
    }
    return true;
}

bool CircleInSquare(circle* c, square* s) {
    float left = (*s).t.x + (*c).rad;
    float right = (*s).t.x + (*s).a - (*c).rad;
    float top = (*s).t.y + (*c).rad;
    float bottom = (*s).t.y + (*s).a - (*c).rad;
    
    return (*c).cntr.x >= left && (*c).cntr.x <= right && (*c).cntr.y >= top && (*c).cntr.y <= bottom;
}