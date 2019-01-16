//
// Created by xinmei365 on 2019/1/16.
//

#include <iostream>
#include <cassert>
#include <atomic>
#include <vector>
#include <unistd.h>
#include <thread>
#include <sstream>

std::atomic<int> foo(0);
std::atomic_flag lock = ATOMIC_FLAG_INIT;

void add_foo()
{
    while (1)
    {
        foo++;
        // foo = foo + 1;
        while (lock.test_and_set());
        std::cout <<"add: " << foo << std::endl;
        lock.clear();
        usleep(1000);
    }
}

void sub_foo()
{
    while (1)
    {
        foo--;
        // foo = foo - 1;
        while (lock.test_and_set());
        std::cout << "sub: " << foo << std::endl;
        lock.clear();
        usleep(1000);
    }
}
int mainthread7()
{
    std::thread th2 = std::thread(add_foo);
    std::thread th1 = std::thread(sub_foo);
    th1.join();
    th2.join();
    return 0;
}