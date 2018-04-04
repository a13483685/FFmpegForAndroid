#include <jni.h>
#include <string>

#include "FFDemux.h"
#include "Xlog.h"
#include "XThread.h"


extern "C"
JNIEXPORT jstring

JNICALL
Java_xz_jfz_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    IDemux *de = new FFDemux();

    de->open("/sdcard/1080.mp4");
    de->start();
    XSleep(3000);
    de->stop();
    return env->NewStringUTF(hello.c_str());
}
