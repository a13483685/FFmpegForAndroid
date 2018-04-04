//
// Created by xiezheng on 2018/4/4.
//

#include "XThread.h"
#include "Xlog.h"
#include <thread>

using namespace std;
//启动线程
void XThread::start() {
    thread th(&XThread::ThreadMain,this);//创建一个线程 并且启动了 在堆栈中
    th.detach();//放弃线程的管理 因为当线程退出的时候 会对资源有影响 当前线程放弃对新线程的控制
}

//通过isExit安全停止线程
void XThread::stop() {

}

void XThread::ThreadMain() {
    XLOGI("线程函数进入");
    main();
    XLOGI("线程函数退出");
}