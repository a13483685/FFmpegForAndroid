//
// Created by xiezheng on 2018/4/3.
//

#include "XDATA.h"
extern "C" {
#include <libavformat/avformat.h>
}

void XDATA::Drop(){
    if(!data) return;
    av_packet_free((AVPacket **)&data);
    data = 0;
    size = 0;
}