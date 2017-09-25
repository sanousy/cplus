#ifndef point_h
#define point_h

#include "sanoC.h"


class(point)
{
    Extends(Object);
    int x;
    int y;
    with_private(point);
    with_methods(point);
};

methods(point)
{
    Implementing(Object);
    void method(setX)(point,int);
    int method(getColor)(point);
    void method(setColor)(point,int);
};


#endif // point_h
