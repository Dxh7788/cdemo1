//
//  main.cpp
//  demo
//
//  Created by 冻小宏 on 2019/3/12.
//  Copyright © 2019年 冻小宏. All rights reserved.
//

#include <iostream>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "jelly_os.h"

#define REGISTER_DECLARATION(type, name, value) \
extern const type name;                         \
enum { name##_##type##EnumValue = value##_##type##EnumValue }

#define THREAD_LOCAL_DECL __thread
#define  GET_MAX     0
#define  GET_MIN     1
#define A_ARRAY 1\
2\
3\
4
#define PASTE_TOKENS(x, y) PASTE_TOKENS_AUX(x, y)
#define PASTE_TOKENS_AUX(x, y) PASTE_TOKENS_AUX2(x, y)
#define PASTE_TOKENS_AUX2(x, y) x ## y
#define VM_SYMBOLS_DO(template, do_alias)                                                         \
/* commonly used class, package, module names */                                                \
template(java_base,                                 JAVA_BASE_NAME)                             \
template(java_lang_System,                          "java/lang/System")                         \
template(java_lang_Object,                          "java/lang/Object")                         \
template(java_lang_Class,                           "java/lang/Class")                          \
template(java_lang_Package,                         "java/lang/Package")                        \
template(java_lang_Module,                          "java/lang/Module")                         \
template(java_lang_String,                          "java/lang/String")                         \
template(java_lang_StringLatin1,                    "java/lang/StringLatin1")                   \
template(java_lang_StringUTF16,                     "java/lang/StringUTF16")                    \
template(java_lang_Thread,                          "java/lang/Thread")                         \

THREAD_LOCAL_DECL int var = 5;

typedef int (*entey_t)(int a, int b, int c);
typedef int (*p)(int,int);
//Box Box::instance = NULL;
int goLopp(int a,int b,int c);

struct JN_Functions{
    void (*def_work1)(void* arg);
    void (*def_work2)(void* arg);
};
void work3(void* arg);
void work4(void* arg);
struct JN_Functions jN_Functions={
    work3,
    work4
};
void* work1(void* arg);
void* work2(void* arg);
int main(int argc, const char * argv[]) {
    entey_t e_t;
    e_t = &goLopp;
    extern int extern_a_;
    //创建两个线程
    pthread_t pid1,pid2;
    pthread_create(&pid1,NULL,work1,NULL);
    pthread_create(&pid2,NULL,work2,NULL);
    // insert code here...
    Box box;
    box.initParams(10, 11.0, 12.0);
    std::cout << "Hello, World!"<<box.size()<<std::endl;
    std::cout << extern_a_<<std::endl;
    
    (*e_t)(1,2,3);
    std::cout<<A_ARRAY<<std::endl;
    int b[6] = {10,A_ARRAY};
    for (int i=0; i<sizeof(b)/sizeof(int); i++) {
        std::cout<<b[i]<<std::endl;
    }
    std::cout<<PASTE_TOKENS(12,13)<<std::endl;
    std::cout<<PASTE_TOKENS_AUX(12,13)<<std::endl;
    std::cout<<PASTE_TOKENS_AUX2(12,14)<<std::endl;
    jN_Functions.def_work1((void *)123);
    
    
    static const char* vm_symbol_enum_names =
    VM_SYMBOLS_DO(VM_SYMBOL_ENUM_NAME_BODY, VM_ALIAS_IGNORE)
    "\0";
    const char* string = &vm_symbol_enum_names[0];
    while (strlen(string)!=0) {
        std::cout<<string<<std::endl;
        string +=strlen(string);
        string +=1;
    }
    return 0;
}
void* work1(void* arg){
    std::cout<<++var<<std::endl;
    return NULL;
}

void* work2(void* arg){
    std::cout<<++var<<std::endl;
    return NULL;
}

void work3(void* arg){
    std::cout<<++var<<std::endl;
}

void work4(void* arg){
    std::cout<<++var<<std::endl;
}

int goLopp(int a,int b,int c){
    int val = a+b+c;
    std::cout<<val<<std::endl;
    return val;
}


int get_max(int i,int j)
{
    return i>j?i:j;
}

int get_min(int i,int j)
{
    return i>j?j:i;
}

int compare(int i,int j,int flag)
{
    int ret;
    
    //这里定义了一个函数指针，就可以根据传入的flag，灵活地决定其是指向求大数或求小数的函数
    //便于方便灵活地调用各类函数
    p p_a;
    if(flag == GET_MAX)
        p_a = get_max;
    else
        p_a = get_min;
    
    ret = p_a(i,j);
    
    return ret;
}

