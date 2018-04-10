//
// Created by xiezheng on 2018/4/9.
//

#include "Idecode.h"
void Idecode::Update(XDATA pkt)
{
    //如果是音频
    if(pkt.isAudio != isAudio)
    {
        return;
    }

    while (!isExit)
    {

        packMutex.lock();
        //当调用者发过来数据的时候，插入到队列之中
        if(packs.size()<maxList)
        {
            //相当于生产者
            packs.push_back(pkt);//如果不给队列限制大小，那么队列可能无限制的增大，最终导致内存耗尽
            packMutex.unlock();
        }
        packMutex.unlock();
        XSleep(1);
    }


}

void Idecode::main()
{
    while (!isExit)
    {
        packMutex.lock();
        if(packs.empty()){
            packMutex.unlock();
            XSleep(1);//减少cpu的消耗，以免没有数据一直在读取
            continue;
        }
        //队列往队尾插数据，头部取数据，相当于消费者
        XDATA pack = packs.front();//从头部取出
        packs.pop_front();//取出删掉

        //发送数据到解码线程，一个数据包，可能解码多个结果
        if(this->SendPacket(pack))
        {//获取解码数据
            XDATA frame = RecvFrame();
            if(!frame.data) break;//没有
            this->notify(frame);//如果读到数据，那么需要继续往下发，发送给观察者
        }
        pack.Drop();
        packMutex.unlock();
    }
}