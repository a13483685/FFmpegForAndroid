//
// Created by xiezheng on 2018/4/3.
//

#ifndef JFZ_XLOG_H
#define JFZ_XLOG_H
#ifdef ANDROID
#include <android/log.h>
#define XLOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"XPlay",__VA_ARGS__)
#define XLOGI(...) __android_log_print(ANDROID_LOG_INFO,"XPlay",__VA_ARGS__)
#define XLOGE(...) __android_log_print(ANDROID_LOG_ERROR,"XPlay",__VA_ARGS__)
#else
#define XLOGD(...) printf("XPlay",__VA_ARGS__)
#define XLOGI(...) printf("XPlay",__VA_ARGS__)
#define XLOGE(...) printf("XPlay",__VA_ARGS__)
#endif

class Xlog {

};


#endif //JFZ_XLOG_H
