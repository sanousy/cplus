#include "sanoC.graphics.circle.h"


protected void SetRadius(circle this, int r)
{
    this->r = r;
    return;
}

//it is just to show override feature
protected int getColor2(circle this)
{
    return this->y;  // this is not a mistake just to show the override ... it will not return color like base class, instead return y!!
}
init(circle)
{
    call_implement_methods(circle);
    this->r = 0;
    this->color = 0;
}

static classTag tag;
implement_methods(circle)
{
    Inherit(point,circle);
    //registerClass(circle);
    implement_method(setRadius,SetRadius);
    implement_method(getColor,getColor2);
}

uninit(circle)
{
    call_uninit(point,this);
    return;
}


