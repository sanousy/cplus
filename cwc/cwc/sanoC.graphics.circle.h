#ifndef circle_h
#define circle_h
#include "sanoC.graphics.point.h"

class(circle)
{
    Extends(point);
    int r;
    int color;
    with_methods(circle);
};

methods(circle)
{
    Implementing(point);
    void method(setRadius)(circle, int);
};

#endif // circle_h
