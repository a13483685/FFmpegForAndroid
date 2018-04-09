//
// Created by xiezheng on 2018/4/2.
//

#include "IDemux.h"
#include "Xlog.h"

//不断地读 然后打印出来 线程中主要的处理函数
//当停止了线程，isExit 就会变成True 那么就不会执行read
void IDemux::main()
{
    while (!isExit)
    {
        XDATA d = read();
        if (d.size>0)
            notify(d);
//        XLOGI("IDemux Read %d",d.size);
//        if (d.size!=0)
//            continue;

    }
}