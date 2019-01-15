//
// Created by xinmei365 on 2019/1/15.
//

#include <iostream>

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

int main() {
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

    return 0;
}