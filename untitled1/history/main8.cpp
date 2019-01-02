//
// Created by xinmei365 on 2018/12/31.
//
#include <thread>
#include <atomic>
#include <stdio.h>
#include <list>

#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <functional>
#include <iostream>
#include "../Test.h"
#include "../TestAdd.h"
#include <thread>

using namespace std;
std::mutex mtx;
std::condition_variable cv;
bool ready = false;
void print_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready)
    {
        cv.wait(lck);
    }
    // ...
    std::cout << "thread " << id << '\n';
}

void go() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}
int main81()
{
    std::thread threads[10];
    for (int i = 0; i<10; ++i)
    {
        threads[i] = std::thread(print_id, i);
    }
    std::cout << "10 threads ready to race...\n";
    go();
    for (auto& th : threads)
    {
        th.join();
    }
    return 0;
}

//int add(int a,int b)
//{
//    return a + b;
//}

int add(int a,int b)
{
    std::cout << "add" << std::endl;
    return a + b;
}
void output(int i)
{
    cout << i << endl;
}

int main82()
{
//    Test test;
//    test.Add(add, 1, 2);
//    Test test;
//    test.Add(add, 1, 2);
//
//    TestAdd testAdd;
//    test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

    auto add= [](int a, int b)->int{
        return a + b;
    };
    int ret = add(1,2);
    std::cout << "ret:" << ret << std::endl;

    for (uint8_t i = 0; i < 4; i++)
    {
        thread t(output, i);
        t.detach();
    }

    return 0;
}
//
//using namespace std;
//std::atomic_bool bIsReady = false;
//std::atomic_int iCount = 100;
//void threadfun1()
//{
//    if (!bIsReady) {
//        std::this_thread::yield();
//    }
//    while (iCount > 0)
//    {
//        printf("iCount:%d\r\n", iCount--);
//    }
//}
//
//int main()
//{
//    std::atomic_bool b;
//    std::list<std::thread> lstThread;
//    for (int i = 0; i < 10; ++i)
//    {
//        lstThread.push_back(std::thread(threadfun1));
//    }
//    for (auto& th : lstThread)
//    {
//        th.join();
//    }
//}
