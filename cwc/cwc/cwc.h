#ifndef __C_with_Classes__
#define __C_with_Classes__

#include <stdio.h>
#include <setjmp.h>


typedef enum {false = 0, true = 1} bool;

// -fplan9-extensions compile directive must be there!!
//======================================
// General definitions
//======================================
#define null (void*)0
#define __tring char*
#define __P(__cls) __cls##__private__
#define __M(__cls) __cls##__methods__
//======================================
// class definition to be added first after include "cwc.h" and other required headers directly
//======================================
#define class(__cls) \
typedef struct __cls * __cls;\
struct __cls

//======================================
// methods definition to be added after class definition in .H file
//======================================
#define methods(__cls) \
typedef struct __M(__cls) * __M(__cls); \
struct __M(__cls)
//======================================
// private part construction of the class to be added only in the .C file
//======================================
#define private(__cls) \
typedef struct __P(__cls) * __P(__cls); \
struct __P(__cls)
//======================================
// class construction with_private ( add pointer to private)
//                    with_methods ( add pointer to methods static structure for memory utilization)
//======================================
#define with_private(__cls) void* __P(__cls);
#define with_methods(__cls) void* __M(__cls);
//======================================
// __ for private access, _call short cust call, _ long path call
//======================================
#define __(__cls,this) (*((__P(__cls))(this-> __P(__cls))))
#define _call(__cls,this,mth,args...) (((__M(__cls))(this-> __M(__cls))))->mth(this, ##args)
#define _(__cls,this) (*((__M(__cls))(this->__M(__cls))))
//======================================
// allocation
//======================================
#define new(__cls)  (__cls)  __ctor__##__cls();
#define delete(__cls,this)   __dtor__##__cls(this); this = null;
//======================================
// Modifiers
//======================================
#define protected static
#define public extern
#define method(mth)  ((*mth))
//======================================
// Inheritance, Methods, ctor, dtor
//======================================
#define Extends(__cls) struct __cls;
#define init(__cls)\
static classTag __tag__;\
__cls __ctor__##__cls()\
{\
    __cls this = (void*)malloc(sizeof( struct __cls));\
    __init__##__cls(this);\
    return this;\
};\
void __dtor__##__cls(__cls this)\
{\
    __uninit__##__cls(this);\
    free(this);\
    return;\
};\
void __init__##__cls(__cls this)
#define uninit(__cls) void __uninit__##__cls(__cls this)
#define call_uninit(__cls,this) __uninit__##__cls(this)
#define init_private(__cls) this->__P(__cls) = (void*) malloc(sizeof(struct __P(__cls)));
#define clear_private(__cls) free(this->__P(__cls));
//======================================
// Methods
//======================================
#define Implementing(__cls) struct __M(__cls);
#define Inherit(__bcls,__cls)  __init__##__bcls(this);\
    memcpy(this->__M(__cls),((__bcls)this)->__M(__bcls),sizeof(struct __M(__bcls)));\
    registerClass(__cls);
#define call_implement_methods(__cls) __cls##__implement_methods__(this);
#define implement_method(method_name, internal_function) __mth__.method_name = &internal_function;
#define registerClass(__cls) \
    __tag__.className = getFileClassName( __FILE__);\
    __tag__.namespace = getFileBase( __FILE__);\
    __tag__.delete = &__dtor__##__cls;\
    _(__cls, this).Register(this, &__tag__);

#define getClassType(this)  _(Object, this).getType(this)
#define getnamespace(this)  _(Object, this).getnamespace(this)

#define implement_methods(__cls) \
static struct __M(__cls) __mth__; \
void __cls##__link_metods__2(__cls this);\
void __cls##__implement_methods__(__cls this) \
{ \
   this->__M(__cls) =(void*)&__mth__;  \
   __cls##__implement_methods__2(this); \
}\
\
void __cls##__implement_methods__2(__cls this)
//======================================
// Exception handling
//======================================
jmp_buf __EX__;
#define try \
{ \
    int ____exx____ = setjmp(__EX__);\
    if(!____exx____) {

#define catch(e) \
    } else {\
    int e = ____exx____;

#define finally }};
#define throw(ex) longjmp(__EX__,ex);

//======================================
// enumeration 
//======================================
#define enum_t(_enum, type) typedef type enum_##_enum; typedef struct enums_##_enum
#define enum_v(_enum)  const struct enums_##_enum _enum
#define enum(_enum) enum_##_enum


#endif // __C_with_Classes__
