
#include "string.h"
#define mkstring(name, size) name = malloc(size+1); name[size] = 0;



init(String)
{
    mkstring(this->value, 0);
    call_implement_methods(String);
    registerClass(String);
}


uninit(String)
{
}

int length(String this)
{
    int  i = strlen(this->value);

    return i;
}

void setValue(String this,  char* value)
{
    int len = strlen(value);
    mkstring(this->value, len);
    for(int i = 0; i < len; i++)
        this->value[i] = value[i];
    //printf("%s\n",this->value);
}

void append(String this, char* addedText)
{
    int mylen  = strlen(this->value);
    int addedlen = strlen(addedText);
    int len =  mylen + addedlen;
    char* ns;
    mkstring(ns, len);
    for(int i=0 ; i< mylen; i++)
    {
        ns[i]=this->value[i];
    }

    for(int i=0; i < addedlen; i++)
    {
        ns[mylen+i] = addedText[i];
    }

    //free(this->value);
    this->value=ns;
    //printf("%s\n",this->value);
}


String substr (String this, int start, int len)
{
    char* sub;
    mkstring(sub, len);
    for(int i = 0; i < len; i++)
    {
        sub[i] = this->value[start+i];
    }
    String subst = new(String);
    subst->value = sub;
    //printf("%s\n",subst->value);
    return subst;
}


String left(String this, int len)
{
    return substr(this,0,len);
}

String right (String this, int len)
{
    if (len > strlen(this->value))
        len = strlen(this->value);

    int strt = strlen(this->value) - len;
    return substr(this,strt,len);
}

bool equals(String this, char* value)
{
    int result=  strcmp(this->value,value);
    if (result > 0 )
        return true;
    else
        return false;
}

String upper(String this)
{
    String str = new(String);
    int len = strlen(this->value);
    mkstring(str->value, len);
    for(int i = 0; i < len; i++)
    {
        str->value[i] = toupper(this->value[i]);
    }
    return str;
}

String lower(String this)
{
    String str = new(String);
    int len = strlen(this->value);
    mkstring(str->value, len)
    for(int i = 0; i < len; i++)
    {
        str->value[i] = toupper(this->value[i]);
    }
    return str;
}

int indexOf(String this, char* str, int index)
{

}
String* split(String this, char* str)
{

}
String trim(String this)
{

}
String ltrim(String this)
{

}
String rtrim(String this)
{

}
String replace(String this, char* what, char* becomes )
{

}

implement_methods(String)
{
    Inherit(Object, String);
    implement_method(length, length);
    implement_method(setValue, setValue);
    implement_method(append, append);
    implement_method(substr, substr);
    implement_method(left, left);
    implement_method(right, right);
    implement_method(equals, equals);
    implement_method(lower, lower);
    implement_method(upper, upper);
    implement_method(indexOf, indexOf);
    implement_method(split, split);
    implement_method(ltrim, ltrim);
    implement_method(rtrim, rtrim);
    implement_method(trim, trim);
    implement_method(replace, replace);
}

