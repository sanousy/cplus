#include "sanoC.graphics.point.h"

private(point)
{
    int color;
};



protected void setColor(point this, int c)
{
    __(point,this).color = c;
    return;
}

protected int getColor(point this)
{
    return __(point,this).color;
}

protected void point_setX(point this, int x)
{
    this->x = x;
    return;
}


init(point)
{
    call_implement_methods(point);
    this->x = 0;
    this->y = 0;

    init_private(point)
    {
        __(point,this).color = 0;
    }
}

implement_methods(point)
{
    Inherit(Object, point);
    //registerClass(point);
    implement_method(setX,point_setX);
    implement_method(getColor,getColor);
    implement_method(setColor,setColor);
}
uninit(point)
{
    clear_private(point);
}


