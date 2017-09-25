#ifndef String_h
#define String_h

#include "sanoC.h"

class(String)
{
    Extends(Object);
    char* value;
    with_methods(String);
};

methods(String)
{
    Implementing(Object);
    int method(length)(String);
    void method(setValue) (String, char*);
    void method(append) (String, char*);
    String method(substr) (String, int, int);
    String method(left)(String, int);
    String method(right) (String, int);
    bool method(equals)(String, char*);
    String method(upper) (String);
    String method(lower) (String);
    int method(indexOf)(String, char*, int);
    String* method(split)(String, char*);
    String method(trim)(String);
    String method(ltrim)(String);
    String method(rtrim)(String);
    String method(replace)(String, char*, char*);



};
#endif // String_h


