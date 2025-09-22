#ifndef STRUCTS_H
#define STRUCTS_H

struct point {
    float x;
    float y;
};

struct circle {
    point cntr;
    float rad;
};

struct square {
    point t;
    float a;
};

#endif