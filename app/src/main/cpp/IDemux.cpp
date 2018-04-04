//
// Created by xiezheng on 2018/4/2.
//

#include "IDemux.h"
#include "Xlog.h"

//不断地读 然后打印出来
void IDemux::main()
{
    for(;;)
    {
        XDATA d = read();
        XLOGI("IDemux Read %d",d.size);
        if (d.size!=0)
            continue;

    }
}