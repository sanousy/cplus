#ifndef Object_h
#define Object_h

#include "cwc.h"

class(Object)
{
    with_private(Object);
    with_methods(Object);
};

typedef struct classTag classTag;
struct classTag
{
    char* namespace;
    char* className;
    void* method(delete)(void*);
};

methods(Object)
{
    char* method(getType)(Object);
    char* method(getnamespace)(Object);
    void method(Register)(Object, classTag*);
};

char* getFileBase(char*);
char* getFileClassName(char* name);
#endif // Object_h
