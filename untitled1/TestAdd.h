//
// Created by xinmei365 on 2018/12/31.
//

#ifndef UNTITLED1_TESTADD_H
#define UNTITLED1_TESTADD_H

#include "iostream"

class TestAdd
{
public:
    int Add(int a,int b)
    {
        std::cout << "TestAdd::Add" << std::endl;
        return a + b;
    }
};


#endif //UNTITLED1_TESTADD_H
