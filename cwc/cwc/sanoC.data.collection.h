#ifndef collection_h
#define collection_h

#include "sanoC.h"

class(collection)
{
    Extends(Object);
    with_private(collection);
    with_methods(collection);
};

methods(collection)
{
    Implementing(Object);
    void* method(itemAt)(collection, int);
    void method(add) (collection, void*);
    void method(removeAt) (collection, int);
    collection method(insertAt) (collection, void*, int);
};
#endif // collection_h


