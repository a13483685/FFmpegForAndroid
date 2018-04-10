//
// Created by xiezheng on 2018/4/9.
//

#ifndef JFZ_IDECODE_H
#define JFZ_IDECODE_H

#include "XParameter.h"
#include "IObserver.h"
#include <list>

//解码接口，支持硬解码
class Idecode :public IObserver{
public:
    //开启解码器
    virtual bool Open(XParameter parameter) = 0;
    //future模型 发送数据到线程解码
    virtual bool SendPacket(XDATA pkt) = 0;
    //从线程中获取解码结果
    virtual XDATA RecvFrame() = 0;
    //由主体notify来调用 生产者
    virtual void Update(XDATA pkt);//阻塞

    bool isAudio = false;
    //最大的队列缓冲
    //如果说视频1秒25帧 那么这个队列最多可以缓冲4秒
    int maxList =100;//这个缓冲也可以依据容量缓冲


protected:
    virtual void main();
    //读取缓冲帧
    std::list<XDATA> packs;

    std::mutex packMutex;
};


#endif //JFZ_IDECODE_H
