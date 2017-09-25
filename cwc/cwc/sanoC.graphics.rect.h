#ifndef rect_h
#define rect_h
#include "sanoC.graphics.point.h"

class(rect)
{
    Extends(Object);
    point p1;
    point p2;
    with_private(rect);
    with_methods(rect);
};

methods(rect)
{
    Implementing(Object);
    int method(getSize)(rect);
};

#endif // circle_h
