//
// Created by xiezheng on 2018/4/2.
//

#ifndef JFZ_IDEMUX_H
#define JFZ_IDEMUX_H

#include "XDATA.h"
#include "XThread.h"
#include "IObserver.h"
#include "XParameter.h"

//解封装接口
class IDemux :public IObserver{
public:
    //打开文件
    virtual bool open(const char* url) = 0;
    //读取一帧数据，由调用者清理，以免发生内存的泄露
    virtual XDATA read() = 0;
    //总时长
    int totalMs = 0;
    virtual XParameter GetVPara() = 0;//获取视频参数
    virtual XParameter GetAPara() = 0;//获取音频参数


protected:

    virtual void main();
};


#endif //JFZ_IDEMUX_H
