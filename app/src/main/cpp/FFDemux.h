//
// Created by xiezheng on 2018/4/2.
//

#ifndef JFZ_FFDEMUX_H
#define JFZ_FFDEMUX_H


//#include <libavformat/avformat.h> 不需要自动引用
#include "XDATA.h"
#include "IDemux.h"
struct AVFormatContext;//指针不用去管它的实现

class FFDemux:public IDemux {
public:
    //virtual不删除 没有啥意义但是可以提醒调用者，这部分是用于重载的
    //打开文件
    virtual bool open(const char* url) ;
    //读取一帧数据，由调用者清理，以免发生内存的泄露
    virtual XDATA read() ;

    FFDemux();

private:
    AVFormatContext *ic = 0;//c++11中 这个值只有在无参数的构造函数中才会被赋值

};


#endif //JFZ_FFDEMUX_H
