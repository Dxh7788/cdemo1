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

#define THREAD_LOCAL_DECL __thread
#define  GET_MAX     0
#define  GET_MIN     1
THREAD_LOCAL_DECL int var = 5;

typedef int (*entey_t)(int a, int b, int c);
typedef int (*p)(int,int);
//Box Box::instance = NULL;
int goLopp(int a,int b,int c);
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

