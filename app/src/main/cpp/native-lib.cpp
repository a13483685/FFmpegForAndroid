#include <jni.h>
#include <string>

#include "FFDemux.h"
#include "Xlog.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_xz_jfz_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    IDemux *de = new FFDemux();

    bool isOpen = de->open("/sdcard/1080.mp4");
    if (isOpen)
    {
        XLOGI("open success!!");
    }
    return env->NewStringUTF(hello.c_str());
}
