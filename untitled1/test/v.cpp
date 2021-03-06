//
// Created by xinmei365 on 2019/1/15.
//

#include <iostream>
#include "../tools/LogTool.h"

using namespace std;

class Base1 {
public:
    virtual void f()
    {
        cout << "base1::f" << endl;
    }
    virtual void g()
    {
        cout << "base1::g" << endl;
    }
    virtual void h()
    {
        cout << "base1::h" << endl;
    }
};

class Base2 {
public:
    virtual void f()
    {
        cout << "base2::f" << endl;
    }
    virtual void g()
    {
        cout << "base2::g" << endl;
    }
    virtual void h()
    {
        cout << "base2::h" << endl;
    }
};

class Base3 {
public:
    virtual void f()
    {
        cout << "base3::f" << endl;
    }
    virtual void g()
    {
        cout << "base3::g" << endl;
    }
    virtual void h()
    {
        cout << "base3::h" << endl;
    }
};


class Derive : public Base1, public Base2, public Base3 {
public:
    void f()
    {
        cout << "derive::f" << endl;
    }
};

class A
{
public:
    int n;
    virtual void Foo(void){}
};

template <class T>
struct MyIter {
    typedef T value_type;
    T* ptr;
    MyIter(T* p = 0) : ptr(p) {}
    T& operator*() const {return *ptr;}
};

template <class I>
typename I::value_type func2(I iter) {
    return *iter;
}

template <typename  Iterator, typename T>
void func_impl(Iterator iter, T t)
{
    T temp;
}

template <typename Iterator>
void func(Iterator iter)
{
    func_impl(iter, *iter);
}


int mainm4() {
    ___TRACE("vtable:%d\n", 0);

    A a;
    char *p1 = reinterpret_cast<char *>(&a);
    char *p2 = reinterpret_cast<char *>(&a.n);
    if (p1 == p2) {
        cout << "vPtr is in the end of class instance!" << endl;
    }
    else
    {
        cout << "vPtr is in the head of class instance!" << endl;
    }

//    cout << "size of Base: " << sizeof(Base1) << endl;
    typedef void (*Func)(void);
//    Base1 *d = new Derive();

    cout << "size of Base: " << sizeof(Base2) << endl;
    typedef void (*Func)(void);
    Base2 *d = new Derive();

    long *pvptr = (long*)d;
    long *vptr = (long*)*pvptr;

    Func f = (Func)vptr[0];
    Func g = (Func)vptr[1];
    Func h = (Func)vptr[2];
    cout << "last value:" << vptr[3] << endl;

    f();
    g();
    h();

    MyIter<int> iter(new int(8));
    cout << func2(iter) << endl;

    int i;
    func(&i);
    return 0;
}