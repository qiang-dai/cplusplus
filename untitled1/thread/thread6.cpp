//
// Created by xinmei365 on 2019/1/16.
//

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>
using namespace std;

std::atomic<int> foo_value(0);

void set_foo(int x)
{
    cout << "before set_foo" << endl;
    foo_value = x;
    cout << "after set_foo" << endl;
}

void print_foo()
{
    while (foo_value == 0)
    {
        cout << "before yield" << endl;
        std::this_thread::yield();
        cout << "after yield" << endl;
    }
    std::cout << "x: " << foo_value << std::endl;
}
int mainthread6()
{
    std::thread print_th(print_foo);
    std::thread set_th(set_foo, 10);
    print_th.join();
    set_th.join();
    return 0;
}