//
// Created by xinmei365 on 2018/12/29.
//

#ifndef UNTITLED1_TT_H
#define UNTITLED1_TT_H

#include "stdio.h"
#include "stdlib.h"

class tt{

public:

//    tt(int*&& pv) : v(pv) {
//        printf("first pv: ");
//    }

    void print() {
        printf("x addr:%08x\n", v);
        if(v != nullptr) {
            printf("x val:%d\n", *v);
        }
    }

    tt(int*& pv, bool hold=false) :v(nullptr) {
        //注意，不能int*，而是int*&，前者会导致编译器不知道调用哪个版本重载
        printf("use left\n");
        if (pv != nullptr) v = new int(*pv);
        if (hold) {
            delete pv;
            pv = nullptr;
        }
        print();
    }//left ref

    tt(int* const&& pv) :v(nullptr) {
        printf("use right\n");
        print();


        v = pv;
        print();
    }//right ref
private:

    int *v;

};


#endif //UNTITLED1_TT_H
