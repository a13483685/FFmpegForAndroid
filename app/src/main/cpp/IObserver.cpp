//
// Created by xiezheng on 2018/4/9.
//

#include "IObserver.h"


void IObserver::add(IObserver *observer)
{
    if (!observer) return;
    mux.lock();
    obss.push_back(observer);
    mux.unlock();
}

void IObserver::notify(XDATA xdata)
{
    mux.lock();
    for (int i = 0; i <obss.size() ; ++i) {
        obss[i]->update(xdata);
    }
    mux.unlock();
}