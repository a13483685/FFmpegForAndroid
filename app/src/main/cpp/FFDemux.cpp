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

    XLOGE("total ms is",this->totalMs);

    return true;
}

XDATA FFDemux::read()
{
    XDATA d;
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