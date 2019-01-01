//
// Created by xinmei365 on 2018/12/30.
//
//#include <sys/_types/_ucontext.h>
//#include "ucontext.h"
#include "unistd.h"

int main41(int argc, const char *argv[]) {
//    ucontext_t context;
//    getcontext(&context);

    int a1 = 3;   ///non-const data
    int a2 = 5;
//    const int a2=a1;    ///const data

    int * a3 = &a1;   ///non-const data,non-const pointer
    const int * a4 = &a1;   ///const data,non-const pointer
    int * const a5 = &a1;   ///non-const data,const pointer
    int const * const a6 = &a1;   ///const data,const pointer
    const int * const a7 = &a1;   ///const data,const pointer

    a4 = &a2;
//    *a4 = 5;
//    a5 = &a2;
//
//    a6 = &a2;
//    a7 = &a2;


    return 0;
}

