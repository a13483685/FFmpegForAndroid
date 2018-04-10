//
// Created by xiezheng on 2018/4/9.
//

extern "C" {
#include <libavcodec/avcodec.h>
}
#include "FFdecode.h"
#include "Xlog.h"

bool FFdecode::Open(XParameter para)
{
    if(!para.para) return false;
    AVCodecParameters *p = para.para;
    //1.查找解码器
    AVCodec *cd = avcodec_find_decoder(p->codec_id);
    if(!cd)
    {
        XLOGE("avcodec_find_decoder %d failed !",p->codec_id);
    }
    XLOGE("avcodec_find_decoder success !");
    //2.创建解码上下文，并复制参数
    codec = avcodec_alloc_context3(cd);
    avcodec_parameters_to_context(codec,p);

    codec->thread_count = 8;
    int re = avcodec_open2(codec,0,0);
    if(re !=0)
    {
        char buf[1024] = {0};
        av_strerror(re,buf, sizeof(buf)-1);
        XLOGE("%s",buf);
        return false;
    }
    XLOGE("avcodec_open2 success !");

    return true;
}

bool FFdecode::SendPacket(XDATA pkt)
{
    if(pkt.size<0 || !pkt.data) return false;
    if(!codec)
    {
        return false;
    }
    //相当于已经打开了解码器
    int re = avcodec_send_packet(codec,(AVPacket*)pkt.data);
    if (!re)
    {
        return false;
    }

    return true;
}
//从线程中获取解码结果
XDATA FFdecode::RecvFrame()
{
    if(!codec)
    {
        return XDATA();
    }
    if(!frame)
    {
        frame = av_frame_alloc();
    }

    int re = avcodec_receive_frame(codec, frame);
    if(re!= 0)
    {
        return XDATA();
    }
    //以下解码成功
    XDATA d;
    d.data = (unsigned char*)frame;
    //linesize:如果是平面格式，对应的yuv是一行的大小 然后再*高度

    if(codec->codec_type == AVMEDIA_TYPE_VIDEO)
        d.size = (frame->linesize[0] + frame->linesize[1] + frame->linesize[2])*frame->height;
    return d;
}