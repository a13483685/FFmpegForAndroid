//
// Created by xiezheng on 2018/4/4.
//

#include "XThread.h"
#include "Xlog.h"
#include <thread>

using namespace std;
void XSleep(int mis)
{
    //设置一个毫秒的定时对象
    chrono::milliseconds du(mis);
    this_thread::sleep_for(du);
}
//启动线程
void XThread::start()
{
    isExit = false;
    thread th(&XThread::ThreadMain,this);//创建一个线程 并且启动了 在堆栈中
    th.detach();//放弃线程的管理 因为当线程退出的时候 会对资源有影响 当前线程放弃对新线程的控制
}

//通过isExit安全停止线程
void XThread::stop()
{
    isExit = true;
    for (int i =0 ;i<200;i++)
    {
        if(!isRunning)
        {
            XLOGI("Stop 停止线程成功！");
            return;
        }
        XSleep(1);
    }
    XLOGI("Stop 停止线程超时！");
}

void XThread::ThreadMain() {
    isRunning = true;
    XLOGI("线程函数进入");
    main();
    XLOGI("线程函数退出");
    isRunning = false;
}