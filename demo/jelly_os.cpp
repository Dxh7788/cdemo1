//
//  jelly_os.cpp
//  demo
//
//  Created by 冻小宏 on 2019/3/12.
//  Copyright © 2019年 冻小宏. All rights reserved.
//

#include <stdio.h>
#include "jelly_os.h"

void Box::initParams(double l, double b, double h){
    HOTSPOT_JNI_CREATEJAVAVM_ENTRY(l, b, h)
    length = l;
    breadth = b;
    height = h;
};
double Box::size(){
#if defined(ZERO)
    {
        return length-1;
    }
#endif
    return length;
}
