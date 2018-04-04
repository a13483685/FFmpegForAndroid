//
// Created by xiezheng on 2018/4/4.
//

#ifndef JFZ_XTHREAD_H
#define JFZ_XTHREAD_H


class XThread {
public:
    //线程的开始
    virtual void start();
    //通过isExit来安全停止线程
    virtual void stop();
    //主入口函数
    virtual void main() {}

private:
    virtual void ThreadMain();

};


#endif //JFZ_XTHREAD_H
