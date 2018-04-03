//
// Created by xiezheng on 2018/4/2.
//

#ifndef JFZ_FFDEMUX_H
#define JFZ_FFDEMUX_H


#include "XDATA.h"
#include "IDemux.h"

class FFDemux:public IDemux {

    //virtual不删除 没有啥意义但是可以提醒调用者，这部分是用于重载的
    //打开文件
    virtual bool open(const char* url) ;
    //读取一帧数据，由调用者清理，以免发生内存的泄露
    virtual XDATA read() ;

public:
    FFDemux();
};


#endif //JFZ_FFDEMUX_H
