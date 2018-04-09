//
// Created by xiezheng on 2018/4/9.
//

#ifndef JFZ_IOBSERVER_H
#define JFZ_IOBSERVER_H

#include "XDATA.h"
#include "XThread.h"
#include <vector>
#include <mutex>//c++ 11支持
//观察者和主体
class IObserver:public XThread
{
public:
    //观察者接收数据函数
    virtual void add(IObserver* observer);
    //添加观察者
    virtual void update(XDATA xdata){};
    //通知观察者
    virtual void notify(XDATA xdata);

protected:
    std::vector<IObserver *> obss;
    //考虑线程安全
    //如果代码要移植到linux中，那么这部分要添加c++ 11的支持
    std::mutex mux;

};


#endif //JFZ_IOBSERVER_H
