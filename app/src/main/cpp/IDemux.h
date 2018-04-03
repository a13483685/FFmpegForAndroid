//
// Created by xiezheng on 2018/4/2.
//

#ifndef JFZ_IDEMUX_H
#define JFZ_IDEMUX_H

#include "XDATA.h"

//解封装接口
class IDemux {
public:
    //打开文件
    virtual bool open(const char* url) = 0;
    //读取一帧数据，由调用者清理，以免发生内存的泄露
    virtual XDATA read() = 0;
};


#endif //JFZ_IDEMUX_H
