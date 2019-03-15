//
//  JellyOs.h
//  demo
//
//  Created by 冻小宏 on 2019/3/12.
//  Copyright © 2019年 冻小宏. All rights reserved.
//

#ifndef jelly_os_h
#define jelly_os_h


#endif /* JellyOs_h */
#define HOTSPOT_JNI_CREATEJAVAVM_ENTRY(arg0, arg1, arg2)
#define CHILD_DECL :Box
class Box
{
public:
    double length;
    double breadth;
    double height;
public:
    void initParams(double l,double b,double h);
    double size();
};

class Package CHILD_DECL{
    
};
