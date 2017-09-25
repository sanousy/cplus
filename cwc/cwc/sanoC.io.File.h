#ifndef File_h
#define File_h

#include "sanoC.h"

typedef FILE* Stream;

class(File)
{
    Extends(Object);
    with_private(File)
    with_methods(File)
};

methods(File)
{
    Implementing(Object);
    void method(open)(File,char*, char*);
    void method(close)(File);
    void method(reopen)(File);
    void method(rename)(File);
    void method(remove)(File);
    void method(flush)(File);
    char* method(readAllText)(File);
    void method(writeLines) (File, char*);
    long method(length) (File);
};


#endif // File_h

