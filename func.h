#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

void InitPoint(point* p, float x, float y);
void InitCircle(circle* c, float x, float y, float rad);
void InitSquare(square* s, float x, float y, float a);

void PrintPnt(point* p);
void PrintCircle(circle* c);


float LenCircle(circle* c);
float SCircle(circle* c);

float LenSquare(square* s);
float SSquare(square* s);


bool InShapeCircle(circle* c, float x, float y);
bool InShapeSquare(square* s, float x, float y);

bool OnContourCircle(circle* c, float x, float y);
bool OnContourSquare(square* s, float x, float y);


bool CirclesIntersect(circle* c1, circle* c2);
bool SquaresIntersect(square* s1, square* s2);
bool CircleSquareIntersect(circle* c, square* s);

bool CircleInCircle(circle* c1, circle* c2);
bool SquareInSquare(square* s1, square* s2);
bool SquareInCircle(square* s, circle* c);
bool CircleInSquare(circle* c, square* s);

#endif