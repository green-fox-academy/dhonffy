#include "points.h"

point_t create_point(float x, float y)
{
    point_t point = {x, y};
    return point;
}

float distance(point_t p1, point_t p2)
{
    double d_x = fabs((double)p1.x - (double)p2.x);
    double d_x_2 = d_x * d_x;
    double d_y = fabs((double)p1.y - (double)p2.y);
    double d_y_2 = d_y * d_y;
    return (float)sqrt(d_x_2 + d_y_2);
}