
#include "sanoC.data.collection.h"

#undef ________
#define ________ 444

class(item)
{
//    union
//    {
//        void* tag;
//        char* stag;
//        int itag;
//        char ctag;
//    };
    void* prev;
    void* object;
    void* next;
};


init(item)
{
    this->next = null;
    this->prev = null;
    this->object= null;
}


uninit(item)
{
    free(this);
}


private(collection)
{
    item* head, tail;
    int length;
};

init(collection)
{
    call_implement_methods(collection);
    registerClass(collection);
    init_private(collection);
    __(collection,this).head = null;
    __(collection,this).tail = null;
    __(collection,this).length= 0;
}


uninit(collection)
{
}


void* itemAt(collection this , int index)
{
    if( index < 0 || index > __(collection, this).length)
        return null;
    item itm = __(collection, this).head;
    int ix = 0;
    if ( index < (int)(__(collection, this).length / 2))
    {
        while ( ix < index)
        {
            itm = itm->next;
            ix++;
        }

    }
    else
    {
        itm = __(collection, this).tail;
        ix = __(collection, this).length - 1;
        while ( ix > index)
        {
            itm = itm->prev;
            ix--;
        }
    }
    return itm->object;
}
void add (collection this, void* object)
{
    item x = new(item);
    if (__(collection,this).length == 0)
    {
        x->object = object;
        __(collection, this).tail = __(collection, this).head = x;
        x->next = x->prev = null;
    }
    else
    {
        x->object = object;
        __(collection, this).tail->next = x;
        x->prev =   __(collection, this).tail;
        x->next = null;
        __(collection, this).tail = x;
    }
    __(collection,this).length++;
}
void removeAt (collection this, int index)
{
    if( index < 0 || index > __(collection, this).length || __(collection,this).length == 0)
        return;
    if (__(collection,this).length == 1 && index == 0)
    {
        item itm = __(collection, this).head;
        delete(item, itm);
        __(collection, this).head = __(collection, this).tail = null;
        __(collection, this).length = 0;
    }
    else
    {
        item itm = itemAt(this,index);
        item nxt = itm->next;
        item prev = itm->prev;
        if (nxt != null) nxt->prev = prev;
        if (prev != null) prev->next = nxt;
        delete(item,itm);
        __(collection, this).length --;
    }
}
collection insertAt (collection this, void* object, int index)
{
    if( index < 0 || index > __(collection, this).length || __(collection,this).length == 0)
        return;
    item toPush = itemAt(this, index);
    item before = toPush->prev;
    item itm = new(item);
    itm->object = object;
    if (before != null)
    {
        before-> next = itm;
        itm->prev = before;
    }
    else
    {
        __(collection, this).head = itm;
        itm->prev = null;
    }

    if(toPush != null)
    {
        toPush->prev = itm;
        itm->next = toPush;
    }
    else
    {
        __(collection,this).tail = itm;
    }

}

implement_methods(collection)
{
    Inherit(Object, collection);
    implement_method(itemAt, itemAt);
    implement_method(add, add);
    implement_method(removeAt, removeAt);
    implement_method(insertAt, insertAt);
}

