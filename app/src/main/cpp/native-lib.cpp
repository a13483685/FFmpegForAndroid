#include <jni.h>
#include <string>

#include "FFDemux.h"
#include "Xlog.h"
#include "XThread.h"
#include "Idecode.h"
#include "FFdecode.h"

class TestObs:public IObserver
{
public:
    void update(XDATA xdata){
//        XLOGI("TestObs update xdata datasize is : %d ",xdata.size);
    }
};

extern "C"
JNIEXPORT jstring

JNICALL
Java_xz_jfz_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    TestObs *obs = new TestObs;
    IDemux *de = new FFDemux();
    de->add(obs);
    de->open("/sdcard/1080.mp4");

    Idecode *vdecode =new FFdecode();
    vdecode->Open(de->GetVPara());

    de->start();
    XSleep(3000);
    de->stop();
    return env->NewStringUTF(hello.c_str());
}
