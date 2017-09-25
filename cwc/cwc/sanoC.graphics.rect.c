#include "sanoC.graphics.rect.h"

private(rect)
{
    int color;
};




protected int getSize(rect this)
{
    return (this->p2->x - this->p1->x)*(this->p2->y - this->p1->y);
}


init(rect)
{
    call_implement_methods(rect);
    this->p1 = new(point);
    this->p2 = new(point);
    this->p1->x = 0;
    this->p2->x = 0;
    this->p1->y = 0;
    this->p2->y = 0;

    init_private(rect)
    {
        __(rect,this).color = 0;
    }
}

implement_methods(rect)
{
    Inherit(Object, rect);
    //registerClass(rect);
    implement_method(getSize,getSize);
}
uninit(rect)
{
    clear_private(rect);
}


