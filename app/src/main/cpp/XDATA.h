//
// Created by xiezheng on 2018/4/3.
//

#ifndef JFZ_XDATA_H
#define JFZ_XDATA_H


struct XDATA {
public:
    int size;
    unsigned char *data = 0;
    bool isAudio = false;
    void Drop();
};


#endif //JFZ_XDATA_H
