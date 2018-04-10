//
// Created by xiezheng on 2018/4/9.
//

#ifndef JFZ_FFDECODE_H
#define JFZ_FFDECODE_H


#include "XParameter.h"
#include "Idecode.h"

struct AVCodecContext;
struct AVFrame;

class FFdecode :public Idecode{
public:
    virtual bool Open(XParameter para);

    virtual bool SendPacket(XDATA pkt);
    //从线程中获取解码结果
    virtual XDATA RecvFrame();

protected:
    AVCodecContext *codec = 0;
    AVFrame * frame = 0;
};


#endif //JFZ_FFDECODE_H
