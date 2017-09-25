#include "sanoC.h"

private(Object)
{
    classTag* tag;
};

static classTag tag;
init(Object)
{
    init_private(Object);
    call_implement_methods(Object);
    registerClass(Object);
    __(Object,this).tag = &tag;
};

char* getFileBase(char* fullPath)
{
    int len= strlen(fullPath);
    int last_dot = len;
    int last_slash = -1;

    for (int ix = len -1; ix >= 0 ; ix--)
    {
        if(fullPath[ix] == '.')
        {
            last_dot = ix;
            break;
        }

    }

    for (int ix = len -1; ix >= 0 ; ix--)
    {

        if(fullPath[ix] == '\\' || fullPath[ix] == '/')
        {
            last_slash = ix;
            break;
        }

    }

    if(last_dot < last_slash) last_dot = len;
    int newLen = last_dot - last_slash -1;
    char* baseFileName = calloc(newLen+1,1);


    //012345678901234567890
    //c:\sano.txt
    // 2,7 --> 7-2 = 5 len(sano) = 4 --> 7-2-1 = 4 ok ...


 //   printf("%d %d", last_slash, last_dot);
    for (int ix = 0; ix < newLen; ix++)
    {
        baseFileName[ix] = fullPath[ix + last_slash + 1];
    }

 //   printf("NAMESPACE= %s  \n", baseFileName);
    return baseFileName;
}

char* getFileClassName(char* name)
{
    char* namespace = getFileBase(name);

    int len= strlen(namespace);
    int last_dot = len;

    for (int ix = len -1; ix >= 0 ; ix--)
    {
        if(namespace[ix] == '.')
        {
            last_dot = ix;
            break;
        }

    }

    if (last_dot == len)
    {
        last_dot = -1;
    }

    int newLen = len - last_dot -1;

    char* className = calloc(newLen+1,1);


    //012345678901234567890
    //c:\sano.txt
    // 2,7 --> 7-2 = 5 len(sano) = 4 --> 7-2-1 = 4 ok ...


  //  printf("%d ",  last_dot);
    for (int ix = 0; ix < newLen; ix++)
    {
        className[ix] = namespace[ix + last_dot + 1];
    }

  //  printf("CLASSNAME=%s \n", className);
    return className;
}


protected char* getType(Object this)
{
    return __(Object, this).tag->className;
};

protected char* nsp(Object this)
{
    return __(Object, this).tag->namespace;
};

protected void regist(Object this, classTag* tag)
{
    __(Object, this).tag = tag;
};

implement_methods(Object)
{
    implement_method(getType,getType);
    implement_method(getnamespace, nsp);
    implement_method(Register, regist);
};

uninit(Object)
{
};


