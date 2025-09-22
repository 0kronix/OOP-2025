#include <iostream>
#include "structs.h"
#include "func.h"

int main() {
    circle c1, c2;
    square s1, s2;
    
    InitCircle(&c1, 0, 0, 5);
    InitCircle(&c2, 3, 3, 3);
    InitSquare(&s1, 1, 1, 4);
    InitSquare(&s2, 2, 2, 2);
    
    std::cout << "Circle 1:" << std::endl;
    PrintCircle(&c1);
    std::cout << "Length: " << LenCircle(&c1) << ", Area: " << SCircle(&c1) << std::endl;
    
    std::cout << "\nSquare 1:" << std::endl;
    std::cout << "Top-left: (" << s1.t.x << ", " << s1.t.y << "), Side: " << s1.a << std::endl;
    std::cout << "Perimeter: " << LenSquare(&s1) << ", Area: " << SSquare(&s1) << std::endl;
    
    std::cout << "\nPoint (2,2) in Circle 1: " << InShapeCircle(&c1, 2, 2) << std::endl;
    std::cout << "Point (3,3) in Square 1: " << InShapeSquare(&s1, 3, 3) << std::endl;
    
    std::cout << "\nCircles intersect: " << CirclesIntersect(&c1, &c2) << std::endl;
    std::cout << "Squares intersect: " << SquaresIntersect(&s1, &s2) << std::endl;
    std::cout << "Circle and Square intersect: " << CircleSquareIntersect(&c1, &s1) << std::endl;
    
    std::cout << "\nCircle 2 in Circle 1: " << CircleInCircle(&c2, &c1) << std::endl;
    std::cout << "Square 2 in Square 1: " << SquareInSquare(&s2, &s1) << std::endl;
    std::cout << "Square 1 in Circle 1: " << SquareInCircle(&s1, &c1) << std::endl;
    
    return 0;
}