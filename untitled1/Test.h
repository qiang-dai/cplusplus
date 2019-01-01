//
// Created by xinmei365 on 2018/12/31.
//

#ifndef UNTITLED1_TEST_H
#define UNTITLED1_TEST_H

#include <iostream>

class Test
{
public:
    typedef int(*FunType)(int, int);
    void Add(FunType fun,int a,int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
    void Add(std::function<int(int, int)> fun, int a, int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
};


#endif //UNTITLED1_TEST_H
