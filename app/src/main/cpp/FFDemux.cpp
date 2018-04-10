//
// Created by xiezheng on 2018/4/2.
//

#include "FFDemux.h"
#include "Xlog.h"


extern "C" {
    #include <libavformat/avformat.h>
}

bool FFDemux::open(const char* url)
{
    XLOGI("Open file %s begin",url);
    int re = avformat_open_input(&ic,url,0,0);
    if(re!=0)
    {
        char buf[1024] = {0};
        av_strerror(re,buf, sizeof(buf));
        XLOGE("FFDemux open %s failed!",buf);
        return false;
    }
    XLOGI("FFDemux success");
    re = avformat_find_stream_info(ic,0);
    if(re !=0)
    {
        char buf[1024] = {0};
        av_strerror(re,buf, sizeof(buf));
        XLOGE("avformat_find_stream_info %s ailed!",url);
    }
    XLOGI("avformat_find_stream_info success");

    this->totalMs = ic->duration/(AV_TIME_BASE/1000);

    XLOGE("total ms is: %d",this->totalMs);

    GetVPara();

    GetAPara();
    return true;
}
//获取视频流的索引信息
XParameter FFDemux::GetVPara()
{
    if(!ic)
    {
        return XParameter();
    }
    //获取视频流信息
    int re = av_find_best_stream(ic,AVMEDIA_TYPE_VIDEO,-1,-1,0,0);
    if(re<0)
    {
        XLOGE("av_find_best_stream failed");
        return XParameter();
    }
    videoStream = re;
    XParameter para;
    para.para = ic->streams[re]->codecpar;
    return para;
}

//获取音频流的索引信息
XParameter FFDemux::GetAPara()
{
    if(!ic)
    {
        return XParameter();
    }
    //获取音频流信息
    int re = av_find_best_stream(ic,AVMEDIA_TYPE_AUDIO,-1,-1,0,0);
    if(re<0)
    {
        XLOGE("av_find_best_stream failed");
        return XParameter();
    }
    audioStream = re;
    XParameter para;
    para.para = ic->streams[re]->codecpar;
    return para;
}

XDATA FFDemux::read()
{
    if(!ic)return XDATA();
    XDATA d;
    AVPacket *pkt = av_packet_alloc();
    int re = av_read_frame(ic,pkt);
    if(re != 0)
    {
        av_packet_free(&pkt);
        return XDATA();
    }
//    XLOGI("pack size is %d ptss %lld",pkt->size,pkt->pts);
    d.data = (unsigned char*)pkt;
    d.size = pkt->size;
    if(pkt->stream_index == audioStream)
    {
        d.isAudio = true;
    }
    else if(pkt->stream_index == videoStream)
    {
        d.isAudio = false;
    } else
    {
        av_packet_free(&pkt);
        return XDATA();
        //既不是音频 也不是视频
    }
    return d;
}

FFDemux::FFDemux()
{
    static bool isFirst = true;
    if (isFirst)
    {
        isFirst = false;
        av_register_all();

        //注册所有的解码器 不用判断是否多次注册 ffmpeg内部有机制判断是否之前有注册
        avcodec_register_all();

        avformat_network_init();

        XLOGI("register ffmpeg");

    }

}