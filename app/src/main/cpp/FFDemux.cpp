//
// Created by xiezheng on 2018/4/2.
//

#include "FFDemux.h"
#include "Xlog.h"
#include <libavformat/avformat.h>

extern "C" {
//#include <>
}

bool FFDemux::open(const char* url)
{
    XLOGI("Open file %s begin",url);
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