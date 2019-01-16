//
// Created by xinmei365 on 2019/1/16.
//
#include "iostream"
using namespace std;

template <class T>
class TestClass
{
public:
    TestClass() { cout << "T" << endl;  }
};

template <class T>
class TestClass<T*>
{
public:
    TestClass() { cout << "T*" << endl;  }
};

template <class T>
class TestClass<const T*>
{
public:
    TestClass() { cout << "const T*" << endl;  }
};

int mains4()
{
    // 偏特化测试
    TestClass<int> obj_common;
    TestClass<int*> obj_spec1;
    TestClass<const int *> obj_spec2;
}
