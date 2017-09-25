#include <stdio.h>
#include <stdlib.h>

#include "sanoC.graphics.h"
#include "sanoC.io.h"
#include "sanoC.data.h"




void string_show();
void collections_show();
void try_catch_show();
void inheritance_show();
void copy_a_file_show();
call_trhow();
call_trhow2();

#define showstep(fn) printf("\n========================\n Step #%d: %s \n========================\n",step++, #fn); fn();

enum_t( windowClass, int) { int a, b, c};
enum_v(windowClass) ={ 0, 1, 2};

enum_t(name, char*) { char a[20], b[20], c[20]};
enum_v(name) ={ "Sanousy", "Ali", "Saeed"};


int main(int argc, char** argv)
{
	enum(windowClass) x = windowClass.b;
	enum(name) y = name.a;
    printf(" showing the value of windowClass.b = %d \n", x);
    printf(" showing the value of enum name.a= %s \n", y);
    int step = 1;

    showstep(inheritance_show);
    showstep( try_catch_show);
    showstep(string_show);
    showstep(collections_show);
    showstep(copy_a_file_show);

    printf("End of show \n");
}



void collections_show()
{
    printf("create a new collection c\n");
    collection c = new(collection);
    printf("add a string hi to c\n");
    _(collection,c).add(c,"hi");
    printf("add a string we to c\n");
    _(collection,c).add(c,"we");
    printf("create a new point object\n");
    point pt = new(point);
    pt->x = 99;
    pt->y = 100;
    printf("set x = 99, y = 100 ... add pt to c\n");
    _(collection, c).add(c, pt);

    printf("get item at location 0 in collection which will be ...\n");
    printf("%s \n\n", _(collection, c).itemAt(c,0));
    printf("get item at location 2 in collection which will be ...\n");
    Object obj = _(collection, c).itemAt(c,2);
    printf("%s \n\n", getClassType(obj));
    printf("cast object to point again and get x and y  x=%d, y=%d\n\n", ((point)obj)->x, ((point)obj)->y);
    printf("Now adding 1 Million objects of type point  to  our collection  \n");
    for (int i = 0; i < 1000000; i++)
    {
    	point tmp = new(point);
    	_(collection,c).add(c, tmp);
	}
    
}



void string_show()
{
    printf("create a string  with value Test1Test2\n");
    String test1 = new(String);
    test1->value = "Test1Test2";
    printf("append this string with value Test3\n");
    _(String,test1).append(test1,"Test3");


    printf("the final result of append method is: %s\n", test1->value);

    printf("call method left(5) = %s\n", _(String, test1).left(test1,5)->value);
    printf("call method substr(5,5) = %s\n", _(String, test1).substr(test1,5,5)->value);
    printf("call method right(5) = %s\n",_(String, test1).right(test1,5)->value);

    printf("testing if my string equals Test1Tests?? ...");
    if (_(String,test1).equals(test1,"Test1Tests"))
        printf("Yes they are equal\n");
    else
        printf("Not equal!\n");

    printf("testing if my string equals Test1Test2?? ...");
    if (_(String,test1).equals(test1,"Test1Test2"))
        printf("Yes they are equal\n");
    else
        printf("Not equal!\n");;
}


try_catch_show()
{
    int e = 0;
    printf("calling two functions ... call_throw and call_throw2\n");
    printf("call_throw throws exception = 1, and call_throw2 throws exception = 2\n");
    printf("try first calling call_throw ... \n");
    try
    {
        call_trhow();
        call_trhow2();
    }
    catch(e)
    {
        printf("Exception reported %d \n", e);
    }
    finally
    {
        printf("finally \n");
    }



    printf("try now calling call_throw2 ... \n");
    try
    {
        call_trhow2();
       call_trhow();
    }
    catch(e)
    {
        printf("Exception reported %d \n", e);
    }
    finally
    {
        printf("finally \n");
    }

}

void inheritance_show()
{

    point p = new(point);
    circle c = new(circle);

    p->x = 1;
    p->y = 2;
    _(point,p).setColor(p,3);
    c->x = 5;
    c->y = 6;
    _(circle,c).setRadius(c,50);
    _(circle,c).setColor(c,12);

    printf("circle is really based on point, but getColor is overridden in circle to get the y instead of color ...");

    printf("this code was used to create objects ans play around ...\n\n");
    printf (" %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n \n\n ", "point p = new(point);",
            "circle c = new(circle);",
    "p->x = 1;",
    "p->y = 2;",
    "_(point,p).setColor(p,3);",
    "c->x = 5;",
    "c->y = 6;",
    "_(circle,c).setRadius(c,50);",
    "_(circle,c).setColor(c,12);");


    printf("Now trying to emphasize what we really got ..\n");
    printf("%s from namespace %s\n", getClassType(p), getnamespace(p));
    printf("%s from namespace %s\n", getClassType(c), getnamespace(c));
    printf("I have a %s(%d , %d) with color =%d \n", getClassType(p), p->x, p->y, _(point,p).getColor(p));
    printf("I have a %s(%d , %d),%d with color = %d \n", getClassType(c),((point)c)->x, c->y, c->r, _(circle,c).getColor(c));
    point pc = (point)c;
    printf("now trying to cast circle to point what will happen: \n %s(%d , %d) with color =%d \n", getClassType(pc), pc->x, pc->y, _(point,pc).getColor(pc));
    printf("note the color is brought to you via point methods not circle methods, refere to the code there is an override  :)");
    delete(point,p);
    delete(circle,c);
}

void copy_a_file_show()
{

    File f = new(File);
    File t = new(File);
    _(File,f).open(f,"hello2.txt","rb");
    char* x;
    try
    {
        x =  _(File,f).readAllText(f);
        printf("reading file hello2.txt, \n I've got the following text %s\n", x);

        _(File,t).open(t,"hello3.txt", "wb");
        _(File,t).writeLines(t,x);
        printf("writing this text to file hellow3.txt");
        _(File, f).close(f);
        _(File, t).close(t);
        _(File,f).open(f, "hello3.txt", "rb");
        x = "";
        x = _(File, f).readAllText(f);
        printf("trying to read hello3.txt, the following is the read text:\n %s\n", x);
    }
    catch(e)
    {
        printf("catching this error: Error reading the file %d\n", e);
    }
    finally
    {
        _(File,f).close(f);
        _(File,t).close(t);
        printf("closing hello2.txt and hello3.txt \n");
    }
}

call_trhow()
{
    throw(1);
}

call_trhow2()
{
    throw(2);
}

