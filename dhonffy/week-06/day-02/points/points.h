#ifndef POINTS_POINTS_H
#define POINTS_POINTS_H
#include "math.h"

typedef struct point{
    float x;
    float y;
} point_t;

point_t create_point(float , float);
float distance(point_t, point_t);
#endif //POINTS_POINTS_H
