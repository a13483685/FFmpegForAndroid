//
// Created by xiezheng on 2018/4/9.
//

#ifndef JFZ_IDECODE_H
#define JFZ_IDECODE_H

#include "XParameter.h"
#include "IObserver.h"

//解码接口，支持硬解码
class Idecode :public IObserver{
public:
    //开启解码器
    virtual bool Open(XParameter parameter) = 0;
    //future模型 发送数据到线程解码
    virtual bool SendPacket(XDATA pkt) = 0;
    //从线程中获取解码结果
    virtual XDATA RecvFrame() = 0;

};


#endif //JFZ_IDECODE_H
