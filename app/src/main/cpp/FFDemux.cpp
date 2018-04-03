//
// Created by xiezheng on 2018/4/2.
//

#include "FFDemux.h"
#include "Xlog.h"

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